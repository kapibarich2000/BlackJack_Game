#pragma once
#include <Cards.h>
//#include <iCardGame.h>
#include <vector>

class Hand{
public:

    Hand() = default;

    void setCard(Card card);


    std::string getFirstCardsName() const;
    void showCardsName() const;
    int getFirstCardValue() const;
    int getCardsValue();
    void ClearCards();
    int getNumberOfCards();

protected:
   std::vector<Card> _inHand;
};
