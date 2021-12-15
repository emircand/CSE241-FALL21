#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "boardgame2d.h"
#include "pegsolitaire.h"
#include "eightpuzzle.h"
#include "klotski.h"

#include "boardgame2d.cpp"
#include "pegsolitaire.cpp"
#include "eightpuzzle.cpp"
#include "klotski.cpp"

#include <chrono>
#include <thread>


using namespace emircand;
using emircand::PegSolitaire;
using emircand::EightPuzzle;
using emircand::Klotski;

void playVector(vector<BoardGame2D*> myVector);

int main()
{
    srand(time(NULL));
    BoardGame2D* klotski_1 = new Klotski();
    BoardGame2D* klotski_2 = new Klotski();
    BoardGame2D* Peg_1 = new PegSolitaire();
    BoardGame2D* Peg_2 = new PegSolitaire();
    BoardGame2D* Puzzle_1 = new EightPuzzle();
    BoardGame2D* Puzzle_2 = new EightPuzzle();

    vector <BoardGame2D *> myVector = {Peg_1, Puzzle_1, klotski_1, Peg_2, Puzzle_2, klotski_2}; 
    playVector(myVector);
    
return 0;
}

void playVector(vector<BoardGame2D*> myVector)
{
    for (auto i = 0; i < myVector.size(); i++)
    {
        //pause
        cout << "press enter to begin new game..." << endl;
        std::cin.get();

        if(i < 3)
            myVector[i]->playUser();
        else 
            myVector[i]->playAutoAll();
    }
}