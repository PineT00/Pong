#pragma once
#include "GameObject.h"

class Bat;

class Ball :
    public GameObject
{
protected:
    sf::Vector2f direction = { 0.f, 0.f };
    float speed = 0.f;
    sf::FloatRect windowBounds;
    sf::CircleShape shape;

    bool isDead = false;
    bool isBound = false;
    bool isBoundBat = false;

public:

    Ball(const std::string& name = "");
    virtual ~Ball() = default;
    void Init() override;
    void Release() override;
    void Reset() override;

    void Fire(sf::Vector2f d, float s);

    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;


};

