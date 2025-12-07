    #pragma once
    #include "GameObject.h"
    #include "IDamageable.h"

    class DamageableObject : public GameObject, public IDamageable
    {
    protected:
        int health;
        int maxHealth;
    public:
        DamageableObject ( int _maxHealth , string bulletPath )
            : GameObject ( bulletPath ), 
            maxHealth ( _maxHealth ),
            health ( _maxHealth ) { }    
        void ReceiveDamage ( int _health ) override
        {
            health -= _health;
            if ( health < 0 ) health = 0;
        }
        virtual void Move ( ) = 0;
        int const GetHealth ( ) const { return health; }
    };

