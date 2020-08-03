#include "Player.h"
#include <iostream>
#include <utility> // ?
#include <iCardGame.h>


BlackJack_Player::BlackJack_Player(int Money, std::string Name):_Insurance(0),_isBlackJack(false){
    _Money=Money;
    _Name=Name;
    _Choice='c';
}


void BlackJack_Player:: setChoice(int n) {

    // ////////////////////////// 11 -> If dealer has Ace, you can make an  insurance //////////////////////////////////
    if (n==11) {
        if (this->_isBlackJack) {
            // ////////You can't make an insurance if you didn't have money, that match a half of bet   ////////////////
            if (this->_Money != this->getBet() / 2) {
                std::cout << getName()
                          << ", Do you want to make an insurance or want to Stand, or get payment"
                          << "now\n (s - Stand, i - Insurance, p - Payment) ? : ";
                std::cin >> _Choice;
                //  //////////////////////  Checking for _Choice  ///////////////////////////////////////
                while (_Choice != 's' && _Choice != 'i' && _Choice != 'p') {
                    std::cout << "! Enter the correct character !" << std::endl;
                    std::cout << getName()
                              << ", Do you want to make an insurance or want to Stand, or get payment"
                              << "now\n (s - Stand, i - Insurance, p - Payment) ? : ";
                    std::cin >> _Choice;
                }
            }
            else {
                std::cout << getName()
                          << ", Do you want to Stand, or get payment "
                          << "now (S - Stand, p - Payment) ? : ";
                std::cin >> _Choice;
                //  //////////////////////  Checking for _Choice  ///////////////////////////////////////
                while (_Choice != 's' && _Choice != 'p') {
                    std::cout << "! Enter the correct character !" << std::endl;
                    std::cout << getName()
                              << ", Do you want to make an insurance or want to Stand, or get payment"
                              << "now\n (S - Stand, p - Payment) ? : ";
                    std::cin >> _Choice;
                }
            }
        }
        else{
            if (this->_Money >= this->getBet() / 2) {
                std::cout << getName()
                          << ", Do you want to make an insurance or want to Stand\n"
                          << " (s - Stand, i - Insurance) ? : ";
                std::cin >> _Choice;
                //  //////////////////////  Checking for _Choice  ///////////////////////////////////////
                while (_Choice != 's' && _Choice != 'i') {
                    std::cout << "! Enter the correct character !" << std::endl;
                    std::cout << getName()
                              << ", Do you want to make an insurance or want to Stand\n"
                              << " (s - Stand, i - Insurance) ? : ";
                    std::cin >> _Choice;
                }
            }
            else { }
        }
    }
    // //////////////////////////////////// 2 -> Player can make a double //////////////////////////////////////////
    else if (n==2 && _Money >= getBet()) {

        // Make bet: 0,5 \ 1 \ 5 \ 10 \ 20 \ 50 \ 100


        // Stand, Hit or Double
            std::cout << getName()
                      << ", Do you want to make a Double, want to Hit, or Stand\n"
                      << " (d - Double, h - Hit, s - Stand) ? : ";
            std::cin >> _Choice;
            //  //////////////////////  Checking for _Choice  ///////////////////////////////////////
            while (_Choice != 'd' && _Choice != 'h' && _Choice != 's') {
                std::cout << "! Enter the correct character !" << std::endl;
                std::cout << getName()
                          << ", Do you want to make a Double, want to Hit, or Stand\n"
                          << " (d - Double, h - Hit, s - Stand) ? : ";
                std::cin >> _Choice;
            }
    }
    // /////////////////////////////////// Do you want to continue playing? ////////////////////////////////////////////
    else if(n==1){
        std::cout<<getName()<<", you have:"<<_Money<<std::endl
        <<"Do you want to play another round ?\n(c - continue // e - exit)  : ";
        std::cin >> _Choice;
        //  //////////////////////  Checking for _Choice  ///////////////////////////////////////
        while (_Choice != 'c' && _Choice != 'e') {
            std::cout << "! Enter the correct character !" << std::endl;
            std::cout<<getName()<<"Do you want to play another round ?\n(c - continue // e - exit)  : ";
            std::cin >> _Choice;
        }
    }
    // ////////////////////////////////// Ordinary Step (Hit or Stand) /////////////////////////////////////////////////
    else setChoice();
}

void BlackJack_Player:: setChoice(){
        std::cout << getName() << ", Do you want to Hit or Stand (h - Hit, s - Stand) ? : ";
        std::cin >> _Choice;
        //  //////////////////////  Checking for _Choice  ///////////////////////////////////////
        while (_Choice != 'h' && _Choice != 's') {
            std::cout << "! Enter the correct character !" << std::endl;
            std::cout << getName() << ", Do you want to Hit or Stand (h - Hit, s - Stand) ? : ";
            std::cin >> _Choice;
        }
}


char BlackJack_Player::getChoice() {
    return _Choice;
}



void BlackJack_Player::Make_Double() {
    std::cout<<_Name<<", you made a double - add another "<<_Bet<<"$"<<" to the bet "<<std::endl;
    _Money-=_Bet;
    _Bet+=_Bet;
}


void BlackJack_Player::addCard(Card card) {
    _Hand.setCard(card);
}


void BlackJack_Player::setInsurance() {
    _Insurance = _Bet/2;
    _Money-=_Insurance;
    std::cout<<_Name<<", you set an insurance bet: "<<_Insurance<<"\n\n";
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

bool const BlackJack_Player::get_isBust() {return _isBust;}
void BlackJack_Player::set_isBust() {_isBust= true;}

bool const BlackJack_Player::get_isBlackJack(){return _isBlackJack;}
void BlackJack_Player::set_isBlackJack(){_isBlackJack=true;}
