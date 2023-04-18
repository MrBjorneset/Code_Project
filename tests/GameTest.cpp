//
// Created by EmilB on 17/04/2023.
//

#define  CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "PingPongGame.hpp"

TEST_CASE("GameTest") {
    SECTION("SingelPlayerMovement") {
        Game game;
        movement movement_;
        game.listener.p1DirectionUp = true;
        REQUIRE(movement_.p1PaddleSpeed.y == 0.05f);
    }
    SECTION("MultiPlayerMovement"){
        Game game;
        movement movement_;
        game.listener.p1DirectionUp = true;
        game.listener.p2DirectionUp = true;
        game.multiPlayerMovement();
        REQUIRE(movement_.p1PaddleSpeed.y == 0.05f);
        REQUIRE(movement_.p2PaddleSpeed.y == 0.05f);
    }
    SECTION("CheckScore"){
        Game game;
        REQUIRE(game.P1Score_ == 0);
        REQUIRE(game.P2Score_ == 0);
    }
}