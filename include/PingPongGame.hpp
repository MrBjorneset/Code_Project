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
    void singlePlayerMovement(bool up, bool down);
    void multiPlayerMovement(bool p1Up, bool p1Down, bool p2Up, bool p2Down);
    void checkWallCollision(Ball& ball, float left, float right, float roof, float floor, int p1Score, int p2Score);
    float p1PaddleSpeedY;
    float p2PaddleSpeedY;
private:
    std::shared_ptr<Ball> Ball_;
    std::shared_ptr<Paddle> Paddle_;
    Vector3 velocity;
};

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

void Game::checkWallCollision(Ball &ball, float left, float right, float roof, float floor, int p1Score, int p2Score) {
    auto ballPos = ball.getMesh()->position;

    //Check collision with the left wall
    if (ballPos.x < left){
        p2Score +=1;
        ball.setPosition(0,0,0);
    }

    //Check collision with the right wall
    if (ballPos.x  > right) {
        p1Score +=1;
        ball.setPosition(0,0,0);
    }

    //check collision with the roof
    if (ballPos.y + ball.velocity.y > roof){
        ball.velocity.y = -std::abs(ball.velocity.y);
    }

    //check collision with the floor
    if (ballPos.y - ball.velocity.y < floor){
        ball.velocity.y = std::abs(ball.velocity.y);
    }
}

#endif //CODE_PROJECT_HEADER1_HPP
