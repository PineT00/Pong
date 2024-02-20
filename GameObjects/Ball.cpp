#include "pch.h"
#include "Ball.h"
#include "Bat.h"

Ball::Ball(const std::string& name)
    :GameObject(name)
{
}

void Ball::Init()
{
    shape.setRadius(10.f);
    shape.setPosition({ 1920.f / 2.f, 1080.f - 70.f });
    shape.setFillColor(sf::Color::White);

    Utils::SetOrigin(shape, Origins::BC);

    const sf::FloatRect& ballBounds = shape.getGlobalBounds();
    float ballLeft = ballBounds.left;
    float ballRight = ballBounds.left + ballBounds.width;
    float ballTop = ballBounds.top;
    float ballBottom = ballBounds.top + ballBounds.height;

    float windowLeft = windowBounds.left;
    float windowRight = windowBounds.left + windowBounds.width;
    float windowTop = windowBounds.top;
    float windowBottom = windowBounds.top + windowBounds.height;
}

void Ball::Release()
{
}

void Ball::Reset()
{
}

void Ball::Fire(sf::Vector2f d, float s)
{
    direction = d;
    speed = s; 
}

void Ball::Update(float dt)
{
    if (InputMgr::GetKeyDown(sf::Keyboard::Space))
    {
        Fire({ -1.f, -1.f }, 500.f);
    }

    const sf::FloatRect& prevBallBounds = shape.getGlobalBounds();
    sf::Vector2f prevPos = shape.getPosition();
    sf::Vector2f pos = prevPos;
    pos += direction * speed * dt;
    shape.setPosition(pos);
}

void Ball::Draw(sf::RenderWindow& window)
{
}
