#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
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

class PegSolitaire{
public:
    class cell{
    public:
        cell(int rowNumber, char position, peg pegType);
        /*setter functions of cell class*/
        void setRowNumber(int rowNumber){RowNumber = rowNumber;}
        void setPosition(char position){Position = position;}
        void setPegType(peg pegType){PegType = pegType;}
        /*getter functions of cell class*/
        int getRowNumber(){return RowNumber;}
        char getPosition(){return Position;} 
        peg getPegType(){return PegType;}

    private:
        int RowNumber;
        char Position;
        peg PegType;
    };

    //-------------------
    PegSolitaire(int pinNumber);
    PegSolitaire(string GameName);
    PegSolitaire(vector<vector<peg>> boardType);
    /*setter functions of PegSolitaire class*/
    void setBoardNumber(int boardNumber){BoardNumber = boardNumber;}
    void setBoardType(int boardNumber){BoardType = CallBoard(boardNumber);}
    void setCellVector(vector<vector<cell>> cellVector){CellVector = cellVector;}
    void setPin(int pin){pegPin = pin;}
    void setGameName(string name){GameName = name;}
    /*getter functions of PegSolitaire class*/
    inline int getBoardNumber() const {return BoardNumber;}
    inline int getPegPin() const{return pegPin;}
    inline string getGameName() const{return GameName;}
    inline vector<vector<peg>> getBoardType() const  {return BoardType;}
    inline vector<vector<cell>> getCellVector() const {return CellVector;}

    /*helper functions*/
    vector<vector<peg>> CallBoard(int boardNumber);
    void FillCell();
    void LoadCell(string filename);
    void SaveCell(string filename);
    void input();
    /*gameplay functions*/
    void play();
    void play(string move);
    void PlayGame();
    /*printer functions of PegSolitaire class*/
    void display();
    void displayPeg(vector<vector<peg>> board);
    void displayAll();
    /*peg changer functions of game*/
    void MakeMove(char direction, int posX, int posY);
    void MakeMove();
    void MakeMove(int aY, int aX, int bY, int bX, int cY, int cX);
    /*counter functions of game*/
    static int getMoves();
    static int getTaken();
    static int getEmpty();
    int PegCounter();
    
    bool isMore(PegSolitaire Obj);
    

private:
    string GameName; 
    int BoardNumber;
    static int numberOfMoves;
    int pegPin;
    static int pegEmpty;
    static int pegTaken;
    vector<vector<peg>> BoardType;
    vector<vector<cell>> CellVector;
    bool isValidPlay(int posY, int posX, char direction);
    bool isGameOver();
    void CheckSize();
};

const PegSolitaire operator+(const PegSolitaire& gameObj1, const PegSolitaire& gameobj2);

int PegSolitaire::numberOfMoves = 0;
int PegSolitaire::pegTaken = 0;
int PegSolitaire::pegEmpty = 0;

vector<vector<peg>> CallBoard(int boardNumber);
void Menu();


#endif