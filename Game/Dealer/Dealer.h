#pragma once
//#include <Player.h>
#include <iCardGame.h>
class Player;

class BlackJack_Dealer: public IDealer {
public:
    BlackJack_Dealer(int Money):IDealer(Money){};
    void getStep(const Player* player);

};
