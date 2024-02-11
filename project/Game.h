#ifndef _GAME_
#define _GAME_

#include "Person.h"
#include <queue>
#include "Monster.h"


class Game {
public:
    void gameStart();
    void gameNewStart(); // Start a new game, enter player's name, construct a new player and some mosters.
    void gameLoop();
    void gameQuit();
    void gameEnd();
    void gameResume();
private:
    void gameCleaner();
    Person *player;
    std::queue<Monster *> monsters;
};

#endif