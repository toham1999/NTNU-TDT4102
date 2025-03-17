#pragma once

#include "AnimationWindow.h"
#include "widgets/Button.h"

#include "Screen.h"
#include "SpaceShip.h"


class SpaceDefender : public TDT4102::AnimationWindow {
public:
    SpaceDefender(TDT4102::Point position, int width, int height, const std::string& title = "Space Defender");

    void setScreen(std::unique_ptr<Screen> newScreen);
    void run();

    // Buttons
    TDT4102::Button StartGameBtn;
    TDT4102::Button HighscoresBtn;
	TDT4102::Button SettingsBtn;
    TDT4102::Button EndGameBtn;
	TDT4102::Button GoToMenuBtn;

	// Spaceships 
	SpaceShipPlayer playerShip;
    std::vector<SpaceShipEnemy> enemyShips;

private:
	std::unique_ptr<Screen> currentScreen;

    // Callback functions for buttons
    void cb_startGame();
    void cb_showHighscores();
	void cb_settings();
	void cb_endGame();
	void cb_menu();
};