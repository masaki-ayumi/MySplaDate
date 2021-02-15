#pragma once
#include "../Library/gameObject.h"

class Bullet :public GameObject {
public:
	/// <summary>
	/// Bulletのインスタンスを作るときに自機位置と移動値を受け取る
	/// </summary>
	/// <param name="scene"></param>
	/// <param name="pos">自機位置</param>
	/// <param name="vel">移動値</param>
	Bullet(SceneBase* scene,VECTOR pos,VECTOR vel);
	~Bullet();
	void Update();
	void Draw();
	//void SetPosition(VECTOR _position);

	
	bool isShot = false;
	int Mx, My;//マウスのスクリーン座標
	float shotspeed = 8.0f;
	VECTOR position;
	VECTOR rotation;
	VECTOR velocity;
	VECTOR vector;//弾の進む方向のベクトル用変数
	VECTOR worldPos;//ワールド座標用変数
	VECTOR playerPosition;//自機の座標
};