/*  This is the header file boardgame2d.h
*   This is interface for the class BoardGame2D
*   This is primarily intended to be used as a base class
*   to derive classes for different kinds of board games
*/
#ifndef BOARDGAME2D_H
#define BOARDGAME2D_H

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;



namespace emircand
{
    class BoardGame2D
    {
    public:
        virtual void playUser(string move) = 0; //playUser takes a string as a parameter and plays the game accordingly. The parameter depends on the game, for the game of Peg Solitaire the string could be “2B UP”
        virtual void playUser() final; //Another overload of playUser is a final function. It does not take any parameters, it takes a string from the user for the next move in a loop and plays the game until it is over. It also prints the board between the moves.
        virtual void playAuto() = 0; //playAuto plays the game by the computer for one move
        virtual void playAutoAll() final; //playAutoAll is a final function. It plays the game until it is over. This one calls playAuto for all the moves. It also prints the board between the moves after some pause.
        virtual bool endGame() const = 0; //endGame returns true if the game is ended.
        virtual bool stringValidity(string move) const = 0;
        virtual int boardScore() const = 0; //boardScore returns an int score value for the current board. It returns a positive integer that indicates the goodness of the current board.
        virtual void initialize() = 0; //initialize initializes the board. For some games the initial board is the same, for other games the initial board is random.
        virtual void print() const = 0; //prints the game on the screen starting from the top left corner of the terminal.

        BoardGame2D();
        ~BoardGame2D();
    };
    
    BoardGame2D::BoardGame2D()
    {
    }
    
    BoardGame2D::~BoardGame2D()
    {
    } 
}


#endif //BOARDGAME2D_H 