#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "Tetromino.h";
#include "Matrix.h";

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
    const int screen_width;
    const int screen_height;
    int moveTime_;
    int dropSpeed;
    int level;
    int title_timestamp;
    int frame_start;
    int frame_end;
    int frame_duration;
    int frame_count;

};

#endif
