#include <string>
#include <iostream>
#include "boardgame2d.h"

using std::string;

namespace emircand
{
    
    int BoardGame2D::playVector(vector<BoardGame2D*> myVector)
    {
        for (auto i = 0; i < myVector.size(); i++)
        {
            //pause
            if(i > 0)
            {
                cout << "press enter to begin new game..." << endl;
                std::cin.get();
            }
            if(i < 3)
                myVector[i]->playUser();
            else 
                myVector[i]->playAutoAll();
        }

        return 0;
    }

    /*  Another overload of playUser is a final function. 
        It does not take any parameters, it takes a string from the user for the next move 
        in a loop and plays the game until it is over. 
        It also prints the board between the moves.*/
    void BoardGame2D::playUser()
    {
        //it takes a string from user in a loop
        initialize();
        do{
            print();
            //take move string - control the move string - if it is valid and possible make move
            string move;
            cout << "enter move: (to exit '-1')" << endl;
            getline(cin, move);
            if(move == "-1") break;
            if(stringValidity(move))
                //call overload of playUser function then make move
                playUser(move);
            //play game until it is over 
        }while(!endGame());
        print();
        if(endGame() == true)
            cout << "GAME OVER!!!\nno more possible moves for this board..." << endl; 
        else cout << "EXITING..." << endl;
    }

    /*
    playAutoAll is a final function. 
    It plays the game until it is over. 
    This one calls playAuto for all the moves. 
    It also prints the board between the moves after some pause.
    */
    void BoardGame2D::playAutoAll()
    {
        initialize();
        //play game until it is over
        while(endGame() == false)
        {
            //make a move
            playAuto();
            //print to the console
            print();
            //pause
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
        cout << "GAME OVER!!!\nno more possible moves for this board..." << endl;  
    }
}