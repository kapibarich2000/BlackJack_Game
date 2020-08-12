#include <iostream>
#include <string>
#include "Cards.h"
#include <ctime>

enum class eValue {
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

enum class eSuit{
    Diamonds, // 0
    Hearts,
    Spades,
    Club // 3
};


int Card::getValue(){
    if (eValue <=8){
        return eValue + 2;
    }
    else if (eValue ==12){
        return 11;
    }
    else{
        return 10;
    }
}

std::string Card::getName() {
    std::string Name = "";
    switch (eValue)
    {
        case (0):
            Name += "Two ";
            break;
        case (1):
            Name += "Three ";
            break;
        case (2):
            Name += "Four ";
            break;
        case (3):
            Name += "Five ";
            break;
        case (4):
            Name += "Six ";
            break;
        case (5):
            Name += "Seven ";
            break;
        case (6):
            Name += "Eight ";
            break;
        case (7):
            Name += "Nine ";
            break;
        case (8):
            Name += "Ten ";
            break;
        case (9):
            Name += "Jack ";
            break;
        case (10):
            Name += "Queen ";
            break;
        case (11):
            Name += "King ";
            break;
        case (12):
            Name += "Ace ";
            break;
        default:
            break;
    }

    switch (eSuit)
    {
        case 0:
            Name += "Diamonds";
            break;
        case 1:
            Name += "Hearts";
            break;
        case 2:
            Name += "Spades";
            break;
        case 3:
            Name += "Club";
            break;
        default:
            break;
    }
    return Name;
}

BlackJack_Deck::BlackJack_Deck() {
    for (size_t i = 0; i <= 12; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            _Deck_of_cards.push_back(Card(i, j));
        }
    }
}


int BlackJack_Deck::size(){
    return _Deck_of_cards.size();
}


void BlackJack_Deck::Refresh() { //  Fischer-Yates Shuffle

        std::srand(time(NULL));
        int j;
        Card TempCard;
        for (int i = _Deck_of_cards.size()-1; i > 1; i--)    {
            j = std::rand() % (i + 1);
            TempCard=_Deck_of_cards[j];
            _Deck_of_cards[j]=_Deck_of_cards[i];
            _Deck_of_cards[i]=TempCard;
        }
}

Card BlackJack_Deck::pop() {
    Card card = _Deck_of_cards[_Deck_of_cards.size()-1];
    _Deck_of_cards.pop_back();
    return card;
}

BlackJack_DeckPile::BlackJack_DeckPile(int number_of_decks) {
    for (int k = 0; k < number_of_decks; k++)
    {
        for (size_t i = 0; i <= 12; i++)
        {
            for (size_t j = 0; j <= 3; j++)
            {
                _Deck_of_cards.push_back(Card(i, j));
            }
        }
    }
}
