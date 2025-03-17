#include "Screen.h"
#include "SpaceDefender.h"


// ---- ScreenMenu ----
void ScreenMenu::draw(SpaceDefender& window) {
    window.draw_text({150, 100}, "Menu", TDT4102::Color::cyan, 30);
    window.StartGameBtn.setVisible(true);
    window.HighscoresBtn.setVisible(true);
    window.SettingsBtn.setVisible(true);
    window.EndGameBtn.setVisible(true);
    window.GoToMenuBtn.setVisible(false);
}


// ---- ScreenGame ----
void ScreenGame::draw(SpaceDefender& window) {
    window.draw_text({150, 100}, "Game screen", TDT4102::Color::cyan, 30);
    window.draw_circle({window.playerShip.getPositionX(),window.playerShip.getPositionY()}, 15, TDT4102::Color::white);

    // Hide unnecessary buttons for this screen
    window.StartGameBtn.setVisible(false);
    window.HighscoresBtn.setVisible(false);
    window.SettingsBtn.setVisible(false);
    window.EndGameBtn.setVisible(false);
    window.GoToMenuBtn.setVisible(true);
}


// ---- ScreenHighscore ----
void ScreenHighscore::draw(SpaceDefender& window) {
    window.draw_text({150, 100}, "Highscores", TDT4102::Color::cyan, 30);
    window.draw_text({150, 150}, "1. Player1 - 100", TDT4102::Color::white, 20);
    window.draw_text({150, 180}, "2. Player2 - 80", TDT4102::Color::white, 20);
    window.draw_text({150, 210}, "3. Player3 - 60", TDT4102::Color::white, 20);

    // Hide unnecessary buttons for this screen
    window.StartGameBtn.setVisible(false);
    window.HighscoresBtn.setVisible(false);
    window.SettingsBtn.setVisible(false);
    window.EndGameBtn.setVisible(false);
    window.GoToMenuBtn.setVisible(true);
}


// ---- ScreenSettings ----
void ScreenSettings::draw(SpaceDefender& window) {
    window.draw_text({150, 100}, "Settings", TDT4102::Color::cyan, 30);

    // Hide unnecessary buttons for this screen
    window.StartGameBtn.setVisible(false);
    window.HighscoresBtn.setVisible(true);
    window.SettingsBtn.setVisible(true);
    window.EndGameBtn.setVisible(false);
    window.GoToMenuBtn.setVisible(true);
}