#pragma once
#include <Cards.h>
#include <Dealer.h>
#include <Hand.h>
#include <Player.h>
#include <vector>


class BlackJackGame{

private:
    std::vector<BlackJack_Player> Players;
    std::vector<int> Bets;
    BlackJack_Dealer Dealre;

    BlackJack_DeckPile DeckPile;

    BlackJack_Player CreatePlayer(int Money);
    BlackJack_Dealer CreateDealer(int Money);
    BlackJack_DeckPile CreateDeckPile();
//    void ConnectParticipant();
//    void DisconnectPlayers(int id);


public:
    BlackJackGame();
    void Start();

};