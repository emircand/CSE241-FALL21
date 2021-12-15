#include <string>
#include <iostream>
#include "pegsolitaire.h"

namespace emircand
{
    void PegSolitaire::Cell::setPegType(peg pegType)
    {
        PegType = pegType;
    }

    PegSolitaire::peg  PegSolitaire::Cell::getPegType() const
    {
        return PegType;
    }

    /*this function takes parameters and check the possibility of entered moves. If move is possible it returns true; else it returns false.*/
    bool PegSolitaire::isMoveValid(int positionY, int positionX, string direction) const
    {
        vector<vector<Cell>> currentBoard = getPegBoard();

        /*else boardNumbers has same movement conditions..*/

        //on limits && chosen one is peg::pin && move is possible
        if((positionX >= currentBoard[0].size()) || (positionX < 0)) //limits for columns
            return false;
        else if ((positionY >= currentBoard.size()) || (positionY < 0)) // limits for rows
            return false;
        else if ((currentBoard[positionY][positionX].getPegType() != peg::pin)) //secilen peg mi
            return false;
        else
        {
            if(direction == "DOWN")
                if(positionY < currentBoard.size() - 2)
                    if((currentBoard[positionY+1][positionX].getPegType() == peg::pin) && (currentBoard[positionY+2][positionX].getPegType() == peg::empty))
                        return true;

            if(direction == "UP")
                if(positionY > 1)
                    if((currentBoard[positionY-1][positionX].getPegType() == peg::pin) && (currentBoard[positionY-2][positionX].getPegType() == peg::empty))
                        return true;
            
            if(direction == "LEFT")
                if(positionX > 1)
                    if((currentBoard[positionY][positionX-1].getPegType() == peg::pin) && (currentBoard[positionY][positionX-2].getPegType() == peg::empty))
                        return true;

            if(direction == "RIGHT")
                if(positionX < currentBoard[0].size() - 2)
                    if((currentBoard[positionY][positionX+1].getPegType() == peg::pin) && (currentBoard[positionY][positionX+2].getPegType() == peg::empty))
                        return true;
        }

        return false;
    }

    /*this function overload version of playUser(string move). Only difference of these functions is parameter types.*/
    void PegSolitaire::playUser(int positionY, int positionX, string direction)
    {
        vector<vector<Cell>> currentBoard = getPegBoard();
            
        if(direction == "DOWN"){ //make move towards down, change cell values
            currentBoard[positionY][positionX].setPegType(peg::empty);
            currentBoard[positionY+1][positionX].setPegType(peg::empty);
            currentBoard[positionY+2][positionX].setPegType(peg::pin);
        }
        else if(direction == "UP"){ //make move towards up, change cell values
            currentBoard[positionY][positionX].setPegType(peg::empty);
            currentBoard[positionY-1][positionX].setPegType(peg::empty);
            currentBoard[positionY-2][positionX].setPegType(peg::pin);
        }
        else if(direction == "RIGHT"){//make move towards right, change cell values
            currentBoard[positionY][positionX].setPegType(peg::empty);
            currentBoard[positionY][positionX+1].setPegType(peg::empty);
            currentBoard[positionY][positionX+2].setPegType(peg::pin);
        }
        else if(direction == "LEFT"){//make move towards left, change cell values
            currentBoard[positionY][positionX].setPegType(peg::empty);
            currentBoard[positionY][positionX-1].setPegType(peg::empty);
            currentBoard[positionY][positionX-2].setPegType(peg::pin);
        }
        setPegBoard(currentBoard);
    }

    /*this function take move string as a parameter and play game according to this parameter for one step.*/
    void PegSolitaire::playUser(string move)
    {
        //uppercase all characters in string
        for (int i = 0; i < move.length(); i++)
            move[i] = toupper(move[i]);

        string token, delimiter = " ";
        string location, direction;
        
        int pos = 0;
        //separate move string to different strings (location-direction) with " " delimiter
        if((pos = move.find(delimiter) != string::npos))
        {
            token = move.substr(0, pos + 1);
            location = token;
            move.erase(0, pos + 2);
            direction = move;
        }

        int positionY = location[0] - '1';
        int positionX = location[1] - 'A';

        if (isMoveValid(positionY, positionX, direction))
        {
            vector<vector<Cell>> currentBoard = getPegBoard();
            
            if(direction == "DOWN"){ //make move towards down, change cell values
                currentBoard[positionY][positionX].setPegType(peg::empty);
                currentBoard[positionY+1][positionX].setPegType(peg::empty);
                currentBoard[positionY+2][positionX].setPegType(peg::pin);
            }
            else if(direction == "UP"){ //make move towards up, change cell values
                currentBoard[positionY][positionX].setPegType(peg::empty);
                currentBoard[positionY-1][positionX].setPegType(peg::empty);
                currentBoard[positionY-2][positionX].setPegType(peg::pin);
            }
            else if(direction == "RIGHT"){//make move towards right, change cell values
                currentBoard[positionY][positionX].setPegType(peg::empty);
                currentBoard[positionY][positionX+1].setPegType(peg::empty);
                currentBoard[positionY][positionX+2].setPegType(peg::pin);
            }
            else if(direction == "LEFT"){//make move towards left, change cell values
                currentBoard[positionY][positionX].setPegType(peg::empty);
                currentBoard[positionY][positionX-1].setPegType(peg::empty);
                currentBoard[positionY][positionX-2].setPegType(peg::pin);
            }
            setPegBoard(currentBoard);
        }
        else cerr << "invalid move!!! please try again.." << endl;

        
    }

    /*this function create random move parameters with the help of rand() function.*/
    void PegSolitaire::playAuto()
    {
        vector < vector<Cell> > temp = getPegBoard();
        while(true)
        {
            int positionY = rand()%temp.size();
            int positionX = rand()%temp[0].size();
            int directionNum = rand()%4;
            string direction;
            switch (directionNum)
            {
            case 0:
                direction = "UP";
                break;
            case 1:
                direction = "DOWN";
                break;
            case 2:
                direction = "LEFT";
                break;
            case 3:
                direction = "RIGHT";
                break;
            }
            if(isMoveValid(positionY, positionX, direction))
            {
                playUser(positionY, positionX, direction);
                break;
            }
        }

    }

    /*this function print the elements of PegBoard top left corner of the terminal. 
    It prints “p” for “peg::pin”;
    “.” For “peg::empty”;
    “ ” for “peg::tab”.*/
    void PegSolitaire::print() const
    {
        vector < vector<Cell> > temp = getPegBoard();
        int row = 0, column = temp[0].size();
        char columnChar = 'A';

        /*clean and print top left of the terminal*/
        cout << "\x1B[2J\x1B[H";


        /*print elements of cell vector to the console*/
        for (int i = 0; i < temp.size(); i++)
        {
            if(i == 0){
                cout << "  ";
                /*print letters (increasing depending on board columns) of coordinations*/
                while(column>0){
                    cout << columnChar++; 
                    column--;
                }
                if(column == 0) cout << endl;     
            }
            for (int j = 0; j < temp[i].size(); j++)
            {
                /*print number of rows*/       
                if(j == 0)
                    cout << ++row << " ";
                if (temp[i][j].getPegType() == peg::tab)
                    cout << " ";
                else if (temp[i][j].getPegType() == peg::pin)
                    cout << "p";
                else if (temp[i][j].getPegType() == peg::empty)
                    cout << ".";
            }
            cout << endl;
        }
        cout<< "input format: 3E RIGHT" << endl;
        cout << "the remaining number of pegs: " << boardScore() << endl;
    }

    /*If there is no more move on PegBoard or BoardScore function returns any number smaller than 2, it returns true; else it returns false.*/
    bool PegSolitaire::endGame() const
    {
        bool gameOver = true;
        vector< vector<Cell> > currentBoard = getPegBoard();
        int pegCount = 0;
        /*nested for loops find the possible moves. */
        for (int i=0; i<currentBoard.size(); i++){
            for(int j=0; j<currentBoard[0].size(); j++){
                /*size functions to prevent segmentation faults*/
                if(i+2 < currentBoard.size()){
                    /*if condition statements to find '.pp' or 'pp.' formations on board, update the boolean value of gameOver variable*/
                    if((currentBoard[i][j].getPegType() == peg::empty) && (currentBoard[i+1][j].getPegType() == peg::pin) && (currentBoard[i+2][j].getPegType() == peg::pin))
                        return false;
                    if((currentBoard[i][j].getPegType() == peg::pin) && (currentBoard[i+1][j].getPegType() == peg::pin) && (currentBoard[i+2][j].getPegType() == peg::empty))
                        return false;
                }
                /*size functions to prevent segmentation faults*/
                if(j+2 < currentBoard[0].size()){
                    /*if condition statements to find 
                    . or p
                    p    p
                    p    . formations on board, update the boolean value of gameOver variable
                    */
                    if((currentBoard[i][j].getPegType() == peg::empty) && (currentBoard[i][j+1].getPegType() == peg::pin) && (currentBoard[i][j+2].getPegType() == peg::pin))
                        return false;
                    if((currentBoard[i][j].getPegType() == peg::pin) && (currentBoard[i][j+1].getPegType() == peg::pin) && (currentBoard[i][j+2].getPegType() == peg::empty))
                        return false;
                }
            }
        }

        if(boardScore() < 2)
            cout << "Congratulations!!!!" << endl;

        return true;
    }

    /*This function check the validity of string if string is not in the correct form (example: 3E RIGHT) it returns false. Else it returns true.*/
    bool PegSolitaire::stringValidity(string move) const
    {
        bool flag = true;
        
        //uppercase all characters in string
        for (int i = 0; i < move.length(); i++)
            move[i] = toupper(move[i]);

        string token, delimiter = " ";
        string location, direction;
        int pos = 0;
        //separate move string to different strings (location-direction) with " " delimiter
        if((pos = move.find(delimiter) != string::npos))
        {
            token = move.substr(0, pos + 1);
            location = token;
            move.erase(0, pos + 2);
            direction = move;
        }
        //check validity of location string
        if((location.length() > 2) || (location[0] < '0' || location[0] > '9') || (location[1] < 'A' || location[1] > 'Z'))
        {
            flag = false;
            cerr << "invalid location!! please try again" << endl;
        }
        //check validity of direction string
        if(direction != "DOWN" && direction != "UP" && direction != "LEFT" && direction != "RIGHT")
        {
            flag = false;
            cerr << "invalid direction!! please try again" << endl;
        }

        return flag;
    }

    /*this function returns the number of peg::pins of PegBoard.*/
    int PegSolitaire::boardScore() const
    {
        int pegCount = 0;
        vector < vector<Cell> > currentBoard = getPegBoard();
        
        for (int i = 0; i < currentBoard.size(); i++)
            for (int j = 0; j < currentBoard[i].size(); j++)
                if(currentBoard[i][j].getPegType() == peg::pin)
                    pegCount++;

        return pegCount;
    }

    void PegSolitaire::setPegBoard(vector<vector<Cell>> pegBoard)
    {
        PegBoard = pegBoard;
    }

    vector< vector<PegSolitaire::Cell> > PegSolitaire::getPegBoard() const
    {
        return PegBoard;
    }

    /*this function initialize 2D vector of peg objects to 2D vector of Cell objects. After that set 2D vector of Cell as PegBoard.*/
    void PegSolitaire::initialize()
    {
        vector<vector<peg>> board_2 {
        {peg::tab, peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab, peg::tab},
        {peg::tab, peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab, peg::tab},
        {peg::tab, peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab, peg::tab},
        {peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin},
        {peg::pin, peg::pin, peg::pin, peg::pin, peg::empty, peg::pin, peg::pin, peg::pin, peg::pin},
        {peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin},
        {peg::tab, peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab, peg::tab},
        {peg::tab, peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab, peg::tab},
        {peg::tab, peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab, peg::tab}
        };

        vector<vector<Cell>> temp2D;
        for (int i = 0; i < board_2.size(); i++)
        {
            vector<Cell> temp;
            for (int j = 0; j < board_2[0].size(); j++)
            {
                Cell obj;
                obj.setPegType(board_2[i][j]);
                temp.push_back(obj);
            }
            temp2D.push_back(temp);
        }
        setPegBoard(temp2D);


    }

}