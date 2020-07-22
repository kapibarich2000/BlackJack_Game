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

class BlackJack_Deck: public Card{
private:
    std::vector<Card> _Deck_of_cards;
public:
    BlackJack_Deck();
    Card moveCard();
   // void push_back(Card card);
    virtual int size();
    virtual Card & operator[](int i);
};

//class  BlackJack_DeckPile : public BlackJack_Deck, public Card {
class  BlackJack_DeckPile: public Card{
private:
    std::vector<Card> _Deck_of_cards;
public:
    BlackJack_DeckPile();
    int size();
    Card & operator[](int i);
    Card moveCard();
};
