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
    void replace(State* state);
    void resetToFirst();
    State* getCurrentState();

private:
    std::vector<std::unique_ptr<State>> states;
};
