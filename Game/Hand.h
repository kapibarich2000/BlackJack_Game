#pragma once
#include <Cards.h>
//#include <iCardGame.h>
#include <vector>

class Hand{
public:

    Hand() = default;
    ~Hand() = default;

    void setCard(Card card);

    std::string getFirstCardsName() const;
    int getFirstCardValue() const;
    int getCardsValue();
    int getNumberOfCards();

    void showCardsName() const;

    void ClearCards();

protected:
   std::vector<Card> _inHand{};
};
