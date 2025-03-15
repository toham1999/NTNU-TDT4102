#include "ScreenHighscore.h"

// Draw the highscore screen elements
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

// Handle the highscore screen input
void ScreenHighscore::handleInput(SpaceDefender& window) {
    // You could add logic here for input (e.g., press 'Back' to go back to the menu)
}
