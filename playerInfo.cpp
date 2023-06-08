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
       // unEquipIt(pOptions);
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
	cin >> playerName;
	cout << "You have just taken your first steps to becoming a great Warrior. \n" << playerName << "! Welcome to the Warrior RUMBLE!!" << endl;
    system("pause");
    playerMenu pInfo = createCharacter(playerName);
	printCharacterSheet(pInfo);
}

playerMenu playerInventory(playerMenu& pOptions){
    inventoryData(pOptions);
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
    
    std::array<bool, 10> inventory = { false, false, false, false, false, false, false, false, false, false };
    //inventory[0] = true;
    for (int i = 0; i < 10; i++) {
        if (inventory[i]) {
            std::cout << "slot " << i << " is occupied" << std::endl;
        }
    }
    if (inventory[0] == false) {
        pOptions.itemOptions.itemName01 = "Empty";
    }
    else {
        pOptions.itemOptions.itemName01 = "Occupied";
    }
    if (inventory[1] == false) {
        pOptions.itemOptions.itemName02 = "Empty";
    }
    else if (inventory[1] == true && inventory[0] == true){
        pOptions.itemOptions.itemName02 = "Occupied";
    }
    if (inventory[2] == false && inventory[1] == true && inventory[0] == true) {
        pOptions.itemOptions.itemName03 = "Empty";
    }
    else {
        pOptions.itemOptions.itemName03 = "Occupied";
    }
    if (inventory[3] == false && inventory[2] == true && inventory[1] == true && inventory[0] == true) {
        pOptions.itemOptions.itemName04 = "Empty";
    }
    else {
        pOptions.itemOptions.itemName04 = "Occupied";
    }
    if (inventory[4] == false && inventory[3] == true && inventory[2] == true && inventory[1] == true && inventory[0] == true) {
        pOptions.itemOptions.itemName05 = "Empty";
    }
    else {
        pOptions.itemOptions.itemName05 = "Occupied.";
    }
    if (inventory[5] == false && inventory[4] == true && inventory[3] == true && inventory[2] == true && inventory[1] == true && inventory[0] == true) {
        pOptions.itemOptions.itemName06 = "Empty";
    }
    else {
        pOptions.itemOptions.itemName06 = "Occupied";
    }
    if (inventory[6] == false && inventory[5] == true && inventory[4] == true && inventory[3] == true && inventory[2] == true && inventory[1] == true && inventory[0] == true) {
        pOptions.itemOptions.itemName07 = "Empty";
    }
    else {
        pOptions.itemOptions.itemName07 = "Occupied";
    }
    if (inventory[7] == false && inventory[6] == true && inventory[5] == true && inventory[4] == true && inventory[3] == true && inventory[2] == true && inventory[1] == true && inventory[0] == true) {
        pOptions.itemOptions.itemName08 = "Empty";
    }
    else {
        pOptions.itemOptions.itemName08 = "Occupied";
    }   
    if (inventory[8] == false && inventory[7] == true && inventory[6] == true && inventory[5] == true && inventory[4] == true && inventory[3] == true && inventory[2] == true && inventory[1] == true && inventory[0] == true) {
        pOptions.itemOptions.itemName09 = "Empty";
    }
    else {
        pOptions.itemOptions.itemName09 = "Occupied";
    }
    if (inventory[9] == false && inventory[8] == true && inventory[7] == true && inventory[6] == true && inventory[5] == true && inventory[4] == true && inventory[3] == true && inventory[2] == true && inventory[1] == true && inventory[0] == true) {
        pOptions.itemOptions.itemName10 = "Empty";
    }
    else {
        pOptions.itemOptions.itemName10 = "Occupied";
    }
    return pOptions;
} 
