//
// Created by EmilB on 22/02/2023.
//

#ifndef THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
#define THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP

#include "threepp/threepp.hpp"
#include "PingPongGame.hpp"

using namespace threepp;

class PingPongScene : public Scene, public KeyListener{

public:
    explicit PingPongScene(PingPongGame &game) : game_(game){


    }


private:
    PingPongGame &game_;
};



#endif //THREEPP_VCPKG_TEST_PINGPONGSCENE_HPP
