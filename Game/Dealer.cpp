#include "Dealer.h"
#include <Player.h>
#include <iostream>
#include <Cards.h>

BlackJack_Dealer::BlackJack_Dealer(double Money): _isBlackJack(false),_isBust(false){
    _Money=Money;
};

void BlackJack_Dealer::setDeckPile(BlackJack_DeckPile* DeckPile){
    this->_DeckPile=DeckPile;
}

BlackJack_DeckPile *BlackJack_Dealer::retPointonDeck() {
   return _DeckPile;
}

void BlackJack_Dealer::ClearHistory() {
    _isBlackJack=false;
    _isBust=false;
    _Hand.ClearCards();
}

double BlackJack_Dealer::givePrize(BlackJack_Player* Player) {
// //////////////////////// If the player has BlackJack, then he  can ask /////////////////////////////////////
// /////////////////to pay your winnings without waiting: "Does the dealer have a BlackJack" //////////////////
    if(Player->getChoice()=='p'){
        std::cout<<Player->getName()<<", your prize 2:1 from the bid : "<<Player->getBet()<<std::endl;
        _Money-=Player->getBet();
        return Player->getBet()*2; // This situation pays like a regular win
    }
    // ///////////////////////////// Checking who has too many cards  /////////////////////////////////////////
    else if(Player->get_isBust()||this->get_isBust()){
        // /////////////////////////// First it is taken from the player ///////////////////////////////////////
        if (Player->get_isBust()){
            std::cout<<Player->getName()<<", you have bust !"<<std::endl;
            std::cout<<"You lost: "<<Player->getBet()<<"$"<<std::endl;
            _Money+=Player->getBet(); // Появилась 20 из воздуха
            return 0;
        }
        else{
            std::cout<<"Dealer have bust !\n"<<Player->getName()<<", you won: "<<Player->getBet()<<"$"<<std::endl;
            _Money-=Player->getBet();
            return Player->getBet()*2;
        }
    }
    // ////////////////////////// If the player has BlackJack and dealer hasn't ////////////////////////////////
    else if(Player->get_isBlackJack()&&!(this->_isBlackJack)){
        std::cout<<Player->getName()<<", your prize 3:2 from the bid : "<<Player->getBet()*3/2
        <<"$"<<std::endl;
        _Money-=Player->getBet()*3/2; // Winning
        // ///////////////////// In this case, the insurance is burned /////////////////////////////////////////
        if (Player->getInsurance()){
            std::cout<<"But you lose your Insurance: "<<Player->getInsurance()<<std::endl;
            _Money+=Player->getInsurance();
        }
        return Player->getBet()*5/2; // Winning + Bet
    }
    // ////////////////////////// If the dealer has BlackJack //////////////////////////////////////////////////
    else if (this->_isBlackJack){
        // //////////////////////////// Compensate to player with insurance ////////////////////////////////////
        if (Player->getInsurance()!=0) {
            std::cout<<Player->getName()<<", you return your Insurance in a 2:1 ratio: " << Player->getInsurance()*3
            << "$" << std::endl;
            return Player->getInsurance()*3;
        }
        else{
                std::cout<<Player->getName()<<", you lost your "<<Player->getBet()<<"$"<<std::endl;
                _Money+=Player->getBet();
                return 0;
        }
    }
    // //////////////////////// If the player's value == the dealer's value ////////////////////////////////////
    else if(Player->_Hand.getValue()==this->_Hand.getValue()){
        std::cout<<Player->getName()<<", you stay with your own PUSH. Returned: "<<Player->getBet()<<"$"<<std::endl;
        return Player->getBet();

    }
    // //////////////////////// If the player's value > the dealer's value ////////////////////////////////////
    else if(Player->_Hand.getValue()>this->_Hand.getValue()){
        std::cout<<Player->getName()<<", you won: "<<Player->getBet()<<std::endl;
        _Money-=Player->getBet();
        return Player->getBet()*2;
    }
    // //////////////////////// If the player's value < the dealer's value ////////////////////////////////////
    else{
        std::cout<<Player->getName()<<", you lost: "<<Player->getBet()<<"$\n";
        _Money+=Player->getBet();
        return 0;
    }
    return 0;
}

int const BlackJack_Dealer::getNumberOfCards() {
    return _Hand.getNumberOfCards();
}

void BlackJack_Dealer::TakeInsurance(BlackJack_Player* Player) {
    _Money+=Player->getInsurance();
}


bool const BlackJack_Dealer::get_isBust() {return _isBust;}
void BlackJack_Dealer::set_isBust() {_isBust= true;}

bool const BlackJack_Dealer::get_isBlackJack(){return _isBlackJack;}
void BlackJack_Dealer::set_isBlackJack(){_isBlackJack=true;}
