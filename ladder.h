#include "snakes.h"
#include "players.h"

#ifndef LADDER_H_INCLUDED
#define LADDER_H_INCLUDED

using namespace std;

class Ladder{
public:
    void setLadder(){
        int topPosition;
        int bottomPosition;
reGen:
        //Follows the same layout as snake.h, with a few tweaks in numbers to make things a little more fair
        bottomPosition = (rand() % 80) + 1;

        //Head position is next, and should always be ahead of tail, but it shouldn't be able to send someone at 90 all the way back to 3.
        topPosition = bottomPosition + ((rand() % 30) + 10);

        if(topPosition >= 100){
            goto reGen;
        }

        bottom = bottomPosition;
        top = topPosition;

    }

    int getTopRung(){
        return top;
    }

    int getBottomRung(){
        return bottom;
    }

    void climbedLadder(Players &player){
        cout<<player.getName() + " you found a ladder!"<<endl;
        cout<<"You climb from: " + bottom<<endl;
        cout<<"To: " + top<<endl;


        player.setPosition(top);
    }

    private:
        int bottom, top;
};

void generateLadders(Ladder*);

void generateLadders(Ladder * ladders){
    srand(time(NULL));
    for(int i = 1; i <= 5; i ++){
        ladders[i - 1].setLadder();
    }
}

#endif // LADDER_H_INCLUDED
