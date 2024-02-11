#include "Person.h"
#include <iostream>

/* Initializer */
Person::Person(int hp, int mp, int maxHp, int maxMp, int lv, int s, std::string n, std::string c) : 
    HP(hp), MP(mp), maxHP(maxHp), maxMP(maxMp), LV(lv), strength(s), name(n), character(c) {}
Person::Person(int hp, int mp, int lv, int s, std::string n, std::string c) : 
    HP(hp), MP(mp), maxHP(hp), maxMP(mp), LV(lv), strength(s), name(n), character(c) {}


/* Getter */
int Person::getHP()                 { return HP; }
int Person::getMP()                 { return MP; }
int Person::getLV()                 { return LV; }
int Person::getStrength()           { return strength; }
std::string Person::getName()       { return name; }
std::string Person::getCharacter()  { return character; }


/* Modifier */
void Person::increaseHP(int amount) { HP = (HP + amount < maxHP)? HP + amount : maxHP; }
void Person::increaseMP(int amount) { MP = (MP + amount < maxMP)? MP + amount : maxMP; }
void Person::decreaseHP(int amount) { HP = (HP > amount)? HP - amount : 0; }
void Person::decreaseMP(int amount) { MP = (MP > amount)? MP - amount : 0; }
void Person::increaseLV()           { LV++; }

/* checker */
bool Person::isDead() {
    if (HP <= 0) return true;
    return false;
}

/* printer */
void Person::printStatus() {
    std::cout << ">> Current status of " << character << " " << name << ":\n";
    std::cout << "    * HP:    " << HP << "/" << maxHP << "\n";
    std::cout << "    * MP:    " << MP << "/" << maxMP << "\n";
    std::cout << "    * LV:    " << LV << "\n";
    std::cout << "    * STR:   " << strength << "\n";
}

