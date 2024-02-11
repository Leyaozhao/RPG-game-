#include "Knight.h"

void Knight::advancedAttack(Person *target) {
    if (Warrior::getMP() >= 100) {
        Warrior::decreaseMP(100);
        Warrior::increaseHP(target->getHP());
        target->decreaseHP(target->getHP());
    }
}

bool Knight::chooseSkill(Person *target) {
    while (1) {
        std::string input;
        bool valid = false;
        std::cout << ">> Please choose your skill " << getCharacter() << " " << getName() << ":\n";
        std::cout << "    * [1] Attack - - - - - - 50  MP\n";
        std::cout << "    * [2] Advanced Attack  - 100 MP\n";
        std::cout << "    * [3] Skip\n";
        
        while (!valid) {
            std::cin >> input;
            if (input == "Quit") return false;
            if (input.length() == 1 && (input[0] == '1' || input[0] == '2' || input[0] == '3'))
                valid = true;
            else
                std::cout << "Invalid input. Please try again.\n";
        }

        if (input[0] == '1') {
            if (getMP() < 50) {
                std::cout << "No sufficient MP. Current MP: " << getMP() << "\n";
            } else {
                attack(target);
                std::cout << getName() 
                        << " chose [1] Attack. Cost " 
                        << getStrength() << " damages on "
                        << target->getName() << "!\n";
                return true;
            }
        } else if (input[0] == '2') {
            if (getMP() < 100) {
                std::cout << "No sufficient MP. Current MP: " << getMP() << "\n";
            } else {
                advancedAttack(target);
                std::cout << getName() 
                        << " chose [2] Advanced Attack. Cost " 
                        << target->getHP() << " damages on "
                        << target->getName() << "!\n";
                return true;
            }
        } else if (input[0] == '3') {
            std::cout << getName() << " chose [3] Skip.\n";
            return true;
        }
    }
}