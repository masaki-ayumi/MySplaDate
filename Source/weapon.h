#pragma once
#include "../Library/gameObject.h"
/// <summary>
/// 武器のクラス
/// </summary>
class Weapon :public GameObject
{
public:
	Weapon(SceneBase*scene);
	~Weapon();
	void Update();
	void Draw();
	//プレイヤーの頭上に座標をセット
	void SetPlayerPosition(VECTOR _position) { position = VAdd(_position, VGet(0, 20.0f, 0.0f)); }
	//プレイヤーの回転行列を取得
	void SetPlayerMatrix(MATRIX _rotationY) { mRotationY = _rotationY; }
	VECTOR position;
private:
	int hModel;
	VECTOR rotation;
	VECTOR velocity;
	MATRIX mRotationY;//回転行列
};