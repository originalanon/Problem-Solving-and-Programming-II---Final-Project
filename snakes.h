#ifndef SNAKES_H_INCLUDED
#define SNAKES_H_INCLUDED


#include<iostream>
#include<cstdlib>
#include<ctime>

#include "players.h"

using namespace std;

class Snake{

public:

    void setHeadandTail(){

        int headPosition;
        int tailPosition;



        //Generate tail position first; the tail should always be below 75
reGen:
        tailPosition = (rand() % 75) + 1;

        //Head position is next, and should always be ahead of tail, but it shouldn't be able to send someone at 90 all the way back to 3.
        headPosition = tailPosition + ((rand() % 40) + 10);

        if(headPosition >= 100){ //just to ensure the head isn't on 100 or over 100
            goto reGen;
        }

        head = headPosition;
        tail = tailPosition;

    }

    int getHead(){
        return head;
    }

    int getTail(){
        return tail;
    }

    void steppedOnHead(Players &player){ //changes player position to end of tail
        cout<<"Uh-oh! You stepped on a snake's head, " + player.getName() + "!"<<endl;
        cout<<"You moved from: "<<head<<"\nTo: "<<tail<<endl;

        player.setPosition(tail);
    }


    private:
    int head, tail;
};

void generateSnakes(Snake*);

void generateSnakes(Snake * snakes){ //mass generates all five snakes
    srand(time(NULL));
    for(int i = 1; i <= 5; i ++){
        snakes[i - 1].setHeadandTail();
    }
}



#endif // SNAKES_H_INCLUDED
