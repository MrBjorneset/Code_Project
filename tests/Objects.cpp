
#include <catch.hpp>
#include "PingPongObjects.hpp"


TEST_CASE("Ball updates position correctly", "[Ball update]") {
    Ball ball(1.0f, 0.0f, 0.0f, 0.0f);
    float dt = 0.1f;
    ball.velocity.set(1.0f, 2.0f, 3.0f);
    ball.update(dt);
    REQUIRE(ball.getMesh()->position.x == (0.1f));
    REQUIRE(ball.getMesh()->position.y == (0.2f));
    REQUIRE(ball.getMesh()->position.z == (0.3f));
}

TEST_CASE("Ball moves correctly", "[Ball move]"){
    Ball ball(1,0,0,0);
    ball.setPosition(10,20,30);
    REQUIRE(ball.getMesh()->position.x == 10);
    REQUIRE(ball.getMesh()->position.y == 20);
    REQUIRE(ball.getMesh()->position.z == 30);
}

TEST_CASE("Paddle moves correctly", "[Paddle move]"){
    Paddle paddle(1,20,1,0,0,0);
    paddle.move(50,60,70);
    REQUIRE(paddle.getMesh()->position.x == 50);
    REQUIRE(paddle.getMesh()->position.y == 60);
    REQUIRE(paddle.getMesh()->position.z == 70);
}

TEST_CASE("Paddle set position correctly", "[Paddle set]"){
    Paddle paddle(1,20,1,0,0,0);
    paddle.setPosition(10,20,30);
    REQUIRE(paddle.getMesh()->position.x == 10);
    REQUIRE(paddle.getMesh()->position.y == 20);
    REQUIRE(paddle.getMesh()->position.z == 30);
}

