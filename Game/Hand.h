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

    void showCardsName() const;

    void ClearCards();

private:
   std::vector<Card> _inHand{};
};
