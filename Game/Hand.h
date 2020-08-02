#pragma once
#include <Cards.h>
#include <iCardGame.h>
#include <vector>

class Hand{
public:

    Hand() = default;

    void setCard(Card card);

    int getValue(int n);
    int getValue();

    Card getCardFromDeck(BlackJack_DeckPile* _DeckPile);
    void showCardsName(int n);
    void showCardsName();
    void showCardsValue(int n);
    void showCardsValue();
    void  Refresh(BlackJack_DeckPile& _DeckPile);
    void ClearCards();
    int getNumberOfCards();

protected:
   std::vector<Card> _inHand;
};
