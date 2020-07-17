#include "Dealer.h"
#include <Player.h>
#include <iostream>
#include <Cards.h>

BlackJack_Dealer::BlackJack_Dealer(int Money) {
    this->_Money=Money;
};

void BlackJack_Dealer::setDeckPile(BlackJack_DeckPile* DeckPile){
    this->_DeckPile=DeckPile;
}

int const BlackJack_Dealer::showMoney() {
    return this->_Money;
}





//void Dealer::getStep(const Player *player) {
//}
