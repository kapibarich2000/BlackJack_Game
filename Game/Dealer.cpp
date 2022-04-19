#include "Dealer.h"
#include <iostream>
#include "windows.h"

BlackJack_Dealer::BlackJack_Dealer(double Money,BlackJack_DeckPile* DeckPile,std::vector<std::shared_ptr<IBlackJackPlayer>>* Players){
    setDeckPile(DeckPile);
    _players = Players;
    _isBlackJack=false;
    _isBust=false;
    _money=Money;
    _name="Dealer";
}


void BlackJack_Dealer::startNewRound() {

    std::cout<<"_____________________________________________\n\n";

    allowMakeBets();

    dealsCards();

// Displaying cards on hands

    this->showFirsCard();
    Sleep(1000); // time delay

    for (auto & _player : *_players) {
        _player->showAllCards();
        Sleep(1000); // time delay
    }

    std::cout <<std::endl;

    giveMove();

    std::cout <<std::endl;

    //  Determining who will take cards and who will not
    if (!this->get_isBlackJack()) additionalDistribution();

    std::cout<<"\n\n";

    this->makePayments();

    Sleep(1000);
}



void BlackJack_Dealer::allowMakeBets(){
    this->getBankSize();
    std::cout<<"Dealer have:"<<this->getBankSize()<<"$\n\n";

    for (auto & _player : *_players) {
        std::cout << _player->getName() << " make a Bet" << std::endl;
        _player->makeBet();
        std::cout <<"__________________" << std::endl;
    }
}

void BlackJack_Dealer::dealsCards() {
    std::cout << "\n\tDealer deals the cards...\n" << std::endl;
    Sleep(1500); // time delay
    for (auto & _player : *_players) {
        _player->_hand.setCard(_deckPile->pop());
    }
    this->_hand.setCard(_deckPile->pop());
    for (auto & _player : *_players) {
        _player->_hand.setCard(_deckPile->pop());
    }
    this->_hand.setCard(_deckPile->pop());
}


void BlackJack_Dealer::additionalDistribution() {
    for ( auto & _player : *_players) {

        // Player go to payment
        if (_player->getChoice() == 'p'
            || _player->get_isBlackJack()
            || _player->getChoice()=='s'){
            continue;
        }

        std::cout<<_player->getName()<<" takes another card...\n";
        Sleep(1500); // time delay

        do{
            _player->_hand.setCard(_deckPile->pop());

            std::cout<<_player->getName()<<" have: ";
            _player->_hand.showCardsName();
            std::cout<<"(";
            std::cout<<_player->_hand.getCardsValue();
            std::cout<<")"<<"\n";

            Sleep(1000); // time delay

            if (_player->_hand.getCardsValue()>=21){
                if(_player->_hand.getCardsValue()>21){
                    _player->set_isBust();
                    Sleep(1500); // time delay
                }
                break;
            }
                // If you didn't make double, then you can
            else if(_player->getChoice()!='d')_player->makeMove();

        }
        while(_player->getChoice()!='s'&&_player->getChoice()!='d');

        std::cout <<std::endl; //For Beauty
    }

    // Dealer deals yourself again
    std::cout<<"\nDealer deals yourself ...\n"<<std::endl;
    Sleep(1500); // time delay
    while (this->_hand.getCardsValue()<17){
        this->_hand.setCard(_deckPile->pop());
    }

    this->showAllCards();
    Sleep(1500); // time delay

    if (this->_hand.getCardsValue()>21){
        this->set_isBust();
    }
}


void BlackJack_Dealer::giveMove() {
    //  If Dealer have BlackJack with first card 10 -> Need go to payment
    if (this->_hand.getFirstCardValue() == 10) {
        checkSecondCard(); // Maybe dealer has BlackJack
    }

    if (!this->get_isBlackJack()) { // After checking, then dealer has the first ten

        // /////    Say, if Player have a BlackJack
        for (auto &_player : *_players) {
            if (_player->_hand.getCardsValue() == 21) { // Blackjack is assigned after the first deals
                std::cout << _player->getName() << ", you have BlackJack\n\n";
                Sleep(1500); // time delay
                _player->set_isBlackJack();
            }
        }

        // If the dealer has an ACE you can make insurance
        if (this->_hand.getFirstCardValue() == 11) {
            std::cout << "Dealer has an ace:" << std::endl;
            for (auto &_player : *_players) {
                _player->makeInsuranceOrPayment();
                std::cout << "__________________" << std::endl;
            }
            this->checkSecondCard(); // Maybe dealer has BlackJack
        }

        if (!this->get_isBlackJack()) { // After checking, then dealer has the Ace (11)

            //  Firstly, take the money from everyone, who choose insurance
            for (auto &player : *_players) {
                if (player->getChoice() == 'i') {
                    std::cout << player->getName()
                              << ", your insurance bet burned out !\n\n";
                    this->takeInsuranceFrom(player);
                }
                // And then, players make another choice
                if (!(player->get_isBlackJack())) {
                    player->makeDouble();
                    std::cout << "__________________" << std::endl;
                }
            }
        }
    }
}

void BlackJack_Dealer::makePayments() {
    for ( auto & _player : *_players) {

        double PrizeForPlayer=0;

        //  If the player has BlackJack, then he  can ask to pay your winnings
        if(_player->getChoice()=='p') {
            std::cout << _player->getName() << ", your prize 2:1 from the bid : " << _player->getBet() << std::endl;
            this->_money -= _player->getBet();

            PrizeForPlayer = _player->getBet() * 2; // This situation pays like a regular win
        }

            // Checking who have bust
        else if(_player->get_isBust()||this->get_isBust()){
            // First it is taken from the player
            if (_player->get_isBust()){
                std::cout<<_player->getName()<<", you lost: "<<_player->getBet()<<"$"<<std::endl;
                this->_money+=_player->getBet();

                PrizeForPlayer = 0;
            }
            else{
                std::cout<<_player->getName()<<", you won: "<<_player->getBet()<<"$"<<std::endl;
                this->_money-=_player->getBet();

                PrizeForPlayer = _player->getBet()*2;
            }
        }

            // If the player has BlackJack and dealer hasn't
        else if(_player->get_isBlackJack()&&!(this->_isBlackJack)){
            std::cout<<_player->getName()<<", your prize 3:2 from the bid : "<<_player->getBet()*3/2
                     <<"$"<<std::endl;
            this->_money-=_player->getBet()*3/2; // Money for player (Winning)

            PrizeForPlayer = _player->getBet()*5/2; // Winning + Bet
        }

            //  If the dealer has BlackJack
        else if (this->_isBlackJack){
            //  Compensate to player with insurance
            if (_player->getInsurance()!=0) {
                std::cout<<_player->getName()<<", you prize = your Insurance in a 2:1 ratio: " << _player->getInsurance()*3
                         << "$" << std::endl;

                PrizeForPlayer = _player->getInsurance()*3;
            }else{
                std::cout<<_player->getName()<<", you lost your "<<_player->getBet()<<"$"<<std::endl;
                this->_money+=_player->getBet();

                PrizeForPlayer = 0;
            }
        }

            // If the player's value == the dealer's value
        else if(_player->_hand.getCardsValue()==this->_hand.getCardsValue()){
            std::cout<<_player->getName()<<", you stay with your own PUSH. Returned: "<<_player->getBet()<<"$"<<std::endl;

            PrizeForPlayer = _player->getBet();
        }


            // If the player's value > the dealer's value
        else if(_player->_hand.getCardsValue()>this->_hand.getCardsValue()){
            std::cout<<_player->getName()<<", you won: "<<_player->getBet()<<std::endl;
            this->_money-=_player->getBet();

            PrizeForPlayer = _player->getBet()*2;
        }


            // If the player's value < the dealer's value
        else{
            std::cout<<_player->getName()<<", you lost: "<<_player->getBet()<<"$\n";
            this->_money+=_player->getBet();

            PrizeForPlayer = 0;
        }

        _player->setPrize(PrizeForPlayer);
        _player->clearHistory();

        std::cout <<"__________________" << std::endl;
        Sleep(1500);
    }
    if (this->getBankSize() == 0) {
        std::cout << "Oo - Unbelievable. You win the casino. You are definitely scammers!" << std::endl;
    }
    this->clearHistory();
}