
#include "PingPongGame.hpp"


using namespace threepp;

int main() {
    //Setting up the different classes from both headers
    MyListener listener;
    Game game;

    Canvas canvas{Canvas::Parameters().size({1280, 700}).antialiasing(8)};
    GLRenderer renderer{canvas};
    renderer.setClearColor(Color::black);
    renderer.enableTextRendering();

    //Creating the Objects from PingPongScene.hpp, making a local group and adding it to the scene
    auto scene = Scene::create();

    auto paddleOne = Paddle(0.5, 15, 0.2, -60,0,0);
    auto paddleTwo = Paddle(0.5, 15, 0.2, 60, 0, 0);
    auto ball = Ball(0.8,0,0,0);

    scene->add(ball.getMesh());
    scene->add(paddleOne.getMesh());
    scene->add(paddleTwo.getMesh());


    //Creating the Camera and setting the position
    auto camera = PerspectiveCamera::create();
    camera->position.z = 120;

    canvas.addKeyListener(&listener);
    canvas.onWindowResize([&](WindowSize size) {
        camera->updateProjectionMatrix();
        renderer.setSize(size);
    });


    canvas.animate([&] {
            if (listener.singelPlayer) {
                ball.update(1);
                game.singlePlayerMovement();
                paddleOne.move(game.p1PaddleSpeed.x,game.p1PaddleSpeed.y,game.p1PaddleSpeed.z);
                paddleTwo.move(game.p2PaddleSpeed.x,game.p2PaddleSpeed.y,game.p2PaddleSpeed.z);
                game.trackBall(ball.getMesh()->position,paddleTwo.getMesh()->position);
                std::cout << ball.getMesh()->position << std::endl;
            }
            else if (listener.multiPlayer){
                game.multiPlayerMovement();
                paddleOne.move(game.p1PaddleSpeed.x,game.p1PaddleSpeed.y,game.p1PaddleSpeed.z);
                paddleTwo.move(game.p2PaddleSpeed.x,game.p2PaddleSpeed.y,game.p2PaddleSpeed.z);

            }


        renderer.render(scene, camera);
    });
}
