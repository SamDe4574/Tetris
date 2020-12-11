#include "Game.h"
#include <iostream>
#include <string>

Game::Game(const int screen_width, const int screen_height) : screen_width(screen_width), screen_height(screen_height),
tetromino_{ static_cast<Tetromino::Type>(rand() % 7) }, moveTime_(SDL_GetTicks())
{   
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }


    // Create Window
    sdl_window_ = SDL_CreateWindow("Tetris Game", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, screen_width,
        screen_height, SDL_WINDOW_SHOWN );

    if (nullptr == sdl_window_) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    sdl_renderer_ = SDL_CreateRenderer(sdl_window_, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == sdl_renderer_) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    level_ = 1;
    dropSpeed_ = 800;
    title_timestamp_ = SDL_GetTicks();
    frame_count_ = 0;
}

Game::~Game() {
    SDL_DestroyRenderer(sdl_renderer_);
    SDL_DestroyWindow(sdl_window_);
    SDL_Quit();
}

bool Game::UpdateTheGame(int target_frame_duration) {
    SDL_Event e;
    Tetromino t = tetromino_;
    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_KEYDOWN:
        {
            switch (e.key.keysym.sym)
            {
                case SDLK_SPACE:
                    while (!matrix_.isCollision(t)) {
                        tetromino_ = t;
                        t.move(0, 1);
                    }
                break;
                case SDLK_DOWN:
                {
                    t.move(0, 1);
                    if(!matrix_.isCollision(t))
                        tetromino_ = t;
                }
                break;
                case SDLK_RIGHT:
                {
                    t.move(1, 0);
                    if (!matrix_.isCollision(t))
                        tetromino_ = t;
                }
                break;
                case SDLK_LEFT:
                {
                    t.move(-1, 0);
                    if (!matrix_.isCollision(t))
                        tetromino_ = t;
                }
                break;
                case SDLK_UP:
                {
                    t.rotate();
                    if (!matrix_.isCollision(t))
                        tetromino_ = t;
                }
                break;
                case SDLK_q:
                    return false;
                break;
                case SDLK_r:
                    RestGame();
                    break;
            }
        }
        break;
        case SDL_QUIT:
            return false;
        }
    }
    SDL_SetRenderDrawColor(sdl_renderer_, 0,0,0,0xff);
    SDL_RenderClear(sdl_renderer_);
    matrix_.PlaceGrid(sdl_renderer_);
    tetromino_.render(sdl_renderer_);
    matrix_.SolidLine();

    Difficulty();
    if (SDL_GetTicks() > moveTime_)
    {
        moveTime_ += dropSpeed_;
        t = tetromino_;
        t.move(0, 1);
        CollisionCheck(t);
    }
    SDL_RenderPresent(sdl_renderer_);
    RunWindowTitle(target_frame_duration);
    return true;
}

void Game::CollisionCheck(const Tetromino &t)
{
    if (matrix_.isCollision(t))
    {
        matrix_.unite(tetromino_);
        tetromino_ = Tetromino{ static_cast<Tetromino::Type>(rand() % 7) };
        if (matrix_.isCollision(tetromino_))
            RestGame();
    }
    else
    {
        tetromino_ = t;
    }
}

void Game::Difficulty()
{
    switch (matrix_.score)
    {
    case  200:
        level_ = 2;
        dropSpeed_ = 720;
    break;
    case  400:
        level_ = 2;
        dropSpeed_ = 630;
        break;
    case  600:
        level_ = 3;
        dropSpeed_ = 550;
        break;
    case  800:
        level_ = 3;
        dropSpeed_ = 470;
        break;
    case  1000:
        level_ = 4;
        dropSpeed_ = 380;
        break;
    case  1200:
        level_ = 4;
        dropSpeed_ = 300;
        break;
    case  1400:
        level_ = 5;
        dropSpeed_ = 220;
        break;
    case  1600:
        level_ = 5;
        dropSpeed_ = 130;
        break;
    case  1800:
        level_ = 6;
        dropSpeed_ = 100;
        break;
    case  2000:
        level_ = 6;
        dropSpeed_ = 80;
        break;
    case  2200:
        level_ = 7;
        dropSpeed_ = 70;
        break;
    case  2400:
        level_ = 7;
        dropSpeed_ = 50;
        break;
    case  2600:
        level_ = 8;
        dropSpeed_ = 30;
        break;
    case  2800:
        level_ = 8;
        dropSpeed_ = 20;
        break;
    case  3000:
        level_ = 9;
        dropSpeed_ = 10;
        break;
    }

}

void Game::RestGame() {
    tetromino_ = Tetromino{ static_cast<Tetromino::Type>(rand() % 7) };
    matrix_ = Matrix();
    level_ = 1;
    dropSpeed_ = 800;
    SDL_Delay(500);
}

void Game::RunWindowTitle(int target_frame_duration) {
        frame_start_ = SDL_GetTicks();

        frame_end_ = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render cycle
        // takes.
        frame_count_++;
        frame_duration_ = frame_end_ - frame_start_;

        // After every second, update the window title.
        if (frame_end_ - title_timestamp_ >= 1000) {
            UpdateWindowTitle(matrix_.score, frame_count_, level_ );
            frame_count_ = 0;
            title_timestamp_ = frame_end_;
        }

        // If the time for this frame is too small (i.e. frame_duration_ is
        // smaller than the target ms_per_frame), delay the loop to
        // achieve the correct frame rate.
        if (frame_duration < target_frame_duration) {
            SDL_Delay(target_frame_duration - frame_duration_);
        }
}

void Game::UpdateWindowTitle(int score, int fps, int level) {
    std::string title{ "Tetris - Level: " + std::to_string(level) + " Score: " + std::to_string(score) + " FPS: " + std::to_string(fps) };
    SDL_SetWindowTitle(sdl_window_, title.c_str());
}


