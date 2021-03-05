#pragma once
#include "../Library/gameObject.h"

class Shot :public GameObject {
public:
	/// <summary>
	/// Bulletのインスタンスを作るときに自機位置と移動値を受け取る
	/// </summary>
	/// <param name="scene"></param>
	/// <param name="pos">プレイヤー位置</param>
	/// <param name="vel">移動値</param>
	Shot(SceneBase* scene,VECTOR pos,VECTOR vel);
	~Shot();
	void Update();
	void Draw();
	//-nからnまでの乱数を取得
	int GetRandom(int n) { return GetRand(2 * n) - n; };

	
	int Mx, My;//マウスのスクリーン座標
	VECTOR position;
	VECTOR rotation;
	VECTOR velocity;
	VECTOR vector;//弾の進む方向のベクトル用変数
	VECTOR worldPos;//ワールド座標用変数
	VECTOR playerPosition;//自機の座標
};