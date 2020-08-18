#pragma once
#include <iCardGame.h>
#include <memory>
#include <Cards.h>
#include <Hand.h>
#include <RealPlayer.h>

class BlackJack_Dealer: public IDealer {
public:

    BlackJack_Dealer()=delete;
    BlackJack_Dealer(double Money,BlackJack_DeckPile* DeckPile,std::vector<std::shared_ptr<IBlackJackPlayer>>* Players);
    ~BlackJack_Dealer()=default;

    void setDeckPile(BlackJack_DeckPile* DeckPile);
    void startNewRound();

    void allowMakeBets();

    void dealsCards();

    void checkSecondCard();

    void giveMove();
    void TakeInsuranceFrom(const std::shared_ptr<IBlackJackPlayer>& Player);
    void additionalDistribution();

    void makePayments ();
};
