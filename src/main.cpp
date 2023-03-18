#include "Game.hpp"

#include<chrono>

int main(int argc, char* argv[]){

	auto t1 = std::chrono::system_clock::now();
	auto t2 = t1;
	Game game(GAME_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
	game.init();
	while(game.running()){
		t1 = t2;
		t2 = std::chrono::system_clock::now();
		std::chrono::duration<float> deltatime = t2 - t1;

		game.handleEvents(deltatime.count());
		game.render();

		if(deltatime.count()<FRAME_DELAY){
			SDL_Delay(FRAME_DELAY-deltatime.count());
		}
	}
	game.clean();

	return 0;
}