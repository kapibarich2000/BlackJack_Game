#include "RealPlayer.h"
#include <iostream>
#include <UsefulFunctions.h>

BlackJack_RealPlayer::BlackJack_RealPlayer() {
    std::cout<<"Player, enter your name:";
    std::cin>>_name;
    std::cout<<_name<<", how much money($) do you have? :";
    _money=EnterInt();
}

void BlackJack_RealPlayer::makeBet() {
    std::cout<<_name<<", you have:"<<_money<<"$"<<std::endl;

    while (true){
        std::cout<<"Your bet:";
        _bet=EnterInt();
        if (_bet<=0||_bet>_money) continue;

        break;
    }
    this->_money-=_bet;
}

void BlackJack_RealPlayer::makeDouble() {
    if (_money >= getBet()) {
        while (true){
            std::cout << getName()
                      << ", Do you want to make a Double, want to Hit, or Stand\n"
                      << " (d - Double, h - Hit, s - Stand) ? :";
            std::cin>>_choice;
            if (getChoice() != 'd' && getChoice() != 'h' && getChoice() != 's') continue;

            if (getChoice()=='d') setDouble();

            break;
        }
    }
    else makeMove();
}

void BlackJack_RealPlayer::makeInsuranceOrPayment() {
    if (this->_isBlackJack) {
        // You can't make an insurance if you didn't have money, that match a half of bet
        if (this->_money >= this->getBet() / 2) {
            while (true){
                std::cout << getName()
                          << ", Do you want to make an insurance or want to Stand, or get payment"
                          << "now\n (s - Stand, i - Insurance, p - Payment) ? :";
                std::cin>>_choice;
                //  Checking for _choice
                if (getChoice() != 's' && getChoice() != 'i' && getChoice() != 'p') continue;
                // If everything is OK:
                break;
            }
        }else {
            while (true){
                std::cout << getName()
                          << ", Do you want to Stand, or get payment "
                          << "now (S - Stand, p - Payment) ? :";
                std::cin>>_choice;
                if (getChoice() != 's' && getChoice() != 'p') continue;

                break;
            }
        }
    }else{
        if (this->_money >= this->getBet() / 2) {
            while (true){
                std::cout << getName()
                          << ", Do you want to make an insurance or want to Stand\n"
                          << " (s - Stand, i - Insurance) ? :";
                std::cin>>_choice;

                if (getChoice() != 's' && getChoice() != 'i') continue;

                break;
            }
        }
    }
    if (getChoice()=='i') setInsurance();
}

void BlackJack_RealPlayer::makeMove() {
    while (true){
        std::cout << getName() << ", Do you want to Hit or Stand (h - Hit, s - Stand) ? :";
        std::cin>>_choice;
        if (getChoice() != 'h' && getChoice() != 's') continue;

        break;
    }
}


char BlackJack_RealPlayer::getChoice_StayOrLeave() const {
    char choice;
    while(true){
        std::cout<<"\n"<< getName()<<", you have:"<<getBankSize()<<std::endl
                 <<"Do you want to play another round ?\n(c - continue // e - exit):";
        std::cin >> choice;
        if (choice != 'c' && choice != 'e') continue;

        break;
    }
    if(choice=='e') {
        std::cout <<_name << " leave the game!"<<std::endl;
        return 'e';
    }
    return 'c';
}
