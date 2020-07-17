#pragma once
#include <Cards.h>
#include <iCardGame.h>
#include <vector>

class Hand: public IHand {
public:
    void setCard(Card card);
    int getAllValue() override;

   Card getCard(BlackJack_DeckPile* _DeckPile);
protected:
   std::vector<Card> _inHand;

};
