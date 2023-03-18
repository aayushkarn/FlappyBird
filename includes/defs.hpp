#pragma once

#define FPS 60
#define FRAME_DELAY 1000/FPS

#define GAME_TITLE "Flappy Bird"
#define SCREEN_WIDTH 479
#define SCREEN_HEIGHT 639

#define BACKGROUND "./assets/img/background-day.png"
#define GROUND "./assets/img/base.png"
#define PIPE "./assets/img/pipe.png"
#define GAMEOVER "./assets/img/gameover.png"
#define PLAYERUP "./assets/img/yellowbird-upflap.png"
#define PLAYERMID "./assets/img/yellowbird-midflap.png"
#define PLAYERDOWN "./assets/img/yellowbird-downflap.png"

#define GROUND_WIDTH 336
#define GROUND_HEIGHT 112

#define BIRD_POS_X SCREEN_WIDTH / 3 -32
#define BIRD_POS_Y SCREEN_HEIGHT / 2
#define BIRD_WIDTH 55
#define BIRD_HEIGHT 39

#define GRAVITY 80.0f

#define PIPE_WIDTH 80
#define PIPE_WIDTH_SRC 52 
#define PIPE_GAP 170
#define PIPE_DISTANCE 250
#define PIPE_VELOCITY 3

#define GAMEOVER_X SCREEN_WIDTH / 2 - 90
#define GAMEOVER_Y SCREEN_HEIGHT/ 3 - 50
#define GAMEOVER_WIDTH 192
#define GAMEOVER_HEIGHT 42

#define SCORE_X SCREEN_WIDTH / 2
#define SCORE_Y 40
#define SCORE_TWO_FIRST_X SCREEN_WIDTH / 2 -20
#define SCORE_TWO_SECOND_X SCREEN_WIDTH / 2 +20
#define SCORE_WIDTH 40
#define SCORE_HEIGHT 52
#define SCORE_THREE_FIRST_X SCREEN_WIDTH / 2 -60
#define SCORE_THREE_SECOND_X SCREEN_WIDTH / 2 -20
#define SCORE_THREE_THIRD_X SCREEN_WIDTH / 2 +20
