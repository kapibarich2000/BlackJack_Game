#include <iostream>
#include "AIPlayer.h"
#include <UsefulFunctions.h>

BlackJack_AIPlayer::BlackJack_AIPlayer() {
    std::cout<<"Enter the AIPlayer's name :";
    std::cin>>_name;
    _name=_name+"_AI";
    while (true){
        std::cout<<"How much money($) it has? :";
        _money=EnterInt();
        if (_money<20) {
            std::cout<<"Need more money (>20) for AI to play the BlackJack\n";
            continue;
        }
        break;
    }
}

void BlackJack_AIPlayer::makeBet() {
    std::cout<<_name<<", you have: "<<_money<<"$"<<std::endl;
    int bet = _money/100*15;
    while (bet%5!=0){
        bet++;
    }
    _bet=bet;
    std::cout << getName()<<"'s Bet: "<<_bet<<"$\n";
    _money-=_bet;
}

void BlackJack_AIPlayer::makeDouble() {
    if ((_money>=_bet/2)&&(_hand.getCardsValue()==10||_hand.getCardsValue()==11)){
        std::cout << getName()<<" chose Double\n";
        _choice='d';
        setDouble();
    }
    else{
        makeMove();
    }
}

void BlackJack_AIPlayer::makeInsuranceOrPayment() {
    if (this->_isBlackJack) {
            std::cout << getName()<<" chose Payment\n";
            _choice='p';
    }
    else{
        if (this->_money >= this->getBet() / 2) {
            if (_hand.getCardsValue()==20||_hand.getCardsValue()==19){
                std::cout << getName()<<" chose Insurance\n";
                _choice='i';
                setInsurance();
            }
            else{
                std::cout << getName()<<" chose Stand\n";
                _choice='s';
            }
            if (this->getChoice() == 'i') this->setInsurance();
        }
    }
    if (getChoice()=='i') setInsurance();
}

void BlackJack_AIPlayer::makeMove() {
    if (_hand.getCardsValue()<17){
        std::cout << getName()<<" chose Hit\n";
        _choice='h';
    }else{
        std::cout << getName()<<" chose Stand\n";
        _choice='s';
    }
}


char BlackJack_AIPlayer::getChoice_StayOrLeave()const {
    // Play to win
    if (_money<20){
        std::cout << getName()<<" chose Exit\n";
        return'e';
    }
    std::cout << getName()<<" chose Continue\n";
    return 's';

}
