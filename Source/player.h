#pragma once
#include "../Library/gameObject.h"

class Player : public GameObject
{
public:
	Player(SceneBase* scene);
	~Player();
	void Update() override;
	void Draw() override;

private:
	void TranslateMove(MATRIX rotationY);//平行移動の関数
	void RotationMove(MATRIX rotationY);//回転をする移動の関数
	bool isShot = false;//自機が弾を撃ったらtrue
	int hModel;//モデルのハンドラー
	VECTOR position;//プレイヤーの座標
	VECTOR rotation;//プレイヤーの向き
};