#include "Game.hpp"

Game::Game(char* title, int width, int height){
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout<<"Couldn't load SDL "<<SDL_GetError()<<std::endl;
	} else{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		if(window == NULL){
			std::cout<<"Unable to create window"<<std::endl;
		} else {
			renderer = SDL_CreateRenderer(window, -1, 0);
			if(renderer == NULL){
				std::cout<<"Unable to create Renderer"<<std::endl;
			} else {
				std::cout<<"Window created sucessfully"<<std::endl;
				loadTextures();
				isRunning = true;
				gameover = false;

				ground1 = -SCREEN_WIDTH / 2;
				ground2 = SCREEN_WIDTH / 2;

				bird = new Bird(tex_playerUp, tex_playerMid, tex_playerDown, renderer);
				pipeManager = new PipeManager(tex_pipe, renderer);
			}
		}
	}
	srand(time(NULL));
}

void Game::init(){
	gameover = false;
	gameStarted = false;

	pipeManager->init();
	bird->init();
	render();
}

void Game::handleEvents(float elapsedTime){
	jump = false;
	while(SDL_PollEvent(&event)){
		if((event.type == SDL_QUIT) || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
			isRunning = false;
		if((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) || (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)){
			jump = gameStarted = true;
		}
	}
	if(gameStarted){
		update(elapsedTime);
		if(gameover){
			gameOver();
		}
	}
}

void Game::render(){
	SDL_RenderClear(renderer);
	// BACKGROUND
	SDL_RenderCopy(renderer, tex_background, NULL, NULL);
	// Pipe
	pipeManager->render();
	// GROUND
	SDL_RenderCopy(renderer, tex_ground, NULL, new SDL_Rect{ground1, SCREEN_HEIGHT - GROUND_HEIGHT,SCREEN_WIDTH,GROUND_HEIGHT});
	SDL_RenderCopy(renderer, tex_ground, NULL, new SDL_Rect{ground2, SCREEN_HEIGHT - GROUND_HEIGHT, SCREEN_WIDTH, GROUND_HEIGHT});

	// Score
	if(bird->score>99){
		SDL_RenderCopy(renderer, tex_numbers[bird->score / 100 % 100], NULL, new SDL_Rect{SCORE_THREE_FIRST_X, SCORE_Y, SCORE_WIDTH, SCORE_HEIGHT});
		SDL_RenderCopy(renderer, tex_numbers[bird->score / 10 % 10], NULL, new SDL_Rect{SCORE_THREE_SECOND_X, SCORE_Y, SCORE_WIDTH, SCORE_HEIGHT});
		SDL_RenderCopy(renderer, tex_numbers[bird->score % 10], NULL, new SDL_Rect{SCORE_THREE_THIRD_X, SCORE_Y, SCORE_WIDTH, SCORE_HEIGHT});
	}
	else if(bird->score>9){
		SDL_RenderCopy(renderer, tex_numbers[bird->score / 10 % 10], NULL, new SDL_Rect{SCORE_TWO_FIRST_X, SCORE_Y, SCORE_WIDTH, SCORE_HEIGHT});
		SDL_RenderCopy(renderer, tex_numbers[bird->score % 10], NULL, new SDL_Rect{SCORE_TWO_SECOND_X, SCORE_Y, SCORE_WIDTH, SCORE_HEIGHT});
	} else {
		SDL_RenderCopy(renderer, tex_numbers[bird->score], NULL, new SDL_Rect{SCORE_X, SCORE_Y, SCORE_WIDTH, SCORE_HEIGHT});
	}

	bird->render();
	SDL_RenderPresent(renderer);
}

void Game::loadTextures(){
	std::cout<<"Loading Textures"<<std::endl;

	tex_background = IMG_LoadTexture(renderer, BACKGROUND);
	tex_pipe = IMG_LoadTexture(renderer, PIPE);
	tex_ground = IMG_LoadTexture(renderer, GROUND);
	tex_playerUp = IMG_LoadTexture(renderer, PLAYERUP);
	tex_playerMid = IMG_LoadTexture(renderer, PLAYERMID);
	tex_playerDown = IMG_LoadTexture(renderer, PLAYERDOWN);
	tex_gameOver = IMG_LoadTexture(renderer, GAMEOVER);

	for(int i=0;i<10;i++){
		std::string path = "./assets/img/"+std::to_string(i)+".png";
		tex_numbers[i] = IMG_LoadTexture(renderer, path.c_str());
	}
	std::cout<<"Done Loading Texture"<<std::endl;
}

void Game::update(float elapsedTime){
	bird->update(jump, elapsedTime);
	pipeManager->update();
	
	// ground
	ground1 -= PIPE_VELOCITY;
	ground2 -= PIPE_VELOCITY;
	if(ground1 + SCREEN_WIDTH < 0)
		ground1 = SCREEN_WIDTH - 10;
	if(ground2 + SCREEN_WIDTH < 0)
		ground2 = SCREEN_WIDTH - 10;

	if(bird->collisionDetector(pipeManager->getCurrentPipe())){
		gameover = true;
	}
}

void Game::gameOver(){
	gameStarted = false;

	SDL_RenderCopy(renderer, tex_gameOver, NULL, new SDL_Rect{GAMEOVER_X, GAMEOVER_Y, GAMEOVER_WIDTH, GAMEOVER_HEIGHT});
	SDL_RenderPresent(renderer);
	SDL_Delay(1000);

	bool wait = true, restart=false;
	while(wait){
		while(SDL_PollEvent(&event)){
			if((event.type == SDL_QUIT) || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)){
				wait = false;
				isRunning = false;
			}
			if((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) || (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)){
				wait = false;
				restart = true;
			}
		}
	}
	if(restart){
		init();
	} else {
		isRunning = false;
	}
}

void Game::clean(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}