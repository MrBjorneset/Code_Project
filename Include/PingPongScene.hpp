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
    static std::shared_ptr<PingPongScene> create(){
        return std::make_shared<PingPongScene>();
    }
    int update();
private:
    Vector3 velocity = Vector3(0.01,0.01,0);
    std::shared_ptr<Group> group_;

};
PingPongScene::PingPongScene() : group_(Group::create()) {
    auto material = MeshBasicMaterial::create();
    material->color = Color::white;

    //Creating the 3D-Object Ball
    auto ballGeometry = SphereGeometry::create(0.1,32,32);
    auto ball = Mesh::create(ballGeometry,material);
    ball->position.set(0,0,0);
    ball->name = "ball";
    group_->add(ball);

    //Creating the 3D-Objects paddles
    auto paddleGeometry = BoxGeometry::create(0.1,1,0.1);
    auto paddleOne = Mesh::create(paddleGeometry,material);
    paddleOne->position.x = -2.5;
    paddleOne->name = "paddleOne";
    group_->add(paddleOne);
    auto paddleTwo = Mesh::create(paddleGeometry,material);
    paddleTwo->position.x = 2.5;
    paddleTwo->name = "paddleTwo";
    group_->add(paddleTwo);




}

#endif //THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
