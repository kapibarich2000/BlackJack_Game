#pragma once
#include <Cards.h>
#include <Dealer.h>
#include <Hand.h>
#include <Player.h>
#include <vector>


class BlackJackGame{
    std::vector<BlackJack_Player> Players;
    BlackJack_Dealer Dealre;

    BlackJack_Player CreatePlayer(int Money);
    BlackJack_Dealer CreateDealer(int Money);
    void CreateDeckPile();
    void ConnectParticipant(){}
    void DisconnectParticipant(){}

public:
    void Start();

};