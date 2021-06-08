#pragma once
#include "../Library/gameObject.h"
/// <summary>
/// 障害物のクラス
/// </summary>
class Target : public GameObject
{
public:
	Target(SceneBase* scene);
	~Target();
	void Update();
	void Draw();
	/// <summary>
	/// 弾と球体のあたり判定関数
	/// </summary>
	/// <param name="CenterPos">球体の中心座標</param>
	/// <param name="r">球体の半径</param>
	/// <returns>当たったら障害物のモデルを消す</returns>
	bool CollisionSphere(VECTOR CenterPos,float r);
private:
	int hModel;
	VECTOR position;
};