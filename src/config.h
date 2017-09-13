#pragma once
#include <string>

constexpr unsigned windowWidth = 800;
constexpr unsigned windowHeight = 600;
static const std::string windowTitle = "PongClone";

constexpr float paddleWidth{ 10.f };
constexpr float paddleHeight{ 200.f };
constexpr float paddleHalfWidth{ paddleWidth / 2.f };
constexpr float paddleHalfHeight{ paddleHeight / 2.f };

constexpr float ballRadius{ 20.f };

const int WIN_SCORE = 3;