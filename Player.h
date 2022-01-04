#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

class Player
{
    public:
        //constructor for string name and 0 score
        Player(string n);
        Player();
            //destructor
            ~Player();
        
        void setName(string n);
       
        //overloading the increment score function
        void operator++();
        //overloading the bool score function
        bool operator<(int wScore); //winnning score is 6
        int getScore();

        char userMovement();


    private:
        string name;
        char movement;
        int score;
         //6points wins the game scoring all chickapigs
        int roll_number;
};


#endif //PLAYER_H