#pragma once
#include <iCardGame.h>
#include <Hand.h>

class BlackJack_Player: public IPlayer {
    double _Money;
    double _Bet;
    char _Choice;
    int _Insurance;
public:
    std::string _Name;
    bool _isBlackJack;
    bool _isBust;
    Hand _Hand;

    BlackJack_Player()=delete;
    BlackJack_Player(int Money = 100, std::string Name = "SomeOne");

    const int showMoney() override ;

    void Make_Bet() ;
    void Make_Double();
    double getBet();
    void setPrize(double n);

    void setChoice(int n);
    char getChoice();

    void setInsurance();
    int getInsurance();

    void ClearHistory();

    void addCard(Card card);
};