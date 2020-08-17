#include "iCardGame.h"

// IPlayer   ________________________________________
IPlayer::IPlayer() {
    _name="";
    _money=0;
    _isBlackJack=false;
    _isBust=false;
}

double IPlayer::getBankSize()const{
    if (_money==0){
        std::cout<<_name<<", you lost all your money"<<std::endl;
        std::cout << "Player: " << _name << " leave the game!\n"<<std::endl;
    }
    return _money;
}
bool IPlayer::get_isBlackJack()const{
    return _isBlackJack;
}
bool IPlayer::get_isBust()const{
    return _isBust;
}
std::string IPlayer::getName()const{
    return _name;
}

void IPlayer::set_isBust() {
    std::cout<<getName()<<" - have bust !"<<std::endl;
    _isBust= true;
}
void IPlayer::set_isBlackJack() {
    _isBlackJack=true;
}
void IPlayer::setPrize(double n) {
    _money+=n;
}

void IPlayer::showAllCards() {
    std::cout << this->getName() << " have:  ";
    this->_hand.showCardsName();
    std::cout << "(";
    std::cout << this->_hand.getCardsValue();
    std::cout << ")\n";
    std::cout <<"__________________" << std::endl;
}

// IBlackJackPlayer   ________________________________________

IBlackJackPlayer::IBlackJackPlayer() {
    _insurance=0;
    _choice='c';
    _bet=0;
}

void IBlackJackPlayer::clearHistory(){
    _insurance=0;
    _isBlackJack= false;
    _isBust= false;
    _choice='c';
    _hand.ClearCards();
}

char IBlackJackPlayer::getChoice() const {
    return _choice;
}

double IBlackJackPlayer::getBet()const{
    return _bet;
}

double IBlackJackPlayer::getInsurance() const {
    return _insurance;
}

double IBlackJackPlayer::takeInsurance(){
    double insurance = _insurance;
    _insurance=0;
    return insurance;
}


void IBlackJackPlayer::setInsurance() {
        _insurance = _bet/2;
        _money-=_insurance;
        std::cout<<_name<<", you set an insurance bet: "<<_insurance<<"\n\n";
}

void IBlackJackPlayer::setDouble(){
    std::cout<<_name<<", you made a double - add another "<<_bet<<"$"<<" to the bet "<<std::endl;
    _money-=_bet;
    _bet+=_bet;
}


