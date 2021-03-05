#include "shotManager.h"
#include "shot.h"

ShotManager::ShotManager(SceneBase* scene) :GameObject(scene)
{
	shots.clear();
}

ShotManager::~ShotManager()
{
	for (auto it = shots.begin(); it != shots.end();) {
		delete (*it);
		it = shots.erase(it);
	}
	shots.clear();
	
}

void ShotManager::Update()
{

	for (auto it = shots.begin(); it != shots.end();) {
		(*it)->Update();
		if ((*it)->IsDestroy()) { // íœ‚ª—v‹‚³‚ê‚½‚Ì‚Å
			delete (*it);
			it = shots.erase(it);
		}
		else
			it++;
	}
}

void ShotManager::Draw()
{
	for (auto b : shots)
		b->Draw();
}

void ShotManager::Create(VECTOR pos, VECTOR vel)
{
	Shot* bullet = new Shot(GetScene(), pos, vel);
	if (bullet != nullptr)
		shots.emplace_back(bullet);
}
