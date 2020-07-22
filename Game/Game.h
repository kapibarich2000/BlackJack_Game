#pragma once
#include <Cards.h>
#include <Dealer.h>
#include <Hand.h>
#include <Player.h>
#include <vector>


class BlackJackGame{

private:
    std::vector<BlackJack_Player*> _Players;
    BlackJack_DeckPile _DeckPile;

//    void ConnectParticipant();
//    void DisconnectPlayers(int id);


public:
  //  BlackJackGame();
    int _PlayersSize;

    void addPlayer(BlackJack_Player* player){
        _Players.push_back(player);
    }
    void StartGame();

     BlackJack_DeckPile getNewDeckPile();
};