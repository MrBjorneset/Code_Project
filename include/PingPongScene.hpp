

#ifndef THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
#define THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
#include "threepp/threepp.hpp"
#include <iostream>


using namespace threepp;

class Ball {
public:
    Ball(float radius, float x, float y, float z){
        auto geometry = SphereGeometry::create(radius, 32, 32);
        auto material = MeshBasicMaterial::create();
        material->color = Color::white;

        mesh_ = Mesh::create(geometry,material);
        mesh_->position.set(x, y, z);
        velocity.set(0.5,0.15,0);
    }

    void update(float dt){
        mesh_->position.add(velocity*(dt));
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



#endif //THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
