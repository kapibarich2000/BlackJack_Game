#pragma once
#include <Cards.h>
#include <string>

class IPlayer { // interface of player
public:
    virtual const double showMoney();
    virtual const std::string getName();
    virtual const double getBet();
    virtual void Make_Bet();
    void setPrize(double n);

protected:
    double _Bet;
    char _Choice;
    double _Money;
    std::string _Name;
};

class IDealer { // interface of Dealer
protected:

public:

};