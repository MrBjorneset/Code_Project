//
// Created by EmilB on 21/02/2023.
//

#ifndef CODE_PROJECT_PingPongGame_HPP
#define CODE_PROJECT_PingPongGame_HPP
#include "PingPongScene.hpp"

using namespace threepp;
class MyListener : public KeyListener{
public:
    bool DirectionUp = false;
    bool DirectionDown = false;
    bool singelPlayer = false;
    bool multiPlayer = false;
    bool started = false;
    bool restart = false;

    void onKeyPressed(KeyEvent evt) override {
        if (evt.key == 265) {           //up arrow key
            DirectionUp = true;
        }
        if (evt.key == 264) {      //down arrow key
            DirectionDown = true;
        }
        if (evt.key == 49 ){       //"1" key
            singelPlayer = true;
        }
        if (evt.key == 50 ){       //"2" key
            multiPlayer = true;
        }
        if (evt.key == 82){        //"r" key
            restart = true;
        }
    }

    void onKeyReleased(KeyEvent evt) override{
        if (evt.key == 265){            //up arrow Key
            DirectionUp = false;
        }
        if (evt.key == 264){       //down arrow key
            DirectionDown = false;
        }
        if (evt.key == 82){        //"r" key
            singelPlayer = false;
            multiPlayer = false;
            restart = false;
        }
    }
};

class Game{
public:
    Game() : PingPongScene_(PingPongScene::create()), velocity(0.15,0.15,0){
    };
    void update();
    void init();
    void CheckCollision();
    void paddleMovement();
    int P1Score_ = 0;
    int P2Score_ = 0;
private:
    Vector3 velocity;
    Vector3 paddleSpeed;
    std::shared_ptr<PingPongScene> PingPongScene_;
    MyListener listener;

};

//Function to move paddles
void Game::paddleMovement(){
    auto ball = PingPongScene_->getGroup()->getObjectByName("ball");
    auto paddleOne = PingPongScene_->getGroup()->getObjectByName("paddleOne");
    auto paddleTwo = PingPongScene_->getGroup()->getObjectByName("paddleTwo");
    //Move paddleTwo based on ball direction
    if (ball->position.y > paddleTwo->position.y){
        paddleTwo->position.y += 0.5f;
    }
    else if(ball->position.y < paddleTwo->position.y){
        paddleTwo->position.y -= 0.5f;
    }
    //Move paddleOne based on user input, arrow up and down keys
    if (listener.DirectionUp){
        paddleSpeed.y = 0.5f;
    }
    if (listener.DirectionDown){
        paddleSpeed.y = -0.5f;
    }
    if (!listener.DirectionUp && !listener.DirectionDown){
        paddleSpeed.y = 0;
    }
    paddleOne->position.add(paddleSpeed);
}

//Function for checking collision between wall, paddle and ball.
void Game::CheckCollision(){

    //Retrieve the 3D-Objects
    auto ball = PingPongScene_->getGroup()->getObjectByName("ball");
    auto paddleOne = PingPongScene_->getGroup()->getObjectByName("paddleOne");
    auto paddleTwo = PingPongScene_->getGroup()->getObjectByName("paddleTwo");

    //Update the ball position based on velocity
    ball->position.add(velocity);

    // Check collision with paddle one
    if (ball->position.x - PingPongScene_->ballRadius_ < paddleOne->position.x + PingPongScene_->paddleWidth_ / 2 &&
        ball->position.x + PingPongScene_->ballRadius_ > paddleOne->position.x - PingPongScene_->paddleWidth_ / 2 &&
        ball->position.y - PingPongScene_->ballRadius_ < paddleOne->position.y + PingPongScene_->paddleHeight_ / 2 &&
        ball->position.y + PingPongScene_->ballRadius_ > paddleOne->position.y - PingPongScene_->paddleHeight_ / 2 &&
        ball->position.z - PingPongScene_->ballRadius_ < paddleOne->position.z + PingPongScene_->paddleDepth_ / 2 &&
        ball->position.z + PingPongScene_->ballRadius_ > paddleOne->position.z - PingPongScene_->paddleDepth_ / 2) {

        velocity.x = -velocity.x * 1.03f;
        ball->position.x = paddleOne->position.x + PingPongScene_->ballRadius_ + PingPongScene_->paddleWidth_ / 2;
    }

    // Check collision with paddle two
    else if (ball->position.x - PingPongScene_->ballRadius_ < paddleTwo->position.x + PingPongScene_->paddleWidth_ / 2 &&
        ball->position.x + PingPongScene_->ballRadius_ > paddleTwo->position.x - PingPongScene_->paddleWidth_ / 2 &&
        ball->position.y - PingPongScene_->ballRadius_ < paddleTwo->position.y + PingPongScene_->paddleHeight_ / 2 &&
        ball->position.y + PingPongScene_->ballRadius_ > paddleTwo->position.y - PingPongScene_->paddleHeight_ / 2 &&
        ball->position.z - PingPongScene_->ballRadius_ < paddleTwo->position.z + PingPongScene_->paddleDepth_ / 2 &&
        ball->position.z + PingPongScene_->ballRadius_ > paddleTwo->position.z - PingPongScene_->paddleDepth_ / 2) {

        velocity.x = -velocity.x * 1.03f;
        ball->position.x = paddleTwo->position.x - PingPongScene_->ballRadius_ - PingPongScene_->paddleWidth_ / 2;
    }

    //Check for collision with the walls and reflect the ball accordingly
    else if (ball->position.y < -60.0f || ball->position.y > 60.0f) {
        velocity.y *= -1;
    }
    //Check if the ball hits the left and right walls, give point to correct team and reset the ball position to (x=0, y=0, z=0)
    else if (ball->position.x < -60.0f){
        P1Score_ ++;
        std::string P1Score = std::to_string(P1Score_);
        PingPongScene_->renderer_.textHandle(P1Score).setPosition(1400, PingPongScene_->canvas_.getSize().height -1000);
        ball->position.set(0,0,0);
        velocity = Vector3(0.15,0.15,0);
        velocity.x *= -1;
    }
    else if (ball->position.x > 60.0f){
        P2Score_ ++;
        std::string  P2Score = std::to_string(P2Score_);
        PingPongScene_->renderer_.textHandle(P2Score).setPosition(400,PingPongScene_->canvas_.getSize().height -1000);
        ball->position.set(0,0,0);
        velocity = Vector3(0.15,0.15,0);
        velocity.x *= -1;
    }
}

//Function to update the game using previously create functions
 void Game::update() {
    Game::CheckCollision();
    Game::paddleMovement();

}
//Function for initializing the game using the update function
void Game::init() {
    PingPongScene_->canvas_.addKeyListener(&listener);
    PingPongScene_->canvas_.onWindowResize([&](WindowSize){
        auto size = PingPongScene_->renderer_.getSize();
        PingPongScene_->renderer_.setSize(size);
    });

    PingPongScene_->canvas_.animate([&]{
        Game::update();
        PingPongScene_->renderer_.render(PingPongScene_->scene_,PingPongScene_->camera_);
    });
}

#endif //CODE_PROJECT_HEADER1_HPP
