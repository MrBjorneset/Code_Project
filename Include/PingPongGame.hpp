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
    int update();
    void init();
private:
    Vector3 velocity;
    Vector3 paddleSpeed;
    std::shared_ptr<PingPongScene> PingPongScene_;
};

class MyListener : public KeyListener{
public:
    bool DirectionDown = false;
    bool DirectionUp = false;

    void onKeyPressed(KeyEvent evt) override {
        if (evt.key == 265) { //up arrow key
            DirectionDown = true;
        }
        if (evt.key == 264) { //down arrow key
            DirectionDown = true;
        }
    }
    void onKeyReleased(KeyEvent evt) override{
        if( evt.key == 265){ //up arrow Key
            DirectionDown   = false;
        }
        if(evt.key == 264){ //down arrow key
            DirectionDown   = false;
        }
    }
};


int Game::update() {
        auto ball = PingPongScene_->getGroup()->getObjectByName("ball");
        //Update the ball position based on velocity
        ball->position.add(velocity);
        paddleSpeed = Vector3(0,0.3,0);
        //Check for collision with the paddles and reflect ball velocity accordingly
        auto paddleOne = PingPongScene_->getGroup()->getObjectByName("paddleOne");
        auto paddleTwo = PingPongScene_->getGroup()->getObjectByName("paddleTwo");
        paddleOne->position.x = -3.5;
        paddleTwo->position.x =  3.5;
        MyListener listener;
        PingPongScene_->canvas_.addKeyListener(&listener);
        if (ball->position.distanceTo(paddleOne->position) < 0.6 && velocity.x < 0) {
            velocity.x *= -1;
        }
        if (ball->position.distanceTo(paddleTwo->position) < 0.6 && velocity.x > 0) {
            velocity *= -1;
        }
        //Check for collision with the walls and reflect the ball accordingly
        if (ball->position.y < -5.0f || ball->position.y > 5.0f) {
            velocity.y *= -1;
        }
        if (ball->position.x < -5.0f){
            PingPongScene_->P1Score += 1;
            ball->position.set(0,0,0);
            velocity.x *= -1;
        }
        if (ball->position.x > 5.0f){
            PingPongScene_->P2Score += 1;
            ball->position.set(0,0,0);
            velocity.x *= -1;
        }
        if (listener.DirectionDown){
            paddleOne->position.add(paddleSpeed);
        }
        if (listener.DirectionUp){
            paddleOne->position.add(paddleSpeed*(-1));
        }
    return 0;
}
void Game::init() {
    PingPongScene_->canvas_.onWindowResize([&](WindowSize){
        auto size = PingPongScene_->renderer_.getSize();
        PingPongScene_->renderer_.setSize(size);
    });

    PingPongScene_->canvas_.animate([&]{
        Game::update();
        std::chrono::milliseconds (16);
        PingPongScene_->renderer_.render(PingPongScene_->scene_,PingPongScene_->camera_);
    });
}

#endif //CODE_PROJECT_HEADER1_HPP
