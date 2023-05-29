#include "includes.h"
string characterName;
using namespace std;
//good
playerMenu createCharacter(string characterName) {

	playerMenu pOptions;
	pOptions.createChar.playerName = characterName;
    pOptions.createChar.playerLevel = 1;
	pOptions.createChar.pRage = 0;
    pOptions.createChar.pRageTOTAL = 100;
	pOptions.createChar.pStamina = (rand() % 5 + 5);
	pOptions.createChar.pDexterity = (rand() % 5 + 5);
	pOptions.createChar.pStrength = (rand() % 5 + 5);
    pOptions.createChar.pHealthTOTAL = 10 + (pOptions.createChar.pStamina * 2);
    pOptions.createChar.pHealth = pOptions.createChar.pHealthTOTAL;
    pOptions.createChar.pMoney = 0;
    pOptions.createChar.pExpValCurrent = 0;
    pOptions.createChar.pExpValNextLevel = (pOptions.createChar.playerLevel * 1000);
    pOptions.createChar.pWeaponDamage = 40;
    pOptions.createChar.pArmorTOTAL = 40;
	return pOptions;
};

playerMenu printCharacterSheet(playerMenu& pOptions) {
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
    //cout << "|     WEAPON:     |           " << pOptions.createChar.weaponQ << " " << pOptions.createChar.weaponT << endl;
   // cout << "|     HELMET:     |           " << pOptions.createChar.armorQHelm << " " << "Helmet" << endl;
   // cout << "|     BODY ARMOR: |           " << pOptions.createChar.armorQBody << " " << "Body Amor" << endl;
    //cout << "|     SHEILD:     |           " << pOptions.createChar.armorQSheild << " " << "Sheild" << endl;
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
        playerInventory(pOptions);
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
	cin >> characterName;
	cout << "You have just taken your first steps to becoming a great Warrior. " << characterName << "! Welcome to the Warrior RUMBLE!!" << endl;
    system("pause");
	playerMenu pInfo = createCharacter(characterName);
	printCharacterSheet(pInfo);
}

playerMenu playerInventory(playerMenu& pOptions){
    system("cls");
    cout << "|==========================================================|" << endl;
    cout << "|                   CHARACTER INVENTORY                    |" << endl;
    cout << "|==========================================================|" << endl;
    cout << "|SLOT  # | ITEM NAME | ARMORS | ATTACK RATING | SELL VALUE |" << endl;
    cout << "|==========================================================|" << endl;
    cout << "|SLOT 1: |" << pOptions.itemOptions.itemName01 << " | " << pOptions.itemOptions.itemArmorVal01 << " | " << pOptions.itemOptions.itemDamageVal01 << " | " << pOptions.itemOptions.itemSellVal01 << endl;
    cout << "|SLOT 2: |" << pOptions.itemOptions.itemName02 << " | " << pOptions.itemOptions.itemArmorVal01 << " | " << pOptions.itemOptions.itemDamageVal01 << " | " << pOptions.itemOptions.itemSellVal01 << endl;
    cout << "|SLOT 3: |" << pOptions.itemOptions.itemName03 << " | " << pOptions.itemOptions.itemArmorVal01 << " | " << pOptions.itemOptions.itemDamageVal01 << " | " << pOptions.itemOptions.itemSellVal01 << endl;
    cout << "|SLOT 4: |" << pOptions.itemOptions.itemName04 << " | " << pOptions.itemOptions.itemArmorVal01 << " | " << pOptions.itemOptions.itemDamageVal01 << " | " << pOptions.itemOptions.itemSellVal01 << endl;
    cout << "|SLOT 5: |" << pOptions.itemOptions.itemName05 << " | " << pOptions.itemOptions.itemArmorVal01 << " | " << pOptions.itemOptions.itemDamageVal01 << " | " << pOptions.itemOptions.itemSellVal01 << endl;
    cout << "|SLOT 6: |" << pOptions.itemOptions.itemName06 << " | " << pOptions.itemOptions.itemArmorVal01 << " | " << pOptions.itemOptions.itemDamageVal01 << " | " << pOptions.itemOptions.itemSellVal01 << endl;
    cout << "|SLOT 7: |" << pOptions.itemOptions.itemName07 << " | " << pOptions.itemOptions.itemArmorVal01 << " | " << pOptions.itemOptions.itemDamageVal01 << " | " << pOptions.itemOptions.itemSellVal01 << endl;
    cout << "|SLOT 8: |" << pOptions.itemOptions.itemName08 << " | " << pOptions.itemOptions.itemArmorVal01 << " | " << pOptions.itemOptions.itemDamageVal01 << " | " << pOptions.itemOptions.itemSellVal01 << endl;
    cout << "|SLOT 9: |" << pOptions.itemOptions.itemName09 << " | " << pOptions.itemOptions.itemArmorVal01 << " | " << pOptions.itemOptions.itemDamageVal01 << " | " << pOptions.itemOptions.itemSellVal01 << endl;
    cout << "|SLOT 10:|" << pOptions.itemOptions.itemName10 << " | " << pOptions.itemOptions.itemArmorVal01 << " | " << pOptions.itemOptions.itemDamageVal01 << " | " << pOptions.itemOptions.itemSellVal01 << endl;
    cout << "|==========================================================|" << endl;
    system("pause");
    printCharacterSheet(pOptions);
    return pOptions;
}

playerMenu inventoryData(playerMenu& pOptions) {

    return pOptions;
}