#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <time.h>

#include "Referee.h"


using namespace std;



int main()
{
    srand(time(0));


    Player p1("player one");
    Player p2("player two");

    Board b;
    Referee r(b,&p1, &p2);
    
    

    r.play();

    return 0;
}