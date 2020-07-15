#include "Game.h"
#include <Player.h>
#include <conio.h>

BlackJack_Player BlackJackGame::CreatePlayer(int Money) {
    return BlackJack_Player(Money);
}
BlackJack_Dealer BlackJackGame::CreateDealer(int Money){
    return BlackJack_Dealer(Money);
}

//void CreateDeckPile() {  }

void BlackJackGame::Start() {
    Players.push_back(CreatePlayer(100));
    Dealre = CreateDealer(10000);

    std::cout<<Players[0].getMoney()<<std::endl;
    std::cout<<Players[0].Hit();
}

