#pragma once
//#include <Player.h>
#include <iCardGame.h>
#include <Cards.h>
#include <Hand.h>

class BlackJack_Dealer: public IDealer, public IPlayer {
private:
    BlackJack_DeckPile* _DeckPile;
    int _Money;
public:

    Hand _hand;

    BlackJack_Dealer()=delete ;
    BlackJack_Dealer(int Money);
    BlackJack_DeckPile* retPointonDeck();
    void setDeckPile(BlackJack_DeckPile* DeckPile);
  //  void setPlayers(std::vector<IPlayer*> Players);
    int const showMoney() override;
  //  void startRound();

};
