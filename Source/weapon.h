#pragma once
#include "../Library/gameObject.h"

class Weapon :public GameObject
{
public:
	Weapon(SceneBase*scene);
	~Weapon();
	void Update();
	void Draw();
	void SetPlayerPosition(VECTOR _position);//自機の座標を取得
	void SetPlayerMatrix(MATRIX _rotationY) { mRotationY = _rotationY; }//自機の回転行列を取得
	VECTOR position;
private:
	int hModel;
	VECTOR rotation;
	VECTOR velocity;
	MATRIX mRotationY;//回転行列
};