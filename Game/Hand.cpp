#include "Hand.h"
#include <ctime>

void Hand::setCard(Card card) {
    _inHand.push_back(card);
}

int Hand::getCardsValue(){
    int value=0;
    int ace=0;
    for (int i = 0; i < _inHand.size(); ++i) {
        value += _inHand[i].getValue();
        if (_inHand[i].getValue() == 11) ace++; // counting of aces
    }
    while(value>21 && ace>0){
        value-=10;
        ace--;
    }
    return  value;

}

int Hand::getFirstCardValue(){
    return _inHand[0].getValue();
}


void Hand::showCardsName() {
    for (int i = 0; i < _inHand.size(); ++i) {
        std::cout<<this->_inHand[i].getName()<<", ";
    }
}
void Hand::showFirstCardsName() {
   std::cout<<this->_inHand[0].getName()<<"  ";
}


void Hand::showFirstCardsValue() {
        std::cout<<this->_inHand[0].getValue();
}
void Hand::showCardsValue() {
    for (int i = 0; i < _inHand.size(); ++i) {
        std::cout << this->_inHand[i].getName() << ", ";
    }
}
// Ivan1 have: Ten Hearts, Two Hearts, Ace Hearts, Ace Spades,
//(24)
//Ivan1 - have bust !

// Omg  Something wrong!



void Hand::ClearCards() {
    _inHand.clear();
}

int Hand::getNumberOfCards() {
    return _inHand.size();
}

