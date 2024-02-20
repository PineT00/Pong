#include "pch.h"
#include "ScenePong.h"
#include "Bat.h"
#include "Ball.h"
#include "UiScore.h"

ScenePong::ScenePong(SceneIds id) : Scene(id)
{
}

ScenePong::~ScenePong()
{
}

void ScenePong::Init()
{
    RES_MGR_FONT.Load("fonts/DS-DIGI.ttf");
    //Scene::Init();
    bat = new Bat("bat");
    AddGo(bat);
    ball = new Ball(*bat, { { 0.f, 0.f }, { 1920.f, 1080.f } }, "ball");
    AddGo(ball);

    score = new UiScore("Ui score");
    score->Set(RES_MGR_FONT.Get("fonts/DS-DIGI.ttf"),"asdasdsa", 60, sf::Color::Cyan);
    AddGo(score);


    for (GameObject* obj : gameObjects) 
    { 
        obj->Init(); 
    }
}

void ScenePong::Release()
{
    Scene::Release();
}

void ScenePong::Enter()
{
    Scene::Enter();
}

void ScenePong::Exit()
{
    Scene::Exit();
}

void ScenePong::Update(float dt)
{
    Scene::Update(dt);

    if (InputMgr::GetKeyDown(sf::Keyboard::Space) && !(ball->isBallActive))
    {
        ball->Fire({ -1.f, -1.f }, 500.f);
        score->Reset();
    }

    if (!(ball->isBallActive))
    {
        sf::Vector2f batPos = bat->shape.getPosition();
        ball->shape.setPosition(batPos);
    }
    if (ball->isBoundBat && ball->isBallActive)
    {
        score->AddScore(10);
    }
}
