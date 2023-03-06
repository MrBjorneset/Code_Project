
#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include "Include/PingPongScene.hpp"
#include "Include/PingPongGame.hpp"

using namespace threepp;

int main() {

 Canvas canvas;
 GLRenderer renderer(canvas);

 /*
 auto gridSize = canvas.getSize();
 auto& gridSize_ = gridSize;
  */

 renderer.setClearColor(Color::black);

 auto camera = PerspectiveCamera::create();
 camera->position.z = 5;

 OrbitControls controls{camera, canvas};

 auto scene = Scene::create();

 renderer.enableTextRendering();

 //Creating the Scoreboard
 auto& Scoreboard = renderer.textHandle("Score");
 Scoreboard.setPosition(280, canvas.getSize().height-480);
 Scoreboard.color = Color::green;
 Scoreboard.scale = 2;

 //Player one Score 100
 int P1Score = 0;
 auto P1Score_  = std::to_string(P1Score);
 auto& PlayerOne = renderer.textHandle(P1Score_);
 PlayerOne.setPosition(100, canvas.getSize().height-480);
 PlayerOne.color = Color::green;
 PlayerOne.scale = 2;

 //Player Two Score 460
    int P2Score = 0;
    auto P2Score_  = std::to_string(P2Score);
    auto& PlayerTwo = renderer.textHandle(P2Score_);
    PlayerTwo.setPosition(460, canvas.getSize().height-480);
    PlayerTwo.color = Color::green;
    PlayerTwo.scale = 2;


 canvas.onWindowResize([&](WindowSize size)->void{
     camera->aspect = size.getAspect();
     camera->updateProjectionMatrix();
     renderer.setSize(size);
     Scoreboard.setPosition(280, canvas.getSize().height-480);
 });

    canvas.animate([&] {

        renderer.render(scene, camera);


    });

}
