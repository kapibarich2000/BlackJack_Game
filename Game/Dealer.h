#pragma once
#include <iCardGame.h>
#include <Cards.h>
#include <Hand.h>
#include <Player.h>

class BlackJack_Dealer: public IDealer, public IPlayer {
private:
    BlackJack_DeckPile* _DeckPile;
public:

    Hand _Hand;
    bool _isBlackJack;
    bool _isBust;

    BlackJack_Dealer()=delete ;
    BlackJack_Dealer(double Money);
    BlackJack_DeckPile* retPointonDeck();
    void setDeckPile(BlackJack_DeckPile* DeckPile);
    double givePrize(BlackJack_Player& Player);
    int getNumberOfCards();
    void TakeInsurance(BlackJack_Player& Player);

    void ClearHistory();

};
