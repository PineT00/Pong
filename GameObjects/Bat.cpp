#include "pch.h"
#include "Bat.h"

Bat::Bat(const std::string& name)
    :GameObject(name)
{
}

void Bat::Init()
{
    //GameObject::Init();
    shape.setSize({ 100.f, 5.f });
    shape.setPosition({ 1920.f / 2.f, 1080.f - 50.f });
    shape.setFillColor(sf::Color::White);
    Utils::SetOrigin(shape, Origins::TC);
}

void Bat::Release()
{
    GameObject::Release();
}

void Bat::Reset()
{
    GameObject::Reset();
}

void Bat::PlayerMove(float dt)
{
    float h = InputMgr::GetAxis(Axis::Horizontal);
    
    sf::Vector2f pos = shape.getPosition();
    pos.x += h * speed * dt;
    shape.setPosition(pos);
}

void Bat::Update(float dt)
{
    PlayerMove(dt);
}

void Bat::Draw(sf::RenderWindow& window)
{
    window.draw(shape);
}
