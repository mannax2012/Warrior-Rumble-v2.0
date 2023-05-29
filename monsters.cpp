#include "includes.h"
using namespace std;

void skeletonEasy(playerMenu& pOptions) {
    pOptions.monsters.menuTitle = "|                    CHALLENGE - EASY                      |";
   // pOptions.monsters.attackList = pOptions.combatStats.jabAttack;
    pOptions.monsters.creatureName = "Skeleton of Kano";
    pOptions.monsters.creatureLevel = (rand() % 2 + 3);
    pOptions.monsters.creatureStrength = (rand() % 5 + 5) + pOptions.monsters.creatureLevel;
    pOptions.monsters.creatureStamina = (rand() % 5 + 5) + pOptions.monsters.creatureLevel;
    pOptions.monsters.creatureHPTOTAL = (2 * pOptions.monsters.creatureStamina) + (pOptions.monsters.creatureLevel * 10);
    pOptions.monsters.creatureHealth = pOptions.monsters.creatureHPTOTAL;
    pOptions.monsters.creatureWeaponAttack = (2 + pOptions.monsters.creatureStrength);
    pOptions.monsters.creatureArmorTOTAL = 3 + (rand() % 5 + 5);
    pOptions.monsters.creatureTotalDamage = 0;
} 

void warriorMedium(playerMenu& pOptions) {
    pOptions.monsters.menuTitle = "|                    CHALLENGE - MEDIUM                    |";
   // pOptions.monsters.attackList = pOptions.combatStats.jabAttack;
    pOptions.monsters.creatureName = "Parjii";
    pOptions.monsters.creatureLevel = 2 + (rand() % 3 + 3);
    pOptions.monsters.creatureStrength = (rand() % 5 + 5) + pOptions.monsters.creatureLevel;
    pOptions.monsters.creatureStamina = (rand() % 5 + 5) + pOptions.monsters.creatureLevel;
    pOptions.monsters.creatureHPTOTAL = (2 * pOptions.monsters.creatureStamina) + (pOptions.monsters.creatureLevel * 10);
    pOptions.monsters.creatureHealth = pOptions.monsters.creatureHPTOTAL;
    pOptions.monsters.creatureWeaponAttack = (2 + pOptions.monsters.creatureStrength);
    pOptions.monsters.creatureArmorTOTAL = 5 + (rand() % 5 + 5);
    pOptions.monsters.creatureTotalDamage = 0;
}

void warriorHard(playerMenu& pOptions) {
    pOptions.monsters.menuTitle = "|                    CHALLENGE - HARD                      |";
   // pOptions.monsters.attackList = pOptions.combatStats.jabAttack;
    pOptions.monsters.creatureName = "Bannon";
    pOptions.monsters.creatureLevel = 3 + (rand() % 3 + 3);
    pOptions.monsters.creatureStrength = (rand() % 5 + 5) + pOptions.monsters.creatureLevel;
    pOptions.monsters.creatureStamina = (rand() % 5 + 5) + pOptions.monsters.creatureLevel;
    pOptions.monsters.creatureHPTOTAL = (2 * pOptions.monsters.creatureStamina) + (pOptions.monsters.creatureLevel * 10);
    pOptions.monsters.creatureHealth = pOptions.monsters.creatureHPTOTAL;
    pOptions.monsters.creatureWeaponAttack = (2 + pOptions.monsters.creatureStrength);
    pOptions.monsters.creatureArmorTOTAL = 5 + (rand() % 5 + 5);
    pOptions.monsters.creatureTotalDamage = 0;
}

void warriorExpert(playerMenu& pOptions) {
    pOptions.monsters.menuTitle = "|                   CHALLENGE - EXPERT                     |";
   // pOptions.monsters.attackList = pOptions.combatStats.jabAttack + ", " + pOptions.combatStats.slashAttack;
    pOptions.monsters.creatureName = "Cigep";
    pOptions.monsters.creatureLevel = 4 + (rand() % 5 + 3);
    pOptions.monsters.creatureStrength = (rand() % 5 + 5) + pOptions.monsters.creatureLevel;
    pOptions.monsters.creatureStamina = (rand() % 5 + 5) + pOptions.monsters.creatureLevel;
    pOptions.monsters.creatureHPTOTAL = (2 * pOptions.monsters.creatureStamina) + (pOptions.monsters.creatureLevel * 10);
    pOptions.monsters.creatureHealth = pOptions.monsters.creatureHPTOTAL;
    pOptions.monsters.creatureWeaponAttack = (2 + pOptions.monsters.creatureStrength);
    pOptions.monsters.creatureArmorTOTAL = 5 + (rand() % 5 + 5);
    pOptions.monsters.creatureTotalDamage = 0;
}

void warriorMaster(playerMenu& pOptions) {
    pOptions.monsters.menuTitle = "|                  CHALLENGE - MASTERFUL                   |";
    //pOptions.monsters.attackList = pOptions.combatStats.jabAttack;
    pOptions.monsters.creatureName = "Daukon the Drunken Master";
    pOptions.monsters.creatureLevel = 5 + (rand() % 5 + 3);
    pOptions.monsters.creatureStrength = (rand() % 5 + 5) + pOptions.monsters.creatureLevel;
    pOptions.monsters.creatureStamina = (rand() % 5 + 5) + pOptions.monsters.creatureLevel;
    pOptions.monsters.creatureHPTOTAL = (2 * pOptions.monsters.creatureStamina) + (pOptions.monsters.creatureLevel * 10);
    pOptions.monsters.creatureHealth = pOptions.monsters.creatureHPTOTAL;
    pOptions.monsters.creatureWeaponAttack = (2 + pOptions.monsters.creatureStrength);
    pOptions.monsters.creatureArmorTOTAL = 5 + (rand() % 5 + 5);
    pOptions.monsters.creatureTotalDamage = 0;
}

void warriorLegendary(playerMenu& pOptions) {
    pOptions.monsters.menuTitle = "|                  CHALLENGE - LEGENDARY                   |";
    //pOptions.monsters.attackList = pOptions.combatStats.jabAttack;
    pOptions.monsters.creatureName = "Somatical";
    pOptions.monsters.creatureLevel = 6 + (rand() % 5 + 5);
    pOptions.monsters.creatureStrength = (rand() % 5 + 5) + pOptions.monsters.creatureLevel;
    pOptions.monsters.creatureStamina = (rand() % 5 + 5) + pOptions.monsters.creatureLevel;
    pOptions.monsters.creatureHPTOTAL = (2 * pOptions.monsters.creatureStamina) + (pOptions.monsters.creatureLevel * 10);
    pOptions.monsters.creatureHealth = pOptions.monsters.creatureHPTOTAL;
    pOptions.monsters.creatureWeaponAttack = (2 + pOptions.monsters.creatureStrength);
    pOptions.monsters.creatureArmorTOTAL = 5 + (rand() % 5 + 5);
    pOptions.monsters.creatureTotalDamage = 0;
}
