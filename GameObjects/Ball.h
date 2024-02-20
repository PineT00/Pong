#pragma once
#include "GameObject.h"

class Bat;

class Ball :
    public GameObject
{
protected:


public:
    sf::Vector2f direction = { 0.f, 0.f };
    float speed = 0.f;
    sf::FloatRect windowBounds = { {0.f, 0.f}, {1920.f, 1080.f} };
    sf::CircleShape shape;

    bool isDead = false;
    bool isBound = false;
    bool isBoundBat = false;

    bool isBallActive = false;

    Ball(Bat& b, const sf::FloatRect& bounds, const std::string name);
    Bat& bat;
    virtual ~Ball() = default;
    void Init() override;
    void Release() override;
    void Reset() override;

    void Fire(sf::Vector2f d, float s);

    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;


};

