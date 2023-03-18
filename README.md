
# Flappy Bird Clone 

Flappy bird clone in C++ and SDL.

Used `Mingw` to compile and `.sublime-project` to build. Here is a sample command I used.

``` 
g++ -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I includes -I thirdparty/include && g++ *.o -o bin/release/main -s -L thirdparty/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf && start bin/release/main
```

## Screenshots

![Game Screenshot](https://raw.githubusercontent.com/aayushkarn/FlappyBird/main/assets/screenshot.PNG)

[Download Game](https://github.com/aayushkarn/FlappyBird/blob/main/bin/release/flappybird.zip)
