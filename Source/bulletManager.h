#pragma once
#include <list>
#include "../Library/gameObject.h"

class Bullet;

class BulletManager : public GameObject
{
public:
	BulletManager(SceneBase* scene);
	~BulletManager();
	void Update();
	void Draw();
	void Create(VECTOR pos, VECTOR vel);
private:
	std::list<Bullet*> bullets;
};