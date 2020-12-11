#pragma once
#include "SDL.h"
#include "Tetromino.h";
#include <iostream>

class Matrix
{
public:
    Matrix();
    void PlaceGrid(SDL_Renderer* renderer);
    enum { Width = 10, Height = 20 };
    int score;
    bool isCollision(const Tetromino& t) const;
    void unite(const Tetromino& t);
    void SolidLine();
private:
    bool data[Width][Height];
    bool solid_;

};

