#include <DxLib.h>
#include "shot.h"
#include "target.h"
#include <stdio.h>
#include "../Source/debugScreen.h"

Shot::Shot(SceneBase* scene, VECTOR pos, VECTOR vel) :GameObject(scene)
{
	position		= pos;//弾の発射原点の位置
	velocity		= vel;//弾の移動値を代入
	playerPosition	= pos;//プレイヤーの座標を代入
	rotation		= VGet(0, 0, 0);//角度の初期化
	vector			= VGet(0, 0, 0);//弾のベクトルの初期化
	int ir			=GetRandom(40);//乱数の取得


	//マウスの座標を取得
	GetMousePoint(&Mx, &My);
	//マウスポインタがある画面座標をワールド座標に変換して代入
	worldPos = ConvScreenPosToWorldPos(VGet(Mx+ir, My, 1.0f));


	//プレイヤーの座標とマウスのワールド座標を引いて弾のベクトルを取得
	vector = VSub(worldPos, playerPosition);
}

Shot::~Shot()
{

}

void Shot::Update()
{
	//弾のベクトルの正規化
	vector = VNorm(vector);


	//前進処理
	position.x += vector.x*velocity.x;
	position.y += vector.y*velocity.y;
	position.z += vector.z*velocity.z;
	

	//障害物と弾の当たり判定
	Target* target = GetScene()->FindGameObject<Target>();
	float r = 5.0f;
	if (target->CollisionSphere(position, r))
	{
		DestroyMe();
	}
}

void Shot::Draw()
{
	DrawSphere3D(position, 1, 16, GetColor(240, 30, 112), GetColor(240, 30, 112), true);
}

