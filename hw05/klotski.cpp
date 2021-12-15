#include <string>
#include <iostream>
#include "klotski.h"

using std::string;

namespace emircand
{
    /*this function swaps the elements of KlotskiBoard.*/
    void Klotski::swapFunc(int momentY, int momentX, int newY, int newX)
    {
        vector< vector<char> > currentBoard = getKlotskiBoard();

        char temp;
        /*swap the char values in given positions*/
        temp = currentBoard[momentY][momentX];
        currentBoard[momentY][momentX] = currentBoard[newY][newX];
        currentBoard[newY][newX] = temp;

        setKlotskiBoard(currentBoard);
    }

    void Klotski::setKlotskiBoard(vector< vector<char> > currentBoard)
    {
        KlotskiBoard = currentBoard;
    }

    vector< vector<char> > Klotski::getKlotskiBoard() const
    {
        return KlotskiBoard;
    }

    /*this function takes parameters and check the possibility of entered moves. If move is possible it returns true; else it returns false.*/
    bool Klotski::isMoveValid(char choice, string direction) const
    {
        bool flag = true, for_break = true;
        vector< vector<char> > currentBoard = getKlotskiBoard();

        int positionY, positionX;
        for (auto i = 0; i < currentBoard.size() && for_break != false; i++)
        {
            for (decltype(i) j = 0; j < currentBoard[i].size() && for_break != false; j++)
            {
                if(currentBoard[i][j] == choice)
                {
                    positionX = j;
                    positionY = i;
                    for_break = false;
                }
            }
                
        } 
        //move conditions for vertical rectangles
        if(choice == 'A' || choice == 'C' || choice == 'D' || choice == 'F')
        {
            if(direction == "RIGHT" && positionX < currentBoard[0].size() - 1)
            {
                if(currentBoard[positionY][positionX+1] == '0' && currentBoard[positionY+1][positionX+1] == '0')
                    return true;
            }
            else if(direction == "LEFT" && positionX >= 1)
            {
                if(currentBoard[positionY][positionX-1] == '0' && currentBoard[positionY+1][positionX-1] == '0')
                    return true;
            }
            else if(direction == "UP" && positionY >= 1)
            {
                if(currentBoard[positionY-1][positionX] == '0')
                    return true;
            }
            else if(direction == "DOWN" && positionY < currentBoard.size() - 2)
            {
                if(currentBoard[positionY+2][positionX] == '0')
                    return true;
            }
        }
        //move conditions for huge square
        else if(choice == 'B')
        {
            if(direction == "RIGHT" && positionX < currentBoard[0].size() - 1)
            {
                if(currentBoard[positionY][positionX+2] == '0' && currentBoard[positionY+1][positionX+2] == '0')
                    return true;
            }
            else if(direction == "LEFT" && positionX >= 1)
            {
                if(currentBoard[positionY][positionX-1] == '0' && currentBoard[positionY+1][positionX-1] == '0')
                    return true;
            }
            else if(direction == "UP" && positionY >= 1)
            {
                if(currentBoard[positionY-1][positionX] == '0' && currentBoard[positionY-1][positionX+1] == '0')
                    return true;
            }
            else if(direction == "DOWN" && positionY < currentBoard.size() - 2)
            {
                if(currentBoard[positionY+2][positionX] == '0' && currentBoard[positionY+2][positionX+1] == '0')
                    return true;
            }
        }
        //move conditions for horizontal square
        else if(choice == 'E')
        {
            if(direction == "RIGHT" && positionX < currentBoard[0].size() - 1)
            {
                if(currentBoard[positionY][positionX+2] == '0')
                    return true; 
            }
            else if(direction == "LEFT" && positionX >= 1)
            {
                if(currentBoard[positionY][positionX-1] == '0')
                    return true;
            }
            else if(direction == "UP" && positionY >= 1)
            {
                if(currentBoard[positionY-1][positionX] == '0' && currentBoard[positionY-1][positionX+1] == '0')
                    return true;
            }
            else if(direction == "DOWN" && positionY < currentBoard.size() - 1)
            {
                if(currentBoard[positionY+1][positionX] == '0' && currentBoard[positionY+1][positionX+1] == '0')
                    return true;
            }
        }
        //move conditions for small square
        else if(choice == 'G' || choice == 'H' || choice == 'I' || choice == 'J')
        {
            if(direction == "RIGHT" && positionX < currentBoard[0].size() - 1)
            {
                if(currentBoard[positionY][positionX+1] == '0')
                    return true; 
            }
            else if(direction == "LEFT" && positionX >= 1)
            {
                if(currentBoard[positionY][positionX-1] == '0')
                    return true;
            }
            else if(direction == "UP" && positionY >= 1)
            {
                if(currentBoard[positionY-1][positionX] == '0')
                    return true;
            }
            else if(direction == "DOWN" && positionY < currentBoard.size() - 1)
            {
                if(currentBoard[positionY+1][positionX] == '0')
                    return true;
            }               
        }
        return false;
    }

    /*this function print the elements of KlotskiBoard top left corner of the terminal. But it prints ‘ ’ instead of ‘0’.*/
    void Klotski::print() const
    {
        vector< vector<char> > currentBoard = getKlotskiBoard();

        /*clean and print top left of the terminal*/
        cout << "\x1B[2J\x1B[H";


        for (auto i = 0; i < currentBoard.size(); i++)
        {
            for (decltype(i) j = 0; j < currentBoard[i].size(); j++)
            {
                if(currentBoard[i][j] == '0')
                    cout << "  ";
                else 
                    cout << currentBoard[i][j] << " "; 
            }
            cout << endl;
        }
        cout<< "------------------------------" << endl;
        cout<< "input format: h right / i down" << endl;
    }
    
    /*This function check the validity of string if string is not in the correct form (example: G RIGHT) it returns false. Else it returns true.*/
    bool Klotski::stringValidity(string move) const
    {
        bool flag = true;
        //uppercase all characters in string
        for (int i = 0; i < move.length(); i++)
            move[i] = toupper(move[i]);

        string token, delimiter = " ";
        string type, direction;
        int pos = 0;
        //separate move string to different strings (type-direction) with " " delimiter
        if((pos = move.find(delimiter) != string::npos))
        {
            token = move.substr(0, pos);
            type = token;
            move.erase(0, pos + 1);
            direction = move;
        }

        //check validity of type string
        if((type.length() > 1) || (type[0] < 'A' || type[0] > 'J'))
        {
            flag = false;
            cerr << "invalid type!! please try again" << endl;
        }
        //check validity of direction string
        if(direction != "DOWN" && direction != "UP" && direction != "LEFT" && direction != "RIGHT")
        {
            flag = false;
            cerr << "invalid direction!! please try again" << endl;
        }
        return flag;
    }

    /*this function take move string as a parameter and play game according to this parameter for one step.*/
    void Klotski::playUser(string move)
    {
        //uppercase all characters in string
        for (int i = 0; i < move.length(); i++)
            move[i] = toupper(move[i]);

        string token, delimiter = " ";
        string type, direction;
        int pos = 0;
        //separate move string to different strings (type-direction) with " " delimiter
        if((pos = move.find(delimiter) != string::npos))
        {
            token = move.substr(0, pos);
            type = token;
            move.erase(0, pos + 1);
            direction = move;
        }
        char choice = type[0];

        if(isMoveValid(choice, direction))
        {
            //implement update...
            vector< vector<char> > currentBoard = getKlotskiBoard();
            int positionY, positionX;
            bool for_break = true;
            for (auto i = 0; i < currentBoard.size() && for_break == true; i++)
            {
                for (decltype(i) j = 0; j < currentBoard[i].size() && for_break == true; j++)
                    if(currentBoard[i][j] == choice)
                    {
                        positionX = j;
                        positionY = i;
                        for_break = false; //break for loop
                    }
            }

            //move implemantations for vertical rectangles
            if(choice == 'A' || choice == 'C' || choice == 'D' || choice == 'F')
            {
                if(direction == "RIGHT")
                {
                    swapFunc(positionY, positionX, positionY, positionX+1);
                    swapFunc(positionY+1, positionX, positionY+1, positionX+1);
                }
                else if(direction == "LEFT")
                {
                    swapFunc(positionY, positionX, positionY, positionX-1);
                    swapFunc(positionY+1, positionX, positionY+1, positionX-1);
                }
                else if(direction == "UP")
                {
                    swapFunc(positionY+1, positionX, positionY-1, positionX);
                }
                else if(direction == "DOWN")
                {
                    swapFunc(positionY, positionX, positionY+2, positionX);
                }
            }
            //move implemantations for large square
            else if(choice == 'B')
            {
                if(direction == "RIGHT")
                {
                    swapFunc(positionY, positionX, positionY, positionX+2);
                    swapFunc(positionY+1, positionX, positionY+1, positionX+2);

                }
                else if(direction == "LEFT")
                {
                    swapFunc(positionY, positionX+1, positionY, positionX-1);
                    swapFunc(positionY+1, positionX+1, positionY+1, positionX-1);
                }
                else if(direction == "UP")
                {
                    swapFunc(positionY+1, positionX, positionY-1, positionX);
                    swapFunc(positionY+1, positionX+1, positionY-1, positionX+1);
                }
                else if(direction == "DOWN")
                {
                    swapFunc(positionY, positionX, positionY+2, positionX);
                    swapFunc(positionY, positionX+1, positionY+2, positionX+1);
                }
            }
            //move implemantations for horizontal rectangle
            else if(choice == 'E')
            {
                if(direction == "RIGHT")
                    swapFunc(positionY, positionX, positionY, positionX+2);
                else if(direction == "LEFT")
                    swapFunc(positionY, positionX+1, positionY, positionX-1);
                else if(direction == "UP")
                {
                    swapFunc(positionY, positionX, positionY-1, positionX);
                    swapFunc(positionY, positionX+1, positionY-1, positionX+1);
                }
                else if(direction == "DOWN")
                {
                    swapFunc(positionY, positionX, positionY+1, positionX);
                    swapFunc(positionY, positionX+1, positionY+1, positionX+1);
                }
            }
            //move implemantations for mini squares
            else if(choice == 'G' || choice == 'H' || choice == 'I' || choice == 'J')
            {
                if(direction == "RIGHT")
                    swapFunc(positionY, positionX, positionY, positionX+1);
                else if(direction == "LEFT")
                    swapFunc(positionY, positionX, positionY, positionX-1);
                else if(direction == "UP")
                    swapFunc(positionY, positionX, positionY-1, positionX);
                else if(direction == "DOWN")
                    swapFunc(positionY, positionX, positionY+1, positionX); 
            }
        }
        else cerr << "\nimpossible move!!! please try again\n";
    }

    /*this function create random move parameters with the help of rand() function.*/
    void Klotski::playAuto()
    {
        int typeNumber = rand()%10;
        int directionNumber = rand()%4;
        string direction, type;


        switch (typeNumber)
        {
        case 0: type = "A "; break;
        case 1: type = "B "; break;
        case 2: type = "C "; break;
        case 3: type = "D "; break;
        case 4: type = "E "; break;
        case 5: type = "F "; break;
        case 6: type = "G "; break;
        case 7: type = "H "; break;
        case 8: type = "I "; break;
        case 9: type = "J "; break;
        }

        switch (directionNumber)
        {
        case 0: direction = "UP"; break;
        case 1: direction = "DOWN"; break;
        case 2: direction = "RIGHT"; break;
        case 3: direction = "LEFT"; break;
        }

        if(isMoveValid(type[0], direction))
        {
            string move = type + direction;
            playUser(move);
        }
        else playAuto();


    }

    /*If huge square which is symbolized with char ‘B’ located at mid-bottom of KlotskiBoard it returns true; else it returns false.*/
    bool Klotski::endGame() const
    {
        vector < vector<char> > currentBoard = getKlotskiBoard();

        if(currentBoard[3][1] == 'B' && currentBoard[3][2] == 'B' && currentBoard[4][1] == 'B' && currentBoard[4][2] == 'B')
            return true;
        else
            return false;
    }


    int Klotski::boardScore() const
    {
        return 0;
    }

    /*this function initialize 2D vector of <char> as a KlotskiBoard.*/
    void Klotski::initialize()
    {
        vector < vector<char> > board {
            {'A', 'B', 'B', 'C'},
            {'A', 'B', 'B', 'C'},
            {'D', 'E', 'E', 'F'},
            {'D', 'H', 'I', 'F'},
            {'G', '0', '0', 'J'}    
        };
        setKlotskiBoard(board);
    }
}