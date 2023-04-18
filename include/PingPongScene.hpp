//
// Created by EmilB on 22/02/2023.
//

#ifndef THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
#define THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
#include "threepp/threepp.hpp"


using namespace threepp;

class Objects {
public:
    Objects();
    std::shared_ptr<Group> getGroup();
    static std::shared_ptr<Objects> create(){
        return std::make_shared<Objects>();
    }
    std::shared_ptr<Mesh> createBall() const;
    std::shared_ptr<Mesh> createPaddleOne() const;
    std::shared_ptr<Mesh> createPaddleTwo() const;
    float ballRadius_ = 0.5;
    float paddleWidth_ = 0.1;
    float paddleDepth_= 0.1;
    float paddleHeight_ = 10;
private:
    std::shared_ptr<Group> group_;
};


std::shared_ptr<Mesh> Objects::createBall() const {
    auto material = MeshBasicMaterial::create();
    material->color = Color::white;
    auto ballGeometry = SphereGeometry::create(ballRadius_,32,32);
    auto ball = Mesh::create(ballGeometry,material);
    ball->name = ("ball");
    ball->position = Vector3(0,0,0);
    group_->add(ball);
    return ball;
}

std::shared_ptr<Mesh> Objects::createPaddleOne() const {
    auto material = MeshBasicMaterial::create();
    material->color = Color::white;
    auto paddleGeometry = BoxGeometry::create(paddleWidth_,paddleHeight_,paddleDepth_);
    auto paddleOne = Mesh::create(paddleGeometry, material);
    paddleOne->name = ("paddleOne");
    paddleOne->position.x = -60;
    group_->add(paddleOne);
    return paddleOne;
}

std::shared_ptr<Mesh> Objects::createPaddleTwo() const {
    auto material = MeshBasicMaterial::create();
    material->color = Color::white;
    auto paddleGeometry = BoxGeometry::create(paddleWidth_,paddleHeight_,paddleDepth_);
    auto paddleTwo = Mesh::create(paddleGeometry, material);
    paddleTwo->name = ("paddleTwo");
    paddleTwo->position.x = 60;
    group_->add(paddleTwo);
    return paddleTwo;
}

Objects::Objects() : group_(Group::create())  {
    Objects::createBall();
    Objects::createPaddleOne();
    Objects::createPaddleTwo();
}

std::shared_ptr<Group> Objects::getGroup() {
    std::cout << group_->getObjectByName("ball")<< std::endl;
    std::cout << group_->getObjectByName("paddleOne") << std::endl;
    std::cout << group_->getObjectByName("paddleTwo") << std::endl;

    std::cout << group_ << std::endl;
    return group_;
}


#endif //THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
