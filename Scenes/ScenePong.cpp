#include "pch.h"
#include "ScenePong.h"
#include "Bat.h"
#include "Ball.h"

ScenePong::ScenePong(SceneIds id) : Scene(id)
{
}

ScenePong::~ScenePong()
{
}

void ScenePong::Init()
{
    //Scene::Init();
    bat = new Bat("bat");
    AddGo(bat);
    ball = new Ball(*bat, { { 0.f, 0.f }, { 1920.f, 1080.f } }, "ball");
    AddGo(ball);
    

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

    if (!(ball->isBallActive))
    {
        sf::Vector2f batPos = bat->shape.getPosition();
        ball->shape.setPosition(batPos);
    }
}
