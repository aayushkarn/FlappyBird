#pragma once

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<list>
#include<random>

#include "Pipe.hpp"
#include "defs.hpp"

class PipeManager{
	public:
		PipeManager(SDL_Texture* pipe, SDL_Renderer* renderer);
		void init();
		void render();
		void update();
		Pipe* getCurrentPipe();

	private:
		SDL_Texture* pipe;
		SDL_Renderer* renderer;

		Pipe* currentPipe;
		std::list<Pipe*> pipes;
};