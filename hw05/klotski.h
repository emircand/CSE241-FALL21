/**
 * This is the file klotski.h
 * This is the interface for the class Klotski
 * 
 */


#ifndef KLOTSKI_H
#define KLOTSKI_H

#include "boardgame2d.h"
#include <vector>

using std::vector;


namespace emircand
{
    class Klotski : public BoardGame2D
    {
    public:
        void setKlotskiBoard(vector< vector<char> > currentBoard);
        vector< vector<char> > getKlotskiBoard() const;


        void playUser(string move); //this function take move string as a parameter and play game according to this parameter for one step.
        void playAuto(); //this function create random move parameters with the help of rand() function.
        void print() const; //this function prints the elements of KlotskiBoard top left corner of the terminal. But it prints ‘ ’ instead of ‘0’.
        bool endGame() const; //If huge square which is symbolized with char ‘B’ located at mid-bottom of KlotskiBoard it returns true; else, it returns false.
        bool stringValidity(string move) const; //This function checks the validity of string if string is not in the correct form (example: G RIGHT) it returns false. Else it returns true.
        bool isMoveValid(char choice, string direction) const; //this function takes parameters and check the possibility of entered moves. If move is possible it returns true; else, it returns false.
        int boardScore() const;
        void initialize(); //this function initializes 2D vector of <char> as a KlotskiBoard.

        void swapFunc(int momentY, int momentX, int newY, int newX); //this function swaps the elements of KlotskiBoard.
        Klotski(/* args */);
        ~Klotski();

    private:
        vector < vector<char> > KlotskiBoard;
    };
    
    Klotski::Klotski(/* args */)
    {
    }
    
    Klotski::~Klotski()
    {
    }
    
}
#endif //KLOTSKI_H