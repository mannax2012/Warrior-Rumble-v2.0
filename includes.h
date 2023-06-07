#pragma once
#ifndef WARRIOR_RUMBLE_INCLUDES_H
#define WARRIOR_RUMBLE_INCLUDES_H
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <array>
#define NOMINMAX
#include <windows.h>
#undef NOMINMAX
#include <tchar.h>
#include <strsafe.h>
#include <map>
#include <limits>
#include "playerInfo.h"
#include "main.h"
#include "items.h"

playerMenu createCharacter(string playerName);
playerMenu inventoryData(playerMenu& pOptions);
void mainMenu(playerMenu& pOptions);
void gameMenu(playerMenu& pOptions);
void saveChar(playerMenu& pOptions);
playerMenu loadChar(playerMenu& pOptions);
void startNewChar(playerMenu& pOptions);
playerMenu printCharacterSheet(playerMenu& pOptions);
playerMenu playerInventory(playerMenu& pOptions);
void levelUpCheck(playerMenu& pOptions);
void levelUpTask(playerMenu& pOptions);

//challenge menu
void challengeMenu(playerMenu& pOptions);
void skeletonEasy(playerMenu& pOptions);
void jabAttack(playerMenu& pOptions);
void deathPrintInfo(playerMenu& pOptions);
void monsterJabAttack(playerMenu& pOptions);
void pDeathPrintInfo(playerMenu& pOptions);
void challengeMenuFIGHT(playerMenu& pOptions);
void warriorMedium(playerMenu& pOptions);
void warriorHard(playerMenu& pOptions);
void warriorExpert(playerMenu& pOptions);
void warriorMaster(playerMenu& pOptions);
void warriorLegendary(playerMenu& pOptions);

//Rumble Shop
void shopMenu(playerMenu& pOptions);
void shopMenuWeapons(playerMenu& pOptions);
void shopMenuSwords(playerMenu& pOptions);
void weaponList(playerMenu& pOptions);
#endif //WARRIOR_RUMBLE_INCLUDES_H