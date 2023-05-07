#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "PingPongGame.hpp"

TEST_CASE("Check paddle one movement", "[Movement]") {
    Game game;
    game.singlePlayerMovement(true, false);
    REQUIRE(game.p1PaddleSpeedY == 0.5f);
}