#pragma once
#include <Cards.h>
#include <Dealer.h>
#include <Hand.h>
#include <Player.h>
#include <vector>

class BlackJackGame{

private:
    std::vector<BlackJack_Player> _Players;
    BlackJack_DeckPile _DeckPile;
    BlackJack_Dealer _Dealer;
    int _PlayersSize=0;
    std::vector<int> _ListToDelete;
    int const _maxPlayers =15;
public:
    BlackJackGame();
    void startGame();
    void startNewRound();
    void deletePlayer(std::vector<BlackJack_Player>& _Players, std::vector<int>& _ListToDelete);
};