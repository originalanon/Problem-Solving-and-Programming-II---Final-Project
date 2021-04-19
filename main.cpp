/**
 *  Lindsay Barton
 *  Final Project
 *  CS 250 (WEB5) - Dr. El Mesalami
 *  07/26/2019
 *  "Snakes and Ladders"
 */


#include <iostream>
#include "players.h"
#include "snakes.h"
#include "ladder.h"
#include "game.h"
#include "board.h"

using namespace std;

void takeTurn(Players &player, int (&snakeHeads)[5], int (&ladderBottoms)[5], Snake (&snakes)[5], Ladder (&ladders)[5]){
            rollDie(player);

            for(int i = 1; i <= 5; i++){
                if(player.getPosition() == snakeHeads[i - 1]){
                    snakes[i - 1].steppedOnHead(player);
                }
                else if(player.getPosition() == ladderBottoms[i - 1]){
                    ladders[i - 1].climbedLadder(player);
                }
            }

}

int main(){
    Players player1;
    Players player2;
    EnterPlayerNames(player1, player2);

    Snake snakes[5];
    int snakeHeads[5];

    Ladder ladders[5];
    int ladderBottoms[5];

    generateSnakes(snakes);
    generateLadders(ladders);

    int highestLevel = 0;
    int currentLevel = 0;

    for(int i = 1; i <= 5; i++){
        snakeHeads[i - 1] = snakes[i - 1].getHead();
        ladderBottoms[i - 1] = ladders[i - 1].getBottomRung();
    }



    while(checkForWin(player1, player2) == false){

        //player1's turn
        cout<<player1.getName()<<"'s position: "<<player1.getPosition()<<"\t\t\t"<<player2.getName()<<"'s position: "<<player2.getPosition()<<endl;
        printLevels(highestLevel);
        printSnakesandLadders(snakes, ladders);
        printBoard();
        takeTurn(player1, snakeHeads, ladderBottoms, snakes, ladders);
        //checks if player1 wins
        currentLevel = levelPassed(player1);
        if(checkForWin(player1, player2) == true){
            break;
        }


        //checks if player1 has crossed a level
        if(hasPassedLevel(currentLevel, highestLevel)){
                generateSnakes(snakes);
                generateLadders(ladders);
            }


        //player2's turn
        cout<<player1.getName()<<"'s position: "<<player1.getPosition()<<"\t\t\t"<<player2.getName()<<"'s position: "<<player2.getPosition()<<endl;
        printLevels(highestLevel);
        printSnakesandLadders(snakes, ladders);
        printBoard();
        takeTurn(player2, snakeHeads, ladderBottoms, snakes, ladders);
        currentLevel = levelPassed(player2);

        //checks if player2 has crossed a level
        if(hasPassedLevel(currentLevel, highestLevel)){
            generateSnakes(snakes);
            generateLadders(ladders);
        }

    }

return 0;
}
