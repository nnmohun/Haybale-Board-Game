#ifndef BOARD_H
#define BOARD_H
#include "Player.h"


class Board
{
    public:
        //set board 2d array 14 by 13 
            //set game pieces in initial position and cursor

            //move function 
        void setGame();
        void setCursor();
        int getCursorRow();
        int getCursorCol(); //take in 5,5 to set up cursor initial placement
        void setSymbol(char s);
        char getSymbol();
       
        void moveCursor(char direction, string player);
       

      
        void setPieces(); //places the haybales and chickapigs
        void updatePiece(int r, int c); //updates the piece row and column ints to allow movement of peices
        bool movePiece(char move); //moving the piece
        void playerMovingPieces(char symbol);
        void foundChickapigPiece(char symbol); //a piece has been selected from the cursor, moves until obstacle
        void foundHaybalePiece(char symbol);
        bool checkScore(char symbol);
        bool getScore();
        
        void UpdateCursorGame();
        void UpdateGamePiece();
        
        
        
        

        //constructor sets everything to default settings
        Board();
            //destructor to delete board 
        ~Board();
    private:
        //array for board
        char game [14][15];
        int cursorCol;
        int cursorRow;
        char symbol; //the symbol the user is moving
        int pieceCol;
        int pieceRow; //coords tied to moving game pieces 

        bool scored;
        

        
};

#endif //BOARD_H