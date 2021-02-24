#include "weapon.h"
#include <DxLib.h>
#include <assert.h>
#include "bullet.h"

Weapon::Weapon(SceneBase*scene) :GameObject(scene)
{
	hModel = MV1LoadModel("data\\model\\Submachine_Gun_M24_R\\M24_R_High_Poly_Version_fbx.mv1");
	assert(hModel > 0);

	int center = MV1SearchFrame(hModel, "Empty");
	MV1SetFrameUserLocalMatrix(hModel, center, MGetRotY(DX_PI_F));

	position = VGet(0, 0, 0);
	rotation = VGet(0, 0, 0);
}

Weapon::~Weapon()
{
	MV1DeleteModel(hModel);
}

void Weapon::Update()
{
	//MATRIX rotationY = MGetRotY(rotation.y);
	//isShot = false;
	//if (GetMouseInput()&MOUSE_INPUT_LEFT)
	//{
	//	isShot = true;
	//	//VECTOR velocity = VTransform(VGet(0, 0, 100.0f), rotationY);
	//	//position = VAdd(position, velocity);
	//	velocity.z += 10.0f;
	//}

}

void Weapon::Draw()
{

	MATRIX matrix;
	//移動行列
	MATRIX mTranslate = MGetTranslate(position);
	//回転行列
	//MATRIX mRotationY = MGetRotY(rotation.y);
	//回転してから移動
	matrix = MMult(mRotationY, mTranslate);



	MV1SetScale(hModel, VGet(5, 5, 5));
	//MV1SetPosition(hModel,position);
	MV1SetMatrix(hModel, matrix);
	MV1DrawModel(hModel);
		//DrawSphere3D(VGet(0, 100.0f, 0), 10, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), true);
	//if(isShot)
	//DrawSphere3D(VAdd(position,velocity), 10, 16, GetColor(255, 0, 0), GetColor(255, 0, 0), true);
}

void Weapon::SetPlayerPosition(VECTOR _position)
{
	//Bullet*pBullet = GetScene()->FindGameObject<Bullet>();
	//pBullet->SetPosition(position);

	//自機の頭上に座標をセット
	position = VAdd(_position,VGet(0,20.0f,0.0f));
	//position = _position;
}
