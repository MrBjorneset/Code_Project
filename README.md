# PING PONG GAME
This is a simple implementation of the classic PingPong Game using the THREEPP library. The game can 
be played in single or multiplayer mode.
![img.png](img.png)


## Dependencies
This C++ program requires the Threepp library to be installed. It also uses the standard C++ libraries 
and Catch2 for unit testing

## How to Play
The game can be played in single or multiplayer mode. 
In single player mode, the player controls one paddle and the computer controls the other paddle. 
In multiplayer mode, there are two human players, each controlling their own paddle.

 
### Controls

- Player one(Left Paddle):
: W: move the paddle up
: S: move the paddle down

- Player two(Right Paddle):
: Up Arrow Key: move the paddle up
: Down Arrow Key: move the paddle down

To switch between single player and multiplayer mode, press 1 for single player and 2 for multiplayer.

To restart the game at any time, press R


## FILES
In this project we use two header files PingPongScene.hpp, PingPongGame.hpp(these files can be located in the 
include folder) and one main.cpp. 

### PingPongScene.hpp
In the PingPongScene.hpp file, we create two classes one for the "Ball" and one for the "paddle".
In the Ball class we have different functions that we use in both main.cpp and PingPongGame.hpp.
We have one function to update the ball`s location, one function to alter the velocity of the ball, 
one function to set the position of the ball and one function to retrieve the ball object.
In the Paddle Class we have different functions that we use in both main.cpp and PingPongGame.hpp. 
We have one function to move the ball, one function to set the position of the paddle and one function to 
retrieve the paddle object.

### PingPongGame.hpp
In the PingPongGame.hpp file, we create a class game with lots of functions that controls the game logic.
We have functions that detect collision with the walls and paddles, functions to move the paddles, one 
function to track the ball movement for single player mode. We also have four global variables, two of these variables 
are for the score and the other two variables are to move the paddle on the Y-axis accordingly to inputs.

We also have a class for KeyListener that reads user inputs that controls the paddles and can restart the game.

### main.cpp



---
Disclaimer: This program is not necessarily completed and may have errors or omissions