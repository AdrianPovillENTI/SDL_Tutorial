#pragma once
#include "../Vector2.h"
#include <vector>
using namespace std;
struct MovementPatternData
{
    vector<Vector2> checkpoints;
public:
    MovementPatternData ( const vector<Vector2> & _checkpoints )
        : checkpoints ( _checkpoints )
    {
    }
};