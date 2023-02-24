//
// Created by EmilB on 22/02/2023.
//

#ifndef THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
#define THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP

#include "threepp/threepp.hpp"
#include "PingPongGame.hpp"

using namespace threepp;


class PingPongScene : public Scene, public KeyListener {
public:
    explicit PingPongScene(PingPongGame &game) : game_(game){

        int size =game.gridSize();
        auto grid = GridHelper::create(size, size, 0x444444, 0x444444);
        grid-> rotation.x =math::PI / 2;
        grid->position.set(static_cast<float>(size) / 2, static_cast<float>(size) / 2, 0);
        add(grid);

        //Creating the object Paddle one
        PaddleOneGeometry_ = BoxGeometry::create();
        PaddleOneGeometry_->translate(0.5, 0.5, 0);

        auto PaddleOneMaterial = MeshBasicMaterial::create();
        PaddleOneMaterial->color = Color::white;

        PaddleOne_.emplace_back(Mesh::create(PaddleOneGeometry_, PaddleOneMaterial));
        add(PaddleOne_.back());

        //Creating the object Paddle Two
        PaddleTwoGeometry_ = BoxGeometry::create();
        PaddleTwoGeometry_->translate(0.5, 0.5, 0);

        auto PaddleTwoMaterial = MeshBasicMaterial::create();
        PaddleTwoMaterial->color = Color::white;

        PaddleTwo_.emplace_back(Mesh::create(PaddleTwoGeometry_, PaddleTwoMaterial));
        add(PaddleTwo_.back());

        //Setting up the Camera
        camera_ = OrthographicCamera::create(-size / 2, size / 2, -size / 2, size / 2);
        camera_->position.set(static_cast<float>(size) / 2, static_cast<float>(size) / 2, static_cast<float>(size));
        add(camera_);
    }

private:
    //Setting up different variables to use in the program
    PingPongGame &game_;
    std::shared_ptr<Mesh> ball_;
    std::shared_ptr<OrthographicCamera> camera_;

    std::shared_ptr<BoxGeometry> PaddleOneGeometry_;
    std::shared_ptr<MeshBasicMaterial> PaddleOneMaterial_;
    std::vector<std::shared_ptr<Mesh>> PaddleOne_;

    std::shared_ptr<BoxGeometry> PaddleTwoGeometry_;
    std::shared_ptr<MeshBasicMaterial> PaddleTwoMaterial_;
    std::vector<std::shared_ptr<Mesh>> PaddleTwo_;
};
#endif //THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
