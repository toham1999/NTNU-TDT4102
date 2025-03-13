#include "mastermind.h"

// BEGIN: 4
//Oppgave 4a til 4j løses her forutenom 4e og 4f
//playMastermind(){}
void playMastermind()
{
    
    constexpr int size = 4;
    constexpr int letters = 6;
    char playingMore = 'y';
    while (playingMore == 'y')
    {
        cout << "Welcome to the mastermind game, you have 10 attempts" << endl;

        string code = randomizeString(size,'A','A' + (letters - 1));
        string guess = readInputToString(size, 'A','A' + (letters - 1));
        int correctPlaces = checkCharactersAndPosition(code,guess);
        int correctLetters = checkCharacters(code,guess);
        cout << "Correct place: " << correctPlaces << ", Correct letters: " << correctLetters << endl;
        int attempts = 1;
        while (correctPlaces < size && attempts < 10)
        {
            guess = readInputToString(size, 'A','A' + (letters - 1));
            correctPlaces = checkCharactersAndPosition(code,guess);
            correctLetters = checkCharacters(code,guess);
            cout << "Correct place: " << correctPlaces << ", Correct letters: " << correctLetters << endl;
            ++attempts;
        }

        if (correctPlaces == 4)
        {
            cout << "You have won" << endl;
        }
        else
        {
            cout << "You have lost..." << endl;
        }
        cout << "Would you like to play again? (y/n), ";
        cin >> playingMore;
    }

}
// END: 4

// BEGIN: 4e
///*returverdi*/ checkCharactersAndPosition(/*param 1: code, param 2: guess*/) {}
int checkCharactersAndPosition(const string& code, const string& guess)
{
    int samePlaceLetter = 0;
    for (int i=0; i<code.size(); ++i)
    {
        if (code.at(i)==guess.at(i))
        {
            samePlaceLetter++;
        }
    }
    return samePlaceLetter;
}
// END: 4e

// BEGIN: 4f
///*returverdi*/ checkCharacters(/*param 1: code, param 2: guess*/) {}
int checkCharacters(const string& code, const string& guess)
{
    int lettersInCommon = 0;
    for (int i=0; i<6;++i)
    {
        char letterToCheck = 'A' + i;
        int letterCheckedInCode = countChar(code,letterToCheck);
        int letterCheckedInGuess = countChar(guess,letterToCheck);
        if (letterCheckedInCode == letterCheckedInGuess)
        {
            lettersInCommon += letterCheckedInCode;
        }
        else if (0 < letterCheckedInCode && letterCheckedInCode < letterCheckedInGuess)
        {
            lettersInCommon += letterCheckedInCode;
        }
        else if (0 < letterCheckedInGuess && letterCheckedInGuess < letterCheckedInCode)
        {
            lettersInCommon += letterCheckedInGuess;
        }
        if (lettersInCommon == 4)
        {
            break;
        }
    }
    return lettersInCommon;
}
// END: 4f