#pragma once
#include "../Library/gameObject.h"
/// <summary>
/// ƒ[ƒ‹ƒhÀ•W²‚Ì‚­‚ç‚·
/// </summary>
class Axis :public GameObject
{
public:
	Axis(SceneBase* scene) :GameObject(scene){}
	~Axis(){}
	void Draw() override;

};