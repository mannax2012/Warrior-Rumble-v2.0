#pragma once
using namespace std;
//good
const string pError = "Fail.";

enum class ItemType {
	Sword,
	Axe,
	Health_potion,
	Helmet,
	Random
};

typedef struct combat {
	string jabAttack = "Quick Jab",
		slashAttack = "Heavy Slash";

	int totalHealthDamage = 0,
		rageRemaining = 0,
		rageUsed = 0,
		swordAttackDamage,
		axeAttackDamage,
		poleaxeAttackDamage,
		jabAttackDamage,
		slashAttackDamage;
} combat;

typedef struct lvlUp {

	int health = 0,
		rage = 0,
		strength = 0,
		level = 1,
		expCharBonus = 0,
		stamina = 0,
		dexterity = 0;
} lvlUp;

typedef struct player {

	string playerName,
		weaponQ = "Empty",
		weaponT = "Hands",
		armorQhelm = "No",
		armorQbody = "No",
		armorQshield = "No";

	int pHealth = 0,
		pHealthTOTAL,
		pRage,
		pRageTOTAL,
		pStrength,
		pDexterity,
		pStamina,
		pArmorTOTAL,
		pWeaponDamage,
		playerLevel,
		pMoney,
		pExpValCurrent,
		pExpValNextLevel;
} player;

typedef struct inventory {
	bool item01;
	string itemName01 = "EMPTY",
		itemName02 = "EMPTY",
		itemName03 = "EMPTY",
		itemName04 = "EMPTY",
		itemName05 = "EMPTY",
		itemName06 = "EMPTY",
		itemName07 = "EMPTY",
		itemName08 = "EMPTY",
		itemName09 = "EMPTY",
		itemName10 = "EMPTY";

	int itemDamageVal01 = 0,
		itemArmorVal01 = 0,
	itemSellVal01 = 0;

} inventory;

typedef struct saveLoad {
	int saveWeaponQ,
		saveWeaponT,
		saveHelmQ,
		saveArmorQ,
		saveShieldQ;
}saveLoad;