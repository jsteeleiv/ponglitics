#pragma once

namespace olc {
    class PixelGameEngine; // Forward declare PixelGameEngine
}

class Ball {
public:
    float x, y, w, h, dx, dy, spd;

    Ball(float x, float y, float w, float h);
    bool collides(float paddleX, float paddleY, float paddleW, float paddleH);
    void center(float screenW, float screenH);
    void update(float fElapsedTime);
    void render(olc::PixelGameEngine* pge);
};
