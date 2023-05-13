
#include "PingPongGame.hpp"

using namespace threepp;

int main() {
    //Setting up the different classes from PingPongGame.hpp
    MyListener listener;
    Game game;

    Canvas canvas{Canvas::Parameters().size({1280, 700}).antialiasing(16)};
    GLRenderer renderer{canvas};
    renderer.setClearColor(Color::black);
    renderer.enableTextRendering();
    std::shared_ptr<Scene> scene = Scene::create();

    //Creating the Objects from PingPongScene.hpp and adding it to the scene
    auto paddleOne = Paddle(0.5, 15, 0.2, -60,0,0);
    auto paddleTwo = Paddle(0.5, 15, 0.2, 60, 0, 0);
    auto ball = Ball(0.8,0,0,0);
    scene->add(ball.getMesh());
    scene->add(paddleOne.getMesh());
    scene->add(paddleTwo.getMesh());

    //Creating the Camera and setting the position
    std::shared_ptr<PerspectiveCamera> camera = PerspectiveCamera::create();
    camera->position.z = 120;

    //Creating the scoreboard
    game.p1Score = 0;
    game.p2Score = 0;
    auto &scoreP1 = renderer.textHandle("");
    auto &scoreP2 = renderer.textHandle("");
    auto &score = renderer.textHandle("Score");
    auto &instructionSingle = renderer.textHandle("Press 1 for singlePlayer Mode");
    auto &instructionMulti = renderer.textHandle("Press 2 for multiPlayer Mode");
    auto &instructionReset = renderer.textHandle("Press R for reset");
    score.setPosition(canvas.getSize().width   * 1/2, 2);
    scoreP1.setPosition(canvas.getSize().width * 1/4, 2);
    scoreP2.setPosition(canvas.getSize().width * 3/4, 2);
    instructionSingle.setPosition(canvas.getSize().width * 1/4, 250);
    instructionMulti.setPosition(canvas.getSize().width * 1/4, 300);
    instructionReset.setPosition(canvas.getSize().width * 1/4, 350);

    canvas.addKeyListener(&listener);
    canvas.onWindowResize([&](WindowSize size) {
        camera->updateProjectionMatrix();
        renderer.setSize(size);
        //Updating the scoreboard position when resizing the canvas
        score.setPosition(canvas.getSize().width   * 1/2, 2);
        scoreP1.setPosition(canvas.getSize().width * 1/4, 2);
        scoreP2.setPosition(canvas.getSize().width * 3/4, 2);
        instructionSingle.setPosition(canvas.getSize().width * 1/4, 250);
        instructionMulti.setPosition(canvas.getSize().width * 1/4, 300);
        instructionReset.setPosition(canvas.getSize().width * 1/4, 350);
    });

    canvas.animate([&] {
        //Writing the score values
        scoreP1.setText(std::to_string(game.p1Score));
        scoreP2.setText(std::to_string(game.p2Score));
        if(listener.singlePlayer || listener.multiPlayer || listener.restart){
            instructionSingle.setText("");
            instructionMulti.setText("");
            instructionReset.setText("");
        }
        else{
            instructionSingle.setText("Press 1 for singlePlayer Mode");
            instructionMulti.setText("Press 2 for multiPlayer Mode");
            instructionReset.setText("Press R for Restart");
        }
        InitGame(ball, paddleOne, paddleTwo, listener, game);

        renderer.render(scene, camera);
    });
}
