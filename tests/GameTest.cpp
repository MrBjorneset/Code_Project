//
// Created by EmilB on 17/04/2023.
//

#define  CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "PingPongScene.hpp"
#include "PingPongGame.hpp"

TEST_CASE("GameTest") {
    SECTION("SingelPlayerMovement") {
        Game game;
        game.PingPongScene_->scene_->add(PingPongScene().getGroup());

        game.listener.p1DirectionUp = true;
        game.singelPlayerMovement();
        auto paddleOne = game.PingPongScene_->getGroup()->getObjectByName("paddleOne");
        CHECK_NOFAIL(paddleOne->position.y + 1);
    }
    SECTION("MultiPlayerMovement"){
        Game game;
        game.PingPongScene_->scene_->add(PingPongScene().getGroup());
        game.listener.p1DirectionUp = true;
        game.listener.p2DirectionUp = true;
        game.multiPlayerMovement();

        auto paddleOne = game.PingPongScene_->getGroup()->getObjectByName("paddleOne");
        auto paddleTwo = game.PingPongScene_->getGroup()->getObjectByName("paddleTwo");
        CHECK_NOFAIL(paddleOne->position.y + 1);
        CHECK_NOFAIL(paddleTwo->position.y + 1);
    }
    SECTION("CheckScore"){
        Game game;
        REQUIRE(game.P1Score_ == 0);
        REQUIRE(game.P2Score_ == 0);
    }
}