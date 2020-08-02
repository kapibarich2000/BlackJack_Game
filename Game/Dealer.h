#pragma once
#include <iCardGame.h>
#include <Cards.h>
#include <Hand.h>
#include <Player.h>

class BlackJack_Dealer: public IDealer, public IPlayer {
private:
    BlackJack_DeckPile* _DeckPile;
    bool _isBust;
    bool _isBlackJack;

public:

    Hand _Hand;

    BlackJack_Dealer(double Money);

    BlackJack_DeckPile* retPointonDeck();
    void setDeckPile(BlackJack_DeckPile* DeckPile);
    double givePrize(BlackJack_Player* Player);
    int const getNumberOfCards();
    void TakeInsurance(BlackJack_Player* Player);

    bool const get_isBust();
    void set_isBust();

    bool const get_isBlackJack();
    void set_isBlackJack();

    void ClearHistory();

};
