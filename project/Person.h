#ifndef _PERSON_
#define _PERSON_

#include <string>

class Person {
public:
	Person(int hp, int mp, int maxHp, int maxMp, int lv, int s, std::string n, std::string c);
	Person(int hp, int mp, int lv, int s, std::string n, std::string c);
	virtual bool chooseSkill(Person *target) = 0; // abstract method interface for a derived class to implement the concrete useSkill() 
	virtual ~Person(){}
	void printStatus(); // print the current state to standard output
	bool isDead(); // check if the character is dead or not i.e. HP <= 0
	int getHP();
	int getMP();
	int getLV();
	int getStrength();
	std::string getName();
	std::string getCharacter();
	void increaseHP(int amount);
	void increaseMP(int amount);
	void decreaseMP(int amount);
	void decreaseHP(int amount);
	void increaseLV();

private:
	int HP;  // Health Points, being attacked will decrease the HP and being healed will increase the HP
	int MP;  // Magic Points,  using strategy will decrease the MP. MP will increase by 5 each round
	int maxHP;
	int maxMP;
	int LV; // Level, killing one monster will increase the LV.  
	int strength; // When using attacking strategy, one character can decrease another one's HP by a certain amount.
	std::string name; // Player's name.
	std::string character;
};

#endif
