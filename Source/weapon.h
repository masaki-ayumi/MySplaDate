#pragma once
#include "../Library/gameObject.h"

class Weapon :public GameObject
{
public:
	Weapon(SceneBase*scene);
	~Weapon();
	void Update();
	void Draw();
	void SetPlayerPosition(VECTOR _position);//©‹@‚ÌÀ•W‚ğ“ü‚ê‚é
	VECTOR position;
private:
	bool isShot = false;//©‹@‚ª’e‚ğŒ‚‚Á‚½‚çtrue
	int hModel;
	VECTOR rotation;
	VECTOR velocity;
};