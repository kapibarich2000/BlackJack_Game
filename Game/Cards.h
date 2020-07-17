#pragma once
#include <iostream>
#include <vector>
#include <string>

class Card {
private:
    int eValue;
    int eSuit;
public:
    int getValue();
    std::string getName();
    Card(int Value, int Suit): eValue(Value), eSuit(Suit){};
    Card(): eValue(0), eSuit(0){};
};

class BlackJack_Deck{
private:
    std::vector<Card> _Deck_of_cards;
public:
    BlackJack_Deck();
    void Refresh();
    Card moveCard();
    void push_back(Card card);
    int size();
};

class  BlackJack_DeckPile : public BlackJack_Deck{
private:
   std::vector<Card> Deck_of_cards;
public:
    BlackJack_DeckPile();
};
