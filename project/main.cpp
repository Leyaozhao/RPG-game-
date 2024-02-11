/************************************************************************
 * OOP Group 12 Project - RPG
 * 
 * Character        HP      MP      STR     SKILLS (COST)
 *   Warrior       200     200      100     Attack (50)
 *    Knight       400     400      200     Attack (50), AdavancedAttack (100)
 *  Magician       100     100       50     Attack (50), Heal (20)
 *    Wizard       300     300      150     Attack (50), Heal (20), AdavancedHeal(100)
 *   Monster    Random  Random   Random     MonsterAttack (5)
*************************************************************************/


#include <iostream>
#include "Person.h"
#include "Warrior.h"
#include "Monster.h"
#include "Knight.h"
#include "Wizard.h"
#include "Magician.h"
#include "Game.h"
#include <queue>

int main() {
    
    Game game;
    
    game.gameStart();

    game.gameLoop();

    game.gameEnd();

}