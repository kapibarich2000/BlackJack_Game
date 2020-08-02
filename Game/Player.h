#pragma once
#include <iCardGame.h>
#include <Hand.h>
#include <string>

class BlackJack_Player: public IPlayer {
protected:
    int _Insurance;
    bool _isBlackJack;
    bool _isBust;
public:
    Hand _Hand;

    BlackJack_Player()=delete;
    BlackJack_Player( int Money = 100, std::string Name = "SomeOne");

    void Make_Double();

    void setInsurance();
    int getInsurance();

    void setChoice(int n);
    void setChoice();
    char getChoice();

    bool const get_isBust();
    void set_isBust();

    bool const get_isBlackJack();
    void set_isBlackJack();


    void ClearHistory();

    void addCard(Card card);
};