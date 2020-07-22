#include "Player.h"
#include <Dealer.h>
#include <iostream>
#include <iCardGame.h>


BlackJack_Player::BlackJack_Player(int Money, std::string Name) :_Money(Money),_Name(Name) {
    _Insurance=0;
    _isBlackJack= false;
    _Choice='c';
}

void BlackJack_Player:: setChoice(int n) {
    if (_Money!=0&&n==4&&!(_isBlackJack)){
        std::cout<<"Stand, Hit, Double or Insurance ? :   ";
        std::cin>>_Choice;
        while (_Choice!='h'&&_Choice!='s'&&_Choice!='e'&&_Choice!='d'&&_Choice!='i'){
            std::cout<<"! Enter the correct character !"<<std::endl;
            std::cout<<"Stand, Hit, Double or Insurance ? :   ";
            std::cin>>_Choice;
        }
    }
    else if(_isBlackJack){
        std::cout<<"Stand or Payment ? :   ";
        std::cin>>_Choice;
        while (_Choice!='s'&&_Choice!='e'&&_Choice!='p'){
            std::cout<<"! Enter the correct character !"<<std::endl;
            std::cout<<"Stand or Payment ? :   ";
            std::cin>>_Choice;
        }
    }
    else if (_Money!=0&&n==3){
        std::cout<<"Stand, Hit or Double ? : ";
        std::cin>>_Choice;
        while (_Choice!='h'&&_Choice!='s'&&_Choice!='e'&&_Choice!='d'){
            std::cout<<"! Enter the correct character !"<<std::endl;
            std::cout<<"Stand, Hit or Double ? :   ";
            std::cin>>_Choice;
        }
    }
    else{
        std::cout<<"Stand or Hit ? :   ";
        std::cin>>_Choice;
        while (_Choice!='h'&&_Choice!='s'&&_Choice!='e'){
            std::cout<<"! Enter the correct character !"<<std::endl;
            std::cout<<"Stand or Hit ? :   ";
            std::cin>>_Choice;
        }
    }


}

char BlackJack_Player::getChoice() {
    return _Choice;
}



void BlackJack_Player::Make_Bet() {
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


void BlackJack_Player::Make_Double() {
    std::cout<<"You made a double: another "<<_Bet<<"$"<<std::endl;
    _Money-=_Bet;
    _Bet+=_Bet;
}

const int BlackJack_Player::showMoney() {return this->_Money;}



double BlackJack_Player::getBet() {
    return _Bet;
}

void BlackJack_Player::setPrize(double n) {
    _Money+=n;
}


void BlackJack_Player::addCard(Card card) {
    _Hand.setCard(card);
}

void BlackJack_Player::setInsurance() {
    _Insurance = _Bet/2;
    std::cout<<"You set an insurance bet: "<<_Insurance<<"\n\n";
}

int BlackJack_Player::getInsurance() {
    return _Insurance;
}

void BlackJack_Player::ClearHistory() {
    _Insurance=0;
    _isBlackJack= false;
    _Choice='c';
    _Hand.ClearCards();
}
