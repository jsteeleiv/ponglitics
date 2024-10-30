#include "Ball.h"
#include "olcPixelGameEngine.h" // Only include in the .cpp

Ball::Ball(float x, float y, float w, float h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->spd = 3.0f;
    srand(static_cast<unsigned>(time(0)));
    this->dy = rand() % 2 == 0 ? -100.0f : 100.0f;
    this->dx = static_cast<float>(rand() % 101 - 50);
}

void Ball::update(float fElapsedTime) {
    x += dx * spd * fElapsedTime;
    y += dy * spd * fElapsedTime;
}

void Ball::render(olc::PixelGameEngine* pge) {
    pge->FillRect(olc::vi2d(x, y), olc::vi2d(w, h), olc::WHITE);
}

void Ball::center(float screenW, float screenH) {
    this->x = screenW;
    this->y = screenH;
    this->dx = rand
}

