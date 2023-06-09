#pragma once
#include "monsters.h"

typedef struct playerMenu {

	player createChar;
	combat combatStats;
	lvlUp lvlBonus;
	monsterStuff monsters;
	saveLoad saveLoad;
} playerMenu;