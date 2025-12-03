#pragma once
#include "Item.h"
class Score : public Item
{
private:
    int points;
public:
    Score ( ) : Item ( "resources/Score.png" ) , points ( 1000 ) { }
    int GetScore ( ) { return points; }
};

