#include <catch.hpp>
#include "PingPongGame.hpp"


TEST_CASE("PaddleOne Move Up","[P1 Up]"){
    Game game;
    game.singlePlayerMovement(true,false);
    REQUIRE(game.p1PaddleSpeedY == Catch::Approx(0.6F));
}

TEST_CASE("PaddleOne Move Down", "[P1 Down]"){
    Game game;
    game.singlePlayerMovement(false, true);
    REQUIRE(game.p1PaddleSpeedY == Catch::Approx(-0.6f));
}

TEST_CASE("PaddleTwo Move Up", "[P2 Up]"){
    Game game;
    game.multiPlayerMovement(true,false);
    REQUIRE(game.p2PaddleSpeedY == Catch::Approx(0.6f));
}
TEST_CASE("PaddleTwo Move Down", "[P2 Down]"){
    Game game;
    game.multiPlayerMovement(false, true);
    REQUIRE(game.p2PaddleSpeedY == Catch::Approx(-0.6f));
}