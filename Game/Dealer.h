#pragma once
#include <iCardGame.h>
#include <Cards.h>
#include <Hand.h>
#include <Player.h>

class BlackJack_Dealer: public IDealer, public IPlayer {
private:
    BlackJack_DeckPile* _DeckPile;
    double _Money;
public:

    Hand _Hand;
    bool _isBlackJack;
    bool _isBust;

    BlackJack_Dealer()=delete ;
    BlackJack_Dealer(int Money);
    BlackJack_DeckPile* retPointonDeck();
    void setDeckPile(BlackJack_DeckPile* DeckPile);
    int const showMoney() override;
    void ClearHistory();
    double givePrize(BlackJack_Player& Player);
    int getNumberOfCards();

    //  void setPlayers(std::vector<IPlayer*> Players);
    //  void startRound();

};
