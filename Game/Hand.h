#pragma once
#include <Cards.h>
#include <iCardGame.h>
#include <vector>

class Hand: public IHand {
public:
    void setCard(Card card);
    int getAllValue() override;
    void _makeBets(){}
    Card getCardFromDeck(BlackJack_DeckPile* _DeckPile);
    void showCardsName(int n);
    void showCardsName();
    void showCardsValue(int n);
    void showCardsValue();
    void  Refresh(BlackJack_DeckPile* _DeckPile);

protected:
   std::vector<Card> _inHand;


};
