#pragma once
#include <iCardGame.h>
#include <Hand.h>
#include <string>

class BlackJack_RealPlayer: public IBlackJackPlayer {
public:

    BlackJack_RealPlayer();

    void makeBet() override;
    void makeDouble();
    void makeInsuranceOrPayment() override;
    void makeMove() override;
    void makeChoice_StayOrLeave() override;

};