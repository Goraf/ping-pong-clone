#pragma once
#include <memory>
#include <vector>
#include "State.h"


class GameStateManager
{
public:
    GameStateManager();

    void push(State* state);
    void pop();
    State* getCurrentState();

private:
    std::vector<std::unique_ptr<State>> states;
};
