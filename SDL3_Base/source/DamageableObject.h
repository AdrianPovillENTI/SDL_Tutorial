    #pragma once
    #include "GameObject.h"
    #include "IDamageable.h"

    class DamageableObject : public GameObject, public IDamageable
    {
    protected:
        int maxHealth;
        bool isDeath;
        function<void ( )> onReceiveDamage;
    public:
        int health;
        DamageableObject ( const int _maxHealth ,const string path )
            : GameObject ( path ), 
            maxHealth ( _maxHealth ),
            health ( _maxHealth ) { }    
        virtual void ReceiveDamage ( int _health ) override
        {
            health -= _health;
            if(onReceiveDamage != nullptr) onReceiveDamage ( );
            std::cout << "Received damage: " << _health << " | Current health: " << health << std::endl;
            if ( health < 0 )
            {
                health = 0;
                isDeath = true;
            }
        }
        virtual void Move ( ) = 0;
        int const GetHealth ( ) const { return health; }
        bool IsDeath ( ) { return isDeath; }
    };

