#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "State.h"

class Ball;
class Paddle;


class PlayState : public State
{
public:
    PlayState(GameStateManager* manager, sf::RenderWindow& window);

    virtual void handleEvents(const sf::Event& event);
    virtual void update(const float& deltaTime);
    virtual void render();

private:
    void doCollisions();
    bool checkCollision(Ball &circle, Paddle &rect);

    Paddle player1;
    Paddle player2;
    Ball ball;
};
