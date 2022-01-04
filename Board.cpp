#include "Board.h"

using namespace std;



Board::Board()
{
    for(int i=0; i<14; i++)
    {
        for(int j=0; j<15;j++)
        {
            game[i][j]=' ';
        }
    }

    cursorCol=5;
    cursorRow=5;
    symbol=' ';
    pieceCol=0;
    pieceRow=0;
    scored=false;

}
Board::~Board()
{
    
}
void Board::setSymbol(char s)
{
    
    symbol = s;
}
char Board::getSymbol()
{
    return symbol;
}

 

void Board::setGame()
{
    
    
    for(int i=0; i<14; i++)
    {
        
        for(int j=0; j<15;j++)
        {
            
            game[i][j]=' ';
            
        }
        
    }

}

void Board::setCursor()
{
    
    cursorCol = 5;
    cursorRow = 5;
}

int Board::getCursorRow()
{
    return cursorRow;
}
int Board::getCursorCol()
{
    return cursorCol;
}


void Board::setPieces()
{
    //loop piece row < 14 etc
    for(int pieceRow=0; pieceRow<14;pieceRow++)
    {
        for(int pieceCol=0; pieceCol<13;pieceCol++)
        {
            if(pieceRow==0&&pieceCol<=5)
            {
                pieceCol++;
                
                game[pieceRow][pieceCol]='X';
                

                
            }
            if(pieceRow==0&&pieceCol>6)
            {
                pieceCol++;
                game[pieceRow][pieceCol]='X';
                
            }
            
            if(pieceRow==1&&pieceCol<=8)
            {
                pieceCol+=5;
                game[pieceRow][pieceCol]='#';
                
                pieceCol+=3;
                game[pieceRow][pieceCol]='#';
                

            }
            if(pieceRow==10&&pieceCol<=8)
            {
                pieceCol+=5;
                game[pieceRow][pieceCol]='#';
                
                pieceCol+=3;
                game[pieceRow][pieceCol]='#';
                

            }
            

            if(pieceRow==13&&pieceCol<=5)
            {
                pieceCol++;
                
                game[pieceRow][pieceCol]='O';
                

                
            }
            if(pieceRow==13&&pieceCol>6)
            {
                pieceCol++;
                game[pieceRow][pieceCol]='O';
                
            }

            if(pieceRow==12&&pieceCol<=8)
            {
                pieceCol+=5;
                game[pieceRow][pieceCol]='@';
                
                pieceCol+=3;
                game[pieceRow][pieceCol]='@';
                

            }
            if(pieceRow==3&&pieceCol<=8)
            {
                pieceCol+=5;
                game[pieceRow][pieceCol]='@';
                
                pieceCol+=3;
                game[pieceRow][pieceCol]='@';

            }

        }
    }
}


void Board::updatePiece(int r, int c)
{
    pieceCol=c;
    pieceRow=r;

    
}

bool Board::checkScore(char symbol)
{
    //pass in symbol for correct piece scoring
    //if and else if for all possible scoring coords

    //updates private bool if scored 

    //pass in the name of player to match the correct piece 

    scored=false;
    // check to see if game board coords are in a winning space
    if(symbol=='O'||symbol=='@')
    {
        if(game[pieceRow][pieceCol] == game[0][6])
        { 
        
        //clear the space where the score piece was
            game[pieceRow][pieceCol]=' ';

            scored = true;
    
        }
    
        else if(game[pieceRow][pieceCol] == game[0][7])
        { 
        
        //clear the space where the score piece was
        game[pieceRow][pieceCol]=' ';

        scored = true;
    
        }
    }
    if(symbol=='X'||symbol=='#')
    {  
        if(game[pieceRow][pieceCol] == game[13][6])
        { 
        
        //clear the space where the score piece was
            game[pieceRow][pieceCol]=' ';

            scored = true;
    
        }
    
        else if(game[pieceRow][pieceCol] == game[13][7])
        { 
        
        //clear the space where the score piece was
        game[pieceRow][pieceCol]=' ';

        scored = true;
        }
    
    }


    return scored;

}

bool Board::getScore()
{
    return scored;
}

bool Board::movePiece(char move)
{
    //piece has been selected user previously entered q
    //altering the privates piece col and piece row to translate/move pieces
    

    //chickapig moves until obstacle found 
    bool valid=false;

       if(move=='a') //left
        {
            if(pieceCol>0&&(game[pieceRow][pieceCol-1]==' ')) //left
            {
                pieceCol--;
                cursorCol--;
                valid=true;
            }
            else
                cout<<"\nEnd of the board. Enter new direction.\n";
            
        }
        if(move=='d'&&(game[pieceRow][pieceCol+1]==' ')) //right
        {
            if(pieceCol<13)
            {
                pieceCol++;
                cursorCol++;
                valid=true;
            }

            else
                cout<<"\nEnd of the board. Enter new direction.\n";
            
        }
        if(move=='s'&&(game[pieceRow+1][pieceCol]==' ')) //down
        {
            if(pieceRow<13)
            {
                pieceRow++;
                cursorRow++;
                valid=true;
                
            }
            else
                cout<<"\nEnd of the board. Enter new direction.\n";
            
        }
        if(move=='w'&&(game[pieceRow-1][pieceCol]==' ')) //up
        { 
            if(pieceRow>0)
            {
                pieceRow--;
                cursorRow--;
                valid=true;
            }
            else
                cout<<"\nEnd of the board. Enter new direction.\n";
           
        }

    return valid;
}



void Board::foundChickapigPiece(char symbol)
{
    //not stopping if piece in front of it 
    //make a valid function to test 
    char s=symbol;


    //moves the coords of piece row and piece col
    //check to see if its a haybale or chicapig to determine movements

    char move;
    cout<<"Enter a = left, d = right, s = down, w = up, or q to quit turn : ";
    cin>>move;

    bool clear=true; //clear path for piece to move assuming piece can move initially

    while(clear!=false)
    {
        clear= movePiece(move);
    }
    game[pieceRow][pieceCol]=symbol;
        
    
    
    checkScore(s);
    

    
    
    

}

void Board::foundHaybalePiece(char symbol)
{
    
    char s = symbol;

    char move;
    cout<<"Enter a = left, d = right, s = down, w = up, or q to end turn: ";
    cin>>move;

    //clear path for piece to move assuming piece can move initially
        
    //only moves one
    if(move!='q')
        movePiece(move);
        


    game[pieceRow][pieceCol]=symbol;

    checkScore(s);
}







void Board::moveCursor(char direction,string player)
{
    
    cout<<cursorCol<<endl;
    if(direction=='a')
    {
        if(cursorCol!=0)
            cursorCol--;
        else
            cout<<"End of the board. Enter new direction.\n";
        cout<<cursorCol<<endl;
    }
    if(direction=='d')
    {
        if(cursorCol!=12)
            cursorCol++;

        else
            cout<<"End of the board. Enter new direction.\n";
        cout<<cursorCol<<endl;
    }
    if(direction=='s')
    {
        if(cursorRow!=13)
            cursorRow++;
        else
            cout<<"End of the board. Enter new direction.\n";
        cout<<cursorRow<<endl;
    }
    if(direction=='w')
    {
        if(cursorRow!=0)
            cursorRow--;
        else
            cout<<"End of the board. Enter new direction.\n";
        cout<<cursorRow<<endl;
    }


    char symbol;
    
   
    if(direction=='q') //piece has been selected 
    {
        if((game[cursorRow][cursorCol]=='X')&&(player=="player two"))
        {
            symbol='X';
            setSymbol(symbol);
            
            updatePiece(cursorRow, cursorCol); //pass in coords of piece to update found coords of piece
            game[pieceRow][pieceCol]=' '; //fill current game coord with empty space, old pos of piece
        }
        if((game[cursorRow][cursorCol]=='O')&&(player=="player one"))
        {
            symbol='O';
            setSymbol(symbol);
          
            updatePiece(cursorRow, cursorCol); //pass in coords of piece to update found coords of piece
            game[pieceRow][pieceCol]=' '; //fill current game coord with empty space, old pos of piece
         
        }
        if((game[cursorRow][cursorCol]=='@')&&(player=="player one"))
        {
            symbol='@';
            setSymbol(symbol);
           
            updatePiece(cursorRow, cursorCol); //pass in coords of piece to update found coords of piece
            game[pieceRow][pieceCol]=' '; //fill current game coord with empty space, old pos of piece
            
        }
        if((game[cursorRow][cursorCol]=='#')&&(player=="player two"))
        {
            symbol='#';
            setSymbol(symbol);
           
            updatePiece(cursorRow, cursorCol); //pass in coords of piece to update found coords of piece
            game[pieceRow][pieceCol]=' '; //fill current game coord with empty space, old pos of piece
        
        }
            
        
    }

}


void Board::UpdateCursorGame()
{
    

    int num=0;
   
    cout<<setw(14)<<' '<<"|   |"<<endl;
    cout<<"  "<<setfill('_')<<setw(28)<<' ';
        cout<<setfill(' ')<<" "<<endl;
    for(int i=0; i<14; i++)
    {
        cout<<setw(2)<<right<<num;
        
        for(int j=0; j<15; j++)
        {
            
            
           
            if(i==cursorRow && j==cursorCol)
            {
                    
                    cout<<"{"<<game[i][j]<<"}";
                    j++;
                    
                      
            }   
            else if(j<=15)
                cout<<'|';
            cout<<game[i][j];
            
            
            
            
        
            
            
            
            
        }
        num++;
        cout<<endl;
        cout<<"  "<<setfill('_')<<setw(30)<<' ';
        cout<<setfill(' ')<<" ";
        cout<<endl;
    }
    cout<<setw(14)<<' '<<"|   |"<<endl;

}

void Board::UpdateGamePiece()
{
    int num=0;

   

    cout<<setw(14)<<' '<<"|   |"<<endl;
    cout<<"  "<<setfill('_')<<setw(28)<<' ';
        cout<<setfill(' ')<<" "<<endl;
    for(int i=0; i<14; i++)
    {
        cout<<setw(2)<<right<<num;
        
        for(int j=0; j<15; j++)
        {
            if(i==pieceRow && j==pieceCol)
            {
                cout<<'|';
                cout<<game[pieceRow][pieceCol];
                continue;
                
                       
            } 
            if(j<=15)
                cout<<'|';
            
            
            cout<<game[i][j];
        
            
            
            
            
        }
        num++;
        cout<<endl;
        cout<<"  "<<setfill('_')<<setw(30)<<' ';
        cout<<setfill(' ')<<" ";
        cout<<endl;
    }
    cout<<setw(14)<<' '<<"|   |"<<endl;
    UpdateCursorGame();

}