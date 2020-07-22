#pragma once
#include <Cards.h>

class IHand { // interface of Hand
protected:
public:
    virtual int getValue(int n)=0;
};

class IPlayer { // interface of player
public:
    virtual const int showMoney()=0;
    //virtual void Make_Bet()=0;
//    Hand _Hand;
};

class IDealer { // interface of Dealer
public:
};