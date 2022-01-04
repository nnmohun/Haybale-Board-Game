#include "Referee.h"

using namespace std;

Referee::Referee(Board board, Player *player, Player *playerTwo)
{
    b=board;
    p1= player;
    p2 = playerTwo;

    currentPlayer = "player one";

    p1Score =0;
    p2Score=0;

    turn=0;
    moves=0;


    
}
Referee::~Referee()
{
    
}

int Referee::incrementTurn()
{
    turn++;

    return turn;
}

int Referee::getTurn()
{
    return turn;
}
int Referee::randomizeMoves()
{
    moves=0;

    moves = rand()%6+1;


    return moves;
}
int Referee::getMoves()
{
    return moves;
}

bool Referee::checkPiece(char object)
{
    
    check =false;

    if(currentPlayer == "player one")
    {
        if(object=='O'||object=='@')
            check=true;
            
    }
    else if(currentPlayer=="player two")
    {
        if(object=='X'||object=='#')
            check=true;
            
    }
    return check;
}

string Referee::getCurrentPlayer()
{
    return currentPlayer;
}

string Referee::switchPlayers(string player)
{
    if (player=="player one")
        currentPlayer="player two";
    else if(player=="player two")
        currentPlayer="player one";

    return currentPlayer;
    
}

int Referee::getPointPlayerOne()
{
    return p1Score;
}
int Referee::getPointPlayerTwo()
{
    return p2Score;
}

void Referee::addingPoints(string current)
{
    if(current=="player one")
    {
        p1Score++;
        
    }
    else if(current=="player two")
    {
        p2Score++;
        
    }
}


void Referee::displayGameData()
{
    //get cursor Coords to display 
    int c = b.getCursorCol();
    int r=b.getCursorRow();

    

    cout<<"\nTurns: "<<getTurn();

    cout<<"\nCursor: "<<r<<","<<c<<endl;

    cout<<endl<<setw(10)<<setfill(' ')<<' '<<"Player 1 Score: "<<getPointPlayerOne()<<endl
        <<setw(10)<<" "<<"Player 2 Score: "<<getPointPlayerTwo()<<endl
        <<setw(10)<<" "<<"Moves Left: "<<getMoves()<<endl<<endl;

    string name=getCurrentPlayer();
    if(name=="player one")
        cout<<"Player 1: O and @"<<endl;
    else if(name=="player two")
        cout<<"Player 2: X and #"<<endl;
    
}




void Referee::movingInitially()
{



   
    char s=' ';
    b.setSymbol(s);
    b.setGame();

    b.setCursor();
    b.setPieces();
    //b.DisplayGame();

    char piece;

    string p = getCurrentPlayer();
   
    

    cout<<endl<<p<<endl;
    
    char dir;
    do 
    {
        b.UpdateCursorGame();
        displayGameData();
        
        dir= p1->userMovement(); //gets users cursor movement

        b.moveCursor(dir,p); //calls board function move cursor
        
        //displays the cursor movement
       
        
    }while (dir!='q');  //user has selected a piece  
    
}
void Referee::movingCursor()
{
    
    string p=getCurrentPlayer();
    cout<<endl<<p<<endl;


    char dir;
    do 
    {
        b.UpdateCursorGame();
        displayGameData();
        dir= p1->userMovement(); //gets users cursor movement
        
      
        b.moveCursor(dir,p); //calls board function move cursor
         //displays the cursor movement
        
    }while (dir!='q');  //user has selected a piece    
}

void Referee::play()
{
    //bool while loop while p1* or p2* less than winning score
    bool winnerP1 = p1Score<6; 
    bool winnerP2 = p2Score<6;
    string player;

    movingInitially();

    while(winnerP1 == true || winnerP2 == true)

    {
        
        player = getCurrentPlayer(); //player one plays first
        
        char obj = b.getSymbol();

        //cout<<"\n\n"<<player<<endl<<obj<<endl<<endl; works shows player one and object selected

        bool test = checkPiece(obj); //make sure user selects correct piece 
        
    
        while(test == false)
        {
            
            if(currentPlayer=="player one")
                cout<<"\nIncorrect piece.\nSelect O or @\n";
            else if(currentPlayer=="player two")
                cout<<"\nIncorrect piece.\nSelect X or #\n";
            movingCursor();
            obj = b.getSymbol();
            test = checkPiece(obj);
        }

       

 
        int n=0;

        moves=randomizeMoves();//random num for private moves value
      
       
        int gameMoves=moves;

        cout<<"\nYou have: "<<gameMoves<<" to make in this turn."<<endl;
        
    
    
        while(n<gameMoves)
        {
            
            
            if((obj =='X' || obj == 'O'))
            {
               
                b.foundChickapigPiece(obj);
                b.UpdateGamePiece();
                moves--;
                n++;
                displayGameData();
                

            }

            else if((obj == '@' || obj == '#'))  
            { 
                b.foundHaybalePiece(obj);
                b.UpdateGamePiece();
                moves--;
                n++;
                displayGameData();
            
            }

            
        
            //check to see if piece scored 
            //if scored then exit this while loop 
            bool scored = b.checkScore(obj);

            if(scored == true)
            {
                addingPoints(player);
            
                break;
            }
            if(n>=gameMoves)
                break;
            displayGameData();
    

        
        

            //start moving cursor to find next piece
            movingCursor();
            obj=b.getSymbol();
            test=checkPiece(obj); //make sure user selects correct piece during their turns
           
            while(test == false)
            {
            
                if(currentPlayer=="player one")
                    cout<<"\nIncorrect piece.\nSelect O or @\n";
                else if(currentPlayer=="player two")
                    cout<<"\nIncorrect piece.\nSelect X or #\n";
                movingCursor();
                obj = b.getSymbol();
                test = checkPiece(obj);
            }
        }
    
        //out of turn loop
        //switch players
        player = switchPlayers(player);
        turn++;
        displayGameData();
        movingCursor();

    }
    

    
   
}
