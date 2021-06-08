#pragma once

#include "../Library/gameObject.h"

/// <summary>
/// 地形クラス
/// </summary>
class  Field : public GameObject
{
public:
	Field(SceneBase* scene);
	~Field();
	void Update() override;
	void Draw() override;

	/// <summary>
	/// レイと地形の当たり判定をする
	/// </summary>
	/// <param name="hit">当たり判定を返す</param>
	/// <param name="from">始点</param>
	/// <param name="to">終点</param>
	/// <returns>当たっていればtrueをかえす</returns>
	bool CollisionLine(VECTOR* hit, VECTOR from, VECTOR to);

private:
	int hModel;//地形のモデル
	int hSkyModel;//空のモデル
};