#pragma once
#include "DamageableObject.h"
#include <string>

class Bullet : public DamageableObject
{
private:
	int damage;
	float speed;

public:
	Bullet(const std::string& path = "resources/bullet.png");
	~Bullet();

	void Start() override;
	void Update() override;
	void Move() override;

	void SetDamage(int d) { damage = d; }
	int GetDamage() const { return damage; }
};