#pragma once
#include <iCardGame.h>

class BlackJack_RealPlayer: public IBlackJackPlayer {
public:

    BlackJack_RealPlayer();

    void makeBet() override;
    void makeDouble()override;
    void makeInsuranceOrPayment() override;
    void makeMove() override;

    char getChoice_StayOrLeave()const override;

};