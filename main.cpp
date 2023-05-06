
#include "PingPongGame.hpp"


using namespace threepp;


int main() {
    //Setting up the different classes from both headers
    MyListener listener;
    Game game;

    Canvas canvas{Canvas::Parameters().size({1280, 700}).antialiasing(16)};
    GLRenderer renderer{canvas};
    renderer.setClearColor(Color::black);
    renderer.enableTextRendering();
    auto scene = Scene::create();

    //Creating the Objects from PingPongScene.hpp and adding it to the scene
    auto paddleOne = Paddle(0.5, 15, 0.2, -60,0,0);
    auto paddleTwo = Paddle(0.5, 15, 0.2, 60, 0, 0);
    auto ball = Ball(0.8,0,0,0);
    scene->add(ball.getMesh());
    scene->add(paddleOne.getMesh());
    scene->add(paddleTwo.getMesh());

    //Creating the Camera and setting the position
    auto camera = PerspectiveCamera::create();
    camera->position.z = 120;

    //Creating the scoreboard
    game.p1Score = 0;
    game.p2Score = 0;
    auto &scoreP1 = renderer.textHandle("");
    auto &scoreP2 = renderer.textHandle("");
    auto &score = renderer.textHandle("Score");
    score.setPosition(canvas.getSize().width   * 1/2, 2);
    scoreP1.setPosition(canvas.getSize().width * 1/4, 2);
    scoreP2.setPosition(canvas.getSize().width * 3/4, 2);

    canvas.addKeyListener(&listener);
    canvas.onWindowResize([&](WindowSize size) {
        camera->updateProjectionMatrix();
        renderer.setSize(size);
        //Updating the scoreboard position when resizing the canvas
        score.setPosition(canvas.getSize().width   * 1/2, 2);
        scoreP1.setPosition(canvas.getSize().width * 1/4, 2);
        scoreP2.setPosition(canvas.getSize().width * 3/4, 2);

    });

    canvas.animate([&] {
        //Writing the score values
        scoreP1.setText(std::to_string(game.p1Score));
        scoreP2.setText(std::to_string(game.p2Score));

        //Activating the correct functions to play the game in single player mode
            if (listener.singelPlayer) {
                ball.update(1);
                game.checkWallCollision(ball,-70,70,70,-70);
                game.checkPaddleCollision(ball,paddleOne,paddleTwo,15,0.8);
                game.singlePlayerMovement(listener.p1DirectionUp,listener.p1DirectionDown);
                game.trackBall(ball,paddleTwo);
                paddleOne.move(0,game.p1PaddleSpeedY,0);
                paddleTwo.move(0,game.p2PaddleSpeedY,0);
            }

        //Activating the correct functions to play the game in multiplayer mode
            else if (listener.multiPlayer){
                ball.update(1);
                game.checkWallCollision(ball,-70,70,70,-70);
                game.checkPaddleCollision(ball,paddleOne,paddleTwo,15,0.8);
                game.singlePlayerMovement(listener.p1DirectionUp,listener.p1DirectionDown);
                game.multiPlayerMovement(listener.p2DirectionUp,listener.p2DirectionDown);
                paddleOne.move(0,game.p1PaddleSpeedY,0);
                paddleTwo.move(0,game.p2PaddleSpeedY,0);
            }

        //Resting the position and score of all objects
            else if (listener.restart){
                ball.setPosition(0,0,0);
                paddleOne.setPosition(-60,0,0);
                paddleTwo.setPosition(60,0,0);
                game.p1Score = 0;
                game.p2Score = 0;
            }

        renderer.render(scene, camera);
    });
}
