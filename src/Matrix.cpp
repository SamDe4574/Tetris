#include "Matrix.h"

Matrix::Matrix():
	data{ false }
{
    score = 0;
}

void Matrix::PlaceGrid(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    for (auto x = 0; x < Width; x++)
        for (auto y = 0; y < Height; y++)
        {
            if (data[x][y]) {
                SDL_Rect rect{ x * 720 / 2 / 10, y * 720 / 2 / 10 ,720 / 2 / 10, 720 / 2 / 10  };
                SDL_RenderFillRect(renderer, &rect);
            }
            else
            {
                SDL_RenderDrawPoint(renderer, x * 720 / 2 / 10 + 720 / 2 / 10 / 2, y * 720 / 2 / 10 + 720 / 2 / 10 / 2);
            }

        }

}

bool Matrix::isCollision(const Tetromino& t) const
{
    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 4; y++)
            if (t.isBlock(x, y))
            {
                auto wx = t.x() + x;
                auto wy = t.y() + y;
                if (wx < 0 || wx >= Width || wy < 0 || wy >= Height)
                    return true;
                if (data[wx][wy])
                    return true;
            }
    return false;
}

void Matrix::unite(const Tetromino &t)
{
    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 4; y++)
            if (t.isBlock(x, y))
            {
                data[t.x() + x][t.y() + y] = true;
            }
}

void Matrix::SolidLine(){
    for (int y = Height - 1; y >= 0; --y)
    {
        solid_ = true;
        for (int x = 0; x < Width; ++x)
            if (!data[x][y])
            {
                solid_ = false;
                break;
            }
        if (solid_)
        {
            for (int yy = y - 1; yy >= 0; --yy)
                for (int x = 0; x < Width; ++x) {
                    data[x][yy + 1] = data[x][yy];
                }
            for (int x = 0; x < Width; ++x)
                data[x][0] = false;

            score += 100;
        }
    }
}
