
#include "include/PingPongGame.hpp"


using namespace threepp;

int main() {
    MyListener listener;
    Game game;

    Canvas canvas{Canvas::Parameters().size({1280,700}).antialiasing(8)};
    GLRenderer renderer{canvas};
    renderer.setClearColor(Color::black);
    renderer.enableTextRendering();

    auto scene = Scene::create();

    auto camera = PerspectiveCamera::create(60,canvas.getAspect(), 0.01,100);
    camera->position.set(0,0,120);


    canvas.addKeyListener(&listener);
    scene->add(PingPongScene().getGroup());


    canvas.onWindowResize([&](WindowSize size){
        camera->aspect = size.getAspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
        });

    canvas.animate([&]{
        renderer.render(scene, camera);
        game.update();
    });
}