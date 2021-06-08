#include "weapon.h"
#include <DxLib.h>
#include <assert.h>

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

}

void Weapon::Draw()
{
	MATRIX matrix;
	//ˆÚ“®s—ñ
	MATRIX mTranslate = MGetTranslate(position);
	//‰ñ“]‚µ‚Ä‚©‚çˆÚ“®
	matrix = MMult(mRotationY, mTranslate);

	MV1SetMatrix(hModel, matrix);
	MV1DrawModel(hModel);
}
