#pragma once
#include "../Library/gameObject.h"

/// <summary>
/// 照準用クラス
/// </summary>
class Aim : public GameObject
{
public:
	Aim(SceneBase* scene);
	~Aim();
	void Update() override;
	void Draw() override;

private:
	int aimGraph;//照準用画像のハンドル
	int mouseX, mouseY;//マウス座標用変数
	int graphX, graphY;//画像の座標
	const int GRAPH_HALF = 32; //画像の半分の値
};

