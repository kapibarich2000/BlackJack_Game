#include "Game.h"
#include <Player.h>
#include <Dealer.h>
#include <conio.h>

BlackJackGame::BlackJackGame() {};

BlackJack_Player BlackJackGame::CreatePlayer(int Money) {
    return BlackJack_Player(Money);
}
BlackJack_Dealer BlackJackGame::CreateDealer(int Money){
    return BlackJack_Dealer(Money);
}
BlackJack_DeckPile BlackJackGame::CreateDeckPile(){
    BlackJack_DeckPile DeckPile;
    return DeckPile;
}

//void CreateDeckPile() {  }

void BlackJackGame::Start() {
    Players.push_back(CreatePlayer(100));
    Dealre = CreateDealer(10000);
    Dealre.setDeckPile(CreateDeckPile());

    std::cout<<""<<std::endl;
    while (Players[0].getMoney()>0){

        for (int i = 0; i < Players.size(); ++i) {
            std::cout<<i<<" player make a Bet"<<std::endl;
            Bets[i]=Players[i].Make_Bet();
        }
    }

    std::cout<<"Dealer deals the cards..."<<std::endl;
    for (int i = 0; i < Players.size(); ++i) {
    //    Players[i]. Dealre.getCard();
        Dealre.getCard();
    }
    //std::cout<<DeckPile;


    //std::cout<<Players[0].getMoney()<<std::endl;
    //std::cout<<Players[0].Hit();
}

