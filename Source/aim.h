#pragma once
#include "../Library/gameObject.h"

class Aim : public GameObject
{
public:
	Aim(SceneBase* scene);
	~Aim();
	void Update() override;
	void Draw() override;

private:
	int aimGraph;//照準用画像のハンドル
	
};

