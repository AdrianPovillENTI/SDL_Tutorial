#pragma once
#include "../DamageableObject.h"
#include "../Patterns/Pattern.h"
#include "../Player.h"
#define EXIT_P pattern->GetExitPattern()
#define UPDATE_P pattern->GetMovementPattern()

class Enemy : public DamageableObject
{
    enum EnemyState
    {
        ON_ENTER, ON_UPDATE, ON_EXIT
    };
protected:
    float speed;
    int damage;
    bool isDeath;
    EnemyBehaviourPattern* pattern;
    EnemyState state;

    float timeElapsed;
public:

    Enemy ( float speed, int health, int _damage , string path, EnemyBehaviourPattern * _movePattern )
        :DamageableObject(health,path), damage (_damage), speed ( speed ) , isDeath ( false ) ,
        pattern ( _movePattern )
    {
        timeElapsed = 0;
    }
    ~Enemy ( );

    void Start ( ) override;
    void Update ( ) override;
    void OnCollision ( Object * collided ) override;
    void Move ( ) override;
};

