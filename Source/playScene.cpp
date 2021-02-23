#include "playScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"
#include "Axis.h"
#include "camera.h"
#include "player.h"
#include "field.h"
#include "weapon.h"
#include "bulletManager.h"
#include "target.h"


PlayScene::PlayScene()
{
	CreateGameObject<Axis>();
	CreateGameObject<Player>();
	Camera*pCamera = CreateGameObject<Camera>();
	SetDrawOrder(pCamera, 1);
	CreateGameObject<Field>();
	CreateGameObject<Weapon>();
	CreateGameObject<BulletManager>();
	CreateGameObject<Target>();
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TitleScene");
	}

	SceneBase::Update();
}

void PlayScene::Draw()
{
	SceneBase::Draw();

	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));

	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
	
	
	
	int aimGraph;//Æ€—p‰æ‘œ‚Ìƒnƒ“ƒhƒ‹
	aimGraph = LoadGraph("data\\graph\\aim.png");
	DrawGraph(400, 300, aimGraph, true);
}
