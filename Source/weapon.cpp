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

	MV1SetScale(hModel, VGet(3, 3, 3));
	MV1SetPosition(hModel,position);
	MV1DrawModel(hModel);
		//DrawSphere3D(VGet(0, 100.0f, 0), 10, 16, GetColor(255, 255, 255), GetColor(255, 255, 255), true);
	//if(isShot)
	//DrawSphere3D(VAdd(position,velocity), 10, 16, GetColor(255, 0, 0), GetColor(255, 0, 0), true);
}

void Weapon::SetPlayerPosition(VECTOR _position)
{
	//Bullet*pBullet = GetScene()->FindGameObject<Bullet>();
	//pBullet->SetPosition(position);

	position = VAdd(_position,VGet(0,20.0f,0.0f));
	//position = _position;
}
