#include "includes.h"
using namespace std;
short youWin = 0;
short monsterWin = 0;

void jabAttack(playerMenu& pOptions) {
    int dontMiss = (rand() % 5 + 5);
    int youMiss = (rand() % 5 + 5);
    pOptions.monsters.creatureDamageTaken = pOptions.createChar.pWeaponDamage - pOptions.monsters.creatureArmorTOTAL;
        if (dontMiss >= youMiss) {
            if (pOptions.monsters.creatureHealth <= youWin) {
                pOptions.monsters.creatureHealth = 0;
            }
            if (pOptions.monsters.creatureDamageTaken <= youWin) {
                pOptions.monsters.creatureDamageTaken = 0;
        }
            pOptions.monsters.creatureHealth -= pOptions.monsters.creatureDamageTaken;
            cout << "You jab at the " << pOptions.monsters.creatureName << " You deal " << pOptions.monsters.creatureDamageTaken << " total damage." << endl;
            cout << pOptions.monsters.creatureName << " - HEALTH: " << pOptions.monsters.creatureHealth << " / " << pOptions.monsters.creatureHPTOTAL << endl;
        }
        else {
            cout << "You Miss! " << pOptions.monsters.creatureName << " laughs at you..." << endl;
        }
}

void deathPrintInfo(playerMenu& pOptions) {
    pOptions.monsters.expReward = (pOptions.monsters.creatureLevel * 100);
    pOptions.monsters.soulsReward = (pOptions.monsters.creatureLevel * 1);
    if (pOptions.monsters.creatureHealth <= youWin) {
        pOptions.monsters.creatureHealth = 0;
        pOptions.createChar.pExpValCurrent += pOptions.monsters.expReward;
        pOptions.createChar.pMoney += pOptions.monsters.soulsReward;
        cout << "You win. " << pOptions.monsters.creatureHealth << endl;
        cout << "You have defeated: " << pOptions.monsters.creatureName << " - HEALTH: " << pOptions.monsters.creatureHealth << " / " << pOptions.monsters.creatureHPTOTAL << endl;
        cout << "You gain: " << pOptions.monsters.expReward << " Experience." << endl;
        cout << "You gain: " << pOptions.monsters.soulsReward << " souls." << endl;
        cout << "Character Experience: " << pOptions.createChar.pExpValCurrent << " / " << pOptions.createChar.pExpValNextLevel << endl;
        cout << "Character Souls: " << pOptions.createChar.pMoney << endl;
        levelUpCheck(pOptions);
        system("pause");
        gameMenu(pOptions);
    }
}

void pDeathPrintInfo(playerMenu& pOptions) {
    if (pOptions.createChar.pHealth <= monsterWin) {
        pOptions.createChar.pHealth = 0;
        cout << "You are DEAD. " << pOptions.createChar.pHealth << endl;
        cout << "You have been defeated: " << pOptions.createChar.playerName << " - HEALTH: " << pOptions.createChar.pHealth << " / " << pOptions.createChar.pHealthTOTAL << endl;
        //cout << "Character Experience: " << pOptions.expChar << " / " << pOptions.expCharTOTAL << endl;
        cout << "Character Souls: " << pOptions.createChar.pMoney << endl;
        system("pause");
        cout << pOptions.createChar.playerName << " has been taken to the medical tents to recover." << endl;
        pOptions.createChar.pHealth = 1;
        gameMenu(pOptions);
    }
}

void monsterJabAttack(playerMenu& pOptions) {
    int monsterHit = (rand() % 5 + 5);
    int monsterMiss = (rand() % 5 + 5);
    pOptions.combatStats.totalHealthDamage = pOptions.monsters.creatureWeaponAttack - pOptions.createChar.pArmorTOTAL;
    if (monsterHit >= monsterMiss) {
        if (pOptions.createChar.pHealth <= monsterWin) {
            pOptions.createChar.pHealth = 0;
        }
        if (pOptions.combatStats.totalHealthDamage <= monsterWin) {
            pOptions.combatStats.totalHealthDamage = 0;
        }
        pOptions.createChar.pHealth -= pOptions.combatStats.totalHealthDamage;
        cout << pOptions.monsters.creatureName << " jabs at " << pOptions.createChar.playerName << " dealing  " << pOptions.combatStats.totalHealthDamage << " total damage." << endl;
        cout << pOptions.createChar.playerName << " - HEALTH: " << pOptions.createChar.pHealth << " / " << pOptions.createChar.pHealthTOTAL << endl;
    }
    else {
        cout << pOptions.monsters.creatureName <<  " misses! " << pOptions.monsters.creatureName << " growls in frustration..." << endl;
    }
}