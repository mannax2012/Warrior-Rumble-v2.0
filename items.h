#pragma once
#include <iostream>
using namespace std;

#ifndef ITEMS_H
#define ITEMS_H

class Item {
public:
	string name;
	int cost;
	Item (const string& itemName, int itemCost) : name(itemName), cost(itemCost) {}
};

class Weapon : public Item {
public:
    int damage;
    int cost;
    bool isEquiped;
    bool isOwnd;

    Weapon(const string& weaponName, int weaponValue, int weaponDamage, bool weaponEquiped, bool ownThis)
        : Item(weaponName, weaponValue), damage(weaponDamage), cost(weaponValue), isEquiped(weaponEquiped), isOwnd(ownThis) {}

};

class Armor : public Item {
public:
    int defense;
    int cost;
    bool isEquiped;

    Armor(const string& armorName, int armorValue, int armorDefense, bool armorEquiped)
        : Item(armorName, armorValue), defense(armorDefense), cost(armorValue), isEquiped(armorEquiped) {}
};

class Potions : public Item {
public:
    int power;
    int cost;

    Potions(const string& potionName, int potionValue, int potionPower)
        : Item(potionName, potionValue), power(potionPower), cost(potionValue) {}
};
#endif // ITEMS_H
