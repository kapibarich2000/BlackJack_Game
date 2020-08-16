#include "Dealer.h"
#include <RealPlayer.h>
#include <iostream>
#include "windows.h"
#include <Cards.h>

BlackJack_Dealer::BlackJack_Dealer(double Money,BlackJack_DeckPile* DeckPile,std::vector<IBlackJackPlayer*>* Players){
    setDeckPile(DeckPile);
    _players = Players;
    _isBlackJack=false;
    _isBust=false;
    _money=Money;
    _name="Dealer";
};

void BlackJack_Dealer::setDeckPile(BlackJack_DeckPile* DeckPile){
    this->_deckPile=DeckPile;
    _deckPile->Refresh();
}

void BlackJack_Dealer::allowMakeBets(){
    this->showMoney();
    std::cout<<"Dealer have:"<<this->showMoney()<<"$\n\n";

    for (int i = 0; i < _players->size(); ++i) {
        std::cout << _players->at(i)->getName() << " make a Bet" << std::endl;
        _players->at(i)->makeBet();
        std::cout <<"__________________" << std::endl;
    }
}

void BlackJack_Dealer::dealsCards() {
    std::cout << "\n\tDealer deals the cards...\n" << std::endl;
    Sleep(2000); // time delay
    for (int i = 0; i < _players->size(); ++i) {
        _players->at(i)->_hand.setCard(_deckPile->pop());// this->_hand.getCardFromDeck(this->retPointonDeck())
    }
    this->_hand.setCard(_deckPile->pop());
    for (int i = 0; i < _players->size(); ++i) {
        _players->at(i)->_hand.setCard(_deckPile->pop());
    }
    this->_hand.setCard(_deckPile->pop());

}

void BlackJack_Dealer::clearHistory() {
    _isBlackJack=false;
    _isBust=false;
    _hand.ClearCards();
}

double BlackJack_Dealer::distributionPrize(IBlackJackPlayer* Player) {

    //  If the player has BlackJack, then he  can ask to pay your winnings
    if(Player->getChoice()=='p'){
        std::cout<<Player->getName()<<", your prize 2:1 from the bid : "<<Player->getBet()<<std::endl;
        _money-=Player->getBet();
        return Player->getBet()*2; // This situation pays like a regular win
    }


    // Checking who have bust
    else if(Player->get_isBust()||this->get_isBust()){
        // First it is taken from the player
        if (Player->get_isBust()){
            std::cout<<Player->getName()<<", you lost: "<<Player->getBet()<<"$"<<std::endl;
            _money+=Player->getBet(); // Появилась 20 из воздуха
            return 0;
        }
        else{
            std::cout<<Player->getName()<<", you won: "<<Player->getBet()<<"$"<<std::endl;
            _money-=Player->getBet();
            return Player->getBet()*2;
        }
    }


    // If the player has BlackJack and dealer hasn't
    else if(Player->get_isBlackJack()&&!(this->_isBlackJack)){
        std::cout<<Player->getName()<<", your prize 3:2 from the bid : "<<Player->getBet()*3/2
        <<"$"<<std::endl;
        _money-=Player->getBet()*3/2; // Winning
        // ///////////////////// In this case, the insurance is burned /////////////////////////////////////////
        if ((bool)Player->getInsurance()){ //
            std::cout<<"But you lose your Insurance: "<<Player->getInsurance()<<std::endl;
            _money+=Player->getInsurance();
        }
        return Player->getBet()*5/2; // Winning + Bet
    }


    //  If the dealer has BlackJack
    else if (this->_isBlackJack){
        // //////////////////////////// Compensate to player with insurance ////////////////////////////////////
        if (Player->getInsurance()!=0) {
            std::cout<<Player->getName()<<", you return your Insurance in a 2:1 ratio: " << Player->getInsurance()*3
            << "$" << std::endl;
            return Player->getInsurance()*3;
        }
        else{
                std::cout<<Player->getName()<<", you lost your "<<Player->getBet()<<"$"<<std::endl;
                _money+=Player->getBet();
                return 0;
        }
    }


    // If the player's value == the dealer's value
    else if(Player->_hand.getCardsValue()==this->_hand.getCardsValue()){
        std::cout<<Player->getName()<<", you stay with your own PUSH. Returned: "<<Player->getBet()<<"$"<<std::endl;
        return Player->getBet();

    }


    // If the player's value > the dealer's value
    else if(Player->_hand.getCardsValue()>this->_hand.getCardsValue()){
        std::cout<<Player->getName()<<", you won: "<<Player->getBet()<<std::endl;
        _money-=Player->getBet();
        return Player->getBet()*2;
    }


    // If the player's value < the dealer's value
    else{
        std::cout<<Player->getName()<<", you lost: "<<Player->getBet()<<"$\n";
        _money+=Player->getBet();
        return 0;
    }
}


void BlackJack_Dealer::TakeInsuranceFrom(IBlackJackPlayer *Player) {
    _money+=Player->getInsurance();
}

void BlackJack_Dealer::startNewRound() {
    Sleep(2000);

    std::cout<<"_____________________________________________\n\n";

    allowMakeBets();

    dealsCards();

// ////////////////////////////////   Displaying cards on hands    /////////////////////////////////////////////////////

    std::cout<<"Dealer have: ";
    std::cout<<this->_hand.getFirstCardsName();
    std::cout<<"   *   "<<"(";
    std::cout<<this->_hand.getFirstCardValue();
    std::cout<<")"<<"\n\n";
    std::cout <<"__________________" << std::endl;
    Sleep(1000); // time delay

    for (int i = 0; i < _players->size(); ++i) {
        std::cout << _players->at(i)->getName() << " have:  ";
        _players->at(i)->_hand.showCardsName();
        std::cout << "(";
        std::cout << _players->at(i)->_hand.getCardsValue();
        std::cout << ")\n";
        std::cout <<"__________________" << std::endl;
        Sleep(1000); // time delay
    }

    std::cout <<std::endl; //For Beauty

// //////////////////////////////////////    Logic    //////////////////////////////////////////////////////////////////

        if(this->_hand.getFirstCardValue()==10){
            std::cout<<"Dealer check your second card:"<<std::endl;
            Sleep(2000); // time delay
            if (this->_hand.getCardsValue()==21){
                std::cout<<"Dealer have BlackJack\n"<<std::endl;
                this->set_isBlackJack();
            }
            else{
                std::cout<<"Dealer dont't has BlackJack\n\n";
                Sleep(1500); // time delay
            }
        }

        //  If Dealer have BlackJack with first card 10 -> Need go to payment
        if (!this->get_isBlackJack()) {

            // /////    Say, if Player have a BlackJack
            for (int i = 0; i < _players->size(); ++i) {
                if (_players->at(i)->_hand.getCardsValue() == 21) { // Blackjack is assigned after the first deals
                    std::cout << _players->at(i)->getName() << ", you have BlackJack\n\n";
                    Sleep(2000); // time delay
                    _players->at(i)->set_isBlackJack();
                }
            }

            // If the dealer has an ACE you can make insurance

            if (this->_hand.getFirstCardValue() == 11) {
                std::cout << "Dealer has an ace:" << std::endl;
                for (int i = 0; i < _players->size(); ++i) {
                    _players->at(i)->makeInsuranceOrPayment();
                    std::cout <<"__________________" << std::endl;
                    if (_players->at(i)->getChoice() == 'i') _players->at(i)->setInsurance();
                }

                std::cout << "Dealer check your second card:" << std::endl;
                Sleep(2000); // time delay
                // ///////////////////////////////// The dealer has BlackJack  /////////////////////////////////////////
                if (this->_hand.getCardsValue() == 21) {
                    std::cout << "Dealer has BlackJack\n" << std::endl;
                    this->set_isBlackJack();
                    Sleep(2000); // time delay
                }
                    // //////////////////////////// The dealer didn't has BlackJack  ////////////////////////////////////
                else {
                    std::cout << "Dealer dont't has BlackJack\n\n";
                    Sleep(2000); // time delay

                    // //////////////// First take the money from everyone, who choose insurance ////////////////////////
                    for (int i = 0; i < _players->size(); ++i) {
                        if (_players->at(i)->getChoice() == 'i') {
                            std::cout << _players->at(i)->getName()
                                      << ", your insurance bet burned out !\n\n";//insurance bet burned out
                            this->TakeInsuranceFrom(_players->at(i));

                        }
                    }
                    // And then, invite their to make another choice ///////////////////////////////
                    for (int i = 0; i < _players->size(); ++i) {
                        if (!(_players->at(i)->get_isBlackJack())) {
                            _players->at(i)->makeDouble();
                            std::cout <<"__________________" << std::endl;
                        }
                    }
                }
            }
            else{
                for (int i = 0; i < _players->size(); ++i) {
                    if (_players->at(i)->get_isBlackJack()) continue;
                    _players->at(i)->makeDouble();
                    std::cout <<"__________________" << std::endl;
                }
            }
        }

        std::cout <<std::endl;

        //  Determining who will take cards and who will not

        for (int i = 0;i<_players->size(); ++i) {

            // Go to payment
            if (_players->at(i)->getChoice() == 'p' || this->get_isBlackJack() || _players->at(i)->get_isBlackJack()
            ||_players->at(i)->getChoice()=='s'){
                continue;
            }
            //

            std::cout<<_players->at(i)->getName()<<" takes another card...\n";
            Sleep(2000); // time delay

            do{
                _players->at(i)->_hand.setCard(_deckPile->pop());

                std::cout<<_players->at(i)->getName()<<" have: ";
                _players->at(i)->_hand.showCardsName();
                std::cout<<"(";
                std::cout<<_players->at(i)->_hand.getCardsValue();
                std::cout<<")"<<"\n";

                Sleep(1000); // time delay

                if (_players->at(i)->_hand.getCardsValue()>=21){
                    if(_players->at(i)->_hand.getCardsValue()>21){
                        _players->at(i)->set_isBust();
                        Sleep(2000); // time delay
                    }
                    break;
                }
                    // If you didn't make double, then you can
                else if(_players->at(i)->getChoice()!='d')_players->at(i)->makeMove();

            }
            while(_players->at(i)->getChoice()!='s'&&_players->at(i)->getChoice()!='d');

            std::cout <<std::endl; //For Beauty

        }

        // Dealer deals yourself
        std::cout<<"\nDealer deals yourself ...\n"<<std::endl;
        Sleep(3000); // time delay
        while (this->_hand.getCardsValue()<17){
            this->_hand.setCard(_deckPile->pop());
        }

        std::cout<<"Dealer have: ";
        this->_hand.showCardsName();
        std::cout<<"\t(";
        std::cout<<this->_hand.getCardsValue();
        std::cout<<")"<<"\n";
        Sleep(2000); // time delay

        if (this->_hand.getCardsValue()>21){
            this->set_isBust();
        }
        std::cout<<"\n\n"; // for beauty


       this->makePayments();
}


void BlackJack_Dealer::makePayments() {
    for (int i = 0; i < _players->size(); ++i) {
        _players->at(i)->setPrize(this->distributionPrize(_players->at(i)));
        std::cout <<"__________________" << std::endl;
        _players->at(i)->clearHistory();
        Sleep(2000);
    }
    if (this->showMoney() == 0) {
        std::cout << "Oo - Unbelievable. You win the casino. You are definitely scammers!" << std::endl;
    }
    this->clearHistory();
}