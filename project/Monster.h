#ifndef _MONSTER_
#define _MONSTER_

#include "Person.h"
#include <iostream>

class Monster : public Person {
public:
    Monster(int hp, int mp, int lv, int str, std::string name) : Person(hp, mp, lv*50, lv*25, lv, str, name, "Monster") {}
	~Monster() {}
	void monsterAttack(Person *target);
	bool chooseSkill(Person *target) { return true; }
};

#endif