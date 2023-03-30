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
    Canvas canvas_;
    GLRenderer renderer_;
    std::shared_ptr<PerspectiveCamera> camera_;
    std::shared_ptr<Scene> scene_;
    float ballRadius_ = 0.5;
    float paddleWidth_ = 0.1;
    float paddleDepth_= 0.1;
    float paddleHeight_ = 10;

private:
    std::shared_ptr<Group> group_;

};
PingPongScene::PingPongScene() :  canvas_(Canvas::Parameters().size({1820,1000}).antialiasing(8)), renderer_(canvas_), group_(Group::create())
{
    renderer_.setClearColor(Color::black);
    renderer_.enableTextRendering();
    camera_ = PerspectiveCamera::create();
    camera_->position.z = 120;
    scene_ = Scene::create();
    auto material = MeshBasicMaterial::create();
    material->color = Color::white;
    //Creating the 3D-Object Ball
    auto ballGeometry = SphereGeometry::create(ballRadius_,32,32);
    auto ball = Mesh::create(ballGeometry,material);
    ball->name = ("ball");
    group_->add(ball);

    //Creating the 3D-Objects paddles
    auto paddleGeometry = BoxGeometry::create(paddleWidth_,paddleHeight_,paddleDepth_);
    auto paddleOne = Mesh::create(paddleGeometry,material);
    paddleOne->name = ("paddleOne");
    paddleOne->position.x = -60;
    group_->add(paddleOne);

    auto paddleTwo = Mesh::create(paddleGeometry,material);
    paddleTwo->name = ("paddleTwo");
    paddleTwo->position.x = 60;
    group_->add(paddleTwo);

    scene_->add(group_);
    //Creating the ScoreBoard
    auto &ScoreBoard = renderer_.textHandle("Score");
    ScoreBoard.setPosition(canvas_.getSize().width * 1 / 2, canvas_.getSize().height * (-1/2) );

}
std::shared_ptr<Group> PingPongScene::getGroup(){
    return group_;
}


#endif //THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
