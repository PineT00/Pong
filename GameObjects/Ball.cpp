#include "pch.h"
#include "Ball.h"
#include "Bat.h"


Ball::Ball(Bat& b, const sf::FloatRect& bounds, const std::string name)
    : bat(b), windowBounds(bounds), GameObject(name)
{
}

void Ball::Init()
{
    shape.setRadius(10.f);
    shape.setPosition({ 1920.f / 2.f, 1080.f - 70.f });
    shape.setFillColor(sf::Color::White);

    Utils::SetOrigin(shape, Origins::BC);

}

void Ball::Release()
{
}

void Ball::Reset()
{
}

void Ball::Fire(sf::Vector2f d, float s)
{
    isBallActive = true;
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

    const sf::FloatRect& ballBounds = shape.getGlobalBounds();
    float ballLeft = ballBounds.left;
    float ballRight = ballBounds.left + ballBounds.width;
    float ballTop = ballBounds.top;
    float ballBottom = ballBounds.top + ballBounds.height;

    float windowLeft = windowBounds.left;
    float windowRight = windowBounds.left + windowBounds.width;
    float windowTop = windowBounds.top;
    float windowBottom = windowBounds.top + windowBounds.height;

    if (ballBottom > windowBottom)
    {
        isDead = true;
        direction.y *= -1.f;
    }
    else if (ballTop < windowTop && direction.y < 0.f)
    {
        direction.y *= -1.f;
    }
    else if (ballLeft < windowLeft && direction.x < 0.f)
    {
        direction.x *= -1.f;
    }
    else if (ballRight > windowRight && direction.x > 0.f)
    {
        direction.x *= -1.f;
    }

    const sf::FloatRect& batBounds = bat.shape.getGlobalBounds();
    if (!prevBallBounds.intersects(batBounds) && ballBounds.intersects(batBounds))
    {
        float batLeft = batBounds.left;
        float batRight = batBounds.left + batBounds.width;
        float batTop = batBounds.top;
        float batBottom = batBounds.top + batBounds.height;

        if (ballBottom > batTop || ballTop < batBottom)
        {
            direction.y *= -1.f;
        }
        if (ballLeft > batRight || ballRight < batLeft)
        {
            direction.x *= -1.f;
        }
        isBoundBat = true;

    }

}

void Ball::Draw(sf::RenderWindow& window)
{
    window.draw(shape);
}
