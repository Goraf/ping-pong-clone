#include "config.h"
#include "PlayState.h"


PlayState::PlayState(GameStateManager* manager, sf::RenderWindow& window) :
    State(manager, window),
    player1(50.f),
    player2(windowWidth - 50.f)
{
}

void PlayState::handleEvents(const sf::Event& event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        player1.stopMovement();
        player2.stopMovement();
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        ball.launch();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player1.moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        player1.moveDown();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {
        player2.moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
    {
        player2.moveDown();
    }
}

void PlayState::update(const float& deltaTime)
{
    ball.update(deltaTime);
    player1.update(deltaTime);
    player2.update(deltaTime);
    doCollisions();

    const bool outOfLeftBound = (ball.getPositionX() + 2 * ballRadius) <= 0.f;
    const bool outOfRightBound = (ball.getPositionX() - 2 * ballRadius) >= windowWidth;
    if (outOfLeftBound || outOfRightBound)
        ball.reset();
}

void PlayState::render()
{
    ball.draw(window);
    player1.draw(window);
    player2.draw(window);
}

void PlayState::doCollisions()
{
    if (checkCollision(ball, player1))
        ball.velocity.x = -ball.velocity.x;

    if (checkCollision(ball, player2))
        ball.velocity.x = -ball.velocity.x;
}

bool PlayState::checkCollision(Ball &b, Paddle &p)
{
    const bool collideX = b.getPositionX() + ballRadius >= p.getPositionX() - paddleHalfWidth &&
        b.getPositionX() - ballRadius <= p.getPositionX() + paddleHalfWidth;

    const bool collideY = b.getPositionY() + ballRadius >= p.getPositionY() - paddleHalfHeight &&
        b.getPositionY() - ballRadius <= p.getPositionY() + paddleHalfHeight;

    return collideX && collideY;
}
