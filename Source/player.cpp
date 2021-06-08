#include<assert.h>
#include<DxLib.h>
#include "player.h"
#include "camera.h"
#include "field.h"
#include "weapon.h"
#include "shot.h"
#include "shotManager.h"

Player::Player(SceneBase * scene) :GameObject(scene)
{
	hModel = MV1LoadModel("data\\model\\MMD用踊る猫ver1.02\\茶ブチねこ.pmx");
	assert(hModel > 0);
	int center = MV1SearchFrame(hModel, "全ての親");
	MV1SetFrameUserLocalMatrix(hModel, center, MGetRotY(DX_PI_F));

	position = VGet(0, 0, 0);
	rotation = VGet(0, 0, 0);
}

Player::~Player()
{
	MV1DeleteModel(hModel);
}

void Player::Update()
{
	isShot = false;
	if (GetMouseInput()&MOUSE_INPUT_LEFT) //弾発射
	{
		isShot = true;
		ShotManager* shotManager = GetScene()->FindGameObject<ShotManager>();
		Weapon* weapon = GetScene()->FindGameObject<Weapon>();
		//武器の座標に弾を生成
		shotManager->Create(weapon->position, VGet(10.0f, 10.0f, 10.0f));
	}

	MATRIX rotationY = MGetRotY(rotation.y);
	if (CheckHitKey(KEY_INPUT_W))//上
	{
		VECTOR velocity = VTransform(VGet(0, 0, 3.0f), rotationY);
		position = VAdd(position, velocity);
	}
	if (CheckHitKey(KEY_INPUT_S))//下
	{
		VECTOR velocity = VTransform(VGet(0, 0, -3.0f), rotationY);
		position = VAdd(position, velocity);
	}

	//移動の状態遷移
	switch (isShot)//弾を発射しているか
	{
	case true://弾を発射しているとき平行移動
		TranslateMove(rotationY);
		break;
	case false://弾を発射していないとき回転する移動
		RotationMove();
		break;
	}




	VECTOR upper = VAdd(position, VGet(0, 1000, 0));//10m上
	VECTOR lower = VAdd(position, VGet(0, -1000, 0));//10m下
	VECTOR hit;

	//地形との当たり判定
	Field* pF = GetScene()->FindGameObject<Field>();
	if (pF->CollisionLine(&hit, upper, lower))
	{
		position = hit;
	}

	//カメラをプレイヤーの後ろに固定
	Camera* pCamera	= GetScene()->FindGameObject<Camera>();
	VECTOR cTarget = VTransform(VGet(0, 0, 100.0f), rotationY);
	pCamera->SetTarget(VAdd(position, cTarget));
	VECTOR cPosition = VTransform(VGet(0, 40.0f, -70.0f), rotationY);
	pCamera->SetPosition(VAdd(position, cPosition));

	//武器にプレイヤーの座標を渡す
	Weapon* pWeapon = GetScene()->FindGameObject<Weapon>();
	pWeapon->SetPlayerPosition(position);

}

void Player::Draw()
{
	MATRIX matrix;
	//移動行列
	MATRIX mTranslate = MGetTranslate(position);
	//回転行列
	MATRIX mRotationY = MGetRotY(rotation.y);
	//回転してから移動
	matrix = MMult(mRotationY, mTranslate);

	Weapon* weapon = GetScene()->FindGameObject<Weapon>();
	//プレイヤーの回転行列を渡す
	weapon->SetPlayerMatrix(mRotationY);

	MV1SetMatrix(hModel, matrix);
	MV1DrawModel(hModel);
}


//平行移動の関数
void Player::TranslateMove(MATRIX rotationY)
{
	if (CheckHitKey(KEY_INPUT_D))//右
	{
		VECTOR velocity = VTransform(VGet(3.0f, 0, 0), rotationY);
		position = VAdd(position, velocity);
	}
	if (CheckHitKey(KEY_INPUT_A))//左
	{
		VECTOR velocity = VTransform(VGet(-3.0f, 0, 0), rotationY);
		position = VAdd(position, velocity);
	}
}


//回転をする移動の関数
void Player::RotationMove()
{
	if (CheckHitKey(KEY_INPUT_D))//右
	{
		rotation.y += 3.0*DX_PI_F / 180.0f;//旋回
	}
	if (CheckHitKey(KEY_INPUT_A))//左
	{
		rotation.y -= 3.0*DX_PI_F / 180.0f;
	}
}
