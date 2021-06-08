#include "playScene.h"
#include "../Library/sceneManager.h"
#include "DebugScreen.h"
#include "Axis.h"
#include "camera.h"
#include "player.h"
#include "field.h"
#include "weapon.h"
#include "shotManager.h"
#include "target.h"
#include "aim.h"


PlayScene::PlayScene()
{
	CreateGameObject<Axis>();
	CreateGameObject<Player>();
	Camera*pCamera = CreateGameObject<Camera>();
	SetDrawOrder(pCamera, 1);
	CreateGameObject<Field>();
	CreateGameObject<Weapon>();
	CreateGameObject<ShotManager>();
	CreateGameObject<Target>();
	Aim*pAim = CreateGameObject<Aim>();
	SetDrawOrder(pAim, 100);
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

	DrawString(0, 0, "PLAY SCENE", GetColor(0, 0, 0));

	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
	
	
	DrawString(10, 100, "操作説明", GetColor(0, 0, 0));
	DrawString(10, 120, "照準操作:マウス", GetColor(0, 0, 0));
	DrawString(10, 140, "ショット発射:マウス左クリック", GetColor(0, 0, 0));
	DrawString(10, 160, "プレイヤー操作:Wキー前進、Sキー後退、Aキー左旋回、Dキー右旋回", GetColor(0, 0, 0));
	DrawString(10, 180, "ショット発射時、平行移動", GetColor(0, 0, 0));
	
	
}
