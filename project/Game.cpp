#include "Game.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Warrior.h"
#include "Monster.h"
#include "Knight.h"
#include "Wizard.h"
#include "Magician.h"
#include "Game.h"
#include <queue>


void Game::gameStart() {
    std::cout << "Welcome to Alanna & Celestine & Summer's RPG game!\n";
    std::cout << ">> Would you like to start a new game or resume?\n";
    std::cout << "    [1] Start a new game\n";
    std::cout << "    [2] Resume\n";
    std::cout << "    [3] Quit\n";
    std::string input;
    while (1) {
        std::cin >> input;
        if (input.length() == 1 && (input[0] == '1' || input[0] == '2'|| input[0] == '3')) 
            break;
        std::cout << "Invalid input. Please try again.\n";  
    }
    if (input[0] == '3') {
        std::cout << "Okay. Will see you next time :O\n";
        gameCleaner();
        exit(0);
    } else if (input[0] == '1') {
        std::cout << "Hello newbie! Starting a new game now...\n";
        gameNewStart();
    } else {
        std::cout << "Reading game record now...\n";
        gameResume();
    }
}

void Game::gameNewStart() {

    std::string name;
    std::cout << ">> Hi there! Please enter your name:\n";
    std::cin >> name;

    std::cout << ">> Welcome here dear " << name << "! ";

    std::cout << "Please choose a character. Your choices are:" << std::endl
                << "    [1] Magician: Heal yourself and attack your enemies!" << std::endl
                << "    [2]  Warrior: Attack your enemies with double the intensity!" << std::endl;

    std::string input;
    bool valid = false;
    while (!valid) {
        std::cin >> input;
        if (input.length() == 1 && (input[0] == '1' || input[0] == '2'))
            valid = true;
        else
            std::cout << "Invalid input. Please try again.\n";   
    }

    if (input[0] == '1') {
        player = new Magician(name);
    } else if (input[0]== '2'){
        player = new Warrior(name);
    }

    int monster_lv[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::string monster_names[10] = {"Morry", "Machi", "Momo", "Micky", "Michael", "Mike", "Master", "Manny", "Muffin", "Magic"};    

    for (int i = 0 ; i < 10; i++) {
        
        monsters.push(new Monster(  50 * monster_lv[i], 
                                    25 * monster_lv[i], 
                                    monster_lv[i],
                                    5 * monster_lv[i], 
                                    monster_names[i]));
    
    }
    
    std::cout << "Let the game begun " << player->getCharacter() << " " << player->getName() << "!\n";
    
}

void Game::gameLoop() {

    std::string input;
    while (1) {

        std::cout << "\n=======================================================\n";
        
        player->printStatus();
        monsters.front()->printStatus();

        if (!player->chooseSkill(monsters.front())) {
            gameQuit();
            continue;
        }

        if (monsters.front()->isDead()) {
            
            std::cout << monsters.front()->getName() << " is Dead. Increase " << player->getName() << "'s LV.\n";
            player->increaseHP(monsters.front()->getMP());
            delete monsters.front();
            monsters.pop();
            player->increaseLV();

            
            if (player->getLV() >= 5) {
                /* Upgrade character */
                if (player->getCharacter() == "Warrior") {
                    player = new Knight(player->getName());
                    std::cout << "Fantastic! You are a Knight now " << player->getName() << ".\n";
                    std::cout << "Good luck on the rest of your journey Knight " << player->getName() << ".\n";
                }
                    
                else if (player->getCharacter() == "Magician") {
                    player = new Wizard(player->getName());
                    std::cout << "Fantastic! You are a Wizard now " << player->getName() << ".\n";
                    std::cout << "Good luck on the rest of your journey Wizard " << player->getName() << ".\n";
                }
                    
            }
        } 

        if (monsters.empty()) {
            std::cout << "Good on ya! There is no more monster left :D\n";
            return;
        }

        monsters.front()->monsterAttack(player);
        if (player->isDead()) {
            std::cout << "Oh no you are dead. Bad luck :(\n";
            return;
        }

        player->increaseMP(20);
        monsters.front()->increaseMP(5);
        
    }
}

void Game::gameEnd() {
        std::cout << "\n==============================================";
    if (player->isDead()) 
        std::cout << "\n=  You lose :( Good luck on your next play!  =";
    else 
        std::cout << "\n=         You win :D  Excellent job!         =";
        std::cout << "\n==============================================\n\n";
    gameCleaner();
}

void Game::gameQuit() {
    std::cout << ">> Are you sure you want to quit? (Y/N)\n";
    std::string input;
    while (1) {
        std::cin >> input;
        if (input.length() == 1 && (input[0] == 'Y' || input[0] == 'N')) 
            break;
        std::cout << "Invalid input. Please try again.\n";  
    }
    if (input[0] == 'N') {
        std::cout << "Glad you are not leaving " << player->getCharacter() << " " << player->getName() << " :)\n";
        return;
    }
    std::cout << ">> Do you want to save your current status? (Y/N)\n";
    while (1) {
        std::cin >> input;
        if (input.length() == 1 && (input[0] == 'Y' || input[0] == 'N')) 
            break;
        std::cout << "Invalid input. Please try again.\n";  
    }
    if (input[0] == 'N') {
        std::cout << "See you next time " << player->getCharacter() << " " << player->getName() << " :)\n";
        gameCleaner();
        exit(0);
    }
    std::ofstream game_file;
    game_file.open ("game_status.txt");
    game_file << player->getCharacter() << std::endl;
    game_file << player->getName() << std::endl;
    game_file << player->getHP() << std::endl;
    game_file << player->getMP() << std::endl;
    game_file << player->getLV() << std::endl;
    game_file << player->getStrength() << std::endl;
    game_file << monsters.size() << std::endl;
    while (!monsters.empty()) {
        game_file << monsters.front()->getName() << " "
                    << monsters.front()->getHP() << " "
                    << monsters.front()->getMP() << " "
                    << monsters.front()->getLV() << " "
                    << monsters.front()->getStrength() << "\n";
        monsters.pop();
    }
    game_file.close();
    std::cout << "Current status has been saved. ";
    std::cout << "See you next time " << player->getCharacter() << " " << player->getName() << " :)\n";
    gameCleaner();
    exit(0);
}

void Game::gameResume() {
    std::ifstream game_file;
    game_file.open ("game_status.txt");
    if (  !game_file.good() ) {
        std::cout << "Cannot find the game record. Please start a new game.\n";
        game_file.close();
        gameNewStart();
        return;
    }
    std::cout << "Successfully open your game record file. Recover your previous game status now...\n";
    std::string name, character;
    int HP, MP, LV, STR;
    try {
        game_file >> character >> name >> HP >> MP >> LV >> STR;
    } catch (std::exception &e) {
        std::cout << "Game record is corrupted. Please start a new game.\n";
        game_file.close();
        gameNewStart();
        return;
    }
    if (character == "Warrior") player = new Warrior(HP, MP, LV, STR, name, character);
    else if (character == "Wizard") player = new Wizard(HP, MP, LV, STR, name, character);
    else if (character == "Magician") player = new Magician(HP, MP, LV, STR, name, character);
    else if (character == "Knight") player = new Knight(HP, MP, LV, STR, name, character);
    else {
        std::cout << "Game record is corrupted. Please start a new game.\n";
        game_file.close();
        gameNewStart();
        return;
    }
    int n_monsters;
    game_file >> n_monsters;
    while (n_monsters--) {
        try {
            game_file >> name >> HP >> MP >> LV >> STR;
        } catch (std::exception &e) {
            std::cout << "Game record is corrupted. Please start a new game.\n";
            game_file.close();
            gameNewStart();
            return;
        }
        monsters.push(new Monster( HP, MP, LV, STR, name ));
    }
    std::cout << "Successfully resume your game record "<< player->getCharacter() << " " << player->getName() << ". Welcome back!\n"; 
}

void Game::gameCleaner() {
    delete player;
    while (!monsters.empty()) {
        delete monsters.front();
        monsters.pop();
    }
}