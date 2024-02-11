#ifndef _MAGICIAN_
#define _MAGICIAN_

#include <string>
#include "Person.h"


class Magician : public Person {
public:  
    // Magician(): Person(100, 100, 1, 50, "Player", "Magician") {};
    Magician(std::string name) : Person(100, 100, 100, 100, 1, 50, name, "Magician") {};
    Magician(int hp, int mp, int lv, int s, std::string name, std::string c) : Person(hp, mp, lv, s, name, c) {}
    Magician(int hp, int mp, int maxHp, int maxMp, int lv, int s, std::string name, std::string c) : Person(hp, mp, maxHp, maxMp, lv, s, name, c) {}
    ~Magician() {}
    void heal();
    void attack(Person *target);
    bool chooseSkill(Person *target);
};

#endif