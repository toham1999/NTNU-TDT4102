#pragma once

#include "AnimationWindow.h"
#include "widgets/Button.h"

#include "Screen.h"
#include "SpaceShip.h"
#include "Weapon.h"


class SpaceDefender : public TDT4102::AnimationWindow {
private:
	std::unique_ptr<Screen> currentScreen;

    // Define button width and height based on screen size
    unsigned int btnWidth;
    unsigned int btnHeight;

    // Callback functions for buttons
    void cb_startGame();
    void cb_showHighscores();
	void cb_settings();
	void cb_endGame();
	void cb_menu();

public:
    SpaceDefender(TDT4102::Point position = {100, 100}, int width = 600, int height = 800, const std::string& title = "Space Defender");
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

    // Weapons
    std::vector<std::unique_ptr<Weapon>> firedWeapons;
};