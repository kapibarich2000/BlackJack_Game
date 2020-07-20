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
    _PlayersSize=_Players.size();
    std::cout<<"\n\n////  Welcome to the honest world of cards :) ////\n////  BlacK Jack, created by kapibarich2000, greet you ////\n\n";

    std::cout<<"Please Enter for control:\nh - for hit, s - for stand, e - for exit, c - for continue\n\n";

    BlackJack_Dealer _Dealer(10000);
    _Dealer.setDeckPile(&_DeckPile);
    _Dealer._hand.Refresh(_Dealer.retPointonDeck());

    char choice='c';
    while (choice!='e') {
        for (int i = 0; i < _PlayersSize; ++i) {
            std::cout << i+1 << " player make a Bet" << std::endl;
            _Players[i]->Make_Bet();
        }
        std::cout << "Dealer deals the cards..." << std::endl;
        for (int i = 0; i < _PlayersSize; ++i) {
            _Players[i]->_Hand.setCard(_Dealer._hand.getCardFromDeck(_Dealer.retPointonDeck()));
            _Players[i]->_Hand.setCard(_Dealer._hand.getCardFromDeck(_Dealer.retPointonDeck()));
        }
        _Dealer._hand.setCard(_Dealer._hand.getCardFromDeck(_Dealer.retPointonDeck()));
        _Dealer._hand.setCard(_Dealer._hand.getCardFromDeck(_Dealer.retPointonDeck()));

        std::cout<<"Dealer have: ";
        _Dealer._hand.showCardsName(1);
        std::cout<<" *\t"<<"(";

        _Dealer._hand.showCardsValue(1);
        std::cout<<")"<<"\n";

        for (int i = 0; i < _PlayersSize; ++i) {
            std::cout<<i+1<<" Player have: ";
            _Players[i]->_Hand.showCardsName();
            std::cout<<"(";
            std::cout<<_Players[0]->_Hand.getAllValue();
            std::cout<<")"<<"\n";



            std::cout<<"Stand or Hit ? :  "<<std::endl;
            std::cin>>choice;
        }





        std::cout<<"Вы хотите сыграть еще раунд ?"<<std::endl;
        std::cin>>choice;
    }


    //for (int i = 0; i < _Players.size(); ++i) {
//
    //}

}