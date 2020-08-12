#pragma once
#include <iostream>
#include <vector>
#include <string>

class Card {
private:
    int eValue;
    int eSuit;
public:
    int getValue()const;
    std::string getName()const;

    Card(int Value, int Suit);

    Card();
};

class BlackJack_Deck{
protected:
    std::vector<Card> _Deck_of_cards;
public:
    void  Refresh();
    BlackJack_Deck();
    int size();
    Card pop();
};


class  BlackJack_DeckPile: public BlackJack_Deck{
public:
    BlackJack_DeckPile(int number_of_decks);
};
