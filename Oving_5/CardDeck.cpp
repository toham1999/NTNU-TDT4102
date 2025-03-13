#include "CardDeck.h"

// BEGIN: 3b
CardDeck::CardDeck()
{
    for (const auto& [keySuit, valueSuit] : SuitToStringMap) //Each suit type
    {
        for (const auto& [keyRank, valueRank] : rankToStringMap) //Each rank for each suit
        {
            Card c(keySuit, keyRank);
            cards.push_back(c);
        }
    }
}
// END: 3b

// BEGIN: 3c
void CardDeck::swap(int index1, int index2)
{
    Card temp = cards.at(index1);
    cards.at(index1) = cards.at(index2);
    cards.at(index2) = temp;
}
// END: 3c

// BEGIN: 3d
void CardDeck::print()
{
    for (Card c : cards)
    {
        cout << c.toString() << endl;
    }
}
// END: 3d

// BEGIN: 3e
void CardDeck::shuffle()
{
    random_device seed;
	default_random_engine generator(seed());
	uniform_int_distribution<int> distribution(0,51);
    for (int i=0;i<1000;++i)
    {
        int index1 = distribution(generator);
        int index2 = distribution(generator);
        swap(index1,index2);
    }
}
// END: 3e

// BEGIN: 3f
Card CardDeck::drawCard()
{
    int cardIndex = cards.size() - 1;
    Card c = cards.at(cardIndex);
    cards.erase(cards.begin() + cardIndex);
    return c;
}
// END: 3f
