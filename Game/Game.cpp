#include "Game.h"
#include <Player.h>
#include <Dealer.h>
#include <conio.h>

//BlackJack_Player BlackJackGame::CreatePlayer(int Money) {
//    return BlackJack_Player(Money);
//}

//BlackJack_DeckPile* BlackJackGame::CreateDeckPile(){
//    BlackJack_DeckPile DeckPile;
//    return &DeckPile;
//}
//void CreateDeckPile() {  }


void BlackJackGame::StartGame() {
    std::cout<<"\n\n////  Welcome to the honest world of cards :) ////\n////  BlacK Jack, created by kapibarich2000, greet you ////\n\n";

    std::cout<<"Please Enter for control:\nh - for hit, s - for stand, e - for exit, c - for continue\n\n";

    BlackJack_Dealer _Dealer(10000);
    _Dealer.setDeckPile(&_DeckPile);

    char choice='s';
    while (choice!='e') {
        for (int i = 0; i < _Players.size(); ++i) {
            std::cout << i+1 << " player make a Bet" << std::endl;
            _Bets[i] = _Players[i]->Make_Bet();
        }
        std::cout << "Dealer deals the cards..." << std::endl;
        std::cin>>choice;

        std::cout<<"Вы хотите сыграть еще раунд ?"<<std::endl;
        std::cin>>choice;
    }


    //for (int i = 0; i < _Players.size(); ++i) {
//
    //}

}