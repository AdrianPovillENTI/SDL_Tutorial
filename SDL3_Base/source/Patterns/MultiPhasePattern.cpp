#include "MultiPhasePattern.h"
Vector2 MultiPhasePattern::GetDelta ( float dt , float elapsed , int index ) const
{
    float time = elapsed;

    for ( Phase phase : phases )
    {
        if ( phase.duration < 0 )
            return phase.pattern->GetDelta ( dt , time , index );
        if ( time <= phase.duration )
            return phase.pattern->GetDelta ( dt , time , index );

        time -= phase.duration;
        if ( time < 0 ) time = 0;
    }

    return phases.back ( ).pattern->GetDelta ( dt , time , index );
}
Vector2 MultiPhasePattern::GetDeltaOnCondition ( float dt , float elapsed , function<bool> change , int index ) const
{
    phaseTime += dt;
    if ( change ( ) )
    {
        currentPhase++;
        phaseTime = 0;
    }
    return phases [ currentPhase ].pattern->GetDelta ( dt , phaseTime , index );
}

