#include "includes.h"
#include "items.h"
using namespace std;

short pArrayShop[7] = { 1,2,3,4,5,6,7 };
short pArrayShopBuy[7] = { 1,2,3,4,5,6,7 };

Weapon sword01("Oak Sword", 10, 10, false);
Weapon sword02("Copper Sword", 20, 15, false);
Weapon sword03("Bronze Sword", 30, 20, false);
Weapon sword04("Iron Sword", 50, 30, false);
Weapon sword05("Steel Sword", 100, 50, false);
Weapon sword06("Mithril Sword", 125, 80, false);
Weapon sword07("Pecker Smasher", 500, 1000, false);

void shopMenu(playerMenu& pOptions) {
	system("cls");
	int shopMenuChoice;
	cout << "|==========================================================|" << endl;
	cout << "|                       RUMBLE SHOP                        |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|      1     |            WEAPONS            |             |" << endl;
	cout << "|      2     |             ARMOR             |             |" << endl;
	cout << "|      3     |            POTIONS            |             |" << endl;
	cout << "|            |                               |             |" << endl;
	cout << "|            |                               |             |" << endl;
	cout << "|            |                               |             |" << endl;
	cout << "|      7     |           MAIN MENU           |             |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "Choose a Menu Option: ";
	cin >> shopMenuChoice;

	if ((cin.fail())) {
		cout << pError << endl;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		shopMenu(pOptions);
	}

	bool pExists = std::find(std::begin(pArrayShop), std::end(pArrayShop), shopMenuChoice) != std::end(pArrayShop);
	if (pExists) {
		switch (shopMenuChoice) {
		case 1:
			shopMenuWeapons(pOptions);
			break;
		case 2:
			//shopMenuArmor(pOptions);
			break;
		case 3:
			//shopMenuPotions(pOptions);
			break;
		case 7:
			gameMenu(pOptions);
			break;
		default:
			shopMenu(pOptions);
			break;
		}
	}
	else
	{
		cout << pError << endl;
		shopMenu(pOptions);
	}
};

void shopMenuWeapons(playerMenu& pOptions) {
	system("cls");
	int shopMenuChoice;
	cout << "|==========================================================|" << endl;
	cout << "|                       WEAPON MENU                        |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|      1     |            SWORDS             |             |" << endl;
	cout << "|      2     |             AXES              |             |" << endl;
	cout << "|      3     |           POLEAXES            |             |" << endl;
	cout << "|            |                               |             |" << endl;
	cout << "|            |                               |             |" << endl;
	cout << "|            |                               |             |" << endl;
	cout << "|      7     |           SHOP MENU           |             |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "Choose a Menu Option: ";
	cin >> shopMenuChoice;

	if ((cin.fail())) {
		cout << pError << endl;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		shopMenuWeapons(pOptions);
	}

	bool pExists = std::find(std::begin(pArrayShop), std::end(pArrayShop), shopMenuChoice) != std::end(pArrayShop);
	if (pExists) {
		switch (shopMenuChoice) {
		case 1:
			shopMenuSwords(pOptions);
			break;
		case 2:
			//shopMenuAxes(createChar);
			break;
		case 3:
			//shopMenuPoleaxes(createChar);
			break;
		case 7:
			gameMenu(pOptions);
			break;
		default:
			shopMenu(pOptions);
			break;
		}
	}
	else
	{
		cout << pError << endl;
		shopMenuWeapons(pOptions);
	}
};

void shopMenuSwords(playerMenu& pOptions) {
	system("cls");
	int shopMenuChoice;
	cout << "|==========================================================|" << endl;
	cout << "|                       WEAPONS MENU                       |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|            |         -------------         |    PRICE    |" << endl;
	cout << "|      1     |           OAK SWORD           |   1 SOUL    |" << endl;
	cout << "|      2     |          COPPER SWORD         |   5 SOULS   |" << endl;
	cout << "|      3     |          BRONZE SWORD         |   10 SOULS  |" << endl;
	cout << "|      4     |           IRON SWORD          |   15 SOULS  |" << endl;
	cout << "|      5     |           STEEL SWORD         |   25 SOULS  |" << endl;
	cout << "|      6     |          MITHRIL SWORD        |   50 SOULS  |" << endl;
	cout << "|      7     |           SHOP MENU           |             |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "Choose a Menu Option: ";
	cin >> shopMenuChoice;

	if ((cin.fail())) {
		cout << pError << endl;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		shopMenuSwords(pOptions);
	}

	bool pExists = std::find(std::begin(pArrayShopBuy), std::end(pArrayShopBuy), shopMenuChoice) != std::end(pArrayShopBuy);
	

	if (pExists) {
		switch (shopMenuChoice) {
		case 1:
			if (pOptions.createChar.pMoney == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(pOptions);
			}
			else {
				if (sword01.isOwnd != false) {
					cout << "You already own a weapon of this quality." << endl;
					system("pause");
					shopMenu(pOptions);
				}
				else {
					sword01.buyIt(pOptions);
					sword01.equipIt(pOptions);
					shopMenu(pOptions);
				}
			}
			break;
		case 2:
			if (pOptions.createChar.pMoney == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(pOptions);
			}
			else {
				if (sword02.isOwnd != false) {
					cout << "You already own a weapon of this quality." << endl;
					system("pause");
					shopMenu(pOptions);
				}
				else {
					pOptions.inventory.addItem("Copper Sword", 20);
					sword02.buyIt(pOptions);
					shopMenu(pOptions);
				}
			}
			break;
		case 7:
			shopMenu(pOptions);
			break;
		}
	}
		else
		{
			cout << pError << endl;
			system("pause");
			shopMenuSwords(pOptions);
	}
};
/*
character shopMenuAxes(playerMenu& pOptions) {
	system("cls");
	int shopMenuChoice;
	cout << "|==========================================================|" << endl;
	cout << "|                       WEAPONS MENU                       |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|            |         -------------         |    PRICE    |" << endl;
	cout << "|      1     |            OAK AXE            |   1 SOUL    |" << endl;
	cout << "|      2     |          COPPER AXE           |   5 SOULS   |" << endl;
	cout << "|      3     |          BRONZE AXE           |   10 SOULS  |" << endl;
	cout << "|      4     |           IRON AXE            |   15 SOULS  |" << endl;
	cout << "|      5     |           STEEL AXE           |   25 SOULS  |" << endl;
	cout << "|      6     |          MITHRIL AXE          |   50 SOULS  |" << endl;
	cout << "|      7     |           SHOP MENU           |             |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "Choose a Menu Option: ";
	cin >> shopMenuChoice;

	if ((cin.fail())) {
		cout << pError << endl;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		shopMenuAxes(createChar);
	}

	bool pExists = std::find(std::begin(pArrayShopBuy), std::end(pArrayShopBuy), shopMenuChoice) != std::end(pArrayShopBuy);
	if (pExists) {
		switch (shopMenuChoice) {
		case 1:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (axeQuality >= materials::Oak) {
					cout << "You already own a weapon of this quality." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Oak Axe
					axeQuality = materials::Oak;
					createChar.souls = createChar.souls - 1;
					buyWeaponAxe(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 2:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (axeQuality >= materials::Copper) {
					cout << "You already own a weapon of this quality." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Copper
					axeQuality = materials::Copper;
					buyWeaponAxe(createChar);
					createChar.souls = createChar.souls - 5;
					shopMenu(createChar);
				}
			}
			break;
		case 3:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (axeQuality >= materials::Bronze) {
					cout << "You already own a weapon of this quality." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Bronze Axe
					axeQuality = materials::Bronze;
					buyWeaponAxe(createChar);
					createChar.souls = createChar.souls - 10;
					shopMenu(createChar);
				}
			}
			break;
		case 4:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (axeQuality >= materials::Iron) {
					cout << "You already own a weapon of this quality." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Iron Axe
					axeQuality = materials::Iron;
					buyWeaponAxe(createChar);
					createChar.souls = createChar.souls - 15;
					shopMenu(createChar);
				}
			}
			break;
		case 5:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (axeQuality >= materials::Steel) {
					cout << "You already own a weapon of this quality." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Steel
					axeQuality = materials::Steel;
					buyWeaponAxe(createChar);
					createChar.souls = createChar.souls - 25;
					shopMenu(createChar);
				}
			}
			break;
		case 6:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (axeQuality >= materials::Mithril) {
					cout << "You already own a weapon of this quality." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Mithril
					axeQuality = materials::Mithril;
					buyWeaponAxe(createChar);
					createChar.souls = createChar.souls - 50;
					shopMenu(createChar);
				}
			}
			break;
		case 7:
			shopMenu(createChar);
			break;
		}
	}
		else
	{
		cout << pError << endl;
		system("pause");
		shopMenuAxes(createChar);
	}
	return createChar;
};

character shopMenuPoleaxes(playerMenu& pOptions) {
	int shopMenuChoice;
	system("cls");
	cout << "|==========================================================|" << endl;
	cout << "|                       WEAPONS MENU                       |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|            |         -------------         |    PRICE    |" << endl;
	cout << "|      1     |            OAK POLEAXE        |   1 SOUL    |" << endl;
	cout << "|      2     |          COPPER POLEAXE       |   5 SOULS   |" << endl;
	cout << "|      3     |          BRONZE POLEAXE       |   10 SOULS  |" << endl;
	cout << "|      4     |           IRON POLEAXE        |   15 SOULS  |" << endl;
	cout << "|      5     |           STEEL POLEAXE       |   25 SOULS  |" << endl;
	cout << "|      6     |          MITHRIL POLEAXE      |   50 SOULS  |" << endl;
	cout << "|      7     |           SHOP MENU           |             |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "Choose a Menu Option: ";
	cin >> shopMenuChoice;

	if ((cin.fail())) {
		cout << pError << endl;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("pause");
		shopMenuPoleaxes(createChar);
	}

	bool pExists = std::find(std::begin(pArrayShopBuy), std::end(pArrayShopBuy), shopMenuChoice) != std::end(pArrayShopBuy);
	if (pExists) {
		switch (shopMenuChoice) {
		case 1:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (poleaxeQuality >= materials::Oak) {
					cout << "You already own a weapon of this quality." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Oak Axe
					poleaxeQuality = materials::Oak;
					createChar.souls = createChar.souls - 1;
					buyWeaponPoleaxe(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 2:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (poleaxeQuality >= materials::Copper) {
					cout << "You already own a weapon of this quality." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Copper
					poleaxeQuality = materials::Copper;
					createChar.souls = createChar.souls - 5;
					buyWeaponPoleaxe(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 3:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (poleaxeQuality >= materials::Bronze) {
					cout << "You already own a weapon of this quality." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Bronze Axe
					poleaxeQuality = materials::Bronze;
					createChar.souls = createChar.souls - 10;
					buyWeaponPoleaxe(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 4:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (poleaxeQuality >= materials::Iron) {
					cout << "You already own a weapon of this quality." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Iron Axe
					poleaxeQuality = materials::Iron;
					createChar.souls = createChar.souls - 15;
					buyWeaponPoleaxe(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 5:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (poleaxeQuality >= materials::Steel) {
					cout << "You already own a weapon of this quality." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Steel
					poleaxeQuality = materials::Steel;
					createChar.souls = createChar.souls - 25;
					buyWeaponPoleaxe(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 6:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (poleaxeQuality >= materials::Mithril) {
					cout << "You already own a weapon of this quality." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Mithril
					poleaxeQuality = materials::Mithril;
					createChar.souls = createChar.souls - 50;
					buyWeaponPoleaxe(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 7:
			shopMenu(createChar);
			break;
		}
	}
	else
	{
		cout << pError << endl;
		system("pause");
		shopMenuPoleaxes(createChar);
	}
	return createChar;
};

void shopMenuArmor(playerMenu& pOptions) {
				int shopMenuChoice;
				system("cls");
				cout << "|==========================================================|" << endl;
				cout << "|                        ARMOR MENU                        |" << endl;
				cout << "|==========================================================|" << endl;
				cout << "|      1     |            HELMETS            |             |" << endl;
				cout << "|      2     |           BODY ARMOR          |             |" << endl;
				cout << "|      3     |            SHEILDS            |             |" << endl;
				cout << "|            |                               |             |" << endl;
				cout << "|            |                               |             |" << endl;
				cout << "|            |                               |             |" << endl;
				cout << "|      7     |           SHOP MENU           |             |" << endl;
				cout << "|==========================================================|" << endl;
				cout << "Choose a Menu Option: ";
				cin >> shopMenuChoice;

				if ((cin.fail())) {
					cout << pError << endl;
					cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					system("pause");
					shopMenuArmor(createChar);
				}

				bool pExists = std::find(std::begin(pArrayShop), std::end(pArrayShop), shopMenuChoice) != std::end(pArrayShop);
				if (pExists) {
					switch (shopMenuChoice) {
					case 1:
						shopMenuHelms(createChar);
						break;
					case 2:
						shopMenuBodyArmor(createChar);
						break;
					case 3:
						shopMenuSheilds(createChar);
						break;
					case 7:
						shopMenu(createChar);
						break;
					default:
						shopMenuArmor(createChar);
						break;
					}
				}
				else
				{
					cout << pError << endl;
					system("pause");
					shopMenu(createChar);
				}
	};

character shopMenuHelms(playerMenu& pOptions) {
	int shopMenuChoice;
	system("cls");
	cout << "|==========================================================|" << endl;
	cout << "|                         HELM MENU                        |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|            |         -------------         |    PRICE    |" << endl;
	cout << "|      1     |            OAK HELM           |   1 SOUL    |" << endl;
	cout << "|      2     |           COPPER HELM         |   5 SOULS   |" << endl;
	cout << "|      3     |           BRONZE HELM         |   10 SOULS  |" << endl;
	cout << "|      4     |            IRON HELM          |   15 SOULS  |" << endl;
	cout << "|      5     |           STEEL HELM          |   25 SOULS  |" << endl;
	cout << "|      6     |           MITHRIL HELM        |   50 SOULS  |" << endl;
	cout << "|      7     |           SHOP MENU           |             |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "Choose a Menu Option: ";
	cin >> shopMenuChoice;

	if ((cin.fail())) {
		cout << pError << endl;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("pause");
		shopMenuHelms(createChar);
	}

	bool pExists = std::find(std::begin(pArrayShopBuy), std::end(pArrayShopBuy), shopMenuChoice) != std::end(pArrayShopBuy);
	if (pExists) {
		switch (shopMenuChoice) {
		case 1:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (helmQuality >= materials::Oak) {
					cout << "You already own a helmet of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Oak Helm
					helmQuality = materials::Oak;
					createChar.souls = createChar.souls - 1;
					buyArmorHelm(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 2:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (helmQuality >= materials::Copper){
					cout << "You already own a helmet of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
					}
				else {
					//Copper Helm
						helmQuality = materials::Copper;
						createChar.souls = createChar.souls - 5;
						buyArmorHelm(createChar);
						shopMenu(createChar);
				}
			}
			break;
		case 3:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (helmQuality >= materials::Bronze) {
					cout << "You already own a helmet of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Bronze Helm
					helmQuality = materials::Bronze;
					createChar.souls = createChar.souls - 10;
					buyArmorHelm(createChar);
					shopMenu(createChar);
				}
			}
			break;

		case 4:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (helmQuality >= materials::Iron) {
					cout << "You already own a helmet of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Iron Helm
					helmQuality = materials::Iron;
					createChar.souls = createChar.souls - 15;
					buyArmorHelm(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 5:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (helmQuality >= materials::Steel) {
					cout << "You already own a helmet of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Steel Helm
					helmQuality = materials::Steel;
					createChar.souls = createChar.souls - 25;
					buyArmorHelm(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 6:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (helmQuality >= materials::Mithril) {
					cout << "You already own a helmet of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Mithril Helm
					helmQuality = materials::Mithril;
					createChar.souls = createChar.souls - 50;
					buyArmorHelm(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 7:
			shopMenu(createChar);
			break;
		}
	}
			else
			{
				cout << pError << endl;
				system("pause");
				shopMenuHelms(createChar);
	}
	return createChar;
};

character shopMenuBodyArmor(playerMenu& pOptions) {
	system("cls");
	int shopMenuChoice;
	cout << "|==========================================================|" << endl;
	cout << "|                      BODY ARMOR MENU                     |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|            |         -------------         |    PRICE    |" << endl;
	cout << "|      1     |         OAK BODY ARMOR        |   1 SOUL    |" << endl;
	cout << "|      2     |       COPPER BODY ARMOR       |   5 SOULS   |" << endl;
	cout << "|      3     |       BRONZE BODY ARMOR       |   10 SOULS  |" << endl;
	cout << "|      4     |        IRON BODY ARMOR        |   15 SOULS  |" << endl;
	cout << "|      5     |        STEEL BODY ARMOR       |   25 SOULS  |" << endl;
	cout << "|      6     |       MITHRIL BODY ARMOR      |   50 SOULS  |" << endl;
	cout << "|      7     |           SHOP MENU           |             |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "Choose a Menu Option: ";
	cin >> shopMenuChoice;

	if ((cin.fail())) {
		cout << pError << endl;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("pause");
		shopMenuBodyArmor(createChar);
	}

	bool pExists = std::find(std::begin(pArrayShopBuy), std::end(pArrayShopBuy), shopMenuChoice) != std::end(pArrayShopBuy);
	if (pExists) {
		switch (shopMenuChoice) {
		case 1:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (armorQuality >= materials::Oak) {
					cout << "You already own a Body Armor of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Oak Body Armor
					armorQuality = materials::Oak;
					createChar.souls = createChar.souls - 1;
					buyArmorBody(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 2:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (armorQuality >= materials::Copper) {
					cout << "You already own Body Armor of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Copper Body Armor
					armorQuality = materials::Copper;
					createChar.souls = createChar.souls - 5;
					buyArmorBody(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 3:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (armorQuality >= materials::Bronze) {
					cout << "You already own Body Armor of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Bronze Body Armor
					armorQuality = materials::Bronze;
					createChar.souls = createChar.souls - 10;
					buyArmorBody(createChar);
					shopMenu(createChar);
				}
			}
			break;

		case 4:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (armorQuality >= materials::Iron) {
					cout << "You already own Body Armor of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Iron Body Armor
					armorQuality = materials::Iron;
					createChar.souls = createChar.souls - 15;
					buyArmorBody(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 5:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (armorQuality >= materials::Steel) {
					cout << "You already own Body Armor of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Steel BodyArmor
					armorQuality = materials::Steel;
					createChar.souls = createChar.souls - 25;
					buyArmorBody(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 6:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (armorQuality >= materials::Mithril) {
					cout << "You already own Body Armor of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Mithril BodyArmor
					armorQuality = materials::Mithril;
					createChar.souls = createChar.souls - 50;
					buyArmorBody(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 7:
			shopMenu(createChar);
			break;
		}
	}
			else
			{
				cout << pError << endl;
				system("pause");
				shopMenuBodyArmor(createChar);
	}
	return createChar;
};

character shopMenuSheilds(playerMenu& pOptions) {
	system("cls");
	int shopMenuChoice;

	cout << "- Sheilds Menu -" << endl;
	cout << "(1) Oak Sheild - 1 Soul" << endl;
	cout << "(2) Copper Sheild - 5 Souls" << endl;
	cout << "(3) Bronze Sheild - 10 Souls" << endl;
	cout << "(4) Iron Sheild - 15 Souls" << endl;
	cout << "(5) Steel Sheild - 25 Souls" << endl;
	cout << "(6) Mithril Sheild - 50 Souls" << endl;
	cout << "(7) Shop Menu" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|                       SHEILD MENU                        |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|            |         -------------         |    PRICE    |" << endl;
	cout << "|      1     |          OAK SHEILD           |   1 SOUL    |" << endl;
	cout << "|      2     |         COPPER SHEILD         |   5 SOULS   |" << endl;
	cout << "|      3     |         BRONZE SHEILD         |   10 SOULS  |" << endl;
	cout << "|      4     |          IRON SHEILD          |   15 SOULS  |" << endl;
	cout << "|      5     |         STEEL SHEILD          |   25 SOULS  |" << endl;
	cout << "|      6     |         MITHRIL SHEILD        |   50 SOULS  |" << endl;
	cout << "|      7     |           SHOP MENU           |             |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "Choose a Menu Option: ";
	cin >> shopMenuChoice;

	if ((cin.fail())) {
		cout << pError << endl;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("pause");
		shopMenuSheilds(createChar);
	}

	bool pExists = std::find(std::begin(pArrayShopBuy), std::end(pArrayShopBuy), shopMenuChoice) != std::end(pArrayShopBuy);
	if (pExists) {
		switch (shopMenuChoice) {
		case 1:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (sheildQuality >= materials::Oak) {
					cout << "You already own a Sheild of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Oak Sheild
					sheildQuality = materials::Oak;
					createChar.souls = createChar.souls - 1;
					buyArmorSheild(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 2:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (sheildQuality >= materials::Copper) {
					cout << "You already own a Sheild of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Copper Sheild
					sheildQuality = materials::Copper;
					createChar.souls = createChar.souls - 5;
					buyArmorSheild(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 3:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (sheildQuality >= materials::Bronze) {
					cout << "You already own a Sheild of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Bronze Sheild
					sheildQuality = materials::Bronze;
					createChar.souls = createChar.souls - 10;
					buyArmorSheild(createChar);
					shopMenu(createChar);
				}
			}
			break;

		case 4:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (sheildQuality >= materials::Iron) {
					cout << "You already own a Sheild of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Iron Sheild
					sheildQuality = materials::Iron;
					createChar.souls = createChar.souls - 15;
					buyArmorSheild(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 5:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (sheildQuality >= materials::Steel) {
					cout << "You already own a Sheild of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Steel Sheild
					sheildQuality = materials::Steel;
					createChar.souls = createChar.souls - 25;
					buyArmorSheild(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 6:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenu(createChar);
			}
			else {
				if (sheildQuality >= materials::Mithril) {
					cout << "You already own a Sheild of this quality or better." << endl;
					system("pause");
					shopMenu(createChar);
				}
				else {
					//Mithril Sheild
					sheildQuality = materials::Mithril;
					createChar.souls = createChar.souls - 50;
					buyArmorSheild(createChar);
					shopMenu(createChar);
				}
			}
			break;
		case 7:
			shopMenu(createChar);
			break;
		}
	}
			else
			{
				cout << pError << endl;
				system("pause");
				shopMenuSheilds(createChar);
	}
	return createChar;
};

character shopMenuPotions(playerMenu& pOptions) {
	system("cls");
	int shopMenuChoice;

	cout << "|==========================================================|" << endl;
	cout << "|                       POTIONS MENU                       |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "|            |         -------------         |    PRICE    |" << endl;
	cout << "|      1     |        EXPERIENCE POTION      |   1 SOUL    |" << endl;
	cout << "|      2     |          HEALTH POTION        |   5 SOULS   |" << endl;
	cout << "|      3     |           RAGE POTION         |   5 SOULS   |" << endl;
	cout << "|      4     |         LARGE EXP POTION      |  10 SOULS   |" << endl;
	cout << "|      5     |        FULL HEALTH POTION     |  25 SOULS   |" << endl;
	cout << "|      6     |        FULL RAGE POTION       |  15 SOULS   |" << endl;
	cout << "|      7     |           SHOP MENU           |             |" << endl;
	cout << "|==========================================================|" << endl;
	cout << "Choose a Menu Option: ";
	cin >> shopMenuChoice;

	if ((cin.fail())) {
		cout << pError << endl;
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		shopMenuPotions(createChar);
	}

	bool pExists = std::find(std::begin(pArrayShopBuy), std::end(pArrayShopBuy), shopMenuChoice) != std::end(pArrayShopBuy);
	if (pExists) {
		switch (shopMenuChoice) {
		case 1:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenuPotions(createChar);
			}
			else {
				//expPot
				createChar.souls = createChar.souls - 10;
				cout << "You bought an Experience Potion granting 100 experience for 10 souls." << endl;
				cout << "You have " << createChar.souls << " remaining." << endl;
				createChar.expChar += 100;
				levelUpCheck(createChar);
				system("pause");
				shopMenuPotions(createChar);
			}
			break;
		case 2:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenuPotions(createChar);
			}
			else {
				if (createChar.health >= createChar.HPTOTAL) {
					cout << "Health already at max. " << createChar.health << " / " << createChar.HPTOTAL << endl;
					system("pause");
					shopMenuPotions(createChar);
				}
				else {
					//HealthPot
					createChar.souls = createChar.souls - 1;
					createChar.combatStats.totalHealthDamage -= 10;
					createChar.health = createChar.HPTOTAL - createChar.combatStats.totalHealthDamage;
					if (createChar.health > createChar.HPTOTAL) {
						createChar.health = createChar.HPTOTAL;
					}
					if (createChar.combatStats.totalHealthDamage > createChar.HPTOTAL) {
						createChar.combatStats.totalHealthDamage = createChar.HPTOTAL;
					}
					cout << "You bought a Health Potion granting 10 Health for 1 soul." << endl;
					cout << "You have " << createChar.health << " / " << createChar.HPTOTAL << " health." << endl;
					cout << "You have " << createChar.souls << " remaining." << endl;
					system("pause");
					shopMenuPotions(createChar);
				}
			}
				break;
		case 3:
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenuPotions(createChar);
			}
			else {
				if (createChar.combatStats.rageUsed == 0) {
						cout << "Rage already at max. " << createChar.rage << " / " << createChar.RAGETOTAL << endl;
						system("pause");
					shopMenuPotions(createChar);
				}
				else {
					//RAGEPot
					createChar.souls = createChar.souls - 5;
					createChar.combatStats.rageUsed -= 50;
					createChar.rage = createChar.RAGETOTAL - createChar.combatStats.rageUsed;

					cout << "You bought a Rage Potion granting 50 Rage for 5 souls. " << createChar.rage << " / " << createChar.RAGETOTAL << endl;
					cout << "You have " << createChar.souls << " remaining." << endl;
					system("pause");
					shopMenuPotions(createChar);
					break;
				}
			}
		case 4:
			//Large XP
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenuPotions(createChar);
			}
			else {
				//expPot
				createChar.souls = createChar.souls - 10;
				cout << "You bought an Experience Potion granting 250(1000 TESTING) experience for 10 souls." << endl;
				cout << "You have " << createChar.souls << " remaining." << endl;
				createChar.expChar += 1000;
				levelUpCheck(createChar);
				system("pause");
				shopMenuPotions(createChar);
			}
			break;
		case 5:
			//FULL HEAL
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenuPotions(createChar);
			}
			else {
				if (createChar.health >= createChar.HPTOTAL) {
					cout << "Health already at max. " << createChar.health << " / " << createChar.HPTOTAL << endl;
					system("pause");
					shopMenuPotions(createChar);
				}
				else {
					//HealthPot
					createChar.souls = createChar.souls - 25;
					createChar.combatStats.totalHealthDamage -= createChar.HPTOTAL;
					createChar.health = createChar.HPTOTAL - createChar.combatStats.totalHealthDamage;
					if (createChar.health > createChar.HPTOTAL) {
						createChar.health = createChar.HPTOTAL;
					}
					if (createChar.combatStats.totalHealthDamage > createChar.HPTOTAL) {
						createChar.combatStats.totalHealthDamage = createChar.HPTOTAL;
					}
					cout << "You bought a Health Potion granting FULL Health for 25 souls." << endl;
					cout << "You have " << createChar.health << " / " << createChar.HPTOTAL << " health." << endl;
					cout << "You have " << createChar.souls << " remaining." << endl;
					system("pause");
					shopMenuPotions(createChar);
				}
			}
			break;
		case 6:
			//FULL RAGE
			if (createChar.souls == 0) {
				cout << "You do not have enough for this purchace." << endl;
				system("pause");
				shopMenuPotions(createChar);
			}
			else {
				if (createChar.combatStats.rageUsed == 0) {
					cout << "Rage already at max. " << createChar.rage << " / " << createChar.RAGETOTAL << endl;
					system("pause");
					shopMenuPotions(createChar);
				}
				else {
					createChar.souls = createChar.souls - 15;
					createChar.combatStats.rageUsed -= 100;
					createChar.rage = createChar.RAGETOTAL - createChar.combatStats.rageUsed;

					cout << "You bought a Rage Potion granting 100 Rage for 5 souls. " << createChar.rage << " / " << createChar.RAGETOTAL << endl;
					cout << "You have " << createChar.souls << " remaining." << endl;
					system("pause");
					shopMenuPotions(createChar);
					break;
				}
			}
			break;
		case 7:
			shopMenu(createChar);
			break;
		default:
			shopMenuPotions(createChar);
			}
		}
				else
				{
					cout << pError << endl;
					system("pause");
					shopMenuPotions(createChar);
	}
	return createChar;
};
*/