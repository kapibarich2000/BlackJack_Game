#include <iostream>
#include <string>
#include "Cards.h"
#include <ctime>

// Card

Card::Card(int Value, int Suit): _value(Value), _suit(Suit){};
Card::Card(Card::enValue eValue, Card::enSuit eSuit): _value(eValue), _suit(eSuit){};
Card::Card(): _value(0), _suit(0){};


int Card::getValue()const{
    if (_value <=8){
        return _value + 2;
    }
    else if (_value ==12){
        return 11;
    }
    else{
        return 10;
    }
}

std::string Card::getName()const {
    std::string Name = "";
    switch (_value)
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

    switch (_suit)
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

// BlackJack_DeckPile

int BlackJack_DeckPile::size(){
    return _deck_of_cards.size();
}


void BlackJack_DeckPile::Refresh() { //  Fischer-Yates Shuffle
        std::srand(time(NULL));
        int j;
        Card TempCard;
        for (int i = _deck_of_cards.size()-1; i > 1; i--)    {
            j = std::rand() % (i + 1);
            TempCard=_deck_of_cards[j];
            _deck_of_cards[j]=_deck_of_cards[i];
            _deck_of_cards[i]=TempCard;
        }
}

Card BlackJack_DeckPile::pop() {
    Card card = _deck_of_cards[_deck_of_cards.size()-1];
    _deck_of_cards.pop_back();
    return card;
}

BlackJack_DeckPile::BlackJack_DeckPile(int number_of_decks) {
    // number_of_decks-1   Because the parent constructor is already creating a deck(with 52 cards)
    for (int k = 0; k < number_of_decks-1; k++)
    {
        for (int i = 0; i <= 12; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                _deck_of_cards.emplace_back(Card(i,j));
            }
        }
    }
}
