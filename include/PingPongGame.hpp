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
            singelPlayer = false;
            multiPlayer = false;
            restart = false;
        }
    }
private:
};

class Game{
public:
    Game() : velocity(0.15,0.8,0){};
    void update(bool single, bool multi);
    void init();
    void CheckCollision(std::shared_ptr<Mesh> &Ball, std::shared_ptr<Mesh> &Paddle1, std::shared_ptr<Mesh> &Paddle2);
    void singlePlayerMovement();
    void multiPlayerMovement();
    void trackBall();
    void addMovement(std::shared_ptr<Mesh> Paddle1, std::shared_ptr<Mesh> Paddle2);

    int P1Score_ = 0;
    int P2Score_ = 0;
    MyListener listener;
    Vector3 p1PaddleSpeed;
    Vector3 p2PaddleSpeed;
    std::shared_ptr<Group> group_;
private:
    std::shared_ptr<Ball> Ball_;
    std::shared_ptr<Paddle> Paddle_;
    Vector3 velocity;

};

void Game::trackBall() {
    auto ball = Ball_->getMesh();
    auto paddleTwo = Paddle_->getMesh();
    //Move paddleTwo based on ball direction
    if (ball->position.y > paddleTwo->position.y){
        paddleTwo->position.y += 0.5f;
    }
    else if(ball->position.y < paddleTwo->position.y){
        paddleTwo->position.y -= 0.5f;
    }
}

//Function to move paddles in singleplayer mode
void Game::singlePlayerMovement(){
    //Move paddleOne based on user input, "w" and "s" keys
    if (listener.p1DirectionUp){
        p1PaddleSpeed.y = 0.5f;
    }
    else if (listener.p1DirectionDown){
        p1PaddleSpeed.y = -0.5f;
    }
    else if (!listener.p1DirectionUp && !listener.p1DirectionDown){
        p1PaddleSpeed.y = 0;
    }
}

//Function to move paddles in multiplayer mode
void Game::multiPlayerMovement() {
    //Move paddleOne based on user input, "w" and "s" keys
    if (listener.p1DirectionUp){
        p1PaddleSpeed.y = 0.5f;
    }
    else if (listener.p1DirectionDown){
        p1PaddleSpeed.y = -0.5f;
    }
    else if (!listener.p1DirectionUp && !listener.p1DirectionDown){
        p1PaddleSpeed.y = 0;
    }

    //Move paddleTwo based on user input, arrow up and down keys
    if (listener.p2DirectionUp){
        p2PaddleSpeed.y = 0.5f;
    }
    else if (listener.p2DirectionDown){
        p2PaddleSpeed.y = -0.5f;
    }
    else if (!listener.p2DirectionUp && !listener.p2DirectionDown){
        p2PaddleSpeed.y = 0;
    }
}

void Game::addMovement(std::shared_ptr<Mesh> Paddle1, std::shared_ptr<Mesh> Paddle2) {
    auto &paddleOne = Paddle1;
    auto &paddleTwo = Paddle2;

    paddleOne->position.add(p1PaddleSpeed);
    paddleTwo->position.add(p2PaddleSpeed);

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
    //Update the ball position based on velocity
   Ball_->update(dt);

    // Check collision with paddle one
    if (ball->position.x - ballRadius < paddleOne->position.x + paddleWidth / 2 &&
        ball->position.x + ballRadius > paddleOne->position.x - paddleWidth / 2 &&
        ball->position.y - ballRadius < paddleOne->position.y + paddleHeight / 2 &&
        ball->position.y + ballRadius > paddleOne->position.y - paddleHeight / 2 &&
        ball->position.z - ballRadius < paddleOne->position.z + paddleDepth / 2 &&
        ball->position.z + ballRadius > paddleOne->position.z - paddleDepth / 2) {

        Ball_->velocity.x = Ball_->velocity.x *-1 * 1.03f;
        ball->position.x = paddleOne->position.x + ballRadius + paddleWidth / 2;
    }

        // Check collision with paddle two
    else if (ball->position.x - ballRadius < paddleTwo->position.x + paddleWidth / 2 &&
             ball->position.x + ballRadius > paddleTwo->position.x - paddleWidth / 2 &&
             ball->position.y - ballRadius < paddleTwo->position.y + paddleHeight / 2 &&
             ball->position.y + ballRadius > paddleTwo->position.y - paddleHeight / 2 &&
             ball->position.z - ballRadius < paddleTwo->position.z + paddleDepth / 2 &&
             ball->position.z + ballRadius > paddleTwo->position.z - paddleDepth / 2) {

        velocity.x = -velocity.x * 1.03f;
        ball->position.x = paddleTwo->position.x - ballRadius - paddleWidth / 2;
    }

        //Check for collision with the walls and reflect the ball accordingly
    else if (ball->position.y < -60.0f || ball->position.y > 60.0f) {
        velocity.y *= -1;
    }
        //Check if the ball hits the left and right walls, give point to correct team and reset the ball position to (x=0, y=0, z=0)
    else if (ball->position.x < -60.0f){
        P1Score_ ++;
        std::string P1Score = std::to_string(P1Score_);
        //Objects_->renderer_.textHandle(P1Score).setPosition(1400, Objects_->canvas_.getSize().height -1000);
        ball->position.set(0,0,0);
        velocity = Vector3(0.15,0.8,0);
        velocity.x *= -1;
    }
    else if (ball->position.x > 60.0f){
        P2Score_ ++;
        std::string  P2Score = std::to_string(P2Score_);
        //Objects_->renderer_.textHandle(P2Score).setPosition(400,Objects_->canvas_.getSize().height -1000);
        ball->position.set(0,0,0);
        velocity = Vector3(0.15,0.8,0);
        velocity.x *= -1;
    }
}



//Function to update the game using previously create functions
void Game::update(bool single, bool multi) {
    //std::cout << "menu" << std::endl;
    //std::cout << velocity << std::endl;
    //std::cout << Objects_->getGroup()->getObjectByName("ball")->position << std::endl;

    if (single && !multi) {
        Game::CheckCollision();
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


#endif //CODE_PROJECT_HEADER1_HPP
