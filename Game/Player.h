#pragma once
#include <iCardGame.h>
#include <Hand.h>
#include <string>

class BlackJack_Player: public IPlayer {
protected:
    int _Insurance;
public:
    bool _isBlackJack;
    bool _isBust;
    Hand _Hand;

    BlackJack_Player()=delete;
    BlackJack_Player( int Money = 100, std::string Name = "SomeOne");

    void Make_Double();

    void setInsurance();
    int getInsurance();

    void setChoice(int n);
    char getChoice();

    void ClearHistory();

    void addCard(Card card);
};