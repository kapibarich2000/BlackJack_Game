#include <iostream>
#include <Game.h>

void  startSinglePlayerGame(){
    BlackJackGame game;
    BlackJack_Player Player(100,"Ivan");
    game.addPlayer(&Player);
    game.StartGame();
}

int main() {
    startSinglePlayerGame();
    return 0;
}