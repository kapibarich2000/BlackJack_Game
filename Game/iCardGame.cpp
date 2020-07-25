#include "iCardGame.h"

// IPlayer   ________________________________________
const double IPlayer::showMoney() {
    return _Money;
}
const std::string IPlayer::getName() {
    return _Name;
}

void IPlayer::Make_Bet(){
        std::cout<<"You have: "<<_Money<<"$"<<std::endl;

        while (1){
            std::cout<<"Your bet: ";
            std::cin>>_Bet;
            if (std::cin.fail()) { // Проверка на ввод числа
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                continue;
            }

            if (_Bet<=0||_Bet>_Money) // убеждаемся, что nAge является положительным числом
                continue;

            break;
        }
        this->_Money-=_Bet;
    }

const double IPlayer::getBet(){
    return _Bet;
}

void IPlayer::setPrize(double n) {
    _Money+=n;
}

// IDealer ________________________________________


