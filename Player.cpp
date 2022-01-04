#include "Player.h"

using namespace std;

Player::Player(string n)
{
    name = n;
    score =0;
    movement =' ';
    roll_number =0;
   
}
Player::Player()
{
    name = " ";
    score =0;
    movement =' ';
    roll_number =0;
    
}
Player::~Player()
{
    //destructor
}
void Player::operator++()
{
    score++;
    
}
bool Player::operator<(int wScore)
{
    wScore=6;

    return score < wScore;
}
int Player::getScore()
{
    return score;
}

void Player::setName(string n)
{
    name =n;
    score =0;
}

char Player::userMovement()
{
    cout<<"Select Piece (a,d,w,s) then (q): ";
    cin>>movement;

    return movement;
}