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


// ---- ScreenGame ---
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
        // Check if the weapon is out of the screen, stops memory leakage
        if (weaponPtr->getPositionY() < 0) {
            window.firedWeapons.erase(std::remove(window.firedWeapons.begin(), window.firedWeapons.end(), weaponPtr), window.firedWeapons.end());
        }
        if (weaponPtr->getPositionY() > window.height()) {
            weaponPtr -> ~Weapon();
        }
        weaponPtr->move();
        weaponPtr->draw(window);
        
        // Check if the weapon hit the enemy ship
        
        for (SpaceShipEnemy& enemyShip : window.enemyShips) {
            if (weaponPtr->getPositionX() >= enemyShip.getPositionX() &&
                weaponPtr->getPositionX() <= enemyShip.getPositionX() + enemyShip.getShipWidth() &&
                weaponPtr->getPositionY() >= enemyShip.getPositionY() &&
                weaponPtr->getPositionY() <= enemyShip.getPositionY() + enemyShip.getShipHeight()) {
                //window.firedWeapons.erase(window.firedWeapons.begin());

                enemyShip.healthReduction(weaponPtr->getDamage());
                weaponPtr -> ~Weapon();
                if (enemyShip.getHealth() <= 0) {
                    enemyShip.~SpaceShipEnemy();
                }
            } 
        }
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