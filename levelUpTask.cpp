#include "includes.h"
using namespace std;

void levelUpCheck(playerMenu& pOptions) {
    if (pOptions.createChar.pExpValCurrent >= pOptions.createChar.pExpValNextLevel) {
        pOptions.createChar.pExpValCurrent = 0;
        levelUpTask(pOptions);
    }
}

void levelUpTask(playerMenu& pOptions){

    pOptions.createChar.playerLevel += pOptions.lvlBonus.level;
    pOptions.lvlBonus.health = (rand() % 10 + pOptions.createChar.playerLevel);
    pOptions.lvlBonus.stamina = (rand() % 3 + 3);
    pOptions.lvlBonus.strength = (rand() % 3 + 3);
    pOptions.lvlBonus.dexterity = (rand() % 3 + 3);
    pOptions.createChar.pHealth += pOptions.lvlBonus.health + pOptions.lvlBonus.stamina;
    pOptions.createChar.pStamina += pOptions.lvlBonus.stamina;
    pOptions.createChar.pStrength += pOptions.lvlBonus.strength;
    pOptions.createChar.pDexterity += pOptions.lvlBonus.dexterity;
    pOptions.createChar.pWeaponDamage += pOptions.createChar.pStrength;
    pOptions.createChar.pHealthTOTAL += pOptions.lvlBonus.health + pOptions.lvlBonus.stamina;
    pOptions.createChar.pExpValNextLevel += 1000 * (rand() % 2 + pOptions.createChar.playerLevel);
    pOptions.createChar.pArmorTOTAL += pOptions.lvlBonus.stamina;
    //system("cls");
    cout << "You have gained a level!!" << endl;
    cout << "Character Level: " << pOptions.createChar.playerLevel << endl;
    cout << "Experience: " << pOptions.createChar.pExpValCurrent << " / " << pOptions.createChar.pExpValNextLevel << endl;
    cout << "You have gained: " << endl;
    cout << "Health: " << pOptions.lvlBonus.health + pOptions.lvlBonus.stamina << endl;
    cout << "Stamina: " << pOptions.lvlBonus.stamina << endl;
    cout << "Strength: " << pOptions.lvlBonus.strength << endl;
    cout << "Dexterity: " << pOptions.lvlBonus.dexterity << endl;
    system("pause");
   // printInfo(pOptions);
}