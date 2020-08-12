#include "iCardGame.h"

// IPlayer   ________________________________________
IPlayer::IPlayer() {
    _Name="";
    _Money=0;
    _isBlackJack=false;
    _isBust=false;
}

double IPlayer::showMoney()const{
    if (_Money==0){
        std::cout<<_Name<<", you lost all your money"<<std::endl;
        std::cout << "Player: " << _Name << " leave the game!\n"<<std::endl;
    }
    return _Money;
}

bool IPlayer::get_isBlackJack()const{
    return _isBlackJack;
}
bool IPlayer::get_isBust()const{
    return _isBust;
}
std::string IPlayer::getName()const{
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

char IBlackJackPlayer::getChoice() const {
    return _Choice;
}

double IBlackJackPlayer::getBet()const{
    return _Bet;
}

double IBlackJackPlayer::getInsurance()const{
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