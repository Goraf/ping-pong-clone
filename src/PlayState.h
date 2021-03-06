#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "State.h"


class PlayState : public State
{
public:
    PlayState(GameStateManager* manager, sf::RenderWindow& window);

    virtual void handleEvents(const sf::Event& event);
    virtual void update(const float& deltaTime);
    virtual void render();

private:
    void doCollisions();
    void checkCollision(Ball &b, Paddle &p);
    void calculateProjection(float x, float y, float oH, float oV, Ball & b, Paddle & p);

    void checkWinner();

    Paddle player1;
    Paddle player2;
    Ball ball;

    sf::Font font;
    sf::Text scorePlayer1;
    sf::Text scorePlayer2;
    sf::Text hitsHeader;
    sf::Text hitsNumber;
};
