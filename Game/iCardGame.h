#pragma once
#include <Cards.h>

class IHand { // interface of Hand
protected:
public:
    virtual int getAllValue()=0;
};

class IPlayer { // interface of player
public:
    virtual const int showMoney()=0;
};

class IDealer { // interface of Dealer
public:
};