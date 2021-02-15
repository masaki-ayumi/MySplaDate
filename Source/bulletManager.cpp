#include "bulletManager.h"
#include "bullet.h"

BulletManager::BulletManager(SceneBase* scene) :GameObject(scene)
{
	bullets.clear();
}

BulletManager::~BulletManager()
{
	for (auto it = bullets.begin(); it != bullets.end();) {
		delete (*it);
		it = bullets.erase(it);
	}
	bullets.clear();
}

void BulletManager::Update()
{

	for (auto it = bullets.begin(); it != bullets.end();) {
		(*it)->Update();
		if ((*it)->IsDestroy()) { // íœ‚ª—v‹‚³‚ê‚½‚Ì‚Å
			delete (*it);
			it = bullets.erase(it);
		}
		else
			it++;
	}
}

void BulletManager::Draw()
{
	for (auto b : bullets)
		b->Draw();
}

void BulletManager::Create(VECTOR pos, VECTOR vel)
{
	Bullet* bullet = new Bullet(GetScene(), pos, vel);
	if (bullet != nullptr)
		bullets.emplace_back(bullet);
}
