#pragma once
#include "State.h"

class PlayState : public State {
public:
    PlayState(GameStateManager* manager, sf::RenderWindow& window);

    virtual void handleEvents(const sf::Event& event);
    virtual void update(const float& deltaTime);
    virtual void render();


private:

};

