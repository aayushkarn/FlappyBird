#pragma once

#include "defs.hpp"

struct Pipe{
	SDL_Rect topDest, topSrc, bottomDest, bottomSrc;
	bool passed;
	Pipe(int x, int height){
		bottomDest.x = x;
		bottomDest.y = SCREEN_HEIGHT - height;
		bottomDest.w = PIPE_WIDTH;
		bottomDest.h = height;

		bottomSrc.x = 0;
		bottomSrc.y = 0;
		bottomSrc.w = PIPE_WIDTH_SRC;
		bottomSrc.h = height;

		topDest.x = x;
		topDest.y = 0;
		topDest.w = PIPE_WIDTH;
		topDest.h = SCREEN_HEIGHT - height - PIPE_GAP;

		topSrc.x = 0;
		topSrc.y = 0;
		topSrc.w = PIPE_WIDTH_SRC;
		topSrc.h = topDest.h;

		passed = false;
	}

	void render(SDL_Renderer* renderer, SDL_Texture* pipe){
		SDL_RenderCopy(renderer, pipe, &bottomSrc, &bottomDest);
		SDL_RenderCopyEx(renderer, pipe, &topSrc, &topDest, -180.0, NULL, SDL_FLIP_NONE);
	}
};