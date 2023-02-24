
#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include "Include\PingPongScene.hpp"

using namespace threepp;

int main() {

    PingPongGame game(30);

    Canvas canvas;
    GLRenderer renderer(canvas);

    auto scene = std::make_shared<PingPongScene>(game);
    canvas.addKeyListener(scene.get());

    canvas.onWindowResize([&](WindowSize size) {
        scene->camera().updateProjectionMatrix();
        renderer.setSize(size);
    });

    canvas.animate([&](float dt) {
        if (game.isRunning()) {

            game.update(dt);
            scene->update();

        }
        renderer.render(scene.get(), &scene->camera());
    });

}
