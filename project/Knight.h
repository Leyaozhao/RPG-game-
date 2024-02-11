#ifndef _KNIGHT_
#define _KNIGHT_

#include "Warrior.h"
#include <iostream>
#include <string>

class Knight : public Warrior {
public:
    Knight(std::string name) : Warrior(400, 400, 5, 200, name, "Knight") {};
    Knight(int hp, int mp, int lv, int s, std::string name, std::string c) : Warrior(hp, mp, 400, 400, lv, s, name, c) {}
    ~Knight() {}
    void advancedAttack(Person *target);
    bool chooseSkill(Person *target);
};

#endif