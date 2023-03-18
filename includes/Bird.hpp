#pragma once

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

#include "defs.hpp"
#include "Pipe.hpp"

class Bird{
	public:
		Bird(SDL_Texture* up, SDL_Texture* mid, SDL_Texture* down, SDL_Renderer* renderer);
		void init();
		void render();
		void update(bool jump, float elpasedTime);
		void animation();
		bool collisionDetector(Pipe* pipe);

		int score;

	private:
		SDL_Texture* up;
		SDL_Texture* mid;
		SDL_Texture* down;
		SDL_Texture* currentRenderingTexture;
		SDL_Renderer* renderer;

		SDL_Rect position;

		float velocity;
		float acceleration;

		int currentFrame;
};