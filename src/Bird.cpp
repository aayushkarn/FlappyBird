#include "Bird.hpp"


void Bird::init(){
	velocity = 0.0f;
	acceleration = 0.0f;

	score = 0;

	currentRenderingTexture = mid;
	currentFrame = 0;

	position.x = BIRD_POS_X;
	position.y = BIRD_POS_Y;
	position.w = BIRD_WIDTH;
	position.h = BIRD_HEIGHT;

}

Bird::Bird(SDL_Texture* up, SDL_Texture* mid, SDL_Texture* down, SDL_Renderer* renderer) : up(up), mid(mid), down(down), renderer(renderer){
	init();
}

void Bird::render(){
	animation();
	if(velocity == 0){
		SDL_RenderCopy(renderer, mid, NULL, &position);
	} else if(velocity < 80){
		SDL_RenderCopyEx(renderer, currentRenderingTexture, NULL, &position, -30.0, NULL, SDL_FLIP_NONE);
	} else if(velocity >= 80 && velocity < 200){
		SDL_RenderCopyEx(renderer, currentRenderingTexture, NULL, &position, 30.0, NULL, SDL_FLIP_NONE);
	} else if(velocity >= 200){
		SDL_RenderCopyEx(renderer, currentRenderingTexture, NULL, &position, 90.0, NULL, SDL_FLIP_NONE);
	}
}

void Bird::animation(){
	currentFrame++;
	if(currentFrame == 5){
		currentRenderingTexture = up;
	} else if(currentFrame == 15){
		currentRenderingTexture = mid;
	} else if(currentFrame == 20){
		currentRenderingTexture = down;
		currentFrame = 0;
	}
}

void Bird::update(bool jump, float elpasedTime){
	elpasedTime *= 5;
	if(jump){
		acceleration = 0.0f;
		velocity = -GRAVITY;
	} else {
		acceleration += GRAVITY * elpasedTime;
	}
	velocity += acceleration * elpasedTime;
	position.y += velocity * elpasedTime;
}

bool Bird::collisionDetector(Pipe* pipe){
	// ground
	if(position.y > SCREEN_HEIGHT - GROUND_HEIGHT)
		return true; 
	// ceiling
	if(position.y < 0)
		return true; 

	//pipe
	if(pipe->topDest.x <= position.x + position.w && pipe->topDest.x + PIPE_WIDTH >= position.x + position.w){
		if(position.y < pipe->topDest.y + pipe->topDest.h || position.y + position.h > pipe->bottomDest.y)
			return true;
	}

	if(!pipe->passed && pipe->topDest.x + PIPE_WIDTH < position.x){
		pipe->passed = true;
		score++;
	}

	return false;
}