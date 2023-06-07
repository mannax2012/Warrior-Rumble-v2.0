#include "includes.h"
using namespace std;

void saveChar(playerMenu& pOptions) {

    string saveTitle = pOptions.createChar.playerName + ".txt";
    ofstream saveCharFile;
    saveCharFile.open(saveTitle);
    
    saveCharFile << "\t\t\t\t" << pOptions.createChar.playerName << ", " << pOptions.createChar.playerLevel << ", " << pOptions.createChar.pExpValCurrent << ", "
                                                   << pOptions.createChar.pExpValNextLevel << ", " << pOptions.createChar.pHealth << ", " << pOptions.createChar.pHealthTOTAL << ", "
                                                   << pOptions.createChar.pRage << ", " << pOptions.createChar.pRageTOTAL << ", " << pOptions.createChar.pStrength << ", "
                                                   << pOptions.createChar.pDexterity << ", " << pOptions.createChar.pStamina << ", " << pOptions.createChar.pArmorTOTAL << ", "
                                                   << pOptions.createChar.pWeaponDamage << ", " << pOptions.createChar.pMoney;
                                                 //<< ", " << weaponQuality << ", " << weaponChoice << ", " << helmQuality << ", " << armorQuality << ", " << sheildQuality
    saveCharFile.close();

    saveCharFile.seekp(0, std::ios::end); //to ensure the put pointer is at the end
    saveCharFile << "\t\t\t\t" << pOptions.createChar.playerName << ", " << pOptions.createChar.playerLevel << ", " << pOptions.createChar.pExpValCurrent << ", " 
                                                   << pOptions.createChar.pExpValNextLevel << ", " << pOptions.createChar.pHealth << ", " << pOptions.createChar.pHealthTOTAL << ", "
                                                   << pOptions.createChar.pRage << ", " << pOptions.createChar.pRageTOTAL << ", " << pOptions.createChar.pStrength << ", " 
                                                   << pOptions.createChar.pDexterity << ", " << pOptions.createChar.pStamina << ", " << pOptions.createChar.pArmorTOTAL << ", " 
                                                   << pOptions.createChar.pWeaponDamage << ", " << pOptions.createChar.pMoney;
                                                 //<< ", " << weaponQuality << ", " << weaponChoice << ", " << helmQuality << ", " << armorQuality << ", " << sheildQuality

    std::ofstream SaveCharFile(saveTitle);
    
    // Always check to see if the file is open and for errors.
    if (SaveCharFile.is_open())
    {

        std::cout << "SAVING... " << pOptions.createChar.playerName << " has saved the game." << endl;

        // do our writing to the file.
        SaveCharFile << pOptions.createChar.playerName << endl;
        SaveCharFile << pOptions.createChar.playerLevel << endl;
        SaveCharFile << pOptions.createChar.pExpValCurrent << endl;
        SaveCharFile << pOptions.createChar.pExpValNextLevel << endl;
        SaveCharFile << pOptions.createChar.pHealth << endl;
        SaveCharFile << pOptions.createChar.pHealthTOTAL << endl;
        SaveCharFile << pOptions.createChar.pRage << endl;
        SaveCharFile << pOptions.createChar.pRageTOTAL << endl;
        SaveCharFile << pOptions.createChar.pStrength << endl;
        SaveCharFile << pOptions.createChar.pDexterity << endl;
        SaveCharFile << pOptions.createChar.pStamina << endl;
        SaveCharFile << pOptions.createChar.pArmorTOTAL << endl;
        SaveCharFile << pOptions.createChar.pWeaponDamage << endl;
        SaveCharFile << pOptions.createChar.pMoney << endl;
        /*
        SaveCharFile << (int)weaponQuality << endl;
        SaveCharFile << (int)weaponChoice << endl;
        SaveCharFile << (int)helmQuality << endl;
        SaveCharFile << (int)armorQuality << endl;
        SaveCharFile << (int)sheildQuality << endl;
        */
    }
    else
    {
        // If the file isn't open something went wrong. Point that out.
        std::cout << "Something went wrong with opening the file!";
        system("pause");
        gameMenu(pOptions);
    }

    // After you are done with the file always close it.
    SaveCharFile.close();
    system("pause");
    gameMenu(pOptions);
}

playerMenu loadChar(playerMenu& pOptions) {

    cout << "Enter the name of the Character File: ";
    cin >> pOptions.createChar.playerName;
    string path = pOptions.saveLoad.name + ".txt";

    std::ifstream fin;

    fin.open(path);

    if (fin.is_open()) {
        system("pause");
        cout << "FILE LOADED" << endl;
        //createCharacter(pInfo);
        fin >> pOptions.createChar.playerName;
        fin >> pOptions.createChar.playerLevel;
        fin >> pOptions.createChar.pExpValCurrent;
        fin >> pOptions.createChar.pExpValNextLevel;
        fin >> pOptions.createChar.pHealth;
        fin >> pOptions.createChar.pHealthTOTAL;
        fin >> pOptions.createChar.pRage;
        fin >> pOptions.createChar.pRageTOTAL;
        fin >> pOptions.createChar.pStrength;
        fin >> pOptions.createChar.pDexterity;
        fin >> pOptions.createChar.pStamina;
        fin >> pOptions.createChar.pArmorTOTAL;
        fin >> pOptions.createChar.pWeaponDamage;
        fin >> pOptions.createChar.pMoney;

        // fin >> static_cast<int>(weaponChoice);
        // fin >> helmQuality;
        // fin >> armorQuality;
        // fin >> sheildQuality;
        fin.close();
    }
    else {
        cout << "File Load Failed!" << endl;
        system("pause");
        mainMenu(pOptions);
    }
    /*
    weaponQCheck(createChar);
    weaponTCheck(createChar);
    helmQCheck(createChar);
    armorQCheck(createChar);
    shieldQCheck(createChar);

    createChar.armorQBody = armorQualityType;
    createChar.armorQHelm = helmQualityType;
    createChar.armorQSheild = sheildQualityType;
    createChar.weaponT = weaponType;
    createChar.weaponQ = weaponQualityType;
    createChar.swordWeaponQ = swordQualityType;
    */
    printCharacterSheet(pOptions);
    return pOptions;
}

/*
void weaponTCheck(playerMenu& createChar) {
    switch (createChar.saveLoad.saveWeaponT) {
    case 3:
        weaponChoice = weapons::sword;
        weaponType = weaponChoiceF(weaponChoice);
        break;
    case 4:
        weaponChoice = weapons::axe;
        weaponType = weaponChoiceF(weaponChoice);
        break;
    case 5:
        weaponChoice = weapons::poleaxe;
        weaponType = weaponChoiceF(weaponChoice);
        break;
    default:
        weaponChoice = weapons::unarmed;
        weaponType = weaponChoiceF(weaponChoice);
        break;
    }
};
void weaponQCheck(playerMenu& createChar) {
    switch (createChar.saveLoad.saveWeaponQ) {
    case 1:
        weaponQuality = materials::Basic;
        weaponQualityType = weaponTypeF(weaponQuality);
        break;
    case 3:
        weaponQuality = materials::Oak;
        weaponQualityType = weaponTypeF(weaponQuality);
        break;
    case 4:
        weaponQuality = materials::Copper;
        weaponQualityType = weaponTypeF(weaponQuality);
        break;
    case 5:
        weaponQuality = materials::Bronze;
        weaponQualityType = weaponTypeF(weaponQuality);
        break;
    case 6:
        weaponQuality = materials::Iron;
        weaponQualityType = weaponTypeF(weaponQuality);
    case 7:
        weaponQuality = materials::Steel;
        weaponQualityType = weaponTypeF(weaponQuality);
        break;
    case 10:
        weaponQuality = materials::Mithril;
        weaponQualityType = weaponTypeF(weaponQuality);
        break;
    default:
        weaponQuality = materials::No;
        weaponQualityType = weaponTypeF(weaponQuality);
        break;
    }
};
void helmQCheck(playerMenu& createChar) {
    switch (createChar.saveLoad.saveHelmQ) {
    case 1:
        helmQuality = materials::Basic;
        helmQualityType = helmTypeF(helmQuality);
        break;
    case 3:
        helmQuality = materials::Oak;
        helmQualityType = helmTypeF(helmQuality);
        break;
    case 4:
        helmQuality = materials::Copper;
        helmQualityType = helmTypeF(helmQuality);
        break;
    case 5:
        helmQuality = materials::Bronze;
        helmQualityType = helmTypeF(helmQuality);
        break;
    case 6:
        helmQuality = materials::Iron;
        helmQualityType = helmTypeF(helmQuality);
        break;
    case 7:
        helmQuality = materials::Steel;
        helmQualityType = helmTypeF(helmQuality);
        break;
    case 10:
        helmQuality = materials::Mithril;
        helmQualityType = helmTypeF(helmQuality);
        break;
    default:
        helmQuality = materials::No;
        helmQualityType = helmTypeF(helmQuality);
        break;
    }

};
void armorQCheck(playerMenu& createChar) {
    switch (createChar.saveLoad.saveArmorQ) {
    case 1:
        armorQuality = materials::Basic;
        armorQualityType = armorTypeF(armorQuality);
        break;
    case 3:
        armorQuality = materials::Oak;
        armorQualityType = armorTypeF(armorQuality);
        break;
    case 4:
        armorQuality = materials::Copper;
        armorQualityType = armorTypeF(armorQuality);
        break;
    case 5:
        armorQuality = materials::Bronze;
        armorQualityType = armorTypeF(armorQuality);
        break;
    case 6:
        armorQuality = materials::Iron;
        armorQualityType = armorTypeF(armorQuality);
        break;
    case 7:
        armorQuality = materials::Steel;
        armorQualityType = armorTypeF(armorQuality);
        break;
    case 10:
        armorQuality = materials::Mithril;
        armorQualityType = armorTypeF(armorQuality);
        break;
    default:
        armorQuality = materials::No;
        armorQualityType = armorTypeF(armorQuality);
        break;
    }
};
void shieldQCheck(playerMenu& createChar) {
    switch (createChar.saveLoad.saveShieldQ) {
    case 1:
        sheildQuality = materials::Basic;
        sheildQualityType = sheildTypeF(sheildQuality);
        break;
    case 3:
        sheildQuality = materials::Oak;
        sheildQualityType = sheildTypeF(sheildQuality);
        break;
    case 4:
        sheildQuality = materials::Copper;
        sheildQualityType = sheildTypeF(sheildQuality);
        break;
    case 5:
        sheildQuality = materials::Bronze;
        sheildQualityType = sheildTypeF(sheildQuality);
        break;
    case 6:
        sheildQuality = materials::Iron;
        sheildQualityType = sheildTypeF(sheildQuality);
        break;
    case 7:
        sheildQuality = materials::Steel;
        sheildQualityType = sheildTypeF(sheildQuality);
        break;
    case 10:
        sheildQuality = materials::Mithril;
        sheildQualityType = sheildTypeF(sheildQuality);
        break;
    default:
        sheildQuality = materials::No;
        sheildQualityType = sheildTypeF(sheildQuality);
        break;
    }
};
*/