//
// Created by EmilB on 17/04/2023.
//
#define  CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "PingPongScene.hpp"


TEST_CASE("Ball updates position correctly", "[Ball Update]") {
    Ball ball(1.0f, 0.0f, 0.0f, 0.0f);
    float dt = 0.1f;
    ball.velocity.set(1.0f, 2.0f, 3.0f);
    ball.update(dt);
    REQUIRE(ball.getMesh()->position.x == Catch::Approx(0.1f));
    REQUIRE(ball.getMesh()->position.y == Catch::Approx(0.2f));
    REQUIRE(ball.getMesh()->position.z == Catch::Approx(0.3f));
}


TEST_CASE("Paddle Moves correctly", "[Paddle Move]"){
    Paddle paddle(1,20,1,0,0,0);
    paddle.move(50,60,70);
    REQUIRE(paddle.getMesh()->position.x == 50);
    REQUIRE(paddle.getMesh()->position.y == 60);
    REQUIRE(paddle.getMesh()->position.z == 70);
}

TEST_CASE("Paddle SetPosition correctly", "[Paddle set]"){
    Paddle paddle(1,20,1,0,0,0);
    paddle.setPosition(10,20,30);
    REQUIRE(paddle.getMesh()->position.x == 10);
    REQUIRE(paddle.getMesh()->position.y == 20);
    REQUIRE(paddle.getMesh()->position.z == 30);
}

