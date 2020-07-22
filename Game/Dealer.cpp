#include "Dealer.h"
#include <Player.h>
#include <iostream>
#include <Cards.h>

BlackJack_Dealer::BlackJack_Dealer(int Money) {
    this->_Money=Money;
    _isBlackJack=false;
    _isBust=false;
};

void BlackJack_Dealer::setDeckPile(BlackJack_DeckPile* DeckPile){
    this->_DeckPile=DeckPile;
}

int const BlackJack_Dealer::showMoney() {
    return this->_Money;
}

BlackJack_DeckPile *BlackJack_Dealer::retPointonDeck() {
   return _DeckPile;
}

void BlackJack_Dealer::ClearHistory() {
    _isBlackJack=false;
    _isBust=false;
    _Hand.ClearCards();
}

double BlackJack_Dealer::givePrize(BlackJack_Player& Player) {

    if(Player.getChoice()=='p'){
        std::cout<<"Your prize 2:1 from the bid : "<<Player.getBet()<<std::endl;
        _Money-=Player.getBet();
        return Player.getBet()*2;
    }

    else if(Player._isBust||this->_isBust){
        if (this->_isBust){
            std::cout<<"Dealer have bust !\n You won: "<<Player.getBet()<<"$"<<std::endl;
            _Money-=Player.getBet();
            return Player.getBet()*2;
        }
        else{
            std::cout<<"You have bust !"<<std::endl;
            std::cout<<"You lost: "<<Player.getBet()<<"$"<<std::endl;
            _Money+=Player.getBet(); // Появилась 20 из воздуха
            return 0;
        }
    }

    else if(Player._isBlackJack&&!(this->_isBlackJack)){
        std::cout<<"Your prize 3:2 from the bid : "<<Player.getBet()*3/2<<"$"<<std::endl; // Make bet: 0,5 \ 1 \ 5 \ 10 \ 20 \ 50 \ 100
        _Money-=Player.getBet()*3/2;
        return Player.getBet()*5/2;
    }

    else if (this->_isBlackJack){
        if (Player._isBlackJack){
            std::cout<<Player._Name<<"  "<<"Dealer and You have BlackJack"<<std::endl;
            if(Player.getInsurance()==0) {
                std::cout<<"You return your "<<Player.getBet()<<"$"<<std::endl;
                return Player.getBet();
            }
            else{
                std::cout<<"You return your "<<Player.getBet()<<"$"<<std::endl;
                std::cout<<"And lost your insurance"<<Player.getBet()<<"$"<<std::endl;
                _Money+=Player.getBet()/3;
                return Player.getBet()/3*2;
            }
        }
        else{
            std::cout<<"Dealer have BlackJack"<<std::endl;
            if(Player.getInsurance()==0) {
                std::cout<<"You lost your Bet "<<Player.getBet()<<"$"<<std::endl;
                _Money+=Player.getBet();
            }
            else{
                std::cout<<"You return your Insurance in a 2:1 ratio: "<<Player.getInsurance()*3<<"$"<<std::endl;
                std::cout<<"And lost your Bet "<<Player.getBet()<<"$"<<std::endl;
                return Player.getInsurance()*3;
            }
        }
    }
    else if(this->_isBust){
        std::cout<<"You won: "<<Player.getBet();
        _Money-=Player.getBet();
        return Player.getBet()*2;
    }
    else if(Player._isBust){
        std::cout<<"You have bust!\n"<<"You lost: "<<Player.getBet();
        _Money+=Player.getBet();
        return 0;
    }
    else if(Player._Hand.getValue()==this->_Hand.getValue()){
        std::cout<<"Stay with your own PUSH. Returned: "<<Player.getBet()<<"$";
        return Player.getBet();

    }
    else if(Player._Hand.getValue()>this->_Hand.getValue()){
        std::cout<<"You won: "<<Player.getBet();
        _Money-=Player.getBet();
        return Player.getBet()*2;
    }
    else{
        std::cout<<"You lost: "<<Player.getBet()<<"$\n";
        _Money+=Player.getBet();
        return 0;
    }
    return 0;
}

int BlackJack_Dealer::getNumberOfCards() {
    return _Hand.getNumberOfCards();
}



//void Dealer::getStep(const Player *player) {
//}
