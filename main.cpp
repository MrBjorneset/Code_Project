
#include "PingPongGame.hpp"


using namespace threepp;

int main() {
    //Setting up the different classes from both headers
    MyListener listener;
    Game game;
    Objects Objects;
    game.init();

    Canvas canvas{Canvas::Parameters().size({1280, 700}).antialiasing(8)};
    GLRenderer renderer{canvas};
    renderer.setClearColor(Color::black);
    renderer.enableTextRendering();

    //Creating the Objects from PingPongScene.hpp, making a local group and adding it to the scene
    auto objects = Objects::create();
    objects->createBall();
    objects->createPaddleOne();
    objects->createPaddleTwo();

    auto scene = Scene::create();
    scene->add(objects->getGroup());

    //Creating the Camera and setting the position
    auto camera = PerspectiveCamera::create();
    camera->position.z = 120;

    canvas.addKeyListener(&listener);
    canvas.onWindowResize([&](WindowSize size) {
        camera->updateProjectionMatrix();
        renderer.setSize(size);
    });


    canvas.animate([&] {
        if (listener.singelPlayer || listener.multiPlayer) {
            game.update(listener.singelPlayer, listener.multiPlayer);
        }
        renderer.render(scene, camera);
    });
}
