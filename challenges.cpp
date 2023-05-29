#include "includes.h"
using namespace std;
short pMenu[7] = { 1,2,3,4,5,6,7 };

void challengeMenu(playerMenu& pOptions) {
	system("cls");
	int menuChoice;
	cout << "|==========================================================|" << endl;
	cout << "|                      CHALLENGE MENU                      |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|            |         -------------         |    REWARD   |" << endl;
	cout << "|      1     |          EASY - 100 EXP       |   1 SOUL    |" << endl;
	cout << "|      2     |        MEDIUM - 250 EXP       |  10 SOULS   |" << endl;
	cout << "|      3     |          HARD - 500 EXP       |  25 SOULS   |" << endl;
	cout << "|      4     |        EXPERT - 1000 EXP      |  50 SOULS   |" << endl;
	cout << "|      5     |     MASTERFUL - 2500 EXP      |  100 SOULS  |" << endl;
	cout << "|      6     |     LEGENDARY - 5000 EXP      |  250 SOULS  |" << endl;
	cout << "|      7     |           MAIN MENU           |             |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "Choose a difficulty level: ";
	cin >> menuChoice;

	if ((cin.fail())) {
		cout << pError << endl;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		challengeMenu(pOptions);
	}

	bool pExists = std::find(std::begin(pMenu), std::end(pMenu), menuChoice) != std::end(pMenu);
	if (pExists) {
		switch (menuChoice) {
		case 1:
			skeletonEasy(pOptions);
			challengeMenuFIGHT(pOptions);
			break;
		case 2:
			warriorMedium(pOptions);
			challengeMenuFIGHT(pOptions);
			break;
		case 3:
			warriorHard(pOptions);
			challengeMenuFIGHT(pOptions);
			break;
		case 4:
			warriorExpert(pOptions);
			challengeMenuFIGHT(pOptions);
			break;
		case 5:
			warriorMaster(pOptions);
			challengeMenuFIGHT(pOptions);
			break;
		case 6:
			warriorLegendary(pOptions);
			challengeMenuFIGHT(pOptions);
			break;
		case 7:
			gameMenu(pOptions);
			break;
		default:
			cout << pError << endl;
			challengeMenu(pOptions);
			break;
		}
	}
	else
	{
		cout << pError << endl;
		challengeMenu(pOptions);
	}
};

void challengeMenuFIGHT(playerMenu& pOptions) {
	system("cls");
	deathPrintInfo(pOptions);
	pDeathPrintInfo(pOptions);
	int menuChoice;
	cout << "|==========================================================|" << endl;
	cout << pOptions.monsters.menuTitle << endl;
	cout << "|==========================================================|" << endl;
	cout << "| Challenger: " << pOptions.monsters.creatureName << endl;
	cout << "| Level: " << pOptions.monsters.creatureLevel << endl;
	cout << "| Health: " << pOptions.monsters.creatureHealth << " / " << pOptions.monsters.creatureHPTOTAL << endl;
	cout << "| Strength: " << pOptions.monsters.creatureStrength << endl;
	cout << "| Stamina: " << pOptions.monsters.creatureStamina << endl;
	cout << "| Armor: " << pOptions.monsters.creatureArmorTOTAL << endl;
	cout << "| Attack Damage: " << pOptions.monsters.creatureWeaponAttack << endl;
	cout << "| Weapon Attacks: " << pOptions.monsters.attackList << endl;
	cout << "|==========================================================|" << endl;
	cout << "|  (1) Jab Attack (2) Slash Attack (3) Block (4)Surrender  |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "Choose: ";
	cin >> menuChoice;

	if ((cin.fail())) {
		cout << pError << endl;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("pause");
		challengeMenuFIGHT(pOptions);
	}

	bool pExists = std::find(std::begin(pMenu), std::end(pMenu), menuChoice) != std::end(pMenu);
	if (pExists) {
		switch (menuChoice) {
		case 1:
			jabAttack(pOptions);
			monsterJabAttack(pOptions);
			system("pause");
			challengeMenuFIGHT(pOptions);
			break;
		case 2:
			challengeMenuFIGHT(pOptions);
			break;
		case 3:
			challengeMenuFIGHT(pOptions);
			break;
		case 4:
			gameMenu(pOptions);
			break;
		default:
			cout << pError << endl;
			system("pause");
			challengeMenuFIGHT(pOptions);
			break;
		}
	}
	else
	{
		cout << pError << endl;
		system("pause");
		challengeMenuFIGHT(pOptions);
	}
}