#ifndef _WIZARD_
#define _WIZARD_


#include "Magician.h"

class Wizard : public Magician {
public:
    Wizard(std::string name) : Magician(300, 300, 5, 150, name, "Wizard") {};
    Wizard(int hp, int mp, int lv, int s, std::string name, std::string c) : Magician(hp, mp, 300, 300, lv, s, name, c) {}
    void advancedHeal(Person *target);
    bool chooseSkill(Person *target);
    ~Wizard() {}
};

#endif