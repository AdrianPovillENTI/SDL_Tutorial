#pragma once
#include "Item.h"
class ForceField : public Item
{
private:
    int points;
public:
    ForceField ( ) : Item ( "resources/ForceField.png" ) , points ( 1000 ) { }

    int GetPoints() const { return points; }
};

