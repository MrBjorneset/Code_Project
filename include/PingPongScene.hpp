//
// Created by EmilB on 22/02/2023.
//

#ifndef THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
#define THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
#include "threepp/threepp.hpp"


using namespace threepp;

class Objects {
public:
    std::shared_ptr<Group> getObjects();
    static std::shared_ptr<Objects> create(){
        return std::make_shared<Objects>();
    }
    std::shared_ptr<MeshBasicMaterial> createMaterial();
    std::shared_ptr<Mesh> createBall();
    std::shared_ptr<Mesh> createPaddleOne();
    std::shared_ptr<Mesh> createPaddleTwo();
    float ballRadius_ = 0.5;
    float paddleWidth_ = 0.1;
    float paddleDepth_= 0.1;
    float paddleHeight_ = 10;
private:
    std::shared_ptr<Group> group_;
};

std::shared_ptr<Group> Objects::getObjects() {
    group_->add(Objects::createBall());
    group_->add(Objects::createPaddleOne());
    group_->add(Objects::createPaddleTwo());
    return group_;
}

std::shared_ptr<MeshBasicMaterial> Objects::createMaterial() {
    auto material = MeshBasicMaterial::create();
    material->color = Color::white;
    return material;
}

std::shared_ptr<Mesh> Objects::createBall() {
    auto ballGeometry = SphereGeometry::create(ballRadius_,32,32);
    auto ball = Mesh::create(ballGeometry,Objects::createMaterial());
    ball->name = ("ball");
    return ball;
}

std::shared_ptr<Mesh> Objects::createPaddleOne() {
    auto paddleGeometry = BoxGeometry::create(paddleWidth_,paddleHeight_,paddleDepth_);
    auto paddleOne = Mesh::create(paddleGeometry, Objects::createMaterial());
    paddleOne->name = ("paddleOne");
    return paddleOne;
}

std::shared_ptr<Mesh> Objects::createPaddleTwo() {
    auto paddleGeometry = BoxGeometry::create(paddleWidth_,paddleHeight_,paddleDepth_);
    auto paddleTwo = Mesh::create(paddleGeometry, Objects::createMaterial());
    paddleTwo->name = ("paddleTwo");
    return paddleTwo;
}



#endif //THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
