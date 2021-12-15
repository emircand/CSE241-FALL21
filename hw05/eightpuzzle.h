/**
 * This is the file eightpuzzle.h
 * This is the interface for the class EightPuzzle
 * 
 */

#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H

#include <iostream>
#include <vector>
#include "boardgame2d.h"
#include <cstdlib>
#include <ctime>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

namespace emircand
{
    class EightPuzzle : public BoardGame2D
    {
    private:
        vector < vector<int> > PuzzleBoard;
        string LastMove;
    public:
        void setPuzzleBoard(vector < vector<int> > puzzleBoard);
        vector < vector<int> > getPuzzleBoard() const;
        void setLastMove(string direction);
        string getLastMove() const;

        void playUser(string move); //this function takes move string as a parameter and play game according to this parameter for one step.
        void playAuto(); //this function create random with the help of RandomDirection() function.
        void print() const; //this function print the elements of PuzzleBoard top left corner of the terminal. But it prints “_” character instead of integer “0”.
        bool endGame() const; //check the game over condition
        bool stringValidity(string move) const; //if move is left/right/up/down (there is no case sensitivity) this function return true. Else return false.
        bool isMoveValid(string direction) const; //this function checks the possibility of move according to the direction string for integer “0”. If it is possible return true; else return false.
        int boardScore() const; //This function returns the number of correctly positioned elements according to game over situation.
        void initialize();

        string RandomDirection(); //this function returns random direction in every separate call. (left/right/up/down)
        
        
        EightPuzzle(/* args */);
        ~EightPuzzle();
    };
    
    EightPuzzle::EightPuzzle(/* args */)
    {
    }
    
    
    EightPuzzle::~EightPuzzle()
    {
    }
    
}
#endif //EIGHTPUZZLE_H