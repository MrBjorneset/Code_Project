//
// Created by EmilB on 17/04/2023.
//

#define  CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "PingPongGame.hpp"

TEST_CASE("ObjectTest") {
    SECTION("CreateBall") {
        auto ball = Ball(0.8,0,0,0);
        ball.setPosition(0,0,0);
        REQUIRE(ball.getMesh()->position.x == 0);
    }

}
