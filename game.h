#include<iostream>
#include<cstdlib>
#include<ctime>
#include "players.h"

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

using namespace std;

bool checkForWin(Players, Players);
void rollDie(Players&);

bool checkForWin(Players player1, Players player2){ //checks if either player has made it past 100
    bool winMet;

    if(player1.getPosition() >= 100){
        notifyPlayer(player1);
        winMet = true;
    }
    else if(player2.getPosition() >= 100){
        notifyPlayer(player2);
        winMet = true;
    }
    else{
        winMet = false;
    }

    return winMet;
}

void rollDie(Players &roller){
    cout<<roller.getName()<<", press enter to roll.";
    cin.ignore();
    cout<<endl;

    srand(time(NULL));

    int dice = (rand() % 6) + 1;
    cout<<"You rolled... "<<endl;

    switch(dice){ //graphical dice
        case 1:
    cout<<"   .+------+"<<endl;
    cout<<" .'      .'| "<<endl;
    cout<<"+------+'  |"<<endl;
    cout<<"|      |   |"<<endl;
    cout<<"|  O   |   +"<<endl;
    cout<<"|      | .' "<<endl;
    cout<<"+------+"<<endl;
    break;

        case 2:
    cout<<"   .+------+"<<endl;
    cout<<" .'      .'| "<<endl;
    cout<<"+------+'  |"<<endl;
    cout<<"|    O |   |"<<endl;
    cout<<"|      |   +"<<endl;
    cout<<"| O    | .' "<<endl;
    cout<<"+------+"<<endl;
    break;

        case 3:
    cout<<"   .+------+"<<endl;
    cout<<" .'      .'| "<<endl;
    cout<<"+------+'  |"<<endl;
    cout<<"| O    |   |"<<endl;
    cout<<"|   O  |   +"<<endl;
    cout<<"|     O| .' "<<endl;
    cout<<"+------+"<<endl;
    break;

        case 4:
    cout<<"   .+------+"<<endl;
    cout<<" .'      .'| "<<endl;
    cout<<"+------+'  |"<<endl;
    cout<<"| O  O |   |"<<endl;
    cout<<"|      |   +"<<endl;
    cout<<"| O  O | .' "<<endl;
    cout<<"+------+"<<endl;
    break;

        case 5:
    cout<<"   .+------+"<<endl;
    cout<<" .'      .'| "<<endl;
    cout<<"+------+'  |"<<endl;
    cout<<"| O  O |   |"<<endl;
    cout<<"|  O   |   +"<<endl;
    cout<<"| O  O | .' "<<endl;
    cout<<"+------+"<<endl;
    break;

    case 6:
    cout<<"   .+------+"<<endl;
    cout<<" .'      .'| "<<endl;
    cout<<"+------+'  |"<<endl;
    cout<<"| O  O |   |"<<endl;
    cout<<"| O  O |   +"<<endl;
    cout<<"| O  O | .' "<<endl;
    cout<<"+------+"<<endl;
    break;

    }

    cout<<"Press enter to move."<<endl;
    cin.ignore();

    roller.setPosition(roller.getPosition() + dice); //sets player position to player position + dice roll
}


#endif // GAME_H_INCLUDED
