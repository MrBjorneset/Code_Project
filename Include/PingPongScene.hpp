//
// Created by EmilB on 22/02/2023.
//

#ifndef THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
#define THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
#include "threepp/threepp.hpp"
#include <chrono>
#include <thread>

using namespace threepp;

class PingPongScene {
public:
    PingPongScene();
    std::shared_ptr<Group> getGroup();
    static std::shared_ptr<PingPongScene> create(){
        return std::make_shared<PingPongScene>();
    }
    int P1Score = 0;
    int P2Score = 0;
    Canvas canvas_;
    GLRenderer renderer_;
    std::shared_ptr<PerspectiveCamera> camera_;
    std::shared_ptr<Scene> scene_;
    std::shared_ptr<Group> group_;
private:
};
PingPongScene::PingPongScene() : group_(Group::create()), canvas_(Canvas::Parameters().size({1024,768}).antialiasing(8)), renderer_(canvas_) {
    renderer_.setClearColor(Color::black);
    renderer_.enableTextRendering();
    camera_ = PerspectiveCamera::create();
    scene_ = Scene::create();
    auto material = MeshBasicMaterial::create();
    material->color = Color::white;

    //Creating the 3D-Object Ball
    auto ballGeometry = SphereGeometry::create(0.1,32,32);
    auto ball = Mesh::create(ballGeometry,material);
    ball->position.set(0,0,0);
    ball->name = "ball";
    group_->add(ball);
    scene_->add(ball);

    //Creating the 3D-Objects paddles
    auto paddleGeometry = BoxGeometry::create(0.1,100,0.1);
    auto paddleOne = Mesh::create(paddleGeometry,material);
    paddleOne->position.set(canvas_.getSize().width - 10,0,0);
    paddleOne->name = "paddleOne";
    group_->add(paddleOne);
    scene_->add(paddleOne);
    auto paddleTwo = Mesh::create(paddleGeometry,material);
    paddleTwo->position.set(2.5,0,0);
    paddleTwo->name = "paddleTwo";
    group_->add(paddleTwo);
    scene_->add(paddleTwo);

    //Creating the ScoreBoard
    auto &ScoreBoard = renderer_.textHandle("Score");
    ScoreBoard.setPosition(canvas_.getSize().width * 1 / 2, canvas_.getSize().height * (-1/2) );
    std::string P1score = std::to_string(P1Score);
    auto &PlayerOne = renderer_.textHandle(P1score);
    PlayerOne.setPosition(paddleOne->position.x, canvas_.getSize().height * (-1/2) );
    std::string P2score = std::to_string(P2Score);
    auto &PlayerTwo = renderer_.textHandle(P2score);
    PlayerTwo.setPosition(paddleTwo->position.x, canvas_.getSize().height * (-1/2) );

}
std::shared_ptr<Group> PingPongScene::getGroup(){
    return group_;
}


#endif //THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
