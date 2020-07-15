#pragma once
#include <iCardGame.h>

class BlackJack_Player: public IPlayer {
public:
    BlackJack_Player(int Money):IPlayer(Money){};
    const bool Hit() override;
    const int getMoney() override ;
    //bool Double();

};