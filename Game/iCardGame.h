#pragma once
#include <Cards.h>
#include <Hand.h>
#include <string>
#include <vector>


class IPlayer {
public:
    IPlayer();
    double showMoney() const;
    std::string getName()const;
    bool get_isBlackJack()const;
    bool get_isBust()const;
    void set_isBust();
    void set_isBlackJack();
    virtual void clearHistory()=0;

    Hand _Hand;

protected:
    double _Money;
    std::string _Name;
    bool _isBlackJack;
    bool _isBust;

};

// Dealer does not have:
class IBlackJackPlayer: public IPlayer{
public:

    IBlackJackPlayer();

    void clearHistory() override; // Перенести в IPlayer

    virtual void makeBet()=0;
    virtual void makeDouble()=0;
    virtual void makeInsuranceOrPayment()=0;
    virtual void makeMove()=0;

    void setInsurance();
    void setDouble();
    virtual void setPrize(double n);
    double getBet() const;
    double getInsurance() const;
    char getChoice() const;

    virtual char getChoice_StayOrLeave()const=0 ;

protected:
    double _Insurance;
    char _Choice;
    double _Bet;
};

class IDealer{

public:

protected:
    BlackJack_DeckPile* _DeckPile;
    std::vector<IBlackJackPlayer*>* _Players;
};