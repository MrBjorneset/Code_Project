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
    void createBall();
    void createPaddleOne();
    void createPaddleTwo();
    float ballRadius_ = 0.5;
    float paddleWidth_ = 0.1;
    float paddleDepth_= 0.1;
    float paddleHeight_ = 10;
    std::shared_ptr<Mesh> ball_;
    std::shared_ptr<Mesh> paddleOne_;
    std::shared_ptr<Mesh> paddleTwo_;
private:
    std::shared_ptr<Group> group_;

};


void Objects::createBall() {
    auto material = MeshBasicMaterial::create();
    material->color = Color::white;
    auto ballGeometry = SphereGeometry::create(ballRadius_,32,32);
    ball_ = Mesh::create(ballGeometry,material);
    ball_->name = ("ball");
    ball_->position.set(0,0,0);
    group_->add(ball_);

}

void Objects::createPaddleOne(){
    auto material = MeshBasicMaterial::create();
    material->color = Color::white;
    auto paddleGeometry = BoxGeometry::create(paddleWidth_,paddleHeight_,paddleDepth_);
    paddleOne_ = Mesh::create(paddleGeometry, material);
    paddleOne_->name = ("paddleOne");
    paddleOne_->position.x = -60;
    group_->add(paddleOne_);
}

void Objects::createPaddleTwo() {
    auto material = MeshBasicMaterial::create();
    material->color = Color::white;
    auto paddleGeometry = BoxGeometry::create(paddleWidth_,paddleHeight_,paddleDepth_);
    paddleTwo_ = Mesh::create(paddleGeometry, material);
    paddleTwo_->name = ("paddleTwo");
    paddleTwo_->position.x = 60;
    group_->add(paddleTwo_);
}

Objects::Objects() : group_(Group::create())  {
}

std::shared_ptr<Group> Objects::getGroup() {
    std::cout << group_->getObjectByName("ball")<< std::endl;
    std::cout << group_->getObjectByName("paddleOne") << std::endl;
    std::cout << group_->getObjectByName("paddleTwo") << std::endl;
    std::cout << group_ << std::endl;
    return group_;
}


#endif //THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
