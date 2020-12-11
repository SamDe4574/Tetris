#include <SDL.h>
#include <iostream>
#include "Game.hpp"



int main(int argc, char *argv[]) {
	
	constexpr int kFramesPerSecond{ 60 };
	constexpr int kMsPerFrame{ 1000 / kFramesPerSecond };
	constexpr int kScreenWidth{ 360 };
	constexpr int kScreenHeight{ 720 };

	Game Game(kScreenWidth, kScreenHeight);
	while(Game.UpdateTheGame(kMsPerFrame));
	return 0;
}