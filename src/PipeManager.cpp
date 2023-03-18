#include "PipeManager.hpp"

PipeManager::PipeManager(SDL_Texture* pipe, SDL_Renderer* renderer) : pipe(pipe), renderer(renderer){};

void PipeManager::init(){
	for(auto p : pipes){
		pipes.pop_front();
	}

	pipes.push_back(new Pipe(SCREEN_WIDTH * 2 + PIPE_DISTANCE, rand() % 300 + 150));
	pipes.push_back(new Pipe(pipes.back()->bottomDest.x + PIPE_DISTANCE, rand() % 300 + 150));
	pipes.push_back(new Pipe(pipes.back()->bottomDest.x + PIPE_DISTANCE, rand() % 300 + 150));
}

void PipeManager::render(){
	for(auto p : pipes){
		p->render(renderer, pipe);
	}
}

void PipeManager::update(){
	for(auto p : pipes){
		p->bottomDest.x -= PIPE_VELOCITY;
		p->topDest.x = p->bottomDest.x;

		if(p->bottomDest.x + p->bottomDest.w < 0){
			pipes.pop_front();
			pipes.push_back(new Pipe(pipes.back()->bottomDest.x + PIPE_DISTANCE, rand() % 300 + 150));
		}
	}
}

Pipe* PipeManager::getCurrentPipe(){
	currentPipe = pipes.front();
	return currentPipe;
}