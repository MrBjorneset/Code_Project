//
// Created by EmilB on 21/02/2023.
//

#ifndef CODE_PROJECT_PingPongGame_HPP
#define CODE_PROJECT_PingPongGame_HPP
#include "PingPongScene.hpp"

using namespace threepp;
class Game{
public:
    Game() : scene_(PingPongScene::create()), velocity(0.01,0.01,0){};
    void update();
private:
    Vector3 velocity;
    std::shared_ptr<PingPongScene> scene_;
};

void Game::update() {
        auto ball = scene_->getGroup()->getObjectByName("ball");

        //Update the ball position based on velocity
        ball->position.add(velocity);

        //Check for collision with the paddles and reflect ball velocity accordingly
        auto paddleOne = scene_->getGroup()->getObjectByName("paddleOne");
        auto paddleTwo = scene_->getGroup()->getObjectByName("paddleTwo");

        if (ball->position.distanceTo(paddleOne->position) < 0.6 && velocity.x < 0) {
            scene_->P1Score++;
            velocity.x *= -1;
        }
        if (ball->position.distanceTo(paddleTwo->position) < 0.6 && velocity.x > 0) {
            scene_->P2Score++;
            velocity *= -1;
        }
        //Check for collision with the walls and reflect the ball accordingly
        if (ball->position.y < -3.4 || ball->position.y > 3.4) {
            velocity.y *= -1;
        }

    }


#endif //CODE_PROJECT_HEADER1_HPP
