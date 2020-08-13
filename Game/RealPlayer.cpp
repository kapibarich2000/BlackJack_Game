#include "RealPlayer.h"
#include <iostream>
#include <utility> // ?
#include <iCardGame.h>


BlackJack_RealPlayer::BlackJack_RealPlayer() {
    std::cout<<"Player, enter your name:";
    std::cin>>_Name;
    while (1){
        std::cout<<_Name<<", how much money($) do you have? :";
        std::cin>>_Money;
        if (std::cin.fail()) { // To prevent the user from entering a letter
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            continue;
        }
        break;
    }
    std::cout<<std::endl; // For beauty
}

void BlackJack_RealPlayer::makeBet() {
    std::cout<<_Name<<", you have:"<<_Money<<"$"<<std::endl;

    while (1){
        std::cout<<"Your bet:";
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

void BlackJack_RealPlayer::makeDouble() {
    if (_Money >= getBet()) {
        // Stand, Hit or Double
        std::cout << getName()
                  << ", Do you want to make a Double, want to Hit, or Stand\n"
                  << " (d - Double, h - Hit, s - Stand) ? :";
       std::cin>>_Choice;
        //  //////////////////////  Checking for _Choice  ///////////////////////////////////////
        while (getChoice() != 'd' && getChoice() != 'h' && getChoice() != 's') {
            std::cout << "! Enter the correct character !" << std::endl;
            std::cout << getName()
                      << ", Do you want to make a Double, want to Hit, or Stand\n"
                      << " (d - Double, h - Hit, s - Stand) ? :";
           std::cin>>_Choice;
        }
    }
    else makeMove();

    if (getChoice()=='d') setDouble();
}

void BlackJack_RealPlayer::makeInsuranceOrPayment() {
    if (this->_isBlackJack) {
        // You can't make an insurance if you didn't have money, that match a half of bet
        if (this->_Money >= this->getBet() / 2) {
            std::cout << getName()
                      << ", Do you want to make an insurance or want to Stand, or get payment"
                      << "now\n (s - Stand, i - Insurance, p - Payment) ? :";
           std::cin>>_Choice;
            // Checking for _Choice
            while (getChoice() != 's' && getChoice() != 'i' && getChoice() != 'p') {
                std::cout << "! Enter the correct character !" << std::endl;
                std::cout << getName()
                          << ", Do you want to make an insurance or want to Stand, or get payment"
                          << "now\n (s - Stand, i - Insurance, p - Payment) ? :";
              std::cin>>_Choice;
            }
        } // DRY !!!!
        else {
            std::cout << getName()
                      << ", Do you want to Stand, or get payment "
                      << "now (S - Stand, p - Payment) ? :";
           std::cin>>_Choice;
            //  Checking for _Choice
            while (getChoice() != 's' && getChoice() != 'p') {
                std::cout << "! Enter the correct character !" << std::endl;
                std::cout << getName()
                          << ", Do you want to make an insurance or want to Stand, or get payment"
                          << "now\n (S - Stand, p - Payment) ? :";
               std::cin>>_Choice;
            }
        }
    }
    else{
        if (this->_Money >= this->getBet() / 2) {
            std::cout << getName()
                      << ", Do you want to make an insurance or want to Stand\n"
                      << " (s - Stand, i - Insurance) ? :";
           std::cin>>_Choice;
            //  //////////////////////  Checking for getChoice()  ///////////////////////////////////////
            while (getChoice() != 's' && getChoice() != 'i') {
                std::cout << "! Enter the correct character !" << std::endl;
                std::cout << getName()
                          << ", Do you want to make an insurance or want to Stand\n"
                          << " (s - Stand, i - Insurance) ? :";
               std::cin>>_Choice;
            }
        }
    }
    if (getChoice()=='i') setInsurance();
}

void BlackJack_RealPlayer::makeMove() {
    std::cout << getName() << ", Do you want to Hit or Stand (h - Hit, s - Stand) ? :";
   std::cin>>_Choice;
    //  //////////////////////  Checking for _Choice  ///////////////////////////////////////
    while (getChoice() != 'h' && getChoice() != 's') {
        std::cout << "! Enter the correct character !" << std::endl;
        std::cout << getName() << ", Do you want to Hit or Stand (h - Hit, s - Stand) ? :";
       std::cin>>_Choice;
    }
}

char BlackJack_RealPlayer::getChoice_StayOrLeave()const {
    char choice;
    std::cout<<"\n"<< getName()<<", you have:"<<showMoney()<<std::endl
             <<"Do you want to play another round ?\n(c - continue // e - exit)  :";
    std::cin >> choice;
    //  //////////////////////  Checking for _Choice  ///////////////////////////////////////
    while (_Choice != 'c' && _Choice != 'e') {
        std::cout << "! Enter the correct character !" << std::endl;
        std::cout << getName() << ", Do you want to play another round ?\n(c - continue // e - exit)  :";
        std::cin >> choice;
    }
    if(choice=='e') {
        std::cout <<_Name << " leave the game!"<<std::endl;
        return 'e';
    }
    return 'c';
}
