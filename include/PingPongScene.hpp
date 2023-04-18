//
// Created by EmilB on 22/02/2023.
//

#ifndef THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
#define THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
#include "threepp/threepp.hpp"


using namespace threepp;

class PingPongScene {
public:
    PingPongScene();
    std::shared_ptr<Group> getGroup();
    static std::shared_ptr<PingPongScene> create(){
        return std::make_shared<PingPongScene>();
    }
    float ballRadius_ = 0.5;
    float paddleWidth_ = 0.1;
    float paddleDepth_= 0.1;
    float paddleHeight_ = 10;

private:
    std::shared_ptr<Group> group_;

};

class Objects {
public:
    std::shared_ptr<Mesh> createMaterial();
    std::shared_ptr<Mesh> createBall();
    std::shared_ptr<Mesh> createPaddleOne();
    std::shared_ptr<Mesh> createPaddleTwo();
private:
};




PingPongScene::PingPongScene()
{
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


}
std::shared_ptr<Group> PingPongScene::getGroup(){
    return group_;
}


#endif //THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
