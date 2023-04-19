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
private:
    std::shared_ptr<Group> group_;

};
class Ball {
    public:
        std::shared_ptr<Group> Ball;
        void create(){
            auto ballGeometry = SphereGeometry::create(ballRadius_, 32,32 );
            auto material = MeshBasicMaterial::create();
            material->color = Color::white;
            mesh_ = Mesh::create(ballGeometry,material);
            mesh_->position.set(0,0,0);
            group_->add(mesh_);
        }
        void update(){
            position_ += velocity;
            mesh_->position.set(position_.x,position_.y,position_.z);
        }

        std::shared_ptr<Mesh> getMesh() const {return mesh_;}
        float ballRadius_ = 0.5;
        Vector3 velocity = Vector3(1.5f,0.7f,0);
    private:
        std::shared_ptr<Group> group_;
        std::shared_ptr<Mesh> mesh_;
        Vector3 position_;
};

class Paddle {
public:
    void create(){
        auto geometry = BoxGeometry::create(0.2,10,0.2);
        auto material = MeshBasicMaterial::create();
        material->color = Color::white;
        mesh_ = Mesh::create(geometry,material);
        group_->add(mesh_);
    }
    void setPosition(Vector3 &position){
        mesh_->position.copy(position);
    }

    void movePaddle(Vector3 &position){
        mesh_->position.copy(position);
    }

    std::shared_ptr<Mesh> getMesh() const {
        return mesh_;
    }

private:
    std::shared_ptr<Group> group_;
    std::shared_ptr<Mesh> mesh_;
};








#endif //THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
