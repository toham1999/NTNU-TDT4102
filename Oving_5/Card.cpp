#include "Card.h"
#include "std_lib_facilities.h"

// BEGIN: 1c
string suitToString(Suit s)
{
    return SuitToStringMap.at(s);
}
// END: 1c

// BEGIN: 1d
string rankToString(Rank r)
{
    return rankToStringMap.at(r);
}
// END: 1d

// BEGIN: 2b
Card::Card(Suit suit, Rank rank)
{
    s = suit;
    r = rank;
}
// END: 2b

// BEGIN: 2c
string Card::getSuit()
{
    return suitToString(s);
}
// END: 2c

// BEGIN: 2d
string Card::getRank()
{
    return rankToString(r);
}
// END: 2d

// BEGIN: 2e
string Card::toString()
{
    return getRank() + " of " + getSuit();
}
// END: 2e