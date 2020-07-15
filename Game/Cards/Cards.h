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
};

class BlackJack_Deck{
private:
    std::vector<Card> Deck_of_cards;
public:
    bool isEmptyDeck();
    BlackJack_Deck();
    void Refresh();
};

class  BlackJack_DeckPile : public BlackJack_Deck{
private:
    std::vector<Card> Deck_of_cards;
public:
    BlackJack_DeckPile();
};
