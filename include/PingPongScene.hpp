//
// Created by EmilB on 22/02/2023.
//


#ifndef THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
#define THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
#include "threepp/threepp.hpp"


using namespace threepp;
/*
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
private:
    std::shared_ptr<Group> group_;

};
*/
class Ball {
public:
    Ball(float radius, float x, float y, float z){
        auto geometry = SphereGeometry::create(radius, 32, 32);
        auto material = MeshBasicMaterial::create();
        material->color = Color::white;

        mesh_ = Mesh::create(geometry,material);
        mesh_->position.set(0,0,0);
        velocity.set(0.15,0.7,0);
    }

    void update(float dt){
        mesh_->position.add(velocity.multiplyScalar(dt));
    }

    void setPosition(float x, float y,float z){
        mesh_->position.set(x, y, z);
    }

    [[nodiscard]] std::shared_ptr<Mesh> getMesh() const {
        return mesh_;
    }
    Vector3 velocity;
private:
    std::shared_ptr<Mesh> mesh_;
};

class Paddle {
public:
    Paddle(float width, float height, float depth, float x, float y, float z){
    auto geometry = BoxGeometry::create(width,height,depth);
    auto material = MeshBasicMaterial::create();
    material->color = Color::white;

    mesh_ = Mesh::create(geometry,material);
    mesh_->position.set(x, y, z);
    }
    void setPosition(float x, float y, float z){
        mesh_->position.set(x, y, z);
    }
    void move(float deltaX, float deltaY, float deltaZ){
        mesh_->position.add({deltaX, deltaY, deltaZ});
    }
    [[nodiscard]] std::shared_ptr<Mesh> getMesh() const {
        return mesh_;
    }
private:
    std::shared_ptr<Mesh> mesh_;
};


/*
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

*/
#endif //THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
