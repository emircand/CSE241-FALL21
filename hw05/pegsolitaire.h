/**
 *      This is the file pegsolitaire.h
 *      This is the interface for the class PegSolitaire
 */

#ifndef PEGSOLITAIRE_H
#define PEGSOLITAIRE_H

#include <iostream>
#include <vector>
#include "boardgame2d.h"
#include <cstdlib>
#include <ctime>

using std::string;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;



namespace emircand
{
    class PegSolitaire : public BoardGame2D
    {
    public:
        /*strongly typed enum which include peg solitaire game's elements */
        enum class peg{
            pin, empty, tab //tab means banned ares of gameboard
        };
        
        class Cell{
        public:
            void setPegType(peg pegType);
            peg getPegType() const;
        private:
            peg PegType;
        };
        
        void setPegBoard(vector< vector<Cell> > pegBoard);
        vector< vector<Cell> > getPegBoard() const;
       
       
        void playUser(string move); //this function take move string as a parameter and play game according to this parameter for one step.
        void playUser(int positionY, int positionX, string direction); //this function overload version of playUser(string move). Only difference of these functions is parameter types.
        void playAuto(); //this function create random move parameters with the help of rand() function.
        void print() const; //this function print the elements of PegBoard top left corner of the terminal.
        bool endGame() const; //If there is no more move on PegBoard or BoardScore function returns any number smaller than 2, it returns true; else it returns false.
        bool stringValidity(string move) const; //This function check the validity of string if string is not in the correct form (example: 3E RIGHT) it returns false. Else it returns true.
        bool isMoveValid(int positionY, int positionX, string direction) const; //this function takes parameters and check the possibility of entered moves. If move is possible it returns true; else it returns false.
        int boardScore() const; //this function returns the number of peg::pins of PegBoard.
        void initialize(); //this function initialize 2D vector of peg objects to 2D vector of Cell objects. After that set 2D vector of Cell as PegBoard.

        PegSolitaire(/* args */);
        ~PegSolitaire();
    private:
        vector< vector<Cell> > PegBoard; 
    };
    
    PegSolitaire::PegSolitaire(/* args */)
    {
    }
    
    PegSolitaire::~PegSolitaire()
    {
    }
}
#endif //PEGSOLITAIRE_H