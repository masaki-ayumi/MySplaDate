#pragma once
#include "../Library/gameObject.h"

class Weapon :public GameObject
{
public:
	Weapon(SceneBase*scene);
	~Weapon();
	void Update();
	void Draw();
	void SetPlayerPosition(VECTOR _position);//プレイヤーの座標を入れる
private:
	bool isShot = false;//プレイヤーが弾を撃ったらtrue
	int hModel;
	VECTOR position;
	VECTOR rotation;
	VECTOR velocity;
};