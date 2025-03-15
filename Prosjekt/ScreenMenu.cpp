#include "ScreenMenu.h"
#include <iostream>


// Draw the menu screen elements
void ScreenMenu::draw(SpaceDefender& window) {
    window.draw_text({150, 100}, "Menu", TDT4102::Color::cyan, 30);
    window.StartGameBtn.setVisible(true);
    window.HighscoresBtn.setVisible(true);
    window.SettingsBtn.setVisible(true);
    window.EndGameBtn.setVisible(true);
    window.GoToMenuBtn.setVisible(false);
}

// Handle the menu screen input
void ScreenMenu::handleInput(SpaceDefender& window) {
    // Just set callbacks for the buttons in SpaceDefender
}
