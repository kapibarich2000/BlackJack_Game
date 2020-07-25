#include "Game.h"
#include <Player.h>
#include <Dealer.h>


BlackJack_DeckPile BlackJackGame::getNewDeckPile() {
    return BlackJack_DeckPile();
}

void BlackJackGame::StartGame() {

    _PlayersSize=_Players.size();
    std::cout<<"\n\n////  Welcome to the honest world of cards :) ////\n////  BlacK Jack, created by kapibarich2000, greet you ////\n\n";

    std::cout<<"Please Enter for control:\nh - for hit, s - for stand, e - for exit, c - for continue, i - for insurance, p - for payment\n\n";

    BlackJack_Dealer _Dealer(10000);
    _Dealer._Hand.Refresh(_DeckPile);
    _Dealer.setDeckPile(&_DeckPile);

    char choice='c';
    while (choice!='e') {
        std::cout<<"Dealer have: "<<_Dealer.showMoney()<<"$\n\n";

        for (int i = 0; i < _PlayersSize; ++i) {
            std::cout << _Players[i]->getName() << " make a Bet" << std::endl;
            _Players[i]->Make_Bet();
        }

        std::cout << "\nDealer deals the cards...\n" << std::endl;
        for (int i = 0; i < _PlayersSize; ++i) {
            _Players[i]->_Hand.setCard(_Dealer._Hand.getCardFromDeck(_Dealer.retPointonDeck()));
        }
        _Dealer._Hand.setCard(_Dealer._Hand.getCardFromDeck(_Dealer.retPointonDeck()));
        for (int i = 0; i < _PlayersSize; ++i) {
            _Players[i]->_Hand.setCard(_Dealer._Hand.getCardFromDeck(_Dealer.retPointonDeck()));
        }
        _Dealer._Hand.setCard(_Dealer._Hand.getCardFromDeck(_Dealer.retPointonDeck()));


        std::cout<<"Dealer have: ";
        _Dealer._Hand.showCardsName(1);
        std::cout<<" *\t"<<"(";
        _Dealer._Hand.showCardsValue(1);
        std::cout<<")"<<"\n";

        for (int i = 0; i < _PlayersSize; ++i) {
            std::cout << _Players[i]->getName() << " have:  ";
            _Players[i]->_Hand.showCardsName();
            std::cout << "(";
            std::cout << _Players[0]->_Hand.getValue();
            std::cout << ")\n\n";
        }

        if(_Dealer._Hand.getValue(1)==10){
            std::cout<<"Dealer check your second card:"<<std::endl;
            if (_Dealer._Hand.getValue()==21){
                std::cout<<"Dealer have BlackJack\n"<<std::endl;
                _Dealer._isBlackJack=true;
            }
            else{
                std::cout<<"Continue...\n"<<std::endl;
            }
        }

        if (_Dealer._Hand.getValue(1)==11) std::cout<<"Dealer has ace:"<<std::endl;

        //  First, each player will make a choice of action, then the dealer show magic

       for (int i = 0; i < _PlayersSize; ++i) {
           if (_Dealer._isBlackJack) break;

           if (_Players[i]->_Hand.getValue() == 21) { // Blackjack is assigned after the first deals
               std::cout << _Players[i]->getName() << ", you have BlackJack\n\n";
               _Players[i]->_isBlackJack = true;
           }

           if (_Dealer._Hand.getValue(1) == 11) { //When the dealer has an ACE open, the player can make insurance
               _Players[i]->setChoice(11);
               if (_Players[i]->getChoice() == 'i') _Players[i]->setInsurance();

           }
           else if (!(_Players[i]->_isBlackJack)) _Players[i]->setChoice(3);

           if (_Players[i]->getChoice() == 'p') break;
       }

        if (_Dealer._Hand.getValue(1)==11) {
            std::cout<<"Dealer check your second card:"<<std::endl;
            if (_Dealer._Hand.getValue()==21){
                std::cout<<"Dealer has BlackJack"<<std::endl;
                _Dealer._isBlackJack=true;
            }
            else{
                std::cout<<"Dealer dont't has BlackJack\n";
                std::cout<<"Your insurance bet burned out\n\n"; // Сгорает страховка !!
                for (int i = 0; i < _PlayersSize; ++i) {
                    _Dealer.TakeInsurance(*_Players[i]);
                    _Players[i]->setChoice(3);
                }
            }
        }

        for (int i = 0;i<_PlayersSize; ++i) {
            if(_Dealer._isBlackJack) break;

            else if(_Players[i]->getChoice()=='e') {
                std::cout<<"Игрок: "<<_Players[i]->getName()<<" выключил игру !\n\n";
                exit(1);
            }

            else if(_Players[i]->getChoice()=='s') continue;
            else if (_Players[i]->getChoice()=='d') _Players[i]->Make_Double();


            std::cout<<_Players[i]->getName()<<" takes another card...\n\n";

            do{
                _Players[i]->_Hand.setCard(_Dealer._Hand.getCardFromDeck(_Dealer.retPointonDeck()));

                std::cout<<_Players[i]->getName()<<" have: ";
                _Players[i]->_Hand.showCardsName();
                std::cout<<"(";
                std::cout<<_Players[0]->_Hand.getValue();
                std::cout<<")"<<"\n";

                if(_Players[i]->_Hand.getValue()>21){
                    _Players[i]->_isBust=true;
                    break;
                }
                if(_Players[i]->getChoice()!='d')_Players[i]->setChoice(2);
            }
            while(_Players[i]->getChoice()!='s'&&_Players[i]->_Hand.getValue()<21&&_Players[i]->getChoice()!='d');
        }

      // ////////////////////////////////// }

        // Dealer deals yourself
        if (!(_Dealer._isBlackJack)){
            std::cout<<"\nDealer deals yourself ...\n"<<std::endl;
            while (_Dealer._Hand.getValue()<17){
                _Dealer._Hand.setCard(_Dealer._Hand.getCardFromDeck(_Dealer.retPointonDeck()));
            }

            std::cout<<"Dealer have: ";
            _Dealer._Hand.showCardsName();

            std::cout<<"\t(";
            std::cout<<_Dealer._Hand.getValue();
            std::cout<<")"<<"\n";

            if (_Dealer._Hand.getValue()>21){
                _Dealer._isBust=true;
            }
        }

        // Payments

        for (int i = 0; i < _PlayersSize; ++i) {

            _Players[i]->setPrize(_Dealer.givePrize(*_Players[i]));

            _Players[i]->ClearHistory();

            if (_Players[i]->showMoney()==0){
                std::cout<<"You lost all your money"<<std::endl;
                _Players.erase(_Players.begin()+i-1); // Deleting a player
                _PlayersSize--;
                if (_Players.empty()){
                    std::cout<<"All players leave the game"<<std::endl;
                    std::exit(1);
                }
            }
            else if(_Dealer.showMoney()==0){
                std::cout<<"Oo - Unbelievable. You won the casino"<<std::endl;
                exit(1);
            }
        }
        _Dealer.ClearHistory();

        if (_Dealer._Hand.getNumberOfCards()==25) { // Checking how many cards are left
            _DeckPile=getNewDeckPile();
            _Dealer._Hand.Refresh(_DeckPile);
            _Dealer.setDeckPile(&_DeckPile);
        }

        std::cout<<"\n\nDo you want to play another round ? (c - continue // e - exit)  : ";
        std::cin>>choice;
        std::cout<<"_______________________________________________"<<std::endl;
    }
}

