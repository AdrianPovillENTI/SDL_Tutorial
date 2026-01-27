    #pragma once
    #include "GameObject.h"
    #include "ICollisionable.h"

    class DamageableObject : public GameObject, public ICollisionable
    {
    protected:
        int maxHealth;
        function<void ( )> onReceiveDamage;
    public:
        int health;
        DamageableObject ( const int _maxHealth ,const string path )
            : GameObject ( path ), 
            maxHealth ( _maxHealth ),
            health ( _maxHealth ) { }    
        virtual void ReceiveDamage(int damage);
        virtual void Move ( ) = 0;
        int const GetHealth ( ) const { return health; }
    };

