#include "Magician.h"
#include <iostream>
void Magician::heal() {
    if (getMP() >= 20) {
        decreaseMP(20);
        increaseHP(getStrength());
    } 
        
}
void Magician::attack(Person *target) {
    if (getMP() >= 50){
        decreaseMP(50);
        target->decreaseHP(getStrength());
    }
}

bool Magician::chooseSkill(Person *target) {
    while (1) {
        std::string input;
        bool valid = false;
        std::cout << ">> Please choose your skill " << getCharacter() << " " << getName() << ":\n";
        std::cout << "    * [1] Attack - - - - - 50  MP\n";
        std::cout<<  "    * [2] Heal - - - - - - 20  MP\n";
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
        }
        else if (input[0]== '2'){
            if (getMP() < 20){
                std::cout  << "No sufficient MP. Current MP: " << getMP() << "\n";
            }
            else{
                heal();
                std::cout << getName() 
                <<  " chose [2] Heal. Healed by " 
                << getStrength() << "HP!\n";
                return true;
            }
        }
        else if (input[0] == '3') {
            std::cout << getName() << " chose [3] Skip.\n";
            return true;
        }
    }
}

