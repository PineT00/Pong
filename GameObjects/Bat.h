#pragma once
#include "GameObject.h"
class Bat :
    public GameObject
{
protected:


public:
    float speed = 600.f;
    sf::RectangleShape shape;
    Bat(const std::string& name = "");
    ~Bat() override = default;

    void Init() override;
    void Release() override;

    void Reset() override;

    void PlayerMove(float dt);

    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;
};

