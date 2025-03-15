#include "ScreenGame.h"

// Draw the highscore screen elements
void ScreenGame::draw(SpaceDefender& window) {
    window.draw_text({150, 100}, "Game screen", TDT4102::Color::cyan, 30);

    // Hide unnecessary buttons for this screen
    window.StartGameBtn.setVisible(false);
    window.HighscoresBtn.setVisible(true);
    window.SettingsBtn.setVisible(false);
    window.EndGameBtn.setVisible(false);
    window.GoToMenuBtn.setVisible(true);
}

// Handle the highscore screen input
void ScreenGame::handleInput(SpaceDefender& window) {
    // You could add logic here for input (e.g., press 'Back' to go back to the menu)
}
