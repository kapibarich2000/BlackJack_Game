#include "Player.h"
#include <Dealer.h>
#include <iostream>
#include <iCardGame.h>


BlackJack_Player::BlackJack_Player(int Money, std::string Name) :_Money(Money),_Name(Name) {}

char const BlackJack_Player:: Hit_or_Stand() {
    char choice;
    std::cin>>choice;
    while (choice!='h'||choice!='s'){
        std::cout<<"! Enter the correct character !"<<std::endl;
        std::cin>>choice;
    }
    return choice;
}

void BlackJack_Player::Make_Bet() {
    int Bet;
    std::cout<<"You have: "<<_Money<<"units"<<std::endl;
    std::cout<<"Your bet: ";
    std::cin>>Bet;
    while (Bet<=0||Bet>_Money){
        std::cout<<"Please make a correct bet"<<std::endl;
        std::cout<<"Your bet:  ";
        std::cin>>Bet;
    }
    this->_Money-=Bet;
     _Bets=Bet;
}

const int BlackJack_Player::showMoney() {return this->_Money;}

void BlackJack_Player::addCard(Card card) {
    _Hand.setCard(card);
}






//bool BlackJack_Player::Double(){
//    return 0;
//}

