#pragma once
#include <Cards.h>
#include <Dealer.h>
#include <Hand.h>
#include <RealPlayer.h>
#include <vector>

class BlackJackGame{

private:

    std::vector<IBlackJackPlayer*> _players;
    BlackJack_DeckPile _deckPile;
    BlackJack_Dealer _dealer;


public:
    BlackJackGame();
    void startGame();

    void updateDeckPile();
    void check_to_deletePlayers();
    void addPlayers(IBlackJackPlayer * human_player);
};