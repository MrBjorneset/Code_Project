
#include "threepp/threepp.hpp"
#include "Include/PingPongScene.hpp"

using namespace threepp;

int main() {

    Canvas canvas(Canvas::Parameters().size({1280,720}).antialiasing(8));
    GLRenderer renderer(canvas);
    renderer.setClearColor(Color::black);
    renderer.enableTextRendering();

    //Create the Camera, Scene and the group of objects
    auto camera = PerspectiveCamera::create();
    camera->position.z = 5;
    auto scene = Scene::create();
    auto group = Group::create();
    scene->add(group);
    {
        //Created the ball and set start position of x.0 and y.0
        auto ballGeometry_ = SphereGeometry::create(0.1);
        auto material = MeshBasicMaterial::create();
        material->color = Color::white;
        auto ball = Mesh::create(ballGeometry_,material);
        ball->position.x = 0;
        ball->position.y = 0;
        group->add(ball);

        //Create the two paddles
        auto paddleMaterial_ = MeshBasicMaterial::create();
        auto paddleGeometry_ = BoxGeometry::create(0.1,1,0.1);
        auto paddleOne = Mesh::create(paddleGeometry_,material);
        paddleOne->position.x = -2.5;
        group->add(paddleOne);
        auto paddleTwo = Mesh::create(paddleGeometry_,material);
        paddleTwo->position.x = 2.5;
        group->add(paddleTwo);
    }

//Creating the Scoreboard
    auto score = "Score";
    auto &Scoreboard = renderer.textHandle(score);
    Scoreboard.color = Color::green;
    Scoreboard.scale = 2;

//Player one Score
    int P1Score = 0;
    auto P1Score_ = std::to_string(P1Score);
    auto &PlayerOne = renderer.textHandle(P1Score_);
    PlayerOne.color = Color::green;
    PlayerOne.scale = 2;

//Player Two Score
    int P2Score = 0;
    auto P2Score_ = std::to_string(P2Score);
    auto &PlayerTwo = renderer.textHandle(P2Score_);
    PlayerTwo.color = Color::green;
    PlayerTwo.scale = 2;

    // Set the initial velocity of the ball
    auto velocity = new Vector3(0.05, 0.05, 0);
    // Get the ball Mesh from the group
    auto ballMesh = group->children[0]->children[0];


    canvas.onWindowResize([&](WindowSize size) -> void {
        renderer.setSize(size);
    });


    canvas.animate([&] {
        //render the scene
        ballMesh.position.x += velocity.x;
        ballMesh.position.y += velocity.y;

        Scoreboard.setPosition(canvas.getSize().width * 1 / 2, canvas.getSize().height * (-1 / 2));
        PlayerOne.setPosition(canvas.getSize().width * 1 / 4, canvas.getSize().height * (-1 / 2));
        PlayerTwo.setPosition(canvas.getSize().width * 3 / 4, canvas.getSize().height * (-1 / 2));
        std::chrono::milliseconds (16); // 60 fps
        renderer.render(scene, camera);

    });

}