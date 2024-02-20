#pragma once
#include "Scene.h"

class Bat;
class Ball;
class UiScore;


class ScenePong :
    public Scene
{
protected:
	Bat* bat = nullptr;
	Ball* ball = nullptr;
	UiScore* score = nullptr;

public:
	ScenePong(SceneIds id);
	virtual ~ScenePong();

	void Init() override;
	void Release() override;

	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
};

