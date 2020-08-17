#pragma once
#include <iCardGame.h>
#include <memory>
#include <Cards.h>
#include <Hand.h>
#include <RealPlayer.h>

class BlackJack_Dealer: public IDealer, public IPlayer {
public:

    BlackJack_Dealer(double Money,BlackJack_DeckPile* DeckPile,std::vector<std::shared_ptr<IBlackJackPlayer>>* Players);
    BlackJack_Dealer()=delete;

    void setDeckPile(BlackJack_DeckPile* DeckPile);
    void startNewRound();

    void allowMakeBets();

    void dealsCards();

    void showFirsCard();
    void checkSecondCard();

    void giveMove();
    void TakeInsuranceFrom(std::shared_ptr<IBlackJackPlayer> Player); // Доделать надо, забрать еще и у игрока
    void additionalDistribution();

    void makePayments ();

    void clearHistory() override;
};
