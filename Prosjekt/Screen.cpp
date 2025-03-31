#include "Screen.h"
#include "SpaceDefender.h"


// ---- ScreenMenu ----
void ScreenMenu::draw(SpaceDefender& window) {
    //window.draw_text({150, 100}, "Menu", TDT4102::Color::cyan, 30);
    window.StartGameBtn.setVisible(true);
    window.HighscoresBtn.setVisible(true);
    window.SettingsBtn.setVisible(true);
    window.EndGameBtn.setVisible(true);
    window.GoToMenuBtn.setVisible(false);
}


// ---- ScreenGame ----
void ScreenGame::draw(SpaceDefender& window) {
    for (SpaceShipEnemy enemyShip : window.enemyShips) {
        //window.draw_circle({enemyShip.getPositionX(),enemyShip.getPositionY()},10,TDT4102::Color::antique_white);
        window.draw_image({enemyShip.getPositionX(),enemyShip.getPositionY()},
                enemyShip.alienImage, enemyShip.getShipWidth(),enemyShip.getShipHeight());
    }
    window.draw_image({window.playerShip.getPositionX(),window.playerShip.getPositionY()}, 
                       window.playerShip.playerImage, window.playerShip.getShipWidth(), window.playerShip.getShipHeight());

    // Hide unnecessary buttons for this screen
    window.StartGameBtn.setVisible(false);
    window.HighscoresBtn.setVisible(false);
    window.SettingsBtn.setVisible(false);
    window.EndGameBtn.setVisible(false);
    window.GoToMenuBtn.setVisible(true);

    // Update and draw fired weapons
    for (auto& weaponPtr : window.firedWeapons) {
        weaponPtr->move();
        weaponPtr->draw(window);
    }

    // Update spaceship movements and shooting
    window.playerShip.movements(window);
    window.playerShip.shooting(window);
}


// ---- ScreenHighscore ----
void ScreenHighscore::draw(SpaceDefender& window) {
    window.draw_text({window.width()/2 - window.width()/4, window.height()/20}, "TOP 10 SCORES", TDT4102::Color::aqua,  35);
    // Headline row
    window.draw_text({150, 120}, "Rank  Player - Score  Round", TDT4102::Color::white, 20);

    // Player rows (you can add round number here as well)
    window.draw_text({150, 150}, "1. Player1 - 100  Round 1", TDT4102::Color::white, 20);
    window.draw_text({150, 180}, "2. Player2 - 80  Round 1", TDT4102::Color::white, 20);
    window.draw_text({150, 210}, "3. Player3 - 60  Round 1", TDT4102::Color::white, 20);
    window.draw_text({150, 240}, "4. Player4 - 40  Round 1", TDT4102::Color::white, 20);
    window.draw_text({150, 270}, "5. Player5 - 30  Round 1", TDT4102::Color::white, 20);
    window.draw_text({150, 300}, "6. Player6 - 20  Round 1", TDT4102::Color::white, 20);
    window.draw_text({150, 330}, "7. Player7 - 15  Round 1", TDT4102::Color::white, 20);
    window.draw_text({150, 360}, "8. Player8 - 10  Round 1", TDT4102::Color::white, 20);
    window.draw_text({150, 390}, "9. Player9 - 50  Round 1", TDT4102::Color::white, 20);
    window.draw_text({150, 420}, "10. Player10 - 0  Round 1", TDT4102::Color::white, 20);


    // Hide unnecessary buttons for this screen
    window.StartGameBtn.setVisible(false);
    window.HighscoresBtn.setVisible(false);
    window.SettingsBtn.setVisible(false);
    window.EndGameBtn.setVisible(false);
    window.GoToMenuBtn.setVisible(true);
}


// ---- ScreenSettings ----
void ScreenSettings::draw(SpaceDefender& window) {
    window.draw_text({window.width()*2/5, 100}, "Settings", TDT4102::Color::cyan, window.height()/20); 

    // Hide unnecessary buttons for this screen
    window.StartGameBtn.setVisible(false);
    window.HighscoresBtn.setVisible(false);
    window.SettingsBtn.setVisible(false);
    window.EndGameBtn.setVisible(false);
    window.GoToMenuBtn.setVisible(true);
}