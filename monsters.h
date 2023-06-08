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

class Monsters {
public:
    string creatureName;
    int creatureHealth,
        creatureLevel,
        creatureStrength,
        creatureStamina,
        creatureDexterity,
        creatureArmorTOTAL,
        creatureWeaponAttack;


    Monsters(const string& cName, int cHealth, int cLvL, int cStr, int cStam, int cDex, int cArmor, int cAP) : 
        creatureName(cName), creatureHealth(cHealth), creatureLevel(cLvL), creatureStrength(cStr), creatureStamina(cStam), 
        creatureDexterity(cDex), creatureArmorTOTAL(cArmor), creatureWeaponAttack(cAP) {}
};