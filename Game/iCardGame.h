#pragma once
#include <Cards.h>
#include <Hand.h>
#include <string>
#include <vector>
#include <memory>


class IPlayer {
public:
    IPlayer();

    double getBankSize() const;
    std::string getName()const;
    bool get_isBlackJack()const;
    bool get_isBust()const;

    void set_isBust();
    void set_isBlackJack();
    void setPrize(double n);
    virtual void clearHistory()=0;

    void showAllCards();

    Hand _hand;

protected:
    double _money;
    std::string _name;
    bool _isBlackJack;
    bool _isBust;

};

// Dealer does not have:
class IBlackJackPlayer: public IPlayer{
public:

    IBlackJackPlayer();

    void clearHistory() override;

    virtual void makeBet()=0;
    virtual void makeDouble()=0;
    virtual void makeInsuranceOrPayment()=0;
    virtual void makeMove()=0;

    void setInsurance();
    void setDouble();
    double getBet() const;
    double getInsurance () const;
    char getChoice() const;
    virtual char getChoice_StayOrLeave()const=0 ;

    double takeInsurance();

protected:
    double _insurance;
    char _choice;
    double _bet;
};

class IDealer{

public:

protected:
    BlackJack_DeckPile* _deckPile;
    std::vector<std::shared_ptr<IBlackJackPlayer>>* _players;
};