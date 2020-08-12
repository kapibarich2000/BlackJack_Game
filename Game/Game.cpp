#include "Game.h"
#include <algorithm>

#define number_of_decks_in_DeckPile 4

void BlackJackGame::addPlayers(IBlackJackPlayer * player) {
    _Players.push_back(player);
}

 BlackJackGame::BlackJackGame():_DeckPile(number_of_decks_in_DeckPile), _Dealer(10000,&_DeckPile,&_Players)  {
 }

void BlackJackGame::check_to_deletePlayers(){
    auto newEnd = std::remove_if(_Players.begin(),_Players.end(),
                                  [](const IBlackJackPlayer* p){
                                      return p->showMoney()==0||p->getChoice_StayOrLeave()=='e';} );
    _Players.erase(newEnd,_Players.end());
}

void BlackJackGame::updateDeckPile() {
    _DeckPile=BlackJack_DeckPile (number_of_decks_in_DeckPile); // Casino brings a new DeckPile for Dealer
    _Dealer.setDeckPile(&_DeckPile);
}

void BlackJackGame::startGame() {

    while (true) {

        _Dealer.startNewRound();

        check_to_deletePlayers();


        if (_DeckPile.size()==25) {
            updateDeckPile();
        }

        // Ending
        if (_Players.empty()||_Dealer.showMoney()==0) break;
    }
}