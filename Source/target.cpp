#include <assert.h>
#include "target.h"
#include "field.h"

Target::Target(SceneBase * scene) :GameObject(scene)
{
	hModel = MV1LoadModel("data\\model\\MMDópóxÇÈîLver1.02\\äDîíÇÀÇ±.pmx");
	assert(hModel > 0);
	position = VGet(0, 0, 100.0f);
}

Target::~Target()
{
	MV1DeleteModel(hModel);
}

void Target::Update()
{
	VECTOR upper = VAdd(position, VGet(0, 1000, 0));//10mè„
	VECTOR lower = VAdd(position, VGet(0, -1000, 0));//10mâ∫
	VECTOR hit;

	//ínå`Ç∆ÇÃìñÇΩÇËîªíË
	Field* field = GetScene()->FindGameObject<Field>();
	if (field->CollisionLine(&hit, upper, lower))
	{
		position = hit;
	}
}

void Target::Draw()
{
	MV1SetPosition(hModel, position);
	MV1DrawModel(hModel);
}

bool Target::CollisionSphere(VECTOR CenterPos, float r)
{
	//ãÖèÛÇÃìñÇΩÇËîªíË
	MV1_COLL_RESULT_POLY_DIM collision = MV1CollCheck_Sphere(hModel, -1, CenterPos, r);
	if (collision.HitNum == 0)
		return false;
	MV1DeleteModel(hModel);
	return true;
}
