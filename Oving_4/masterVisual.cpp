#pragma once
#include "masterVisual.h"
#include "mastermind.h"


// i denne løses 5 a, d, g og litt av f
// BEGIN: 5

void playMastermindVisual()
{
	// --- From mastermind.cpp ---
	constexpr int size = 4;
    constexpr int letters = 6;
    char playingMore = 'y';
    while (playingMore == 'y')
    {
		MastermindWindow mwin{900, 20, winW, winH, size, "Mastermind"};
        cout << "Welcome to the mastermind game, you have 10 attempts" << endl;

        string code = randomizeString(size,'A','A' + (letters - 1));
        string guess = mwin.getInput(size, 'A','A' + (letters - 1));
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
// END: 5


void addGuess(MastermindWindow &mwin, const string code, const char startLetter)
{
	// BEGIN: 5b
	mwin.guesses.push_back({code, startLetter});
	// END: 5b
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	// BEGIN: 5e

	// END: 5e
}

void MastermindWindow::drawCodeHider()
{
	if (code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::cb_guess, this));
};

void MastermindWindow::drawGuessesAndFeedbacks()
{
	std::map<int, Color> colorConverter{
		{1, Color::red},
		{2, Color::green},
		{3, Color::yellow},
		{4, Color::blue},
		{5, Color::blue_violet},
		{6, Color::dark_cyan}};

	for (int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++)
	{
		/*********************************************************************/

		// BEGIN: 5c
		
		// Implementer funksjonalitet slik at det vises fargede rektangler i grafikkvinduet
		// Legg merke til at vi er i et for-løkke som går gjennom alle gjettene som er gjort.
		// Tegn gjettet som ligger på plassen guessIndex i vektoren guesses.
		draw_rectangle({guessIndex * padX + padX, guessIndex * padY}, padX, padY, colorConverter.at(guessIndex + 1), Color::black);

		for (int i = 0; i < size; i++)
		{
			draw_rectangle({i * padX + padX, guessIndex * padY}, padX, padY, colorConverter.at(guessIndex + 1), Color::black);
			// Denne for-løkken går gjennom alle firkantene som skal tegnes i et gjett.
			// Tegn rektangler ved bruk av draw_rectangle(). Bruk: colorConverter.at() for å få riktig farge

		}
		// END: 5c
	}

	for (int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++)
	{
		/*********************************************************************/

		// BEGIN: 5f

		// Implementer feedback
		// Her skal mye likt gjøres som i 5c

		for (int i = 0; i < size; i++)
		{
			// Tegn sirkler ved hjelp av draw_circle().

		}
		// END: 5f
	}
}

string MastermindWindow::wait_for_guess()
{

	while (!button_pressed && !should_close())
	{
		drawGuessesAndFeedbacks();
		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");

	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}

