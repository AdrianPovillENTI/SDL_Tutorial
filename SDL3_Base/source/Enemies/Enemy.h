#pragma once
#include "../DamageableObject.h"
#include "../Patterns/Pattern.h"
#include "../Player.h"
#define EXIT_P pattern->GetExitPattern()
#define MOVE_PATTERN pattern->GetMovementPattern()
#define SC_WIDTH RM->WINDOW_WIDTH
#define SC_HEIGHT RM->GAME_WINDOW_HEIGHT
#define X _transform->position.x
#define Y _transform->position.y
class Enemy : public DamageableObject
{
protected:
    enum EnemyState
    {
        ON_ENTER, ON_UPDATE
    };
    float speed;
    int damage;
    EnemyBehaviourPattern* pattern;
    EnemyState state;
    bool playOnStart = true;
    float timeElapsed;
public:

    Enemy ( float speed, int health, int _damage , string path)
        :DamageableObject(health,path), damage (_damage), speed ( speed )
    {

        _physics->AddCollider ( new AABB ( _transform->position , _transform->size ) );
        timeElapsed = 0;
        Start ( );
    }
    Enemy ( float speed , int health , int _damage , string path , EnemyBehaviourPattern * _movePattern )
        :DamageableObject ( health , path ) , damage ( _damage ) , speed ( speed ) , pattern ( _movePattern ),
        state(ON_ENTER)
    {
        _physics->AddCollider ( new AABB ( _transform->position , _transform->size ) );       
        timeElapsed = 0;
        Start ( );
    }

    ~Enemy ( )
    {
        delete pattern;
        pattern = nullptr;
    }

    void Start ( ) override;
    void Update ( ) override;
    void OnCollision ( Object * collided ) override;
    void Move ( ) override;
    virtual bool OutOfLimits ( );
    virtual void OnEnterFunction ( );
};

