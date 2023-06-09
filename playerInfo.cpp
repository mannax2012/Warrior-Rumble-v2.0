#include "includes.h"
#include "items.h"
using namespace std;
string playerName;

playerMenu createCharacter(string playerName) {

    playerMenu pOptions;
    pOptions.createChar.playerName = playerName;
    pOptions.createChar.playerLevel = 1;
	pOptions.createChar.pRage = 0;
    pOptions.createChar.pRageTOTAL = 100;
	pOptions.createChar.pStamina = (rand() % 5 + 5);
	pOptions.createChar.pDexterity = (rand() % 5 + 5);
	pOptions.createChar.pStrength = (rand() % 5 + 5);
    pOptions.createChar.pHealthTOTAL = 10 + (pOptions.createChar.pStamina * 2);
    pOptions.createChar.pHealth = pOptions.createChar.pHealthTOTAL;
    pOptions.createChar.pMoney = 100;
    pOptions.createChar.pExpValCurrent = 0;
    pOptions.createChar.pExpValNextLevel = (pOptions.createChar.playerLevel * 1000);
    pOptions.createChar.pWeaponDamage = pOptions.createChar.pStrength * 2;
    pOptions.createChar.pArmorTOTAL = 0;
	return pOptions;
};

playerMenu printCharacterSheet(playerMenu& pOptions) {
    Inventory inventory;
    int menuOptionChoice;
    system("cls");
    cout << "|==========================================================|" << endl;
    cout << "|                     CHARACTER SHEET                      |" << endl;
    cout << "|==========================================================|" << endl;
    cout << "|     NAME:       |           " << pOptions.createChar.playerName << endl;
    cout << "|     LEVEL:      |           " << pOptions.createChar.playerLevel << endl;
    cout << "|     EXPERIENCE: |           " << pOptions.createChar.pExpValCurrent << " / " << pOptions.createChar.pExpValNextLevel << endl;
    cout << "|     HEALTH:     |           " << pOptions.createChar.pHealth << " / " << pOptions.createChar.pHealthTOTAL << endl;
    cout << "|     RAGE:       |           " << pOptions.createChar.pRage << " / " << pOptions.createChar.pRageTOTAL << endl;
    cout << "|     STRENGTH:   |           " << pOptions.createChar.pStrength << endl;
    cout << "|     DEXTERITY:  |           " << pOptions.createChar.pDexterity << endl;
    cout << "|     STAMINA:    |           " << pOptions.createChar.pStamina << endl;
    cout << "|     ARMOR:      |           " << pOptions.createChar.pArmorTOTAL << endl;
    cout << "|     ATTACK:     |           " << pOptions.createChar.pWeaponDamage << endl;
    cout << "|     GOLD:       |           " << pOptions.createChar.pMoney << endl;
    cout << "|     WEAPON:     |           " << pOptions.createChar.weaponT << endl;
    cout << "|     HELMET:     |           " << pOptions.createChar.armorQhelm << endl;
    cout << "|     BODY ARMOR: |           " << pOptions.createChar.armorQbody << endl;
    cout << "|     SHEILD:     |           " << pOptions.createChar.armorQshield << endl;
    cout << "|==========================================================|" << endl;
    cout << "|           (1) INVENTORY   -   (2) MAIN MENU              |" << endl;
    cout << "|==========================================================|" << endl;
    cout << "Choose a Menu Option: ";
    cin >> menuOptionChoice;
    if ((cin.fail())) {
        cout << pError << endl;
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("pause");
        printCharacterSheet(pOptions);
    }
    switch (menuOptionChoice) {
    case 1:
        inventory.displayInventory();
        printCharacterSheet(pOptions);
        break;
    case 2:
        gameMenu(pOptions);
        break;
    default:
        printCharacterSheet(pOptions);
        break;
    }
	return pOptions;
}


void startNewChar(playerMenu& pOptions) {

	system("cls");
	cout << "|==========================================================|" << endl;
	cout << "|               WELCOME TO WARRIOR RUMBLE v1.0             |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "| Enter a Name for your NEW WARRIOR: ";
	cin >> playerName;
	cout << "You have just taken your first steps to becoming a great Warrior. \n" << playerName << "! Welcome to the Warrior RUMBLE!!" << endl;
    system("pause");
    playerMenu pInfo = createCharacter(playerName);
	printCharacterSheet(pInfo);
}