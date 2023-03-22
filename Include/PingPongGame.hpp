//
// Created by EmilB on 21/02/2023.
//

#ifndef CODE_PROJECT_PingPongGame_HPP
#define CODE_PROJECT_PingPongGame_HPP
#include "PingPongScene.hpp"

using namespace threepp;
class Game{
public:
    Game() : PingPongScene_(PingPongScene::create()), velocity(0.01,0.01,0){};
    void update();
    void init();
private:
    Vector3 velocity;
    std::shared_ptr<PingPongScene> PingPongScene_;
};

class MyKeylistner : public KeyListener {
public:
    MyKeylistner(const std::shared_ptr<Mesh>& mesh) {}
    void onKeyPressed(KeyEvent evt) override{
        float P1y = paddleOne->position.y;
        float P2y = paddleTwo->position.y;

        if( evt.key == 265){
            paddleOne->position.y -= 0.3;
        }
        if(evt.key == 264){
            paddleOne->position.y += 0.3;
        }
    };
private:
    std::shared_ptr<Mesh> paddleOne;
    std::shared_ptr<Mesh> paddleTwo;
};

void Game::update() {
        auto ball = PingPongScene_->getGroup()->getObjectByName("ball");

        //Update the ball position based on velocity
        ball->position.add(velocity);

        //Check for collision with the paddles and reflect ball velocity accordingly
        auto paddleOne = PingPongScene_->getGroup()->getObjectByName("paddleOne");
        auto paddleTwo = PingPongScene_->getGroup()->getObjectByName("paddleTwo");
        paddleOne->position.x = -2.5;
        paddleTwo->position.x = 2.5;

        if (ball->position.distanceTo(paddleOne->position) < 0.6 && velocity.x < 0) {
            PingPongScene_->P1Score++;
            ball->position.set(0,0,0);
            velocity.x *= -1;
        }
        if (ball->position.distanceTo(paddleTwo->position) < 0.6 && velocity.x > 0) {
            PingPongScene_->P2Score++;
            ball->position.set(0,0,0);
            velocity *= -1;
        }
        //Check for collision with the walls and reflect the ball accordingly
        if (ball->position.y < -3.4 || ball->position.y > 3.4) {
            velocity.y *= -1;
        }

}
void Game::init() {
    //PingPongScene_->scene_->add(PingPongScene_->group_);
    PingPongScene_->canvas_.animate([&]{
        Game::update();
        std::chrono::milliseconds (16);
        PingPongScene_->renderer_.render(PingPongScene_->scene_,PingPongScene_->camera_);
    });
}

#endif //CODE_PROJECT_HEADER1_HPP
