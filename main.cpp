
#include "include/PingPongGame.hpp"


using namespace threepp;

int main() {
    Canvas canvas;
    GLRenderer renderer(canvas);
    renderer.setClearColor(Color::black);
    renderer.enableTextRendering();
    std::shared_ptr<PerspectiveCamera> camera;
    camera = PerspectiveCamera::create();
    camera->position.z = 120;


    Game game;
    game.init();
}