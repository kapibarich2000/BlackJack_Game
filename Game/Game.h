#pragma once
#include <Dealer.h>
#include <RealPlayer.h>
#include <AIPlayer.h>
#include <memory>
#include <vector>

class BlackJackGame{

private:

    std::vector<std::shared_ptr<IBlackJackPlayer>> _players;
    BlackJack_DeckPile _deckPile;
    BlackJack_Dealer _dealer;


public:
    BlackJackGame();
    void startGame();

    void updateDeckPile();
    void check_to_deletePlayers();
    void addPlayers(const std::shared_ptr<IBlackJackPlayer>& player);
};