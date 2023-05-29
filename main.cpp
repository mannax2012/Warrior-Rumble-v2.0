#include "includes.h"
using namespace std;

int main(playerMenu& pOptions) {
	/*
	cout << "#     #                                         ######                                                #####        ###   " << endl;
	cout << "#  #  #   ##   #####  #####  #  ####  #####     #     # #    # #    # #####  #      ######    #    # #     #      #   #  " << endl;
	cout << "#  #  #  #  #  #    # #    # # #    # #    #    #     # #    # ##  ## #    # #      #         #    #       #     #     # " << endl;
	cout << "#  #  # #    # #    # #    # # #    # #    #    ######  #    # # ## # #####  #      #####     #    #  #####      #     # " << endl;
	cout << "#  #  # ###### #####  #####  # #    # #####     #   #   #    # #    # #    # #      #         #    # #       ### #     # " << endl;
	cout << "#  #  # #    # #   #  #   #  # #    # #   #     #    #  #    # #    # #    # #      #          #  #  #       ###  #   #  " << endl;
	cout << "## ##  #    # #    # #    # #  ####  #    #    #     #  ####  #    # #####  ###### ######      ##   ####### ###   ###   " << endl;
	system("pause");
	*/
	mainMenu(pOptions);
}

int pExit() {
	cout << "Exiting Game!" << endl;
	system("pause");
	exit(0);
	return 0;
}

void mainMenu(playerMenu& pOptions){
	system("cls");
	int menuOptionChoice;
	cout << "|==========================================================|" << endl;
	cout << "|      0====={>;;;;;;;;WARRIOR RUMBLE v2.0;;;;;;|>         |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|      1     |       START NEW CHARACTER     |             |" << endl;
	cout << "|      2     |         LOAD CHARACTER        |             |" << endl;
	cout << "|            |                               |             |" << endl;
	cout << "|            |                               |             |" << endl;
	cout << "|            |                               |             |" << endl;
	cout << "|            |                               |             |" << endl;
	cout << "|            |                               |             |" << endl;
	cout << "|      7     |             EXIT              |             |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "Choose a Menu Option: ";
	cin >> menuOptionChoice;
	if ((cin.fail())) {
		cout << pError << endl;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("pause");
		mainMenu(pOptions);
	}
	switch (menuOptionChoice) {
	case 1:
		startNewChar(pOptions);
		break;
	case 2:
		mainMenu(pOptions);
		break;
	case 7:
		pExit();
		break;
	default:
		mainMenu(pOptions);
		break;
}
};

void gameMenu(playerMenu& pOptions) {
	system("cls");
	int menuOptionChoice;
	cout << "|==========================================================|" << endl;
	cout << "|         0====={>;;;;;;;-MAIN MENU-;;;;;;|>               |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|      1     |         CHARACTER SHEET       |             |" << endl;
	cout << "|      2     |         CHALLENGE MENU        |             |" << endl;
	cout << "|      3     |          RUMBLE SHOP          |             |" << endl;
	cout << "|            |                               |             |" << endl;
	cout << "|            |                               |             |" << endl;
	cout << "|            |                               |             |" << endl;
	cout << "|      6     |         SAVE CHARACTER        |             |" << endl;
	cout << "|      7     |             QUIT              |             |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "Choose a Menu Option: ";
	cin >> menuOptionChoice;
	if ((cin.fail())) {
		cout << pError << endl;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("pause");
		gameMenu(pOptions);
	}
	switch (menuOptionChoice) {
	case 1:
		printCharacterSheet(pOptions);
		break;
	case 2:
		challengeMenu(pOptions);
		break;
	case 3:
		gameMenu(pOptions);
		break;
	case 6:
		saveChar(pOptions);
	case 7:
		mainMenu(pOptions);
		break;
	default:
		gameMenu(pOptions);
		break;
	}
};