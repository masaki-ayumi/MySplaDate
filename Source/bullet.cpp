#include <DxLib.h>
#include "bullet.h"
#include "target.h"
#include <stdio.h>
#include "../Source/debugScreen.h"

Bullet::Bullet(SceneBase* scene, VECTOR pos, VECTOR vel) :GameObject(scene)
{
	int ir = rand() % 20 - 10;//-2～2までの乱数生成
	//ir = ir * 1.3;
	//double dbl = 10.0;
	//double fr;
	//fr = (double)ir % dbl;
	//position = VAdd(pos,VGet(GetRand(3),20.0f,10.0f));//弾の発射原点の位置
	//position = VAdd(pos, VGet(ir, 10.0f, 10.0f));//弾の発射原点の位置

	DebugSetColor(0, 0, 0);
	DebugPrintf(0, 300, "弾発射原点X:%f,Y:%f,Z:%f", pos.x, pos.y, pos.z);


	position = VAdd(pos, VGet(ir, 0.0f, 0.0f));//弾の発射原点の位置
	velocity = vel;//弾の移動値を代入
	playerPosition = pos;//自機の座標を代入
	rotation = VGet(0, 0, 0);//角度の初期化
	vector = VGet(0, 0, 0);//弾のベクトルの初期化
	//自機の座標と弾の座標を引いてベクトルを取得
	vector = VSub(position, playerPosition);
	//ベクトルの正規化
	//vector = VNorm(vector);

	//マウスの座標を取得
	GetMousePoint(&Mx, &My);
	float Near = 10.0f;
	float Far = 500.0f;
	SetCameraNearFar(Near, Far);

	//マウスポインタがある画面座標をワールド座標に変換して代入
	worldPos = ConvScreenPosToWorldPos(VGet(Mx, My, 1.0f));
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	int count = 0;
	count++;
	//MATRIX rotationY = MGetRotY(rotation.y);
	//isShot = false;
	//if (GetMouseInput()&MOUSE_INPUT_LEFT)
	//{
	//	isShot = true;
	//	velocity.z += 10.0f;
	//}
	//position = VAdd(position, velocity);
	//position.z += velocity.z;
	//if (count >= 1000) {
	//	count = 0;
	//	DestroyMe();
	//}
	//position = VAdd(position, vector);

	//ワールド座標のベクトルの正規化
	vector = VNorm(worldPos);

	

	//前進処理
	position.x += vector.x*velocity.x;
	position.y += vector.y*velocity.y;
	position.z += vector.z*velocity.z;

#if 0


	position.x += vector.x * 10;
	position.z += vector.z * 10;
#endif // 0
	//position.z += Nvector.z;

	//障害物と弾の当たり判定
	Target* target = GetScene()->FindGameObject<Target>();
	float r = 5.0f;
	if (target->CollisionSphere(position, r))
	{
		DestroyMe();
	}
}

void Bullet::Draw()
{
	
	//if (isShot)
		//DrawSphere3D(VAdd(position, velocity), 10, 16, GetColor(255, 0, 0), GetColor(255, 0, 0), true);
	DrawSphere3D(position, 1, 16, GetColor(240, 30, 112), GetColor(240, 30, 112), true);
	
	//DrawLine3D(playerPosition, worldPos, GetColor(255, 255, 0));
}

//void Bullet::SetPosition(VECTOR _position)
//{
//	position = VAdd(_position, VGet(0, 10.0f, 10.0f));
//
//
//}
