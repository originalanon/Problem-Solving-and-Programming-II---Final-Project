#include "players.h"

using namespace std;

#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

void displayIntInChar(int *arr, int sizeofarr, bool newLineRequired);
void printBoard();
int levelPassed(Players);
bool hasPassedLevel(int&, int&);
void printSnakesandLadders(Snake, Ladder);
void printLevels(int);

void printBoard()
{
    int topl[] = {201,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,187};
    int midl[] = {204,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,185};
    int bottoml[] = {200,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,188};
    int arr[10][10] = {{100,99,98,97,96,95,94,93,92,91},
                        {81,82,83,84,85,86,87,88,89,90},
                        {80,79,78,77,76,75,74,73,72,71},
                        {61,62,63,64,65,66,67,68,69,70},
                        {60,59,58,57,56,55,54,53,52,51},
                        {41,42,43,44,45,46,47,48,49,50},
                        {40,39,38,37,36,35,34,33,32,31},
                        {21,22,23,24,25,26,27,28,29,30},
                        {20,19,18,17,16,15,14,13,12,11},
                        {1,2,3,4,5,6,7,8,9,10}};
    int x,y;

    // to print top row
    displayIntInChar(topl,51,true);
    for(x=0;x<10;x++){
        for(y=0;y<10;y++){
            if(y==0){
                cout<<char(186);
            }
            if(arr[x][y] < 10){
                    cout<<char(32)<<char(32)<<arr[x][y]<<char(32); // prints 2 spaces, position, space
            }else if(arr[x][y] < 100){
                cout<<char(32)<<arr[x][y]<<char(32); // prints space position and space
            }else{
                cout<<arr[x][y]<<char(32); // prints position and space
            }
            cout<<char(186);
        }
        cout<<endl;
        if(x<9){
            //print middle row
            displayIntInChar(midl,51,true);
        }
    }
    //prints bottom border
    displayIntInChar(bottoml,51,true);
}

void displayIntInChar(int *arr, int sizeofarr, bool newLineRequired){
    int aSize = sizeofarr;
    for(int i=0;i<aSize;i++){
        cout<<char(arr[i]);
    }
    if(newLineRequired){
        cout<<endl;
    }
}

int levelPassed(Players player){ //sets the level -- levels are as follows
    int level = 1; //1 - 20
    if(player.getPosition() >= 20){
        level = 2;  //20 - 40
    }
    else if(player.getPosition() >= 40){
        level = 3; // 40 - 60
    }
    else if(player.getPosition() >= 60){
        level = 4; //60 - 80
    }
    else if(player.getPosition() >= 80){
        level = 5; //80 - 100
    }

    return level;
}

bool hasPassedLevel(int & currentLevel, int & highestLevel){ //checks if a new level has been passed and sets current level to the highest level
    bool newLevelhasPassed = false;
    if(currentLevel > highestLevel){
        newLevelhasPassed = true;
        cout<<"New level passed! Highest level: "<<currentLevel<<endl;
        highestLevel = currentLevel;
    }

    return newLevelhasPassed;
}

void printSnakesandLadders(Snake snakes[], Ladder ladders[]){
    cout<<"==============================================================="<<endl;
    cout<<"<-----------Snakes----------->"<<endl;
    for(int i = 1; i <= 5; i++){
        cout<<"<-----------Snake "<<i<<" - Head:"<<snakes[i - 1].getHead()<<" Tail:"<<snakes[i - 1].getTail()<<"----------->"<<endl;
    }

    cout<<"<-----------Ladders----------->"<<endl;
    for(int i = 1; i <= 5; i++){
        cout<<"<-----------Ladder "<<i<<" - Bottom:"<<ladders[i - 1].getBottomRung()<<" Top:"<<ladders[i - 1].getTopRung()<<"----------->"<<endl;
    }

    cout<<"==============================================================="<<endl;
}

void printLevels(int highestLevel){ //prints highest level and levels before it
    cout<<"==============================================================="<<endl;
    cout<<"<-----------Levels----------->"<<endl;

    for(int i = 1; i <= 5; i++){
        cout<<"Level "<<i<<": ";

        if(highestLevel >= i){
            cout<<"PASSED!"<<endl;
        }
        else{
            cout<<"Not passed."<<endl;
        }
    }
    }


#endif // BOARD_H_INCLUDED
