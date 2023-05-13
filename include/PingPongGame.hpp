

#ifndef CODE_PROJECT_PingPongGame_HPP
#define CODE_PROJECT_PingPongGame_HPP
#include "PingPongObjects.hpp"

using namespace threepp;
class MyListener : public KeyListener{
public:
    bool p1DirectionUp = false;
    bool p1DirectionDown = false;
    bool p2DirectionUp = false;
    bool p2DirectionDown = false;
    bool singlePlayer = false;
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
            singlePlayer = true;
            multiPlayer = false;
        }
        if (evt.key == 50 ){       //"2" key
            multiPlayer = true;
            singlePlayer = false;
        }
        if (evt.key == 82){        //"r" key
            restart = true;
            singlePlayer = false;
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
    void singlePlayerMovement(bool up, bool down){
        //Move paddleOne based on user input, "w" and "s" keys
        if (up){
            p1PaddleSpeedY = 0.6f;
        }
        else if (down){
            p1PaddleSpeedY = -0.6f;
        }
        else {
            p1PaddleSpeedY = 0;
        }
    };
    void multiPlayerMovement(bool up, bool down){
        //Move paddleTwo based on user input, arrow up and down keys
        if (up){
            p2PaddleSpeedY = 0.6f;
        }
        else if (down){
            p2PaddleSpeedY = -0.6f;
        }
        else {
            p2PaddleSpeedY = 0;
        }
    };
    void checkWallCollision(Ball& ball, float left, float right, float roof, float floor){
    auto ballPos = ball.getMesh()->position;

    //Check collision with the left walls
    if (ballPos.x < left){
        p2Score +=1;
        ball.setPosition(0,0,0);
        ball.velocity.set(0.5,0.15,0);
    }

    //Check collision with the right wall
    if (ballPos.x  > right) {
        p1Score +=1;
        ball.setPosition(0,0,0);
        ball.velocity.set(-0.5, 0.15,0);
    }

    //check collision with the roof
    if (ballPos.y > roof){
        ball.velocity.y = ball.velocity.y *(-1);
    }

    //check collision with the floor
    if (ballPos.y < floor){
        ball.velocity.y = ball.velocity.y * (-1);
    }
    };
    void checkPaddleCollision(Ball& ball, Paddle& paddleOne, Paddle& paddleTwo, float paddleHeight, float ballRadius){
    auto ballPos = ball.getMesh()->position;
    auto paddleOnePos = paddleOne.getMesh()->position;
    auto paddleTwoPos = paddleTwo.getMesh()->position;

    if (ballPos.x - ballRadius < paddleOnePos.x &&
        ballPos.x + ballRadius > paddleOnePos.x &&
        ballPos.y - ballRadius < paddleOnePos.y + paddleHeight / 2 &&
        ballPos.y + ballRadius > paddleOnePos.y - paddleHeight / 2 ) {
        ball.velocity.x = ball.velocity.x* (-1.03f);
    }

    else if (ballPos.x - ballRadius < paddleTwoPos.x &&
        ballPos.x + ballRadius > paddleTwoPos.x &&
        ballPos.y - ballRadius < paddleTwoPos.y + paddleHeight / 2 &&
        ballPos.y + ballRadius > paddleTwoPos.y - paddleHeight / 2 ) {
        ball.velocity.x = ball.velocity.x * (-1.03f);
    }
    };
    void trackBall(Ball &ball, Paddle &paddleTwo){
    auto ballPos = ball.getMesh()->position;
    auto paddlePos = paddleTwo.getMesh()->position;
    p2PaddleSpeedY = 0;
    //Move paddleTwo based on ball direction
    if ((ballPos.y > paddlePos.y) && (ballPos.x > -10)){
        p2PaddleSpeedY += 0.5f;
        }
    else if((ballPos.y < paddlePos.y) && (ballPos.x > -10)){
        p2PaddleSpeedY -= 0.5f;
        }
    };

    float p1PaddleSpeedY{};
    float p2PaddleSpeedY{};
    int p1Score{};
    int p2Score{};
private:
};

class InitGame {
public:
    InitGame(Ball &ball, Paddle & paddleOne, Paddle &paddleTwo, MyListener &listener, Game &game){
        if(listener.singlePlayer && !listener.multiPlayer){
            ball.update(1);
            game.checkWallCollision(ball,-70,70,70,-70);
            game.checkPaddleCollision(ball,paddleOne,paddleTwo,15,0.8);
            game.singlePlayerMovement(listener.p1DirectionUp,listener.p1DirectionDown);
            game.trackBall(ball,paddleTwo);
            paddleOne.move(0,game.p1PaddleSpeedY,0);
            paddleTwo.move(0,game.p2PaddleSpeedY,0);
        }
        if(listener.multiPlayer && !listener.singlePlayer){
            ball.update(1);
            game.checkWallCollision(ball,-70,70,70,-70);
            game.checkPaddleCollision(ball,paddleOne,paddleTwo,15,0.8);
            game.singlePlayerMovement(listener.p1DirectionUp,listener.p1DirectionDown);
            game.multiPlayerMovement(listener.p2DirectionUp,listener.p2DirectionDown);
            paddleOne.move(0,game.p1PaddleSpeedY,0);
            paddleTwo.move(0,game.p2PaddleSpeedY,0);
        }
        if(listener.restart){
            ball.setPosition(0,0,0);
            paddleOne.setPosition(-60,0,0);
            paddleTwo.setPosition(60,0,0);
            game.p1Score = 0;
            game.p2Score = 0;
        }
    } ;
private:

};

#endif //CODE_PROJECT_PingPongGame_HPP
