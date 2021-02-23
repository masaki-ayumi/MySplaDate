#include "aim.h"

Aim::Aim(SceneBase * scene)
{
	aimGraph = LoadGraph("data\\graph\\aim.png");
}

Aim::~Aim()
{
	DeleteGraph(aimGraph);
}

void Aim::Update()
{
}

void Aim::Draw()
{
	DrawGraph(400, 300, aimGraph, true);
}
