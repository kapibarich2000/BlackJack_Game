#pragma once
#include <vector>

class IPlayer { // interface of player
public:
    int Money;
    IPlayer(int Money):Money(Money){};
    virtual const bool Hit() =0;
    //virtual const bool Stand()=0;
    //virtual const int Make_Bet()=0;
    virtual const int getMoney()=0;

};

class IDealer { // interface of Dealer
public:
    int Money;
    IDealer(int Money):Money(Money){};
};

//class IDeck{ // interface of Deck
//public:
//   virtual  void Refresh()=0;
//};

//class IGame{
//public:
 //   void CreatePlayer(){
//
 //   }
 //   std::vector<IPlayer> Gamers;
//};