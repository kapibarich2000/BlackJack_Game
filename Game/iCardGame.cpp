#include "iCardGame.h"

// IPlayer   ________________________________________
IPlayer::IPlayer() {
    _Name="";
    _Money=0;
    _isBlackJack=false;
    _isBust=false;
}

const double IPlayer::showMoney() {
    return _Money;
}

const bool IPlayer::get_isBlackJack() {
    return _isBlackJack;
}
const bool IPlayer::get_isBust() {
    return _isBust;
}
const std::string IPlayer::getName() {
    return _Name;
}

void IPlayer::set_isBust() {
    std::cout<<getName()<<" - have bust !"<<std::endl;
    _isBust= true;
}

void IPlayer::set_isBlackJack() {
    _isBlackJack=true;
}

// IBlackJackPlayer   ________________________________________

IBlackJackPlayer::IBlackJackPlayer() {
    _Insurance=0;
    _Choice='c';
    _Bet=0;
}

void IBlackJackPlayer::clearHistory(){
    _Insurance=0;
    _isBlackJack= false;
    _isBust= false;
    _Choice='c';
    _Hand.ClearCards();
}

const char IBlackJackPlayer::getChoice() {
    return _Choice;
}

const double IBlackJackPlayer::getBet(){
    return _Bet;
}

const double IBlackJackPlayer::getInsurance() {
    return _Insurance;
}

void IBlackJackPlayer::setPrize(double n) {
    _Money+=n;
}

void IBlackJackPlayer::setInsurance() {
        _Insurance = _Bet/2;
        _Money-=_Insurance;
        std::cout<<_Name<<", you set an insurance bet: "<<_Insurance<<"\n\n";
}

void IBlackJackPlayer::setDouble(){
    std::cout<<_Name<<", you made a double - add another "<<_Bet<<"$"<<" to the bet "<<std::endl;
    _Money-=_Bet;
    _Bet+=_Bet;
}



// IDealer ________________________________________


