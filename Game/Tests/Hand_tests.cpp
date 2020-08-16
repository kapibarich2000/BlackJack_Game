#include <gtest/gtest.h>
#include <Cards.h>
#include <Hand.h>

TEST(Hand, setCard){
    // Arrange
    Hand hand;
    // Act
    for (int i = 0; i <10; ++i) {
        hand.setCard(Card());
    }
    // Assert
    std::cout<<"1) The setCard method must add one object Card at a time to the container\n";
    EXPECT_EQ(hand.getNumberOfCards(),10);
    EXPECT_TRUE(hand.getFirstCardValue()); //check: is it Card ?
}

TEST(Hand, getCardsValue){
    // //////////// Arrange
    // Ace + 10 == 21
    Hand hand1;
    hand1.setCard(Card((Card::Ace),(Card::Hearts)));
    hand1.setCard(Card(Card::Ten,Card::Club));

    // Ace + Queen + Jack == 21
    Hand hand2;
    hand2.setCard(Card((Card::Ace),(Card::Diamonds)));
    hand2.setCard(Card(Card::Queen,Card::Spades));
    hand2.setCard(Card(Card::Jack,Card::Diamonds));

    // Ace + Queen + Ace + 8 == 20
    Hand hand3;
    hand3.setCard(Card((Card::Ace),(Card::Diamonds)));
    hand3.setCard(Card(Card::Queen,Card::Spades));
    hand3.setCard(Card(Card::Ace,Card::Club));
    hand3.setCard(Card(Card::Eight,Card::Diamonds));

    // 8 + 10 + Ace == 19
    Hand hand4;
    hand4.setCard(Card((Card::Eight),(Card::Spades)));
    hand4.setCard(Card(Card::Ten,Card::Spades));
    hand4.setCard(Card(Card::Ace,Card::Club));

    // Ace + King + Ace + 8 < 21
    Hand hand5;
    hand5.setCard(Card((Card::Ace),(Card::Diamonds)));
    hand5.setCard(Card(Card::King,Card::Hearts));
    hand5.setCard(Card(Card::Ace,Card::Club));
    hand5.setCard(Card(Card::Eight,Card::Hearts));

    // //////////// Act

    // //////////// Assert
    std::cout<<"2) Calculates card points correctly\n";
    EXPECT_EQ(hand1.getCardsValue(),21);
    EXPECT_EQ(hand2.getCardsValue(),21);
    EXPECT_EQ(hand3.getCardsValue(),20);
    EXPECT_EQ(hand4.getCardsValue(),19);
    EXPECT_LT(hand4.getCardsValue(),21);


}