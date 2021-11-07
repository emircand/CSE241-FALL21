#include "Functions.h"
#include <iostream>

/*constructor functions of PegSolitaire class*/
PegSolitaire::PegSolitaire(vector<vector<peg>> boardType)
{
    //if statement to initialize boardtype
    int i;
    if(boardType == board_1)
        i = 1;
    else if(boardType == board_2)
        i = 2;
    else if(boardType == board_3)
        i = 3;
    else if(boardType == board_4)
        i = 4;
    else if(boardType == board_5)
        i = 5;
    else if(boardType == board_6)
        i = 6;
    //set PegSolitaire private variables
    setBoardNumber(i);
    setBoardType(i);
}

PegSolitaire::PegSolitaire(int pinNumber)
{
    //set PegSolitaire private variables
    setPin(pinNumber);
    setBoardNumber(getBoardNumber());
}

PegSolitaire::PegSolitaire(string name)
    :GameName(name)
{
}

/*constructor function of cell class*/
PegSolitaire::cell::cell(int rowNumber, char position, peg pegType)
    :RowNumber(rowNumber), Position(position), PegType(pegType){
}

/*counts the number of pegs on the board*/
int PegSolitaire::PegCounter(){
    vector<vector<cell>> currentBoard = getCellVector();
    int counter = 0; 
    for(int i=0; i<currentBoard.size(); i++){ //boardType.size() find number of rows to put newlines
        for(int j=0; j<currentBoard[0].size(); j++){ //boardType[0].size() find number of collumns and limiting loop to print elements
            if(currentBoard[i][j].getPegType() == peg::pin)
                counter++;
        }
    }
    /*setter function of pegpin variable*/
    setPin(counter);
    return counter;
}

/*static int variable functions of PegSolitaire class*/
int PegSolitaire::getMoves()
{
    numberOfMoves++;
    return numberOfMoves;
}

int PegSolitaire::getTaken()
{
    pegTaken++;
    return pegTaken;
}

int PegSolitaire::getEmpty()
{
    pegEmpty++;
    return pegEmpty;
}

/*check the validity of move input for both user and computer plays..*/
bool PegSolitaire::isValidPlay(int positionY, int positionX, char direction){
    bool result = false;
    vector<vector<cell>> currentBoard = getCellVector();
    /*If boardNumber is 6, different rules apply*/
    if(getBoardNumber() == 6){
        if((positionX >= currentBoard[0].size()) || (positionX < 0)) //limits for columns
            result = false;
        else if ((positionY >= currentBoard.size()) || (positionY < 0)) // limits for rows
            result = false;    
        else if ((currentBoard[positionY][positionX].getPegType() != peg::pin)) //secilen peg mi
            result = false;
        else {
            switch (direction)
            {
            case 'D':
            case 'd':
                /*check down direction moves like;
                  p
                  p and also cross directional variants 
                  . 
                */
                if(positionY < currentBoard.size()-2){
                    if(currentBoard[positionY+1][positionX+1].getPegType() == peg::pin && currentBoard[positionY+2][positionX+2].getPegType() == peg::empty ){
                        result = true;
                        MakeMove(positionY, positionX, positionY+1, positionX+1, positionY+2, positionX+2);
                    }   
                    else if(currentBoard[positionY+1][positionX-1].getPegType() ==peg::pin && currentBoard[positionY+2][positionX-2].getPegType() == peg::empty){
                        result = true;
                        MakeMove(positionY, positionX, positionY+1, positionX-1, positionY+2, positionX-2);
                    }
                    else if(positionY == 0 && positionX == 4){
                        if(currentBoard[positionY+2][positionX].getPegType() == peg::pin && currentBoard[positionY+4][positionX].getPegType() == peg::empty){
                            result = true;
                            MakeMove(positionY, positionX, positionY+2, positionX, positionY+4, positionX);
                        }
                    }
                }
                
                break;
            case 'U':
            case 'u':
                /*check up directions moves like;
                  .
                  p and also cross directional variants 
                  p 
                */
                if(positionY > 1 ){
                    if(currentBoard[positionY-1][positionX+1].getPegType() == peg::pin && currentBoard[positionY-2][positionX+2].getPegType() == peg::empty ){
                        result = true;
                        MakeMove(positionY, positionX, positionY-1, positionX+1, positionY-2, positionX+2);
                    }   
                    else if(currentBoard[positionY-1][positionX-1].getPegType() == peg::pin && currentBoard[positionY-2][positionX-2].getPegType() == peg::empty ){
                        result = true;
                        MakeMove(positionY, positionX, positionY-1, positionX-1, positionY-2, positionX-2);
                    }
                    else if (positionY == 4 && positionX == 4){
                        if(currentBoard[positionY-2][positionX].getPegType() == peg::pin && currentBoard[positionY-4][positionX].getPegType() == peg::empty ){
                            result = true;
                            MakeMove(positionY, positionX, positionY-2, positionX, positionY-4, positionX);
                        }
                    }
                }
                break;
            case 'L':
            case 'l':
                /*check left direction moves like;
                    . p p 
                */
                if(positionX >= 4){
                    if(currentBoard[positionY][positionX-2].getPegType() == peg::pin && currentBoard[positionY][positionX-4].getPegType() == peg::empty){
                        result = true;
                        MakeMove(positionY, positionX, positionY, positionX-2, positionY, positionX-4);
                    }
                }
                break;
            case 'R':
            case 'r':
                /*check right direction moves like;
                  p p .
                */
                if(positionX < currentBoard[0].size() - 4){
                    if(currentBoard[positionY][positionX+2].getPegType() == peg::pin && currentBoard[positionY][positionX+4].getPegType() == peg::empty){
                        result = true;
                        MakeMove(positionY, positionX, positionY, positionX+2, positionY, positionX+4);
                    }
                }
                break;
            }
        }
    }
    /*else boardNumbers has same movement conditions..*/
    else {
        //on limits && secilen peg ise && aradaki peg ise && gidilen yer peg::tab degilse
        if((positionX >= currentBoard[0].size()) || (positionX < 0)) //limits for columns
            result = false;
        else if ((positionY >= currentBoard.size()) || (positionY < 0)) // limits for rows
            result = false;
        else if ((currentBoard[positionY][positionX].getPegType() != peg::pin)) //secilen peg mi
            result = false;
        else {
            switch (direction)
            {
            case 'D':
            case 'd':
                /*check down direction moves like;
                  p
                  p 
                  . 
                */
                if(positionY < currentBoard.size() - 2){
                    if((currentBoard[positionY+1][positionX].getPegType() == peg::pin) && (currentBoard[positionY+2][positionX].getPegType() == peg::empty))
                        result = true;
                }
                break;
            case 'U':
            case 'u':
                /*check up direction moves like;
                  .
                  p 
                  p 
                */
                if(positionY > 1){
                    if((currentBoard[positionY-1][positionX].getPegType() == peg::pin) && (currentBoard[positionY-2][positionX].getPegType() == peg::empty))
                        result = true;
                }
                break;
            case 'L':
            case 'l':
                /*check left direction moves like;
                  . p p 
                */
                if(positionX > 1){
                    if((currentBoard[positionY][positionX-1].getPegType() == peg::pin) && (currentBoard[positionY][positionX-2].getPegType() == peg::empty))
                        result = true;
                }
                break;
            case 'R':
            case 'r':
                /*check left direction moves like;
                  p p . 
                */
                if(positionX < currentBoard[0].size() - 2)
                    if((currentBoard[positionY][positionX+1].getPegType() == peg::pin) && (currentBoard[positionY][positionX+2].getPegType() == peg::empty))
                        result = true;
                break;
            }
        }
    }
    return result;
}

bool PegSolitaire::isMore(PegSolitaire Obj){
    if(PegCounter() >= Obj.PegCounter())
        return true;
    else return false;
}

bool PegSolitaire::isGameOver(){
    bool gameOver = true;
    vector<vector<cell>> currentBoard = getCellVector();
    int boardnum = getBoardNumber();

    if(boardnum == 6){
        /*nested for loops find the possible moves. */
        for (int i=0; i<currentBoard.size() && gameOver != false; i++){
            for(int j=0; j<currentBoard[0].size() && gameOver != false; j++){
                /*size functions to prevent segmentation faults*/
                if(i+4 < currentBoard.size()){
                    /*if condition statements to find '.pp' or 'pp.' formations on board, update the boolean value of gameOver varriable*/
                    if((currentBoard[i][j].getPegType() == peg::empty) && (currentBoard[i+2][j].getPegType() == peg::pin) && (currentBoard[i+4][j].getPegType() == peg::pin))
                        gameOver = false;
                    if((currentBoard[i][j].getPegType() == peg::pin) && (currentBoard[i+2][j].getPegType() == peg::pin) && (currentBoard[i+4][j].getPegType() == peg::empty))
                        gameOver = false;
                }
                /*size functions to prevent segmentation faults*/
                if(j+4 < currentBoard[0].size()){
                    /*if condition statements to find 
                    . or p
                    p    p
                    p    . formations on board, update the boolean value of gameOver varriable
                    */
                    if((currentBoard[i][j].getPegType() == peg::empty) && (currentBoard[i][j+2].getPegType() == peg::pin) && (currentBoard[i][j+4].getPegType() == peg::pin))
                        gameOver = false;
                    if((currentBoard[i][j].getPegType() == peg::pin) && (currentBoard[i][j+2].getPegType() == peg::pin) && (currentBoard[i][j+4].getPegType() == peg::empty))
                        gameOver = false;
                }
                //if condition statements to find crossed formations
                if(i+2 < currentBoard.size() && j+2 < currentBoard[0].size()){
                    if((currentBoard[i][j].getPegType() == peg::empty) && (currentBoard[i+1][j+1].getPegType() == peg::pin) && (currentBoard[i+2][j+2].getPegType() == peg::pin))
                        gameOver = false;
                    if((currentBoard[i][j].getPegType() == peg::pin) && (currentBoard[i+1][j+1].getPegType() == peg::pin) && (currentBoard[i+2][j+2].getPegType() == peg::empty))
                        gameOver = false;
                }
                if(i+2 < currentBoard.size() && j-2 >= 0){
                    if((currentBoard[i][j].getPegType() == peg::empty) && (currentBoard[i+1][j-1].getPegType() == peg::pin) && (currentBoard[i+2][j-2].getPegType() == peg::pin))
                        gameOver = false;
                    if((currentBoard[i][j].getPegType() == peg::pin) && (currentBoard[i+1][j-1].getPegType() == peg::pin) && (currentBoard[i+2][j-2].getPegType() == peg::empty))
                        gameOver = false;
                }
            }
        }
    }
    else{
        /*nested for loops find the possible moves. */
        for (int i=0; i<currentBoard.size() && gameOver != false; i++){
            for(int j=0; j<currentBoard[0].size() && gameOver != false; j++){
                /*size functions to prevent segmentation faults*/
                if(i+2 < currentBoard.size()){
                    /*if condition statements to find '.pp' or 'pp.' formations on board, update the boolean value of gameOver varriable*/
                    if((currentBoard[i][j].getPegType() == peg::empty) && (currentBoard[i+1][j].getPegType() == peg::pin) && (currentBoard[i+2][j].getPegType() == peg::pin))
                        gameOver = false;
                    if((currentBoard[i][j].getPegType() == peg::pin) && (currentBoard[i+1][j].getPegType() == peg::pin) && (currentBoard[i+2][j].getPegType() == peg::empty))
                        gameOver = false;
                }
                /*size functions to prevent segmentation faults*/
                if(j+2 < currentBoard[0].size()){
                    /*if condition statements to find 
                    . or p
                    p    p
                    p    . formations on board, update the boolean value of gameOver varriable
                    */
                    if((currentBoard[i][j].getPegType() == peg::empty) && (currentBoard[i][j+1].getPegType() == peg::pin) && (currentBoard[i][j+2].getPegType() == peg::pin))
                        gameOver = false;
                    if((currentBoard[i][j].getPegType() == peg::pin) && (currentBoard[i][j+1].getPegType() == peg::pin) && (currentBoard[i][j+2].getPegType() == peg::empty))
                        gameOver = false;
                }
            }
        }
    }
    /*prints message on the console at game-end situations*/
    if(PegCounter() == 1) {
        gameOver = true;
        cout << "CONGRATULATIONS...." << endl;
    }
    else if (gameOver == true)
    {
        cerr << "No More Possible Moves..." << endl;
    }
    return gameOver;
}

void PegSolitaire::play(){
    string input;
    /*call make move: create random variables and make move*/
    MakeMove();
    display(); //print the game board 
    if(isGameOver()) 
        cerr << "returning the menu...." << endl << endl;
    else{
        cout << "to continue press 1, to exit enter any input.." << endl;
        cin >> input;
        if (input == "1") //to block consecutive games
            play();
    }
}

/*user play - take move as a parameter*/
void PegSolitaire::play(string locateMove){
    int posY, posX, temp;
    char direction;
    //seperate locateMove strings to move variables
    posY = locateMove[1] - '1';
    posX = locateMove[0] - 'a';
    direction = locateMove[3];
    //check the validity of wanted move
    if(isValidPlay(posY, posX, direction)){
        numberOfMoves++; 
        //if boardNumber6, automatically call MakeMove func.. else use this
        if(getBoardNumber() != 6){
            MakeMove(direction, posY, posX);
            display();
        }
    }
    //check the game end condition..
    if(isGameOver()) cerr << "returning the menu...." << endl << endl;
    else{
        cout << "to continue press 1..  " ;
        cin >> temp;
        if(temp == 1){
            string newMove;
            while(newMove.size() != 4){
                cout << "move input (ex: A3-R): ";
                cin >> ws;
                getline(cin, newMove);
            }
            play(newMove);
        }
        else cerr << "returning the menu...." << endl << endl;
    }
    
}

/*computer play the game automatically until end*/
void PegSolitaire::PlayGame(){
    while(!isGameOver()){
        MakeMove();
        display();
    }
}

/*make moves for boardtype_6 */
void PegSolitaire::MakeMove(int aY, int aX, int bY, int bX, int cY, int cX){
    vector<vector<cell>> currentBoard = getCellVector();
    currentBoard[aY][aX].setPegType(peg::empty);
    currentBoard[bY][bX].setPegType(peg::empty);
    currentBoard[cY][cX].setPegType(peg::pin);
    //increase static int getter functions of PegSolitaire private variables
    getMoves();
    getTaken();
    getEmpty();
    //set CellVector of object
    setCellVector(currentBoard);
}

/*make moves randomly*/
void PegSolitaire::MakeMove(){
    /*get random coordinates and direction using rand() function */
    int randY, randX, randDirection;
    char direction;
    vector<vector<cell>> currentBoard = getCellVector();

    randY = rand()%(currentBoard.size());
    randX = rand()%(currentBoard[0].size());
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
    /*if move possible make move*/
    if(isValidPlay(randY, randX, direction)){
        if(getBoardNumber() != 6){
            MakeMove(direction, randY, randX);
        }
    }
    else MakeMove();
}

/*main: make moves function*/
void PegSolitaire::MakeMove(char direction, int positionY, int positionX){
    vector<vector<cell>> currentBoard = getCellVector();
    if(direction == 'D' || direction == 'd'){ //make move towards down, change cell values
        currentBoard[positionY][positionX].setPegType(peg::empty);
        currentBoard[positionY+1][positionX].setPegType(peg::empty);
        currentBoard[positionY+2][positionX].setPegType(peg::pin);
    }
    else if(direction == 'U' || direction == 'u'){ //make move towards up, change cell values
        currentBoard[positionY][positionX].setPegType(peg::empty);
        currentBoard[positionY-1][positionX].setPegType(peg::empty);
        currentBoard[positionY-2][positionX].setPegType(peg::pin);
    }
    else if(direction == 'R' || direction == 'r'){//make move towards right, change cell values
        currentBoard[positionY][positionX].setPegType(peg::empty);
        currentBoard[positionY][positionX+1].setPegType(peg::empty);
        currentBoard[positionY][positionX+2].setPegType(peg::pin);
    }
    else if(direction == 'L' || direction == 'l'){//make move towards left, change cell values
        currentBoard[positionY][positionX].setPegType(peg::empty);
        currentBoard[positionY][positionX-1].setPegType(peg::empty);
        currentBoard[positionY][positionX-2].setPegType(peg::pin);
    }
    getMoves();
    getTaken();
    getEmpty();
    setCellVector(currentBoard);
}

/*return boardtype by passing boardNumber*/
vector<vector<peg>> PegSolitaire::CallBoard(int boardNumber){
    vector<vector<peg>> boardType;

    switch (boardNumber)
    {
    case 1:
        boardType = board_1;
        break;
    case 2:
        boardType = board_2;
        break;
    case 3:
        boardType = board_3;
        break;
    case 4:
        boardType = board_4;
        break;
    case 5:
        boardType = board_5;
        break;
    case 6:
        boardType = board_6;
        break;
    }
    return boardType;
}

/*prints peg variables of cellVector by using algebraic notation*/
void PegSolitaire::display(){
    vector<vector<cell>> cellVector = getCellVector();
    /*variables to symbolize coordinations for algebraic notation*/
    int row=0, column=cellVector[0].size();
    char columnChar = 'a';
    
    /*iteration for rows*/
    for (int i = 0; i < cellVector.size(); i++)
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
        /*iteration for columns*/
        for (int j = 0; j < cellVector[0].size(); j++) //cellVector[0].size() find number of collumns and limiting loop to print elements
        {
            /*print number of rows*/       
            if(j == 0)
                cout << ++row << " "; 
            /*print different symbols depending on game elements*/
            if(cellVector[i][j].getPegType() == peg::empty)
                cout << ".";
            else if(cellVector[i][j].getPegType() == peg::pin)
                cout << "p";
            else if(cellVector[i][j].getPegType() == peg::tab)
                cout << " ";
        }
        cout << endl;
    }
    cout << "number of moves: " << numberOfMoves << endl
        << "number of pegs on the board: " << PegCounter() << endl 
        << "number of empties on the board: " << pegEmpty << endl;
}

void PegSolitaire::displayPeg(vector<vector<peg>> currentBoard){
    /*iteration for rows*/
    for (int i = 0; i < currentBoard.size(); i++)
    {
        /*iteration for columns*/
        for (int j = 0; j < currentBoard[0].size(); j++) //cellVector[0].size() find number of collumns and limiting loop to print elements
        {
            /*print different symbols depending on game elements*/
            if(currentBoard[i][j] == peg::empty)
                cout << ".";
            else if(currentBoard[i][j] == peg::pin)
                cout << "p";
            else if(currentBoard[i][j] == peg::tab)
                cout << " ";
        }
        cout << endl;
    }
}

/*print all peg boardtypes*/
void PegSolitaire::displayAll(){
    cout << "1-" << endl;
    displayPeg(board_1);
    cout << "2-"<< endl;
    displayPeg(board_2);
    cout << "3-"<< endl;
    displayPeg(board_3);
    cout << "4-"<< endl;
    displayPeg(board_4);    
    cout << "5-"<< endl;
    displayPeg(board_5);
    cout << "6-"<< endl;
    displayPeg(board_6);
}

/*create cellVector*/
void PegSolitaire::FillCell(){    
    vector<vector<peg>> boardType = getBoardType();
    vector<vector<cell>> cellVector;

    /*use peg boardtypes as a reference for CellVector*/
    for (int i = 0; i < boardType.size(); i++)
    {
        //temporary cell vector to pushback main CellVector
        vector<cell> temp;
        for (int j = 0; j < boardType[0].size(); j++)
        {
            /*j+48 means type casting of j variable int to char(ascii)*/
            cell tempCell(i+1, j+48, boardType[i][j]);
            temp.push_back(tempCell);
        }
        cellVector.push_back(temp);
    }
    /*setter of cellVector*/
    setCellVector(cellVector);
    cout << "---------------------------------------------" << endl;
    display();
    cout << "--------------selected board-----------------" << endl ;
}

void PegSolitaire::SaveCell(string fileName){
    ofstream fout;
    vector<vector<cell>> currentBoard = getCellVector();
    int boardNumber = getBoardNumber();

    /*open file -which is string variable fileName- in write mode*/    
    fout.open(fileName, ios::out);

    if(fout.is_open()){
        /*saved data of GameName*/
        fout << getGameName() << endl;
        /*saved data of boardNumber*/
        fout << getBoardNumber() << endl; 

        /*save data of row and column numbers of board*/
        fout << currentBoard.size() << " " << currentBoard[0].size() << endl;

        for (int i = 0; i < currentBoard.size(); i++)
        {
            for (int j = 0; j < currentBoard[0].size(); j++)
            {
                /*convert enum to integer*/
                if(currentBoard[i][j].getPegType() == peg::pin)
                    fout << 1 << " ";
                else if(currentBoard[i][j].getPegType() == peg::tab)
                    fout << 0 << " ";
                else if(currentBoard[i][j].getPegType() == peg::empty)
                    fout << 2 << " ";
            }
            fout << endl;
        }
        /*save and number of moves info*/
        fout << numberOfMoves << endl;
        fout.close();
        /*statement*/
        cout << "game board saved succesfully to " << fileName << endl;
    }
    else cout << "game board could not saved to " << fileName << endl;
}

void PegSolitaire::LoadCell(string fileName){
    ifstream fin;
    int row, column, finput, boardNumber;
    string name;
    vector<vector<cell>> currentBoard;

    /*open file in read mode*/
    fin.open(fileName, ios::in);

    /*check the file*/
    if(fin.is_open()){
        /*take saved data of board type*/
        fin >> name;
        /*take saved data of board number*/
        fin >> boardNumber;
        setGameName(name);
        setBoardNumber(boardNumber);
        setBoardType(boardNumber);
        /*take saved data of board's row and column numbers*/
        fin >> row >> column;
        for (int i = 0; i < row; i++){
            vector <cell> temp;
            for (int j = 0; j < column; j++)
            {
                /*take data and save to vector with push_back method*/
                fin >> finput;
                /*j+48 means type casting of j variable int to char(ascii)*/
                if(finput == 1){
                    cell tempCell(i+1, j+48, peg::pin);
                    temp.push_back(tempCell);
                }
                else if(finput == 2){
                    cell tempCell(i+1, j+48, peg::empty);
                    temp.push_back(tempCell);
                }
                else if(finput == 0){
                    cell tempCell(i+1, j+48, peg::tab);
                    temp.push_back(tempCell);
                }
                
            }
            /*take every row and go to next row*/
            currentBoard.push_back(temp);
        }
        setCellVector(currentBoard);
        display();
        /*take player and number of moves info*/
        fin >> numberOfMoves;
        cout << "loaded succesfully" << endl;
        fin.close();
        /*menu operations for loaded function*/
        while(true){
            cout  << "1 - step-by-step computer play" << endl
                 << "2 - step-by-step user play" << endl
                 << "3 - all-in-one computer play" << endl
                 << "4 - save to file" << endl
                 << "5 - EXIT" << endl;
            string inputStr;
            cin >> inputStr;

            if(inputStr == "1"){
                play();
            }
            else if(inputStr == "2"){
                string locateMove;
                while(locateMove.size() != 4){
                    cout << "move input (ex: a3-r): ";
                    cin >> ws;
                    getline(cin, locateMove);
                }
                play(locateMove);
            }
            else if(inputStr == "3"){
                PlayGame();
            }
            else if(inputStr == "4"){
                string fileName;
                cout << "enter file name(.txt): ";
                cin >> ws;
                getline(cin, fileName);
                SaveCell(fileName);
            }
            else if(inputStr == "5"){
                break;
            }
        }
    }
}

/*operator overloading function to count number of all pegs in all Games...*/
const PegSolitaire operator+(const PegSolitaire& gameObj1, const PegSolitaire& gameobj2){
    int allPegs = gameObj1.getPegPin() + gameobj2.getPegPin();

    return PegSolitaire(allPegs);
}

void Menu(){
    cout << endl
             << "##########################" << endl
             << "#     Peg Solitaire      #" << endl
             << "##########################" << endl
             << "1 - step-by-step computer play" << endl
             << "2 - step-by-step user play" << endl
             << "3 - all-in-one computer play" << endl
             << "4 - load from file" << endl
             << "5 - save to file" << endl
             << "6 - create a new game" << endl
             << "7 - which one has more pegs?" << endl
             << "8 - total number of pegs" << endl
             << "9 - EXIT" << endl;
}

void PegSolitaire::input(){
    /*print all boards*/
    displayAll();
    int boardNumber;
    while(boardNumber < 1 || boardNumber > 6){    
        cout << "enter the number of gameboard: ";
        cin >> boardNumber;
    }
    /*set pegsolitaire private variables*/
    setBoardType(boardNumber);
    setBoardNumber(boardNumber);
    //initialize CellVector elements
    FillCell();
    //reseting static integers
    numberOfMoves = 0;
    pegTaken = 0;
    pegEmpty = 0;
}