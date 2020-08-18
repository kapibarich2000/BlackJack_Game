#pragma once
#include <iostream>
#include <vector>
#include <string>


class Card {
public:
    enum enValue {
        Two, // 0
        Three,//1
        Four,//2
        Five,//3
        Six,    // 4
        Seven,
        Eight,
        Nine,
        Ten, // 8
        Jack,
        Queen,
        King,
        Ace, // 12
    };
    enum enSuit{
        Diamonds, // 0
        Hearts,
        Spades,
        Club // 3
    };
private:
    int _value;
    int _suit;
public:
    int getValue()const;
    std::string getName()const;

    Card(int Value, int Suit);
    Card(enValue eValue, enSuit eSuit);
    Card();


};

class  BlackJack_DeckPile{
public:
    BlackJack_DeckPile(int number_of_decks);

    void  Refresh();
    int size();
    Card pop();
private:
    std::vector<Card> _deck_of_cards;
};
