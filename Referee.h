#ifndef REFEREE_H
#define REFEREE_H

#include "Board.h"




class Referee
{
    public:
    //constructors take in private pointers 
    //Referee(Board *board);
        //destructors delete pointers

    void play(); //calls all game functions in here
    void movingInitially();
    void movingCursor(); //player is moving cursor to select next piece

    string getCurrentPlayer();
    string switchPlayers(string player);

    bool checkPiece(char object); //checks to see if player piece is correct
    

    void displayGameData(); //display cursor coord, turns and scoring
   
    

    //random function to generate number moves tied to pointer of player class
    int randomizeMoves();
    int getMoves(); //returns moves
    int incrementTurn(); //after each player turn, increment turn
    int getTurn();

    void addingPoints(string current); //if player one or player two scores increment their points 
    int getPointPlayerOne();
    int getPointPlayerTwo();
   
    //constructor
    Referee(Board board,Player *player, Player *playerTwo);
    ~Referee();


    private:

    //pointers to player one and player two
    Player *p1;
    Player *p2;
    Board b;

    string currentPlayer; //used to match the string id to player one or player two
    int p1Score;
    int p2Score;
    
    int turn;
    int moves;
    bool check;

};






#endif //BOARD_H