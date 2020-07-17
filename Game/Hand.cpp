#include "Hand.h"

void Hand::setCard(Card card) {
    _inHand.push_back(card);
}

int Hand::getAllValue(){
    int value=0;
    int ace=0;
    for (int i = 0; i < _inHand.size(); ++i) {
        value += _inHand[i].getValue();
        if (_inHand[i].getValue() == 11) ace++; // counting of aces
    }
    if (value>21 && ace>0){
        value-=10;
        ace--;
    }
    return  value;
}

Card Hand::getCard(BlackJack_DeckPile* _DeckPile) {
    Card card = _DeckPile->moveCard();
    _inHand.pop_back();
    return card;
}


