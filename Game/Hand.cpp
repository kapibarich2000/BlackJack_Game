#include "Hand.h"
#include <ctime>

void Hand::setCard(Card card) {
    _inHand.push_back(card);
}

int Hand::getValue(){
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

int Hand::getValue(int n){
    return _inHand[n].getValue();
}


Card Hand::getCardFromDeck(BlackJack_DeckPile* _DeckPile) {
    Card card = _DeckPile->moveCard();
   // _inHand.pop_back(); there is in move Card
    return card;
}


void Hand::showCardsName() {
    for (int i = 0; i < _inHand.size(); ++i) {
        std::cout<<this->_inHand[i].getName()<<", ";
    }
}
void Hand::showCardsName(int n) {
   std::cout<<this->_inHand[n].getName()<<"  ";
}
void Hand::showCardsValue(int n) {
        std::cout<<this->_inHand[n].getValue();
}
void Hand::showCardsValue() {
    for (int i = 0; i < _inHand.size(); ++i) {
        std::cout << this->_inHand[i].getName() << ", ";
    }
}

void Hand::Refresh(BlackJack_DeckPile& Deck_of_cards) {    //  Тасование Фишера-Йетса
    std::srand(time(NULL));
    int j;
    Card TempCard;
    for (int i = Deck_of_cards.size()-1; i > 1; i--)    {
        j = std::rand() % (i + 1);
        TempCard=Deck_of_cards[j];
        Deck_of_cards[j]=Deck_of_cards[i];
        Deck_of_cards[i]=TempCard;
       //std::swap(_Deck_of_cards[j], _Deck_of_cards[i]);
    }
}

void Hand::ClearCards() {
    _inHand.clear();
}

int Hand::getNumberOfCards() {
    return _inHand.size();
}

