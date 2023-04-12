# PING PONG GAME
This is a simple implementation of the classic PingPong Game using the THREEPP library

## How to Play
The game can be chosen to be either as a singel player game or a multiplayer game.

In the singelplayer mode the player controls the paddle on the left of the screen and moves the paddle using 
the "W" and "S" keys, and a function controls the other paddle. 

In the multiplayer mode you have one player for each paddle. Where one player controls the left paddle using
the "W" and "S" keys, and another player controls the right side paddle using ↑ and ↓ arrow keys.

The goal of the game is to score points by getting past the other paddle 


## FILES
In this project we use two header files PingPongScene.hpp, PingPongGame.hpp and one 
main.cpp. 

In the PingPongScene.hpp we create the canvas ande set the desired parameters, and we also 
create all the 3D-objects in this header. We also have one function to return the 3D-Objects
that way we can access these 3D-objects in PingPongGame.hpp

In the PingPongGame.hpp we create an update function to check for collision between the ball,
paddles and the walls of the canvas, and we check for user inputs to control paddle One. 
We also have one function called Init to initialise the program. In the init function we 
Use the function in PingPongScene.hpp to create the canvas and add the 3D-objects we also 
use the update function in PingPongGame.hpp to update the scene with game mechanics. 

In the main.cpp we call for the init function in PingPongGame.hpp, which runs the program.