
#include "Include/PingPongGame.hpp"


using namespace threepp;

int main() {


    Canvas canvas(Canvas::Parameters().title("Score"));
    GLRenderer renderer(canvas);
    Scene scene;
    Camera camera;

    canvas.addKeyListener(scene.get());

    canvas.onWindowResize([&](WindowSize size){
        scene.camera().updateProjectionMatrix;
        renderer.setSize(size);
    });
    renderer.enableTextRendering();
    auto& handle = renderer.textHandle("Press \"r\" to reset");

    canvas.animate([&](float dt ){
        if (game.isRunning()){

            game.update(dt);
            scene.update();
        }
        renderer.render(scene.get(), &scene.camera());
    });
}