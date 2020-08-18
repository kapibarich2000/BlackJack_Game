#include "Hand.h"

void Hand::setCard(Card card) {
    _inHand.push_back(card);
}


int Hand::getCardsValue(){
    int value=0;
    int ace=0;
    for (auto & i : _inHand) {
        value += i.getValue();
        if (i.getValue() == 11) ace++; // counting of aces
    }
    while(value>21 && ace>0){
        value-=10;
        ace--;
    }
    return  value;
}

std::string Hand::getFirstCardsName() const{
    return this->_inHand[0].getName(); //<<"  "
}

int Hand::getFirstCardValue() const{
    return _inHand[0].getValue();
}

int Hand::getNumberOfCards() {
    return _inHand.size();
}


void Hand::showCardsName() const{
    for (int i = 0; i < _inHand.size(); ++i) {
        std::cout<<this->_inHand[i].getName()<<", ";
    }
}


void Hand::ClearCards() {
    _inHand.clear();
}


