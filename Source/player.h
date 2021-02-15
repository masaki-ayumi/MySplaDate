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
	int hModel;//モデルのハンドラー
	VECTOR position;//プレイヤーの座標
	VECTOR rotation;//プレイヤーの向き
};