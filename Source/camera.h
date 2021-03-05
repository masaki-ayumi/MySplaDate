#pragma once
#include "../Library/gameObject.h"

class  Camera : public GameObject
{
public:
	 Camera(SceneBase*scene);
	 ~Camera();
	 void Update() override;
	 void Draw() override;
	 void SetPosition(VECTOR vec) { position = vec; }
	 void SetTarget(VECTOR trg) { target = trg; }
	VECTOR vec;
private:
	VECTOR position;
	VECTOR rotation;
	VECTOR target;
};