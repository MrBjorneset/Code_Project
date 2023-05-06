//
// Created by EmilB on 17/04/2023.
//
#define  CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "PingPongScene.hpp"
#include "threepp/threepp.hpp"
using namespace threepp;

TEST_CASE("Ball updates position correctly", "[Ball]") {
    Ball ball(1.0f, 0.0f, 0.0f, 0.0f);
    float dt = 1;
    ball.velocity.set(1.0f, 2.0f, 3.0f);
    ball.update(dt);
    REQUIRE(ball.getMesh()->position.x == 1.0f);
    REQUIRE(ball.getMesh()->position.y == 2.0f);
    REQUIRE(ball.getMesh()->position.z == 3.0f);
}
