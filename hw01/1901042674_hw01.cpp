/**
 * @file 1901042674_hw01.cpp
 * @author Emircan Demirel (e.demirel2019@gtu.edu.tr)
 * @date Fall-2021
 */

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

/*strongly typed enum which include peg solitaire game's elements */
enum class peg{
    pin, empty, tab //tab means banned ares of gameboard
};

/*
    different type of boards for peg solitaire game
*/
vector<vector<peg>> board_1 {
    {peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab},
    {peg::tab, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::tab},
    {peg::pin, peg::pin, peg::pin, peg::empty, peg::pin, peg::pin, peg::pin},
    {peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin},
    {peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin},
    {peg::tab, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::tab},
    {peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab}
};

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

vector<vector<peg>> board_3 {
    {peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab, peg::tab},
    {peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab, peg::tab},
    {peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin},
    {peg::pin, peg::pin, peg::pin, peg::empty, peg::pin, peg::pin, peg::pin, peg::pin},
    {peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin},
    {peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab, peg::tab},
    {peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab, peg::tab}
};

vector<vector<peg>> board_4 {
    {peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab},
    {peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab},
    {peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin},
    {peg::pin, peg::pin, peg::pin, peg::empty, peg::pin, peg::pin, peg::pin},
    {peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin},
    {peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab},
    {peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab}
};

vector<vector<peg>> board_5 {
    {peg::tab, peg::tab, peg::tab, peg::tab, peg::pin, peg::tab, peg::tab, peg::tab, peg::tab},
    {peg::tab, peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab, peg::tab},
    {peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab},
    {peg::tab, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::tab},
    {peg::pin, peg::pin, peg::pin, peg::pin, peg::empty, peg::pin, peg::pin, peg::pin, peg::pin},
    {peg::tab, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::tab},
    {peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab},
    {peg::tab, peg::tab, peg::tab, peg::pin, peg::pin, peg::pin, peg::tab, peg::tab, peg::tab},
    {peg::tab, peg::tab, peg::tab, peg::tab, peg::pin, peg::tab, peg::tab, peg::tab, peg::tab}
};

vector<vector<peg>> board_6 {
    {peg::tab, peg::tab, peg::tab, peg::tab, peg::empty, peg::tab, peg::tab, peg::tab, peg::tab},
    {peg::tab, peg::tab, peg::tab, peg::pin, peg::tab, peg::pin, peg::tab, peg::tab, peg::tab},
    {peg::tab, peg::tab, peg::pin, peg::tab, peg::pin, peg::tab, peg::pin, peg::tab, peg::tab},
    {peg::tab, peg::pin, peg::tab, peg::pin, peg::tab, peg::pin, peg::tab, peg::pin, peg::tab},
    {peg::pin, peg::tab, peg::pin, peg::tab, peg::pin, peg::tab, peg::pin, peg::tab, peg::pin}
};

/*count number of pegs on choosen board*/
int PegCounter(vector<vector<peg>> currentBoard){
    int counter = 0; 
    for(int i=0; i<currentBoard.size(); i++){ //boardType.size() find number of rows to put newlines
        for(int j=0; j<currentBoard[0].size(); j++){ //boardType[0].size() find number of collumns and limiting loop to print elements
            if(currentBoard[i][j] == peg::pin)
                counter++;
        }
    }
    return counter;
}


/*checks the finish condition for peg solitaire game*/
bool IsGameFinishedBoard6(vector<vector<peg>> currentBoard){
    bool finished = true;

    /*nested for loops find the possible moves. */
    for (int i=0; i<currentBoard.size() && finished != false; i++){
        for(int j=0; j<currentBoard[0].size() && finished != false; j++){
            /*size functions to prevent segmentation faults*/
            if(i+4 < currentBoard.size()){
                /*if condition statements to find '.pp' or 'pp.' formations on board, update the boolean value of finished varriable*/
                if((currentBoard[i][j] == peg::empty) && (currentBoard[i+2][j] == peg::pin) && (currentBoard[i+4][j] == peg::pin))
                    finished = false;
                if((currentBoard[i][j] == peg::pin) && (currentBoard[i+2][j] == peg::pin) && (currentBoard[i+4][j] == peg::empty))
                    finished = false;
            }
            /*size functions to prevent segmentation faults*/
            if(j+4 < currentBoard[0].size()){
                /*if condition statements to find 
                . or p
                p    p
                p    . formations on board, update the boolean value of finished varriable
                */
                if((currentBoard[i][j] == peg::empty) && (currentBoard[i][j+2] == peg::pin) && (currentBoard[i][j+4] == peg::pin))
                    finished = false;
                if((currentBoard[i][j] == peg::pin) && (currentBoard[i][j+2] == peg::pin) && (currentBoard[i][j+4] == peg::empty))
                    finished = false;
            }
            //if condition statements to find crossed formations
            if(i+2 < currentBoard.size() && j+2 < currentBoard[0].size()){
                if((currentBoard[i][j] == peg::empty) && (currentBoard[i+1][j+1] == peg::pin) && (currentBoard[i+2][j+2] == peg::pin))
                    finished = false;
                if((currentBoard[i][j] == peg::pin) && (currentBoard[i+1][j+1] == peg::pin) && (currentBoard[i+2][j+2] == peg::empty))
                    finished = false;
            }
            if(i+2 < currentBoard.size() && j-2 >= 0){
                if((currentBoard[i][j] == peg::empty) && (currentBoard[i+1][j-1] == peg::pin) && (currentBoard[i+2][j-2] == peg::pin))
                    finished = false;
                if((currentBoard[i][j] == peg::pin) && (currentBoard[i+1][j-1] == peg::pin) && (currentBoard[i+2][j-2] == peg::empty))
                    finished = false;
            }


        }
    }
    if(PegCounter(currentBoard) == 1) finished = true;

    return finished;
}


/*checks the finish condition for peg solitaire game*/
bool IsGameFinished(vector<vector<peg>> currentBoard){
    bool finished = true;

    /*nested for loops find the possible moves. */
    for (int i=0; i<currentBoard.size() && finished != false; i++){
        for(int j=0; j<currentBoard[0].size() && finished != false; j++){
            /*size functions to prevent segmentation faults*/
            if(i+2 < currentBoard.size()){
                /*if condition statements to find '.pp' or 'pp.' formations on board, update the boolean value of finished varriable*/
                if((currentBoard[i][j] == peg::empty) && (currentBoard[i+1][j] == peg::pin) && (currentBoard[i+2][j] == peg::pin))
                    finished = false;
                if((currentBoard[i][j] == peg::pin) && (currentBoard[i+1][j] == peg::pin) && (currentBoard[i+2][j] == peg::empty))
                    finished = false;
            }
            /*size functions to prevent segmentation faults*/
            if(j+2 < currentBoard[0].size()){
                /*if condition statements to find 
                . or p
                p    p
                p    . formations on board, update the boolean value of finished varriable
                */
                if((currentBoard[i][j] == peg::empty) && (currentBoard[i][j+1] == peg::pin) && (currentBoard[i][j+2] == peg::pin))
                    finished = false;
                if((currentBoard[i][j] == peg::pin) && (currentBoard[i][j+1] == peg::pin) && (currentBoard[i][j+2] == peg::empty))
                    finished = false;
            }
        }
    }
    if(PegCounter(currentBoard) == 1) finished = true;

    return finished;
}

/*print 2D vectors on the console*/
void PrintBoard(vector<vector<peg>> boardType){
    /*variables to symbolize coordinations for algebraic notation*/
    int rowNumber = 0;
    int columnNumber = boardType[0].size();
    char columnChar = 'a';

    /*iteration for rows*/
    for(int i=0; i<boardType.size(); i++){ 
        if(i == 0){
            cout << "  ";
            /*print letters (increasing depending on board columns) of coordinations*/
            while(columnNumber>0){
                cout << columnChar++;
                columnNumber--;
            }
            if(columnNumber == 0) cout << endl;     
        }
        /*iteration for columns*/
        for(int j=0; j<boardType[0].size(); j++){ //boardType[0].size() find number of collumns and limiting loop to print elements
            if(j == 0)
                cout << ++rowNumber << " "; 

            /*print different symbols depending on game elements*/
            if(boardType[i][j] == peg::tab) 
                cout << " ";
            else if(boardType[i][j] == peg::pin)
                cout << "p";
            else cout << ".";
        }
        cout << endl;
    }
    cout << endl; //put a newline for clear output
}

/*take coordinates and direction for user's moves*/
char LocationInput(vector<vector<peg>> currentBoard, int *posX, int *posY){
    string locateMove;

    PrintBoard(currentBoard); //print board
    cout << "There are " << PegCounter(currentBoard) << " pegs on the board." << endl << endl; //game statements before taking move from user
    
    do
    { /*user guide to take input in wanted terms*/
        cout << "move input (ex: A3-R): ";
        cin >> locateMove;
    } while (locateMove.size() != 4);
    

    
    *posY = locateMove[0] - 'A'; //type castin char-to-integer.
    *posX = locateMove[1] - '1'; //type casting char-to-integer and minus 1. 

    return locateMove[3];
} 

/*check the validity of user's move*/
bool IsMoveValid(vector<vector<peg>> currentBoard, int positionY, int positionX, char direction)
{
    bool result = false;
    
    //on limits && secilen peg ise && aradaki peg ise && gidilen yer peg::tab degilse
    if((positionX >= currentBoard[0].size()) || (positionX < 0)) //limits for columns
        result = false;
    else if ((positionY >= currentBoard.size()) || (positionY < 0)) // limits for rows
        result = false;
    else if ((currentBoard[positionY][positionX] != peg::pin)) //secilen peg mi
        result = false;
    else {
        switch (direction)
        {
        case 'D':
            if(positionY < currentBoard.size() - 2)
                if((currentBoard[positionY+1][positionX] == peg::pin) && (currentBoard[positionY+2][positionX] == peg::empty))
                    result = true;
            break;
        case 'U':
            if(positionY > 1)
                if((currentBoard[positionY-1][positionX] == peg::pin) && (currentBoard[positionY-2][positionX] == peg::empty))
                    result = true;
            break;
        case 'L':
            if((currentBoard[positionY][positionX-1] == peg::pin) && (currentBoard[positionY][positionX-2] == peg::empty))
                result = true;
            break;
        case 'R':
            if((currentBoard[positionY][positionX+1] == peg::pin) && (currentBoard[positionY][positionX+2] == peg::empty))
                result = true;
            break;
        
        default:
            break;
        }
    }
    return result;
}


void MakeMoveBoard6(vector<vector<peg>> &currentBoard, int aY, int aX, int bY, int bX, int cY, int cX){
    currentBoard[aY][aX] = peg::empty;
    currentBoard[bY][bX] = peg::empty;
    currentBoard[cY][cX] = peg::pin;
}


/*check the validity of user's move*/
bool CheckMoveBoard6(vector<vector<peg>> &currentBoard, int pY, int pX, char direction)
{
    bool result;
    //on limits && secilen peg ise && aradaki peg ise && gidilen yer peg::tab degilse
    if((pX >= currentBoard[0].size()) || (pX < 0)) //limits for columns
        result = false;
    else if ((pY >= currentBoard.size()) || (pY < 0)) // limits for rows
        result = false;
    else if ((currentBoard[pY][pX] != peg::pin)) //secilen peg mi
        result = false;
    else {
        switch (direction)
        {
        case 'D':
            if(pY < currentBoard.size()-2){
                if(currentBoard[pY+1][pX+1]==peg::pin && currentBoard[pY+2][pX+2] == peg::empty ){
                    result = true;
                    MakeMoveBoard6(currentBoard, pY, pX, pY+1, pX+1, pY+2, pX+2);
                }   
                else if(currentBoard[pY+1][pX-1]==peg::pin && currentBoard[pY+2][pX-2] == peg::empty){
                    result = true;
                    MakeMoveBoard6(currentBoard, pY, pX, pY+1, pX-1, pY+2, pX-2);
                }
                else if((pY == 0) && (currentBoard[pY+2][pX]==peg::pin && currentBoard[pY+4][pX] == peg::empty)){
                    result = true;
                    MakeMoveBoard6(currentBoard, pY, pX, pY+2, pX, pY+4, pX);
                }
            }
            
            break;
        case 'U':
            if(pY >= 2 ){
                if(currentBoard[pY-1][pX+1]==peg::pin && currentBoard[pY-2][pX+2] == peg::empty ){
                    result = true;
                    MakeMoveBoard6(currentBoard, pY, pX, pY-1, pX+1, pY-2, pX+2);
                }   
                else if(currentBoard[pY-1][pX-1]==peg::pin && currentBoard[pY-2][pX-2] == peg::empty ){
                    result = true;
                    MakeMoveBoard6(currentBoard, pY, pX, pY-1, pX-1, pY-2, pX-2);
                }
                else if((pY == 4) && (currentBoard[pY-2][pX]==peg::pin && currentBoard[pY-4][pX] == peg::empty) ){
                    result = true;
                    MakeMoveBoard6(currentBoard, pY, pX, pY-2, pX, pY-4, pX);
                }
            }
            
            break;
        case 'L':
            if(pX >= 4){
                if(currentBoard[pY][pX-2]==peg::pin && currentBoard[pY][pX-4] == peg::empty){
                    result = true;
                    MakeMoveBoard6(currentBoard, pY, pX, pY, pX-2, pY, pX-4);
                }
            }
            break;
        case 'R':
            if(pX <= 4){
                if(currentBoard[pY][pX+2]==peg::pin && currentBoard[pY][pX+4] == peg::empty){
                    result = true;
                    MakeMoveBoard6(currentBoard, pY, pX, pY, pX+2, pY, pX+4);
                }
            }
            break;
        
        default:
            break;
        }
    }

    return result; 
}


/*if move input is valid, update currentBoard vector*/
void MakeMove(vector<vector<peg>> &currentBoard, int positionY, int positionX, char direction){
    if(direction == 'D'){ //make move towards down, change cell values
        currentBoard[positionY][positionX] = peg::empty;
        currentBoard[positionY+1][positionX] = peg::empty;
        currentBoard[positionY+2][positionX] = peg::pin;
    }
    else if(direction == 'U'){ //make move towards up, change cell values
        currentBoard[positionY][positionX] = peg::empty;
        currentBoard[positionY-1][positionX] = peg::empty;
        currentBoard[positionY-2][positionX] = peg::pin;
    }
    else if(direction == 'R'){//make move towards right, change cell values
        currentBoard[positionY][positionX] = peg::empty;
        currentBoard[positionY][positionX+1] = peg::empty;
        currentBoard[positionY][positionX+2] = peg::pin;
    }
    else if(direction == 'L'){//make move towards left, change cell values
        currentBoard[positionY][positionX] = peg::empty;
        currentBoard[positionY][positionX-1] = peg::empty;
        currentBoard[positionY][positionX-2] = peg::pin;
    }
}

/*function to call other movement functions in different conditions*/
void TakeMove(vector<vector<peg>> currentBoard){
    int positionY, positionX;
    char direction;
    bool result;
    
    /*take movement input and get direction*/
    direction = LocationInput(currentBoard, &positionY, &positionX);

    /*conditions for correct directions*/    
    while((direction != 'R') && (direction != 'L') && (direction != 'U') && (direction != 'D')){
        cerr << "invalid move.." << endl;
        direction = LocationInput(currentBoard, &positionY, &positionX);
    }

    /*check the input*/
    result = IsMoveValid(currentBoard, positionY, positionX, direction);

    /*if result false, recall TakeMove function (end of the function); else call MakeMove function and apply the movement*/
    if(result != true){
        cout << endl << endl << "impossible move" << endl << endl;
    }
    else MakeMove(currentBoard, positionY, positionX, direction);

    /*check game over condition*/
    if(IsGameFinished(currentBoard))
        cout << "game over... your score is " << PegCounter(currentBoard) << endl; //print the result
    else TakeMove(currentBoard); // else recall the function and go to next step.
}

/*create random moves and call movement functions for computer play*/
void ComputerPlay(vector<vector<peg>> currentBoard){
    int randX, randY, randDirection;
    char direction;

    /*get random coordinates and direction using rand() function */
    randY = rand()%(currentBoard[0].size());
    randX = rand()%(currentBoard.size());
    randDirection = rand()%4;

    /*type casting for direction integer-to-char*/
    switch (randDirection)
    {
    case 0:
        direction = 'D';
        break;
    case 1:
        direction = 'U';
        break;
    case 2:
        direction = 'L';
        break;
    case 3:
        direction = 'R';
        break;    
    }

    /*if move possible, make move and print the number of pegs to the console; else continue*/
    if(IsMoveValid(currentBoard, randX, randY, direction)){
        MakeMove(currentBoard, randX, randY, direction);
        PrintBoard(currentBoard);
        cout << "There are " << PegCounter(currentBoard) << " pegs on the board." << endl << endl;
    }
        
    /*if game over print result the console, else recall ComputerPlay function and continue*/
    if(IsGameFinished(currentBoard) == true)
        cout << "Game Over... no more possiple moves... " << endl <<  "Computer Result: " << PegCounter(currentBoard) << endl;
    else ComputerPlay(currentBoard);

}



void PlayBoard_6(vector<vector<peg>> currentBoard){
    int positionY, positionX;
    char direction;
    bool result;
    
    /*take movement input and get direction*/
    direction = LocationInput(currentBoard, &positionY, &positionX);

    /*conditions for correct directions*/    
    while((direction != 'R') && (direction != 'L') && (direction != 'U') && (direction != 'D')){
        cerr << "invalid move.." << endl;
        direction = LocationInput(currentBoard, &positionY, &positionX);
    }

    result = CheckMoveBoard6(currentBoard, positionY, positionX, direction);

    /*check the input*/

    /*if result false, recall TakeMove function; else call MakeMove function and apply the movement*/
    if(result != true){
        cout << endl << endl << "impossible move" << endl << endl;
    }

    /*check game over condition*/
    if(IsGameFinishedBoard6(currentBoard)){
        PrintBoard(currentBoard);
        cout << "game over... your score is " << PegCounter(currentBoard) << endl; //print the result
        exit(1);
    }
    else PlayBoard_6(currentBoard); // else recall the function and go to next step.
}

/*create random moves and call movement functions for computer play*/
void ComputerPlayBoard6(vector<vector<peg>> currentBoard){
    int randX, randY, randDirection;
    char direction;

    /*get random coordinates and direction using rand() function */
    randX = rand()%(currentBoard[0].size());
    randY = rand()%(currentBoard.size());
    randDirection = rand()%4;

    /*type casting for direction integer-to-char*/
    switch (randDirection)
    {
    case 0:
        direction = 'D';
        break;
    case 1:
        direction = 'U';
        break;
    case 2:
        direction = 'L';
        break;
    case 3:
        direction = 'R';
        break;    
    }

    /*if move possible, make move and print the number of pegs to the console; else continue*/
    if(CheckMoveBoard6(currentBoard, randY, randX, direction) == true){
        PrintBoard(currentBoard);
        cout << "There are " << PegCounter(currentBoard) << " pegs on the board." << endl << endl;
    }

    /*if game over print result the console, else recall ComputerPlay function and continue*/
    if(IsGameFinishedBoard6(currentBoard)){
        cout << "Game Over... no more possiple moves... " << endl <<  "Computer Result: " << PegCounter(currentBoard) << endl;
        exit(1);
    }
    else ComputerPlayBoard6(currentBoard);

}

/*menu screen for console*/
void OpeningScreen(){
    
    int choice;
    char player;

    cout << "1 - " << endl;
    PrintBoard(board_1);
    cout << "2 - " << endl;
    PrintBoard(board_2);
    cout << "3 - " << endl;
    PrintBoard(board_3);
    cout << "4 - " << endl;
    PrintBoard(board_4);
    cout << "5 - " << endl;
    PrintBoard(board_5);
    cout << "6 - " << endl;
    PrintBoard(board_6);

    cout << "choose one of the boards for peg solitaire... " << endl
         << "choice: ";
    cin >> choice;

    /*if input is not correct, ask for new input from user*/
    do
    {
        cout << "human or computer? (h/c)" << endl;
        cin >> player;    
    } while (player != 'h' && player != 'c');
        
    switch (choice)
    {
    case 1:
        if(player == 'h')
        TakeMove(board_1);
        else if( player == 'c') ComputerPlay(board_1);
        break;
    case 2:
        if(player == 'h')
        TakeMove(board_2);
        else if( player == 'c') ComputerPlay(board_2);
        break;
    case 3:
        if(player == 'h')
        TakeMove(board_3);
        else if( player == 'c') ComputerPlay(board_3);
        break;
    case 4:
        if(player == 'h')
        TakeMove(board_4);
        else if( player == 'c') ComputerPlay(board_4);
        break;
    case 5:
        if(player == 'h')
        TakeMove(board_5);
        else if( player == 'c') ComputerPlay(board_5);
        break;
    case 6: //this case have some issues
        if(player == 'h')
        PlayBoard_6(board_6);
        else if( player == 'c') ComputerPlayBoard6(board_6);
        break;
    
    default:
        cerr << "invalid board type.." << endl;
        cout << "calling new screen..." << endl;
        OpeningScreen();
        break;
    }
}


int main(){
    srand(time(NULL));
    OpeningScreen();
    return 0;
}