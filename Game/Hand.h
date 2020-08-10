#pragma once
#include <Cards.h>
//#include <iCardGame.h>
#include <vector>

class Hand{
public:

    Hand() = default;

    void setCard(Card card);

    int getFirstCardValue();
    int getCardsValue();

    void showFirstCardsName();
    void showCardsName();
    void showFirstCardsValue();
    void showCardsValue();
    void ClearCards();
    int getNumberOfCards();

protected:
   std::vector<Card> _inHand;
};
