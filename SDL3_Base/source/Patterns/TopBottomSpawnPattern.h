#pragma once
#include "SpawnPattern.h"

class TopBottomSpawnPattern : public SpawnPattern
{
private:
    float _verticalSeparation;
    float _horizontalSpacing;

public:
    TopBottomSpawnPattern ( float verticalSeparation = 100.f , float horizontalSpacing = 100.f )
        : _verticalSeparation ( verticalSeparation ) ,
        _horizontalSpacing ( horizontalSpacing )
    {
    }

    std::vector<Vector2> GetSpawnPositions ( const Vector2 & origin , int count ) const override
    {
        std::vector<Vector2> res;
        res.reserve ( count );

        int half = count / 2;
        bool odd = ( count % 2 != 0 );

        // --- Línea superior ---
        for ( int i = 0; i < half; ++i )
        {
            res.push_back (
                origin +
                Vector2 ( _horizontalSpacing * i , -_verticalSeparation )
            );
        }
        if ( odd )
        {
            res.push_back ( origin );
        }
        for ( int i = 0; i < half; ++i )
        {
            res.push_back (
                origin +
                Vector2 ( _horizontalSpacing * i , _verticalSeparation )
            );
        }

        return res;
    }
};