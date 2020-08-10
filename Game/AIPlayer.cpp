#include "AIPlayer.h"

BlackJack_AIPlayer::BlackJack_AIPlayer() {
    std::cout<<"Enter the AIPlayer's name : ";
    std::cin>>_Name;
    _Name=_Name+"_AI";
    while (1){
        std::cout<<"How much money($) it has? : ";
        std::cin>>_Money;
        if (std::cin.fail()) { // To prevent the user from entering a letter
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            continue;
        }
        break;
    }
    std::cout<<std::endl; // For beauty
}

void BlackJack_AIPlayer::makeBet() {
    int bet = _Money/100*15;
    while (bet%5!=0){
        bet++;
    }
    _Bet=bet;
    std::cout << getName()<<"'s Bet: "<<_Bet<<"$\n";
    _Money-=_Bet;
}

void BlackJack_AIPlayer::makeDouble() {
    if ((_Money>=_Bet/2)&&(_Hand.getCardsValue()==10||_Hand.getCardsValue()==11)){
        std::cout << getName()<<" chose Double\n";
        _Choice='d';
        setDouble();
    }
    else{
        makeMove();
    }
}

// 1 Ivan 100 1 John 100

void BlackJack_AIPlayer::makeInsuranceOrPayment() {
    if (this->_isBlackJack) {
            std::cout << getName()<<" chose Payment\n";
            _Choice='p';
    }
    else{
        if (this->_Money >= this->getBet() / 2) {
            if (_Hand.getCardsValue()==20||_Hand.getCardsValue()==19){
                std::cout << getName()<<" chose Insurance\n";
                _Choice='i';
                setInsurance();
            }
            else{
                std::cout << getName()<<" chose Stand\n";
                _Choice='s';
            }

        }
    }
    if (getChoice()=='i') setInsurance();
}

void BlackJack_AIPlayer::makeMove() {
    if (_Hand.getCardsValue()<17){
        std::cout << getName()<<" chose Hit\n";
        _Choice='h';
    }
    else{
        std::cout << getName()<<" chose Stand\n";
        _Choice='s';
    }
}

void BlackJack_AIPlayer::makeChoice_StayOrLeave() {
    // Play to win
    if (_Money<20){
        std::cout << getName()<<" chose Exit\n";
        _Choice='e';
    }
    std::cout << getName()<<" chose Continue\n";
    _Choice='s';


}
