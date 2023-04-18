
#include "PingPongGame.hpp"


using namespace threepp;

int main() {
    //Setting up the different classes from both headers
    MyListener listener;
    Game game;
    Objects Objects;

    Canvas canvas{Canvas::Parameters().size({1280,700}).antialiasing(8)};
    GLRenderer renderer(canvas);
    renderer.setClearColor(Color::black);
    renderer.enableTextRendering();

    auto scene = Scene::create();

    //Grabbing Objects from PingPongScene.hpp, creating a lokal group and adding it to the scene
    auto objects = Objects::create();
    auto group = objects->getGroup();
    scene->add(group);

    //Creating the Camera and setting the position
    auto camera = PerspectiveCamera::create();
    camera->position.z = 120;


    canvas.addKeyListener(&listener);
    canvas.onWindowResize([&](WindowSize size){
        camera->updateProjectionMatrix();
        renderer.setSize(size);
        });

    canvas.animate([&]{
        game.init();
        renderer.render(scene, camera);
    });
}