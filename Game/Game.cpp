#include "Game.h"
#include <algorithm>

#define number_of_decks_in_DeckPile 4


void BlackJackGame::addPlayers(IBlackJackPlayer * player) {
    _players.push_back(player);
}

 BlackJackGame::BlackJackGame():_deckPile(number_of_decks_in_DeckPile), _dealer(10000,&_deckPile,&_players)  {
 }

void BlackJackGame::check_to_deletePlayers(){
    auto newEnd = std::remove_if(_players.begin(),_players.end(),
                                  [](const IBlackJackPlayer* p){
                                      return p->showMoney()==0||p->getChoice_StayOrLeave()=='e';} );
    _players.erase(newEnd,_players.end());
}

void BlackJackGame::updateDeckPile() {
    _deckPile=BlackJack_DeckPile (number_of_decks_in_DeckPile); // Casino brings a new DeckPile for Dealer
    _dealer.setDeckPile(&_deckPile);
}

void BlackJackGame::startGame() {

    while (true) {

        _dealer.startNewRound();

        check_to_deletePlayers();


        if (_deckPile.size()==25) {
            updateDeckPile();
        }

        // Ending
        if (_players.empty()||_dealer.showMoney()==0) break;
    }
}


