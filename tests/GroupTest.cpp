//
// Created by EmilB on 17/04/2023.
//
#define  CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "PingPongScene.hpp"


TEST_CASE("Test PingPongScene"){
    SECTION("Test group") {
        Objects objects;
        auto group = objects.getGroup();
        REQUIRE(group->children.size() == 3);
        REQUIRE(group->getObjectByName("ball") != nullptr);
        REQUIRE(group->getObjectByName("paddleOne") != nullptr);
        REQUIRE(group->getObjectByName("paddleTwo") != nullptr);
    }
}
