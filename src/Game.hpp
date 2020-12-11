#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "Tetromino.h"
#include "Matrix.h"

class Game {
public:
    Game(const int screen_width, const int screen_height);
    ~Game();

    bool UpdateTheGame(int target_frame_duration);
    void UpdateWindowTitle(int score, int fps, int level);
    void RunWindowTitle(int target_frame_duration);
    void CollisionCheck(const Tetromino &t);
    void Difficulty();

private:
    void RestGame();
    SDL_Window* sdl_window_;
    SDL_Renderer* sdl_renderer_;
    Tetromino tetromino_;
    Matrix matrix_;
    int moveTime_;
    int dropSpeed_;
    int level_;
    int title_timestamp_;
    int frame_start_;
    int frame_end_;
    int frame_duration_;
    int frame_count_;

};

#endif
