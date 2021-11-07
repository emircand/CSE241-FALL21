#include <iostream>
#include <vector>
#include <string>
#include "Functions.h"
#include "Functions.cpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

/*gameObj vector to play at same time..*/
vector<PegSolitaire> gameObj;

int main(){
    srand(time(NULL));
    vector<PegSolitaire> gameObj;
    int index = 0;
    string GameName;
    cout << "Game Name: ";
    cin >> GameName;
    gameObj.push_back(GameName);
    gameObj[index].input();
    Menu();
    while(true){
        string inputStr;
        cout << "game number: " << index+1 << endl;
        cout << "your choice: ";
        cin >> inputStr;
        if(inputStr == "1"){
            //gameObj[index].input();
            gameObj[index].play(); 
            Menu();
        }
        else if(inputStr == "2"){
            string locateMove;
            //gameObj[index].input();
            gameObj[index].display();
            while (locateMove.size() != 4)
            { /*user guide to take input in wanted terms*/
                cout << "move input (ex: a3-r): ";
                cin >> ws;
                getline(cin, locateMove);
            } 
            gameObj[index].play(locateMove);
            Menu();
        }
        else if(inputStr == "3"){
            //gameObj[index].input();
            gameObj[index].PlayGame();
            Menu();
        }
        else if(inputStr == "4"){
            string fileName;
            cout << "enter filename (.txt): ";
            cin >> ws;
            getline(cin, fileName);
            gameObj[index].LoadCell(fileName);
            Menu();
        }
        else if(inputStr == "5"){
            string fileName;
            cout << "enter filename (.txt): ";
            cin >> ws;
            getline(cin, fileName);
            gameObj[index].SaveCell(fileName);
            Menu();
        }
        else if(inputStr == "6"){
            index++;
            string GameName;
            cout << "Game Name: ";
            cin >> GameName;
            gameObj.push_back(GameName);
            gameObj[index].input();
            Menu();
        }
        else if(inputStr == "7"){
            int var1=0, var2=0;
            while(var1 < 1 || var1 > 6){
                cout << "enter number of first game to compare: ";
                cin >> var1;
                if(var1 < 1 || var1 > 6) cerr << "invalid input" << endl;
            }
            while(var2 < 1 || var2 > 6){
                cout << "enter number of second game to compare: ";
                cin >> var2;
                if(var2 < 1 || var2 > 6) cerr << "invalid input" << endl;
            }
            cout << "-----------------------------------------------" << endl
                 << var1 << ". game has " << gameObj[var1-1].PegCounter() << " pegs." << endl
                 << var2 << ". game has " << gameObj[var2-1].PegCounter() << " pegs." << endl
                 << "-----------------------------------------------" << endl;
            if(gameObj[var1-1].isMore(gameObj[var2-1]))
                cout << var1 << ". game has more pegs than " << var2 << ". game." << endl;
            else
                cout << var2 << ". game has more pegs than " << var1  << ". game." << endl;
            Menu();
        }
        else if(inputStr == "8"){
            int sum = 0;
            if(index < 1){
                sum = gameObj[index].getPegPin();
            }
            else{
                for (int i = 0; i < gameObj.size()-1; i++)
                {
                    PegSolitaire Total = gameObj[i] + gameObj[i+1];
                    sum += Total.getPegPin();
                }
            }
            cout << "Total Number of pegs: " << sum << endl;
            Menu();
        }
        else if(inputStr == "9"){
            break;
        }
        else cerr << "invalid input" << endl;
    }
    cout << "have a nice day..." << endl;
    return 0;
}