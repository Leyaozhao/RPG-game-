#include "Monster.h"

void Monster::monsterAttack (Person *target) {

    if (getMP() >= getStrength()) {
        std::cout << "Monster " << getName() << " attacks " << target->getName() << ". "
                << "Causes " << getStrength() << " damage on " << target->getName() << ".\n";
        target->decreaseHP(getStrength());
        decreaseMP(getStrength());
    }   else {
        std::cout << "Oh no there is no sufficient HP for Monster " << getName() << " :(\n";
        std::cout << "You are lucky " << target->getName() << "!\n";
    }
    
}