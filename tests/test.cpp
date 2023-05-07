//
// Created by EmilB on 17/04/2023.
//
#define  CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "PingPongScene.hpp"


TEST_CASE("Ball updates position correctly", "[Ball]") {
    Ball ball(1.0f, 0.0f, 0.0f, 0.0f);
    float dt = 0.1f;
    ball.velocity.set(1.0f, 2.0f, 3.0f);
    ball.update(dt);
    REQUIRE(ball.getMesh()->position.x == Catch::Approx(0.1f));
    REQUIRE(ball.getMesh()->position.y == Catch::Approx(0.2f));
    REQUIRE(ball.getMesh()->position.z == Catch::Approx(0.3f));
}


TEST_CASE("Paddle Moves correctly", "[Paddle]"){
    Paddle paddle(1,20,1,0,0,0);
    paddle.move(20,30,10);
    REQUIRE(paddle.getMesh()->position.x == 20);
    REQUIRE(paddle.getMesh()->position.y == 30);
    REQUIRE(paddle.getMesh()->position.z == 10);
}
