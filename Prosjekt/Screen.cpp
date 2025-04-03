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
/*
    for (auto& weaponPtr : window.firedWeapons) {
        // Check if the weapon is out of the screen, stops memory leakage
        if (weaponPtr->getPositionY() < 0) {
            window.firedWeapons.pop_back();
        }
        if (weaponPtr->getPositionY() > window.height()) {
            weaponPtr -> ~Weapon();
            weaponPtr = nullptr;
            break;
        }
    
        weaponPtr->move();
        weaponPtr->draw(window);
        
        // Check if the weapon hit the enemy ship
        
        for (SpaceShipEnemy& enemyShip : window.enemyShips) {
            if (weaponPtr->getPositionX() >= enemyShip.getPositionX() ||
                weaponPtr->getPositionX() <= enemyShip.getPositionX() + enemyShip.getShipWidth() ||
                weaponPtr->getPositionY() >= enemyShip.getPositionY() ||
                weaponPtr->getPositionY() <= enemyShip.getPositionY() + enemyShip.getShipHeight()) {
                //window.firedWeapons.erase(window.firedWeapons.begin());

                enemyShip.healthReduction(weaponPtr->getDamage());
                window.firedWeapons.erase(std::remove(window.firedWeapons.begin(), window.firedWeapons.end(), weaponPtr), window.firedWeapons.end());
                if (enemyShip.getHealth() <= 0) {
                    //window.enemyShips.erase(std::remove(window.enemyShips.begin(), window.enemyShips.end(), enemyShip), window.enemyShips.end());
                    //enemyShip.~SpaceShipEnemy();
                    window.enemyShips.pop_back();
                }
            } 
        }
    }
    */
    // itereator version
    if(!window.firedWeapons.empty()){
        std::vector<std::unique_ptr<Weapon>> firedWeaponsCopy;
        
        for(auto it = window.firedWeapons.begin(); it != window.firedWeapons.end();)
        {  
            for(int i = 0; i < window.enemyShips.size(); i++)
            {
                auto itEnemy = window.enemyShips.at(i);
                if((itEnemy.getPositionX()<=(*it)->getPositionX() && (*it)->getPositionX()<= itEnemy.getPositionX() + itEnemy.getShipWidth()) &&
                ((*it)->getPositionY() <= (itEnemy).getPositionY() + (itEnemy).getShipHeight()))
                {
                    window.firedWeapons.erase(it);
                    break;
                    //window.enemyShips.erase(window.enemyShips.at(i));

                    /*window.enemyShips.erase(std::remove_if(window.enemyShips.begin(), window.enemyShips.end(), [](SpaceShipEnemy& enemyShip) 
                    {
                        return ((itEnemy->getPositionX()<=(*it)->getPositionX() && (*it)->getPositionX()<= (itEnemy)->getPositionX() + (itEnemy)->getShipWidth()) &&
                        ((*it)->getPositionY() <= (itEnemy)->getPositionY() + (itEnemy)->getShipHeight()));}
                    ))
                    */
                    /*
                    (itEnemy)->healthReduction((*it)->getDamage());
                    it = window.firedWeapons.erase(it);
                    if ((itEnemy)->getHealth() <= 0) {
                        window.enemyShips.erase(itEnemy);
                        
                        } */
                }
                else{
                    //itEnemy++;
                    //break;
                }
            } 
            //window.firedWeapons.erase();
            
            // Check if the weapon is out of the screen, stops memory leakage WORKS!!!
        
            if ((*it)->getPositionY() < 100)
            {
                it = window.firedWeapons.erase(it);
            }
            else{
                (*it)->move();
                (*it)->draw(window);
                it++;
            }
            
        
            /*
            if (((itEnemy)->getPositionX()>=(*it)->getPositionX()<= (itEnemy)->getPositionX() + (itEnemy)->getShipWidth())&&
                ((*it)->getPositionY() <= (itEnemy)->getPositionY() + (itEnemy)->getShipHeight()) )
            for(auto itEnemy = window.enemyShips.begin(); itEnemy != window.enemyShips.end(); itEnemy++){
                if (((itEnemy)->getPositionX()>=(*it)->getPositionX()<= (itEnemy)->getPositionX() + (itEnemy)->getShipWidth())&&
                ((*it)->getPositionY() <= (itEnemy)->getPositionY() + (itEnemy)->getShipHeight()) ){
                    (*itEnemy).healthReduction((*it)->getDamage());
                    window.firedWeapons.erase(it);
                    if ((*itEnemy).getHealth() <= 0) {
                        window.enemyShips.erase(itEnemy);
                    }
        }}
            */

        
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