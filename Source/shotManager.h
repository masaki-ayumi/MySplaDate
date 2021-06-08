#pragma once
#include <list>
#include "../Library/gameObject.h"
/// <summary>
/// ショットを管理するクラス
/// </summary>
class Shot;

class ShotManager : public GameObject
{
public:
	ShotManager(SceneBase* scene);
	~ShotManager();
	void Update();
	void Draw();
	void Create(VECTOR pos, VECTOR vel);
private:
	std::list<Shot*> shots;
};