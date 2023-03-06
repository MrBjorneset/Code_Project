//
// Created by EmilB on 21/02/2023.
//

#ifndef CODE_PROJECT_PingPongGame_HPP
#define CODE_PROJECT_PingPongGame_HPP
#include "threepp/threepp.hpp"


using namespace threepp;
/*
 *
enum class Direction {
    UP,
    DOWN
};

class PingPongGame {

public:
    Direction direction;
    Direction nextDirection;

    explicit PingPongGame(int gridSize)
        :gridSize_(gridSize),
        PaddleOne_(gridSize -1, gridSize -1){

        reset();
    }


    void update(float dt) {
        if (t_ < moveInterval_) {
            t_ += dt;
            return;
        }
        Vector2 PaddleOne;
        switch (nextDirection) {
            case Direction::DOWN:
                PaddleOne.y -= 1;
                break;
            case Direction::UP:
                PaddleOne.y += 1;
                break;
        }
        PaddleOne += PaddleOne_.Position();

        Vector2 PaddleTwo;
        switch (nextDirection) {
                case Direction::DOWN:
                    PaddleTwo.y -= 1;
                    break;
                case Direction::UP:
                    PaddleTwo.y += 1;
                    break;
                }
        PaddleTwo += PaddleTwo_.Position();
        }


};

private:{

    float t_{};
    int gridSize_{};
    bool running_{};

    float moveInterval_{};
    Vector2 ballPos_;
    PaddleOne PaddleOne_;
    PaddleTwo PaddleTwo_;

    void spawnBall(){
        do {
            auto x = 0;
            auto y = 0;
            ballPos_.set(x, y);

        }
    };
*/
#endif //CODE_PROJECT_HEADER1_HPP
