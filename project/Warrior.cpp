#include "Warrior.h"
#include <iostream>
#include <string>

void Warrior::attack(Person *target) {
    decreaseMP(50);
    target->decreaseHP(getStrength());
}

bool Warrior::chooseSkill(Person *target) {
    while (1) {
        std::string input;
        bool valid = false;
        std::cout << ">> Please choose your skill " << getCharacter() << " " << getName() << ":\n";
        std::cout << "    * [1] Attack - - - - - 50  MP\n";
        std::cout << "    * [2] Skip\n";
        while (!valid) {
            std::cin >> input;
            if (input == "Quit") return false;
            if (input.length() == 1 && (input[0] == '1' || input[0] == '2'))
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
                        << " choose [1] Attack. Cost " 
                        << getStrength() << " damages on "
                        << target->getName() << "!\n";
                return true;
            }
        } else if (input[0] == '2') {
            std::cout << getName() << " choose [2] Skip.\n";
            return true;
        }
    }
}