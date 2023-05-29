#pragma once
using namespace std;

typedef struct monsterStuff {

    string creatureName,
        attackList,
        menuTitle;

    int creatureHealth,
        creatureLevel = 1,
        creatureStrength,
        creatureStamina,
        creatureHPTOTAL,
        creatureTotalDamage = 0,
        creatureDamageTaken,
        creatureArmorTOTAL = 5,
        creatureWeaponAttack,
        expReward,
        soulsReward;
}monsterStuff;
