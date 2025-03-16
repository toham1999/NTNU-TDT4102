#include "ScreenGame.h"


void ScreenGame::draw(SpaceDefender& window) {
    window.draw_text({150, 100}, "Game screen", TDT4102::Color::cyan, 30);
    window.draw_circle({window.playerShip.getPositionX(),window.playerShip.getPositionY()}, 15, TDT4102::Color::white);


    window.StartGameBtn.setVisible(false);
    window.HighscoresBtn.setVisible(false);
    window.SettingsBtn.setVisible(false);
    window.EndGameBtn.setVisible(false);
    window.GoToMenuBtn.setVisible(true);
}

void ScreenGame::handleInput(SpaceDefender& window) {}