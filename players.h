#include<iostream>
#include<string>

#ifndef PLAYERS_H_INCLUDED
#define PLAYERS_H_INCLUDED

using namespace std;

class Players{
public:
    Players(string n = "NULL", int p = 1){
        name = n;
        position = p;
    }

    void setName(string n){
        name = n;
    }

    string getName(){
        return name;
    }

    void setPosition(int p){
        position = p;
    }

    int getPosition(){
        return position;
    }

private:
    string name;
    int position;
};

void EnterPlayerNames(Players&, Players&);
void notifyPlayer(Players);

void EnterPlayerNames(Players & player1, Players & player2){ //Gets players names
    string name;
    cout<<"Welcome to Snakes and Ladders! \r\nPlease enter player 1's name:";
    cin>>name;
    player1.setName(name);

    cout<<"Please enter player 2's name:";
    cin>>name;
    player2.setName(name);
}

void notifyPlayer(Players winner){
    cout<<"Congratulations, "<<winner.getName()<<"!"<<endl;
    cout<<"Thank you for playing!"<<endl;
}

#endif // PLAYERS_H_INCLUDED
