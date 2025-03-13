#pragma once
#include "CardDeck.h"

// Her kan du lage dine funksjons- og klassedeklarasjoner for å lage blackjack
class Blackjack
{
    CardDeck deck;
    vector<Card> playerHand;
    vector<Card> dealerHand;
    int playerHandSum = 0;
    int dealerHandSum = 0;
    string getFirstWord(const string& input);
public:
    bool isAce(Card card);
    int getCardValue(Card card);
    int getHandScore(vector<Card> cards);
    bool askPlayerDrawCard();
    void drawPlayerCard();
    void drawDealerCard();
    void playGame();
};

const map<string, int> cardToIntMap 
{
	{"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
    {"ten", 10},
    {"jack", 10},
    {"queen", 10},
    {"king", 10},
    {"ace", 11}

};
const map<Rank, int> cardToIntMap_v2 
{
	{Rank::two, 2},
    {Rank::three, 3},
    {Rank::four, 4},
    {Rank::five, 5},
    {Rank::six, 6},
    {Rank::seven, 7},
    {Rank::eight, 8},
    {Rank::nine, 9},
    {Rank::ten, 10},
    {Rank::jack, 10},
    {Rank::queen, 10},
    {Rank::king, 10},
    {Rank::ace, 11}
};


