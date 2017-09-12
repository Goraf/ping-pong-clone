#include <math.h>
#include "config.h"
#include "GameStateManager.h"
#include "PauseState.h"
#include "PlayState.h"
#include "WinState.h"


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

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateManager->push(new PauseState(stateManager, window));

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
    if (outOfLeftBound)
    {
        player2.addPoint();
        ball.reset();
    }

    const bool outOfRightBound = (ball.getPositionX() - 2 * ballRadius) >= windowWidth;
    if (outOfRightBound)
    {
        player1.addPoint();
        ball.reset();
    }

    checkWinner();
}

void PlayState::render()
{
    ball.draw(window);
    player1.draw(window);
    player2.draw(window);
}

void PlayState::doCollisions()
{
    checkCollision(ball, player1);
    checkCollision(ball, player2);
}

void PlayState::checkCollision(Ball & b, Paddle & p)
{
    float dx = b.getPositionX() - p.getPositionX();
    float px = (paddleHalfWidth + ballRadius) - std::fabsf(dx);//penetration depth in x

    if (0 < px)
    {
        float dy = b.getPositionY() - p.getPositionY();
        float py = (paddleHalfHeight + ballRadius) - std::fabsf(dy);//pen depth in y

        if (0 < py)
        {
            //object may be colliding with tile

            //determine grid/voronoi region of circle center
            float oH = 0.f;
            float oV = 0.f;
            if (dx < -paddleHalfWidth)
            {
                //circle is on left side of tile
                oH = -1.f;
            }
            else if (paddleHalfWidth < dx)
            {
                //circle is on right side of tile
                oH = 1.f;
            }

            if (dy < -paddleHalfHeight)
            {
                //circle is on top side of tile
                oV = -1.f;
            }
            else if (paddleHalfHeight < dy)
            {
                //circle is on bottom side of tile
                oV = 1.f;
            }

            calculateProjection(px, py, oH, oV, b, p);
        }
    }
}

void PlayState::calculateProjection(float x, float y, float oH, float oV, Ball & b, Paddle& p)
{
    //if we're colliding vs. the current cell, we need to project along the
    //smallest penetration vector.
    //if we're colliding vs. horiz. or vert. neighb, we simply project horiz/vert
    //if we're colliding diagonally, we need to collide vs. tile corner

    if (oH == 0.f)
    {
        if (oV == 0.f)
        {

            //collision with current cell
            if (x < y)
            {
                //penetration in x is smaller; project in x
                float dx = b.getPositionX() - p.getPositionX();//get sign for projection along x-axis

                 //NOTE: should we handle the delta == 0 case?! and how? (project towards oldpos?)
                if (dx < 0)
                {
                    b.resolveCollision(-x, 0, -1, 0, p);
                }
                else
                {
                    b.resolveCollision(x, 0, 1, 0, p);
                }
            }
            else
            {
                //penetration in y is smaller; project in y
                float dy = b.getPositionY() - p.getPositionY();//get sign for projection along y-axis

                //NOTE: should we handle the delta == 0 case?! and how? (project towards oldpos?)
                if (dy < 0)
                {
                    b.resolveCollision(0, -y, 0, -1, p);
                }
                else
                {
                    b.resolveCollision(0, y, 0, 1, p);
                }
            }
        }
        else
        {
            //collision with vertical neighbor
            b.resolveCollision(0, y*oV, 0, oV, p);
        }
    }
    else if (oV == 0.f)
    {
        //collision with horizontal neighbor
        b.resolveCollision(x*oH, 0, oH, 0, p);
    }
    else
    {
        //diagonal collision

        //get diag vertex position
        float vertexX = p.getPositionX() + (oH*paddleHalfWidth);
        float vertexY = p.getPositionY() + (oV*paddleHalfHeight);

        float dx = b.getPositionX() - vertexX;
        float dy = b.getPositionY() - vertexY;

        float length = std::sqrtf(dx*dx + dy*dy);
        float penetration = ballRadius - length;
        if (0.f < penetration)
        {
            //vertex is in the circle; project outward
            if (length == 0.f)
            {
                //project out by 45deg
                dx = oH / std::sqrtf(2.f);
                dy = oV / std::sqrtf(2.f);
            }
            else
            {
                dx /= length;
                dy /= length;
            }

            b.resolveCollision(dx*penetration, dy*penetration, dx, dy, p);
        }
    }
}

void PlayState::checkWinner()
{
    if (player1.getPoints() == WIN_SCORE)
    {
        stateManager->push(new WinState(stateManager, window, Player1));
    }
    else if (player2.getPoints() == WIN_SCORE)
    {
        stateManager->push(new WinState(stateManager, window, Player2));
    }
}


