#pragma once
#include <iCardGame.h>
#include <Cards.h>
#include <Hand.h>
#include <RealPlayer.h>

class BlackJack_Dealer: public IDealer, public IPlayer {
public:

    BlackJack_Dealer(double Money,BlackJack_DeckPile* DeckPile,std::vector<IBlackJackPlayer*>* Players);


    void setDeckPile(BlackJack_DeckPile* DeckPile);

    double distributionPrize(IBlackJackPlayer* Player);

    void TakeInsuranceFrom(IBlackJackPlayer* Player); // Доделать надо, забрать еще и у игрока

    void makePayments ();

    void startNewRound();
    void allowMakeBets();

    void clearHistory() override;


    void dealsCards();
};
