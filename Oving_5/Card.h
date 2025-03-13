#pragma once
#include "std_lib_facilities.h"

// BEGIN: 1a
enum class Suit 
{
	clubs,diamonds,hearts,spades
};
// END: 1a

// BEGIN: 1b
enum class Rank 
{
	two=2,three,four,five,six,seven,eight,nine,ten,jack,queen,king,ace
};
// END: 1b


// Les deg opp på map og unordered_map i C++, og bruk disse map-ene 
// for å konvertere mellom Rank/Suit og string i oppgavene videre
// Husk å fjern /* for å bruke map-ene
const map<Rank, string> rankToStringMap {
	{Rank::two, "two"},
	{Rank::three, "three"},
	{Rank::four, "four"},
	{Rank::five, "five"},
	{Rank::six, "six"},
	{Rank::seven, "seven"},
	{Rank::eight, "eight"},
	{Rank::nine, "nine"},
	{Rank::ten, "ten"},
	{Rank::jack, "jack"},
	{Rank::queen, "queen"},
	{Rank::king, "king"},
	{Rank::ace, "ace"}
};

const map<Suit, string> SuitToStringMap {
	{Suit::clubs, "clubs"},
	{Suit::diamonds, "diamonds"},
	{Suit::hearts, "hearts"},
	{Suit::spades, "spades"}
};


// BEGIN: 1c
string suitToString(Suit s);
// END: 1c

// BEGIN: 1d
string rankToString(Rank r);
// END: 1d

// BEGIN: 2a
class Card
{
	Suit s;
	Rank r;
	
public:
	string getSuit();
	string getRank();
	string toString();
	Card(Suit suit, Rank rank);
};
// END: 2a