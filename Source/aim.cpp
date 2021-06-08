#include "aim.h"
#include "config.h"

Aim::Aim(SceneBase * scene)
{
	//照準用画像の読み込み
	aimGraph = LoadGraph("data\\graph\\aim.png");
	//マウスの位置を画面中央付近に固定
	SetMousePoint(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100);
	//マウス非表示
	SetMouseDispFlag(false);
}

Aim::~Aim()
{
	DeleteGraph(aimGraph);
}

void Aim::Update()
{
	//照準画像の座標をマウス座標の下に設定
	GetMousePoint(&mouseX, &mouseY);
	graphX = mouseX - GRAPH_HALF;
	graphY = mouseY - GRAPH_HALF + 100;
}

void Aim::Draw()
{
	DrawGraph(graphX, graphY, aimGraph, true);
}
