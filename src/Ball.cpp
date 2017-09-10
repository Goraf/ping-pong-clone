#include "Ball.h"
#include "config.h"


Ball::Ball() :
    gen(rd()),
    dist(0, 1)
{
    shape.setRadius(ballRadius);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setFillColor(sf::Color::Blue);
    reset();
}

void Ball::update(const float& dt)
{
    shape.move(velocity * dt);

    float dy = 0.f - (shape.getPosition().y - ballRadius);
    if (dy > 0.f)
    {
        shape.move(0.f, dy);
        velocity.y = -velocity.y;
    }
    else
    {
        dy = (shape.getPosition().y + ballRadius) - windowHeight;
        if (dy > 0.f)
        {
            shape.move(0.f, -dy);
            velocity.y = -velocity.y;
        }
    }
}

void Ball::draw(sf::RenderTarget & target) const
{
    target.draw(shape);
}

void Ball::reset()
{
    velocity.x = 0.f;
    velocity.y = 0.f;
    isMoving = false;

    float horizonatlCenter = windowWidth / 2.f;
    float verticalCenter = windowHeight / 2.f;
    shape.setPosition(horizonatlCenter, verticalCenter);
}

void Ball::launch()
{
    if (!isMoving)
    {
        if (dist(gen))
            velocity.x = 300.f;
        else
            velocity.x = -300.f;

        if (dist(gen))
            velocity.y = 300.f;
        else
            velocity.y = -300.f;

        isMoving = true;
    }
}

void Ball::resolveCollision(float px, float py, float dx, float dy, Paddle & p)
{
    shape.move(px, py);

    if (dx != 0.f)
        velocity.x *= -1;
    if (dy != 0.f)
        velocity.y *= -1;
    if (dx == 0.f && dy == 0.f)
    {
        velocity.x *= -1.f;
        velocity.y *= -1.f;
    }

    velocity *= 1.1f;
}
