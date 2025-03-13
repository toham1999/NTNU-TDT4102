#include "Blackjack.h"

// Her kan du lage dine funksjons- og klasseimplementasjoner for å lage blackjack

bool Blackjack::isAce(Card card)
{
    return card.toString().compare(0,3,"ace") == 0;
}

int Blackjack::getCardValue(Card card)
{
    string cardStringValue = card.getRank();
    return cardToIntMap.at(cardStringValue);
}

int Blackjack::getHandScore(vector<Card> cards)
{
    int aceCounter = 0;
    int sumCounter = 0;
    for (Card card : cards)
    {
        if (isAce(card))
        {
            ++aceCounter;
            if (aceCounter == 2)
            {
                sumCounter += 12;
                aceCounter = 0;
            }
        }
        else
        {
            sumCounter += getCardValue(card);
        }
    }
    if (aceCounter == 1)
    {
        sumCounter += 11;
    }
    return sumCounter;
}

bool Blackjack::askPlayerDrawCard()
{
    char moreCard = 'n';
    cout << "Do you wanna draw a new card? (y/n) ";
    cin >> moreCard;
    return moreCard == 'y';
}

void Blackjack::drawPlayerCard()
{
    playerHand.push_back(deck.drawCard());
    playerHandSum = getHandScore(playerHand);
}

void Blackjack::drawDealerCard()
{
    dealerHand.push_back(deck.drawCard());
    dealerHandSum = getHandScore(dealerHand);
}

void Blackjack::playGame()
{
    deck.shuffle();
// --- Starting cards ---
    drawDealerCard();
    cout << "Dealer card: hidden card " << endl;
    drawPlayerCard();
    cout << "Player card: " << playerHand.at(0).toString() << endl;
    drawDealerCard();
    cout << "Dealer card: " << dealerHand.at(1).toString() << endl;
    drawPlayerCard();
    cout << "Player card: " << playerHand.at(1).toString() << endl;

// --- Start the game ---
    int counter = 1;
    bool playerTurn = true;
    while (playerHandSum < 21 && dealerHandSum < 21 && playerTurn && counter < 5)
    {
    // --- Dealer turn ---
        if (dealerHandSum < 17)
        {
            drawDealerCard();
            cout << "Dealer card: " << dealerHand.at(dealerHand.size() - 1).toString() << endl;
        }
        else if (17 <= dealerHandSum && dealerHandSum <= 21)
        {
            cout << "Dealer card: No card drawn." << endl;
        }
    // --- Player turn ---
        playerTurn = askPlayerDrawCard();
        if (playerTurn)
        {
            drawPlayerCard();
            cout << "Player card: " << playerHand.at(playerHand.size() - 1).toString() << endl;
        }


    ++counter;
    }
    // Vinning conditions
    if (playerHandSum > 21)
    {
        cout << "You lost." << endl;
    }
    else if (playerHandSum == 21 && dealerHandSum == 21)
    {
        cout << "Draw, no winner" << endl;
    }
    else if (playerHandSum == 21 && dealerHandSum != 21)
    {
        cout << "You won!" << endl;
    }
    else if (playerHandSum > dealerHandSum && playerHandSum < 22)
    {
        cout << "You won!" << endl;
    }

    cout << "Player score: " << playerHandSum << endl;
    cout << "Dealer score: " << dealerHandSum << endl;
    // Finne stop setning
    // dealer automatisk
    // 
}