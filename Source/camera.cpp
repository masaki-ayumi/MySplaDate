#include "camera.h"
#include "../Source/debugScreen.h"

Camera::Camera(SceneBase * scene) : GameObject(scene)
{
	position	= VGet(0, 0, 0);
	rotation	= VGet(0, 0, 0);
	target		= VGet(0, 0, 0);
}

Camera::~Camera()
{
}

void Camera::Update()
{
}

void Camera::Draw()
{
	//Ž©‹@‚ÌŒã‚ë‚ÉŒÅ’è
	SetCameraPositionAndTarget_UpVecY(position, target);
}
