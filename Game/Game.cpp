#include <iostream>
#include "Game.h"
#include <RealPlayer.h>
#include <AIPlayer.h>
#include <algorithm>

#define number_of_decks_in_DeckPile 4

void BlackJackGame::addPlayers(IBlackJackPlayer * player) {
    _Players.push_back(player);
}

void BlackJackGame::addAiPlayers() {}

 BlackJackGame::BlackJackGame():_DeckPile(number_of_decks_in_DeckPile), _Dealer(10000,&_DeckPile,&_Players)  {
 }

void BlackJackGame::check_to_deletePlayers(){

    for (int i = 0; i < _Players.size(); ++i) {

        //  The player was left without money
        if (_Players[i]->showMoney()==0){
            std::cout<<_Players[i]->getName()<<", you lost all your money"<<std::endl;
            std::cout << "Player: " << _Players[i]->getName() << " leave the game!\n"<<std::endl;
            _VectorToDeletePlayers.push_back(_Players[i]->getName());
            continue;
        }
        // Do you want to continue playing?
        _Dealer.ask_aboutContinuing(_Players[i]);

        //if (_Players[i]->getChoice()=='e') _VectorToDeletePlayers.push_back(_Players[i]->getName());
    }

    // Take each player and check

    _Players.erase(std::remove_if(_Players.begin(),_Players.end(),[](const IBlackJackPlayer& p){return p.showMoney()==0;}));

    if (!(_VectorToDeletePlayers.empty())){
        for (int i = _Players.size()-1; i>=0 && !(_VectorToDeletePlayers.empty()) ; --i) {
            for (int j = _VectorToDeletePlayers.size()-1; j >=0 ; --j) {
                if(_Players[i]->getName()==_VectorToDeletePlayers[j]){
                    _Players.erase(_Players.begin()+i);
                    _VectorToDeletePlayers.erase(_VectorToDeletePlayers.begin()+j);
                    break;
                }

            }
        }
    }
}

void BlackJackGame::updateDeckPile() {
    _DeckPile=BlackJack_DeckPile (number_of_decks_in_DeckPile); // Casino brings a new DeckPile for Dealer
    _Dealer.setDeckPile(&_DeckPile);
}

void BlackJackGame::startGame() {

    while (1) {

        _Dealer.startNewRound();

        check_to_deletePlayers();


        if (_DeckPile.size()==25) {
            updateDeckPile();
        }

        // Ending
        if (_Players.size()==0||_Dealer.showMoney()==0) break;


    }
}