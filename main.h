#pragma once
#include "includes.h"
#include "monsters.h"
typedef struct playerMenu {
	inventory itemOptions;
	player createChar;
	combat combatStats;
	lvlUp lvlBonus;
	monsterStuff monsters;
	saveLoad saveLoad;
} playerMenu;