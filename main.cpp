
#include "Include/PingPongGame.hpp"


using namespace threepp;

int main() {
    Game game;
    while(true){
        game.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); //update at 60fps
    }

    return 0;
}