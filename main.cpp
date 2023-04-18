
#include "PingPongGame.hpp"


using namespace threepp;

int main() {
    MyListener listener;
    //Game game;

    Canvas canvas{Canvas::Parameters().size({1280,700}).antialiasing(8)};
    GLRenderer renderer(canvas);
    renderer.setClearColor(Color::black);
    renderer.enableTextRendering();

    auto scene = Scene::create();
    auto objects = Objects::create();
    auto group = objects->getObjects();
    scene->add(group);
    auto camera = PerspectiveCamera::create(60,canvas.getAspect(), 0.01,100);
    camera->position.z = 120;


    canvas.addKeyListener(&listener);


    canvas.onWindowResize([&](WindowSize size){
        camera->updateProjectionMatrix();
        renderer.setSize(size);
        });

    canvas.animate([&]{
        //game.update();
        renderer.render(scene, camera);
    });
}