#pragma once
#include <iCardGame.h>
#include <Hand.h>

class BlackJack_Player: public IPlayer {
    int _Money;

public:
    std::string _Name;
    Hand _Hand;

    BlackJack_Player()=delete;
    BlackJack_Player(int Money = 100, std::string Name = "Player");

    const int showMoney() override ;

    int Make_Bet();
    char const Hit_or_Stand();

    //bool Double();

    void addCard(Card card);
};