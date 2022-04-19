#pragma once
#include <iCardGame.h>

class BlackJack_AIPlayer: public IBlackJackPlayer {
public:
    BlackJack_AIPlayer();
    ~BlackJack_AIPlayer()=default;

    void makeBet() override;
    void makeDouble() override;
    void makeInsuranceOrPayment() override;
    void makeMove() override;

    char getChoice_StayOrLeave()const override;
};
