#include <gtest/gtest.h>
#include <Cards.h>

// Arrange

// Act

// Assert

TEST(Card, getValue){
    // Arrange
    std::vector<Card> allCards;
    for (int i = 0; i <= 12; ++i) {
        for (int j = 0; j < 4; ++j) {
            allCards.emplace_back(Card(i,j));
        }
    }

    // Act
    int counter=0;
    for (auto i=0;i<allCards.size();i++) {
        counter+=allCards[i].getValue();
    }

    // Assert
    std::cout<<"The total points of a full deck of cards without jokers must be equal to 380\n";
    EXPECT_EQ(counter,380);
}

TEST(BlackJack_Deck, Constructor){
    // Arrange
    BlackJack_Deck deckPile;
    // Act
    // Assert
    std::cout<<"The new deck must contain 52 cards:\n";
    EXPECT_EQ(deckPile.size(),52);
}

TEST(BlackJack_Deck, Pop){
    // Arrange
    BlackJack_Deck deckPile;
    // Act
    auto card=deckPile.pop();
    for (int i = 0; i < 51; ++i) {
        card=deckPile.pop();
    }
    // Assert
    std::cout<<"1) After executing pop () 52 times, the container must be empty:\n";
    EXPECT_EQ(deckPile.size(),0);
    std::cout<<"2) pop () returns an object of the Card class\n";
    EXPECT_TRUE(card.getValue());
}

TEST(BlackJack_DeckPile, Constructor){
    // Arrange
    BlackJack_DeckPile deckPile(4);
    // Act
    // Assert
    std::cout<<"If I pass 4 to the Deck constructor, then created a DeckPile with 208 cards:\n";
    EXPECT_EQ(deckPile.size(),208);
    EXPECT_TRUE(deckPile.pop().getValue());
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}