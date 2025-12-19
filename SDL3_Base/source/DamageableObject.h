    #pragma once
    #include "GameObject.h"
    #include "IDamageable.h"

    class DamageableObject : public GameObject, public IDamageable
    {
    protected:
        int health;
        int maxHealth;
        bool isDeath;
    public:
        DamageableObject ( const int _maxHealth ,const string path )
            : GameObject ( path ), 
            maxHealth ( _maxHealth ),
            health ( _maxHealth ) { }    
        void ReceiveDamage ( int _health ) override
        {
            health -= _health;
            if ( health < 0 )
            {
                health = 0;
                isDeath = true;
            }
        }
        virtual void Move ( ) = 0;
        int const GetHealth ( ) const { return health; }
    };

