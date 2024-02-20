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
    ball = new Ball("Ball");
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
    //if (InputMgr::GetMouseButtonDown Left)
    //{

    //}
}
