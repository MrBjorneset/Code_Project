//
// Created by EmilB on 21/02/2023.
//


#ifndef CODE_PROJECT_PingPongGame_HPP
#define CODE_PROJECT_PingPongGame_HPP
#include "PingPongScene.hpp"

using namespace threepp;
class MyListener : public KeyListener{
public:
    bool p1DirectionUp = false;
    bool p1DirectionDown = false;
    bool p2DirectionUp = false;
    bool p2DirectionDown = false;
    bool singelPlayer = false;
    bool multiPlayer = false;
    bool restart = false;

    void onKeyPressed(KeyEvent evt) override {
        if (evt.key == 87) {        //"w" key
            p1DirectionUp = true;
        }
        if (evt.key == 83) {        //"s" key
            p1DirectionDown = true;
        }
        if (evt.key == 265) {       //up arrow key
            p2DirectionUp = true;
        }
        if (evt.key == 264) {      //down arrow key
            p2DirectionDown = true;
        }
        if (evt.key == 49 ){       //"1" key
            singelPlayer = true;
        }
        if (evt.key == 50 ){       //"2" key
            multiPlayer = true;
        }
        if (evt.key == 82){        //"r" key
            restart = true;
            singelPlayer = false;
            multiPlayer = false;
        }
    }

    void onKeyReleased(KeyEvent evt) override{
        if (evt.key == 87) {        //"w" key
            p1DirectionUp = false;
        }
        if (evt.key == 83) {        //"s" key
            p1DirectionDown = false;
        }
        if (evt.key == 265){       //up arrow Key
            p2DirectionUp = false;
        }
        if (evt.key == 264){       //down arrow key
            p2DirectionDown = false;
        }
        if (evt.key == 82){        //"r" key
            restart = false;
        }
    }
private:
};

class Game{
public:
    Game() : velocity(0.15,0.8,0){};
    void CheckCollision(std::shared_ptr<Mesh> &Ball, std::shared_ptr<Mesh> &Paddle1, std::shared_ptr<Mesh> &Paddle2);
    void singlePlayerMovement(bool up, bool down);
    void multiPlayerMovement(bool p1Up, bool p1Down, bool p2Up, bool p2Down);
    void trackBall(Vector3 ball);
    int P1Score_ = 0;
    int P2Score_ = 0;
    float p1PaddleSpeedY;
    float p2PaddleSpeedY;
    MyListener listener;
    std::shared_ptr<Group> group_;
private:
    std::shared_ptr<Ball> Ball_;
    std::shared_ptr<Paddle> Paddle_;
    Vector3 velocity;

};

void Game::trackBall(Vector3 ball) {
    auto ballPosition = ball;

    // Calculate the target y position of the paddle based on the ball's x position
    float targetY = ballPosition.y;
    if (ballPosition.x > 0) {
        // Ball is moving towards paddleTwo, so move paddleTwo towards the ball's y position
        targetY += (rand() % 5) - 2; // add some randomness to the target y position
    } else {
        // Ball is moving away from paddleTwo, so move paddleTwo towards the center
        targetY = 0.0f;
    }

    // Move the paddle towards the target y position
    float speed = 0.5f; // adjust this value to change the paddle's movement speed
    p2PaddleSpeedY = targetY * speed;
}


//Function to move paddles in singleplayer mode
void Game::singlePlayerMovement(bool up, bool down){
    //Move paddleOne based on user input, "w" and "s" keys
    if (up){
        p1PaddleSpeedY = 0.5f;
    }
    else if (down){
        p1PaddleSpeedY = -0.5f;
    }
    else if (!up && !down){
        p1PaddleSpeedY = 0;
    }
}

//Function to move paddles in multiplayer mode
void Game::multiPlayerMovement(bool p1Up, bool p1Down, bool p2Up, bool p2Down) {
    //Move paddleOne based on user input, "w" and "s" keys
    if (p1Up){
        p1PaddleSpeedY = 0.5f;
    }
    else if (p1Down){
        p1PaddleSpeedY = -0.5f;
    }
    else if (!p1Up && !p1Down){
        p1PaddleSpeedY = 0;
    }

    //Move paddleTwo based on user input, arrow up and down keys
    if (p2Up){
        p2PaddleSpeedY = 0.5f;
    }
    else if (p2Down){
        p2PaddleSpeedY = -0.5f;
    }
    else if (!p2Up && !p2Down){
        p2PaddleSpeedY = 0;
    }
}


//Function for checking collision between wall, paddle and ball.
void Game::CheckCollision(std::shared_ptr<Mesh> &Ball, std::shared_ptr<Mesh> &Paddle1, std::shared_ptr<Mesh> &Paddle2){
    //Retrieve the 3D-Objects
    auto &ball = Ball;
    auto &paddleOne = Paddle1;
    auto &paddleTwo = Paddle2;
    float ballRadius = 0.8;
    float paddleWidth = 0.5;
    float paddleHeight = 15;
    float paddleDepth = 0.2;
    float dt = 0.16;

    // Check collision with paddle one
    if (ball->position.x - ballRadius < paddleOne->position.x + paddleWidth / 2 &&
        ball->position.x + ballRadius > paddleOne->position.x - paddleWidth / 2 &&
        ball->position.y - ballRadius < paddleOne->position.y + paddleHeight / 2 &&
        ball->position.y + ballRadius > paddleOne->position.y - paddleHeight / 2 &&
        ball->position.z - ballRadius < paddleOne->position.z + paddleDepth / 2 &&
        ball->position.z + ballRadius > paddleOne->position.z - paddleDepth / 2) {

        Ball_->velocity.x = Ball_->velocity.x * -1.03f;
        ball->position.x = paddleOne->position.x + ballRadius + paddleWidth / 2;
    }

    // Check collision with paddle two
    else if (ball->position.x - ballRadius < paddleTwo->position.x + paddleWidth / 2 &&
             ball->position.x + ballRadius > paddleTwo->position.x - paddleWidth / 2 &&
             ball->position.y - ballRadius < paddleTwo->position.y + paddleHeight / 2 &&
             ball->position.y + ballRadius > paddleTwo->position.y - paddleHeight / 2 &&
             ball->position.z - ballRadius < paddleTwo->position.z + paddleDepth / 2 &&
             ball->position.z + ballRadius > paddleTwo->position.z - paddleDepth / 2) {

        Ball_->velocity.x = Ball_->velocity.x * -1.03f;
        ball->position.x = paddleTwo->position.x - ballRadius - paddleWidth / 2;
    }

    //Check for collision with the walls and reflect the ball accordingly
    else if (ball->position.y < -60.0f || ball->position.y > 60.0f) {
        Ball_->velocity.y *= -1;
    }
        //Check if the ball hits the left and right walls, give point to correct team and reset the ball position to (x=0, y=0, z=0)
    else if (ball->position.x < -60.0f){
        P1Score_ ++;
        std::string P1Score = std::to_string(P1Score_);
        Ball_->setPosition(0,0,0);
        Ball_->velocity.x *= -1;
    }
    else if (ball->position.x > 60.0f){
        P2Score_ ++;
        std::string  P2Score = std::to_string(P2Score_);
        Ball_->setPosition(0,0,0);
        Ball_->velocity.x *= -1;
    }
}


/*
//Function to update the game using previously create functions
void Game::update(bool single, bool multi) {
    //std::cout << "menu" << std::endl;
    //std::cout << velocity << std::endl;
    //std::cout << Objects_->getGroup()->getObjectByName("ball")->position << std::endl;

    if (single && !multi) {
        Game::CheckCollision(Ball_->getMesh(),Paddle_->getMesh());
        Game::singlePlayerMovement();
        Game::trackBall();
        Game::addMovement();
        std::cout << "SinglePlayer" << std::endl;
    }
    else if (!single && multi){
        Game::CheckCollision();
        Game::multiPlayerMovement();
        Game::addMovement();
        std::cout << "Multiplayer" << std::endl;
    }
}

void Game::init(){
}

*/
#endif //CODE_PROJECT_HEADER1_HPP
