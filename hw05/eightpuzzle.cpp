#include <string>
#include <iostream>
#include "eightpuzzle.h"

using std::string;

namespace emircand
{
    void EightPuzzle::setPuzzleBoard(vector < vector<int> > puzzleBoard)
    {
        PuzzleBoard = puzzleBoard;
    }

    vector < vector<int> > EightPuzzle::getPuzzleBoard() const
    {
        return PuzzleBoard;
    }

    void EightPuzzle::setLastMove(string direction)
    {
        LastMove = direction;
    }

    string EightPuzzle::getLastMove() const
    {
        return LastMove;
    }

    /*this function take move string as a parameter and play game according to this parameter for one step.*/
    void EightPuzzle::playUser(string direction)
    {
        vector < vector<int> > currentBoard = getPuzzleBoard();
        int momentY, momentX, temp;

        /*find '0' and assign 0's location to momentY and momentX variables*/
        for (int i = 0; i < currentBoard.size(); i++)
            for (int j = 0; j < currentBoard[i].size(); j++)
                if(currentBoard[i][j] == 0)
                {
                    momentY = i;
                    momentX = j;
                }
        
        //uppercase all characters in string
        for (int i = 0; i < direction.length(); i++)
            direction[i] = toupper(direction[i]);

        if(isMoveValid(direction))
        {
            /*update the PuzzleBoard according to the direction string*/
            if (direction == "RIGHT")
            {
                temp = currentBoard[momentY][momentX];
                currentBoard[momentY][momentX] = currentBoard[momentY][momentX+1];
                currentBoard[momentY][momentX+1] = temp;
            }
            else if (direction == "LEFT")
            {
                temp = currentBoard[momentY][momentX];
                currentBoard[momentY][momentX] = currentBoard[momentY][momentX-1];
                currentBoard[momentY][momentX-1] = temp;
            }
            else if (direction == "UP")
            {
                temp = currentBoard[momentY][momentX];
                currentBoard[momentY][momentX] = currentBoard[momentY-1][momentX];
                currentBoard[momentY-1][momentX] = temp;
            }
            else if (direction == "DOWN")
            {
                temp = currentBoard[momentY][momentX];
                currentBoard[momentY][momentX] = currentBoard[momentY+1][momentX];
                currentBoard[momentY+1][momentX] = temp;
            }
            setPuzzleBoard(currentBoard);
        }
        else cerr << "\nimpossible move... please try again..." << endl;
    }

    /*this function create random with the help of RandomDirection() function. */
    void EightPuzzle::playAuto()
    {
        string direction = RandomDirection();

        /*
        I used do-while loop to prevent repeating moves while playAutoAll function was running.
        for example, if the last move is to the left, the next move should not be to the right;
        otherwise it creates an unnecessary repeat.
        */
        do
        {
            direction = RandomDirection();
        }while
            (
                (direction == "RIGHT" && getLastMove() == "LEFT") ||
                (direction == "LEFT" && getLastMove() == "RIGHT") ||
                (direction == "UP" && getLastMove() == "DOWN")    ||
                (direction == "DOWN" && getLastMove() == "UP")    
            );
        
        if(isMoveValid(direction))
        {
            setLastMove(direction);
            playUser(direction);    //if move is possible, call playUser function and update the board 
        }
        else playAuto(); //if move is not possible call playAuto function again  
    }

    /*if move is left/right/up/down (there is no case sensitivity) this function return true. Else return false.*/
    bool EightPuzzle::stringValidity(string move) const
    {
        //uppercase all characters in string
        for (int i = 0; i < move.length(); i++)
            move[i] = toupper(move[i]);

        if(move == "RIGHT" || move == "LEFT" || move == "UP" || move == "DOWN")
            return true;
        else
        {
            cerr << "invalid move!!! please try again" << endl;
            return false;
        } 
    }

    /*this function print the elements of PuzzleBoard top left corner of the terminal. But it prints “_” character instead of integer “0”*/
    void EightPuzzle::print() const
    {
        vector < vector<int> > currentBoard = getPuzzleBoard();

        /*clean and print top left of the terminal*/
        cout << "\x1B[2J\x1B[H";

        for (int i = 0; i < currentBoard.size(); i++)
        {
            for (int j = 0; j < currentBoard[i].size(); j++)
            {
                //print all elements in vector; if element is 0 print '_'
                if (currentBoard[i][j] != 0)
                    cout << currentBoard[i][j] << " ";
                else cout << "_" << " ";
            }
            cout << endl;
        }
        cout << "------------------------" << endl;
        cout<< "input format according to blank space: right / left / down / up" << endl;
        cout << "Board Score: " << boardScore() << endl;
    }

    /*
    if puzzle is ordered as   1 2 3 return true; else return false..
                              4 5 6
                              7 8 _ 
    */
    bool EightPuzzle::endGame() const
    {
        vector< vector<int> > correctBoard {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
        };

        vector< vector<int> > currentBoard = getPuzzleBoard();

        if(currentBoard == correctBoard)
            return true;
        else return false;
    }

    /*This function returns the number of correctly positioned elements according to game over situation.*/
    int EightPuzzle::boardScore() const
    {
        vector< vector<int> > correctBoard {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
        };
        vector< vector<int> > currentBoard = getPuzzleBoard();
        int result = 0;
        for (auto i = 0; i < correctBoard.size(); i++)
            for(decltype(i) j=0; j < currentBoard[i].size(); j++)
                if(currentBoard[i][j] != correctBoard[i][j])
                    result++;
        
        return result;
    }

    /*this function check the possibility of move according to the direction string for integer “0”. If it is possible return true; else return false.*/
    bool EightPuzzle::isMoveValid(string direction) const
    {
        vector< vector<int> > currentBoard = getPuzzleBoard();
        int momentY, momentX, temp;

        /*find '0' and assign 0's location to momentY and momentX variables*/
        for (int i = 0; i < currentBoard.size(); i++)
            for (int j = 0; j < currentBoard[i].size(); j++)
                if(currentBoard[i][j] == 0)
                {
                    momentY = i;
                    momentX = j;
                }

        /*check limits of 2D vector for given direction; if it is possible return true*/
        if (direction == "RIGHT" && momentX < currentBoard[0].size() - 1)
            return true;
        else if (direction == "LEFT" && momentX >= 1)
            return true;
        else if (direction == "UP" && momentY >= 1)
            return true;
        else if (direction == "DOWN" && momentY < currentBoard.size() - 1)
            return true;
        else
            return false;
    }


    /*initialize board then shuffle puzzle*/
    void EightPuzzle::initialize()
    {
        //for solvable puzzle, board initialized as game over condition
        vector< vector<int> > temp2D {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
        };

        //set PuzzleBoard
        setPuzzleBoard(temp2D);

        //shuffle puzzle  
        for (int i = 0; i < 99; i++)
            playAuto();
    }

    /*return any direction randomly*/
    string EightPuzzle::RandomDirection()
    {
        string direction;
        int d = rand()%4;
        switch (d)
        {
        case 0:
            direction = "DOWN";
            break;
        case 1:
            direction = "UP";
            break;
        case 2:
            direction = "LEFT";
            break;
        case 3:
            direction = "RIGHT";
            break;
        }
        return direction;
    }
}