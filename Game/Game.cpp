#include "Game.h"
#include <Player.h>
#include <Dealer.h>
#include <vector>
#include "windows.h"

 BlackJackGame::BlackJackGame():_Dealer(10000){

    int money;
    std::string name;

    // ///////////////////////////////// Set the number of players  //////////////////////////////////////////////////
    while (1){
        std::cout<<"\nHow many players will play? :";
        std::cin>>_PlayersSize;
        if (std::cin.fail()) { // Проверка на ввод числа
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            continue;
        }

        if (_PlayersSize<=0||_PlayersSize>_maxPlayers) { // Make sure that it is a positive number and not too large
            std::cout<<"No more than 15 people are allowed!"<<std::endl;
            continue;
        }
        break;
    }
    std::cout<<std::endl;
    // //////////////////////////////////// Entire information about players ///////////////////////////////////////////
    for (int i = 0; i < _PlayersSize; ++i) {
        std::cout<<"Enter a name of the "<<i+1<<" player: ";
        std::cin>>name;
        while (1){
            std::cout<<name<<", how much money($) do you have? : ";
            std::cin>>money;
            if (std::cin.fail()) { // To prevent the user from entering a letter
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                continue;
            }
            if (money<=0||money>10000) // A player can't have more money than there is in the casino
            {
                std::cout << "Oo ," << name
                          << ", you have a too much money. Our casino doesn't have enough chips for you!\n"
                          << "Anything less than 10,000\n";
                continue;
            }
            break;
        }

        BlackJack_Player Player(money,name);
        _Players.push_back(Player);
        std::cout<<std::endl;
    }
    std::cout<<"\n\tOkay let's go!\n";
    std::cout<<"---------------------------------------------\n";
}

void BlackJackGame::deletePlayer(std::vector<BlackJack_Player>& _Players, std::vector<int>& _ListToDelete){
    for (int i = 0; i < _ListToDelete.size(); ++i) {
        _Players.erase(_Players.begin()+_ListToDelete[i]);
    }
}

void BlackJackGame::startGame() {

    std::cout<<"\n\n////  Welcome to the honest world of cards :) ////\n"<<
             "////  BlacK Jack, created by kapibarich2000, greet you ////\n\n";

    std::cout<<"Please Enter for control:\nh - for hit, s - for stand, d - for double "<<
             "e - for exit, c - for continue, i - for insurance, p - for payment\n\n";


    _Dealer._Hand.Refresh(_DeckPile);
    _Dealer.setDeckPile(&_DeckPile);

    char choice='c';
    while (choice!='e') {

        startNewRound();


        for (int i = 0; i < _PlayersSize; ++i) {
            // Payments
            _Players[i].setPrize(_Dealer.givePrize(&_Players[i]));
            std::cout <<"__________________" << std::endl;
            _Players[i].ClearHistory();
        }
        _Dealer.ClearHistory();

        // ////////////////// The casino was left without money //////////////////////////////////////
        if(_Dealer.showMoney()==0){
            std::cout<<"Oo - Unbelievable. You win the casino. You are definitely scammers!"<<std::endl;
            choice ='e';
            continue;
        }
        // /////////////////////////////  Do you want to continue playing? /////////////////////////////////////
        for (int i = 0; i < _PlayersSize; ++i) {

            // ////////////////// The player was left without money //////////////////////////////////////
            if (_Players[i].showMoney()==0){
                std::cout<<_Players[i].getName()<<", you lost all your money"<<std::endl;
                std::cout << "Player: " << _Players[i].getName() << " leave the game!\n"<<std::endl;
                Sleep(1000); // time delay
                _ListToDelete.push_back(i);
                continue;
            }
            _Players[i].setChoice(1);
            if(_Players[i].getChoice()=='e') {
                // list stores the IDs of players to delete //
                _ListToDelete.push_back(i);
                std::cout << "Player: " << _Players[i].getName() << " leave the game!"<<std::endl;
            }
        }

        std::cout<<"\n\n"; //For Beauty

        // Removing players //
        deletePlayer(_Players,_ListToDelete);
        // Cleaning up useless information //
        _ListToDelete.clear();
        // Updating the number of people //
        if (_Players.size()!=_PlayersSize) _PlayersSize=_Players.size();
        // If all people leave. We exit from the while loop //
        if (_PlayersSize==0)  choice='e';

        std::cout<<"_______________________________________________\n\n";

        // //////////// Checking how many cards are left in DeckPile ///////////////////////////////
        if (_Dealer._Hand.getNumberOfCards()==25) {
            _DeckPile=BlackJack_DeckPile (); // Casino brings a new DeckPile for Dealer
            _Dealer._Hand.Refresh(_DeckPile);
            _Dealer.setDeckPile(&_DeckPile);
        }
    }
}

void BlackJackGame::startNewRound(){

    std::cout<<"Dealer have: "<<_Dealer.showMoney()<<"$\n\n";

// //////////////////////////////////   Make a Bet    //////////////////////////////////////////////////////////////////
    for (int i = 0; i < _PlayersSize; ++i) {
        std::cout << _Players[i].getName() << " make a Bet" << std::endl;
        _Players[i].Make_Bet();
        std::cout <<"__________________" << std::endl;
    }

// ////////////////////////////////   Distribution of Сards    /////////////////////////////////////////////////////////
    std::cout << "\n\tDealer deals the cards...\n" << std::endl;
    Sleep(2000); // time delay
    for (int i = 0; i < _PlayersSize; ++i) {
        _Players[i]._Hand.setCard(_Dealer._Hand.getCardFromDeck(_Dealer.retPointonDeck()));
    }
    _Dealer._Hand.setCard(_Dealer._Hand.getCardFromDeck(_Dealer.retPointonDeck()));
    for (int i = 0; i < _PlayersSize; ++i) {
        _Players[i]._Hand.setCard(_Dealer._Hand.getCardFromDeck(_Dealer.retPointonDeck()));
    }
    _Dealer._Hand.setCard(_Dealer._Hand.getCardFromDeck(_Dealer.retPointonDeck()));

// ////////////////////////////////   Displaying cards on hands    /////////////////////////////////////////////////////

    std::cout<<"Dealer have: ";
    _Dealer._Hand.showCardsName(1);
    std::cout<<"   *   "<<"(";
    _Dealer._Hand.showCardsValue(1);
    std::cout<<")"<<"\n\n";
    std::cout <<"__________________" << std::endl;
    Sleep(1000); // time delay

    for (int i = 0; i < _PlayersSize; ++i) {
        std::cout << _Players[i].getName() << " have:  ";
        _Players[i]._Hand.showCardsName();
        std::cout << "(";
        std::cout << _Players[i]._Hand.getValue();
        std::cout << ")\n";
        std::cout <<"__________________" << std::endl;
        Sleep(1000); // time delay
    }

    std::cout <<std::endl; //For Beauty
// //////////////////////////////////////    Logic    //////////////////////////////////////////////////////////////////

    if(_Dealer._Hand.getValue(1)==10){
        std::cout<<"Dealer check your second card:"<<std::endl;
        Sleep(3000); // time delay
        if (_Dealer._Hand.getValue()==21){
            std::cout<<"Dealer have BlackJack\n"<<std::endl;
            _Dealer.set_isBlackJack();
        }
        else{
            std::cout<<"Dealer dont't has BlackJack\n\n";
        }
    }
    // ///////////////// If Dealer have BlackJack with first card 10 -> Need go to payment  ////////////////////////////

    if (!_Dealer.get_isBlackJack()) {

        // /////////    Say, if you have a BlackJack    ///////////////////
        for (int i = 0; i < _PlayersSize; ++i) {
            if (_Players[i]._Hand.getValue() == 21) { // Blackjack is assigned after the first deals
                std::cout << _Players[i].getName() << ", you have BlackJack\n\n";
                Sleep(2000); // time delay
                _Players[i].set_isBlackJack();
            }
        }

        // ///////////////  If the dealer has an ACE you can make insurance  ///////////////////////////////////////////

        if (_Dealer._Hand.getValue(1) == 11) {
            std::cout << "Dealer has an ace:" << std::endl;
            for (int i = 0; i < _PlayersSize; ++i) {
                _Players[i].setChoice(11);
                std::cout <<"__________________" << std::endl;
                if (_Players[i].getChoice() == 'i') _Players[i].setInsurance();
            }

            std::cout << "Dealer check your second card:" << std::endl;
            Sleep(3000); // time delay
            // ///////////////////////////////// The dealer has BlackJack  /////////////////////////////////////////////////
            if (_Dealer._Hand.getValue() == 21) {
                std::cout << "Dealer has BlackJack\n" << std::endl;
                _Dealer.set_isBlackJack();
                Sleep(2000); // time delay
            }
                // //////////////////////////// The dealer didn't has BlackJack  ///////////////////////////////////////////////
            else {
                std::cout << "Dealer dont't has BlackJack\n\n";
                Sleep(2000); // time delay

                // //////////////// First take the money from everyone, who choose insurance ///////////////////////////////
                for (int i = 0; i < _PlayersSize; ++i) {
                    if (_Players[i].getChoice() == 'i') {
                        std::cout << _Players[i].getName()
                                  << ", your insurance bet burned out !\n\n";//insurance bet burned out
                        _Dealer.TakeInsurance(&_Players[i]);

                    }
                }
                // //////////////////// And then, invite their to make another choice //////////////////////////////////////
                for (int i = 0; i < _PlayersSize; ++i) {
                    if (!(_Players[i].get_isBlackJack())) {
                        _Players[i].setChoice(2);
                        std::cout <<"__________________" << std::endl;
                    }
                }
            }
        }
        else{
            for (int i = 0; i < _PlayersSize; ++i) {
                if (_Players[i].get_isBlackJack()) continue;
                _Players[i].setChoice(2);
                std::cout <<"__________________" << std::endl;
            }
        }
    }

    std::cout <<std::endl;

    // ///////////////////////  Determining who will take cards and who will not  /////////////////////////////////////

    for (int i = 0;i<_PlayersSize; ++i) {

        // Go to payment
        if (_Players[i].getChoice() == 'p' || _Dealer.get_isBlackJack() || _Players[i].get_isBlackJack()){
            continue;
        }
        else if(_Players[i].getChoice()=='s') continue;

        // //////////////////////////////// Players who continued playing //////////////////////////////////////////////

        else if (_Players[i].getChoice()=='d') _Players[i].Make_Double();

        std::cout<<_Players[i].getName()<<" takes another card...\n";
        Sleep(2000); // time delay

        do{
            _Players[i]._Hand.setCard(_Dealer._Hand.getCardFromDeck(_Dealer.retPointonDeck()));

            std::cout<<_Players[i].getName()<<" have: ";
            _Players[i]._Hand.showCardsName();
            std::cout<<"(";
            std::cout<<_Players[i]._Hand.getValue();
            std::cout<<")"<<"\n";

            Sleep(1000); // time delay

            if (_Players[i]._Hand.getValue()>=21){
                if(_Players[i]._Hand.getValue()>21){
                    std::cout<<_Players[i].getName()<<", sorry you have bust !";
                    Sleep(2000); // time delay
                    _Players[i].set_isBust();
                }
                break;
            }
            // If you didn't make double, then you can
            else if(_Players[i].getChoice()!='d')_Players[i].setChoice();

        }
        while(_Players[i].getChoice()!='s'&&_Players[i].getChoice()!='d');

        std::cout <<std::endl; //For Beauty

    }

    // Dealer deals yourself
    if (!(_Dealer.get_isBlackJack())){
        std::cout<<"\nDealer deals yourself ...\n"<<std::endl;
        Sleep(3000); // time delay
        while (_Dealer._Hand.getValue()<17){
            _Dealer._Hand.setCard(_Dealer._Hand.getCardFromDeck(_Dealer.retPointonDeck()));
        }

        std::cout<<"Dealer have: ";
        _Dealer._Hand.showCardsName();
        std::cout<<"\t(";
        std::cout<<_Dealer._Hand.getValue();
        std::cout<<")"<<"\n";
        Sleep(2000); // time delay

        if (_Dealer._Hand.getValue()>21){
            _Dealer.set_isBust();
            std::cout<<"\n"; // for beauty
        }
    }
}