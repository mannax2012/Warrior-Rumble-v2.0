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
    string name;
    int damage, cost;
    bool isOwnd;

    Weapon(const string& weaponName, int weaponValue, int weaponDamage, bool ownThis)
        : Item(weaponName, weaponValue), name(weaponName), damage(weaponDamage), cost(weaponValue), isOwnd(ownThis) {}

    void equipIt(playerMenu& pOptions) {
        if (pOptions.createChar.isEquipedWeapon == false) {
            pOptions.createChar.isEquipedWeapon = true;
            pOptions.createChar.weaponT = name;
            pOptions.createChar.pWeaponDamage += damage;
            cout << "You have just equiped " << pOptions.createChar.weaponT << endl;
            system("pause");
        }
        else {
            cout << "You aleady have a weapon equiped. You must first unequip your current weapon first." << endl;
            system("pause");

        }
    }
    void buyIt(playerMenu& pOptions) {
        isOwnd = true;
        pOptions.createChar.pMoney -= cost;
        cout << name << " has been added to your inventory. You spent " << cost << " on this item." << endl;
        system("pause");
    }
    void sellIt(playerMenu& pOptions) {
        isOwnd = false;
        pOptions.createChar.pMoney += (cost / 2);
        cout << name << " has been sold." << endl;
        cout << "Gold: " << pOptions.createChar.pMoney << endl;
        system("pause");
    }
    void unEquipIt(playerMenu& pOptions) {
        pOptions.createChar.isEquipedWeapon = false;
        pOptions.createChar.weaponT = "Deez Hands";
        pOptions.createChar.pWeaponDamage -= damage;
        cout << "You have unequiped" << name << endl;
        system("pause");
    }
};

class Armor : public Item {
public:
    int defense;
    int cost;
    bool isOwnd;

    Armor(const string& armorName, int armorValue, int armorDefense, bool armorOwnd)
        : Item(armorName, armorValue), defense(armorDefense), cost(armorValue), isOwnd(armorOwnd) {}

};

class Potions : public Item {
public:
    int power;
    int cost;

    Potions(const string& potionName, int potionValue, int potionPower)
        : Item(potionName, potionValue), power(potionPower), cost(potionValue) {}
    
    void use(playerMenu& pOptions) {

    }
};
#endif // ITEMS_H
