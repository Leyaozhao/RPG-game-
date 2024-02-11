#ifndef _WARRIOR_
#define _WARRIOR_

#include "Person.h"
#include <string>

class Warrior : public Person {
public:
	Warrior(int hp, int mp, int lv, int s, std::string name, std::string c) : Person(hp, mp,  lv, s, name, c) {}
	Warrior(int hp, int mp, int maxHp, int maxMp, int lv, int s, std::string name, std::string c) : Person(hp, mp, maxHp, maxMp, lv, s, name, c) {}
	
	// Warrior() : Person(200, 200, 1, 100, "Player", "Warrior") {}
	Warrior(std::string name) : Person(200, 200, 1, 100, name, "Warrior") {}
	void attack(Person *target);
	bool chooseSkill(Person *target);
	~Warrior() {}
};


#endif