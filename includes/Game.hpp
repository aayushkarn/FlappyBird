#pragma once

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<time.h>

#include "defs.hpp"
#include "Bird.hpp"
#include "PipeManager.hpp"

class Game{
	public:
		Game(char* title, int width, int height);
		void init();
		void handleEvents(float elapsedTime);
		void loadTextures();
		void update(float elapsedTime);
		void render();
		void gameOver();
		void clean();
		bool running(){return isRunning;}

	private:
		SDL_Renderer* renderer;
		SDL_Window* window;
		SDL_Event event;

		SDL_Texture* tex_background;
		SDL_Texture* tex_pipe;
		SDL_Texture* tex_gameOver;
		SDL_Texture* tex_playerUp;
		SDL_Texture* tex_playerMid;
		SDL_Texture* tex_playerDown;
		SDL_Texture* tex_ground;
		SDL_Texture* tex_numbers[10];

		Bird* bird;
		bool jump;

		PipeManager* pipeManager;

		bool gameStarted, gameover, isRunning;
		int ground1, ground2;
};