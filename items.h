#pragma once
#include <iostream>
using namespace std;
#ifndef ITEMS_H
#define ITEMS_H
class Item {
public:
	string name;
	int cost, armorVal, wATP, sellVal;
	Item (const string& itemName, int itemCost, int armor, int wATK, int sellMe) : name(itemName), cost(itemCost), armorVal(armor), wATP(wATK), sellVal(sellMe) {}

    string getName() const {
        return name;
    }

    int getCost() const {
        return cost;
    }
    int getArmor() const {
        return armorVal;
    }
    int getATK() const {
        return wATP;
    }
    int getSellVal(int sellVal) const {
        sellVal = cost / 2;
        return sellVal;
    }
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

class Inventory {
private:
    static const int MAX_SLOTS = 10;
    vector<Item> items;
    bool slotAvailability[MAX_SLOTS];

public:
    Inventory(playerMenu& pOptions) {
        for (int i = 0; i < MAX_SLOTS; ++i) {
            slotAvailability[i] = true;  // Set all slots as available initially
        }
    }

    void addItem(playerMenu& pOptions, const string& name, int cost, int armorVal, int wATP, int sellVal) {
        if (items.size() >= MAX_SLOTS) {
            cout << "Inventory is full. Cannot add more items.\n";
            return;
        }

        // Find an available slot
        int slotIndex = -1;
        for (int i = 0; i < MAX_SLOTS; ++i) {
            if (slotAvailability[i]) {
                slotIndex = i;
                break;
            }
        }

        if (slotIndex != -1) {
            Item item(name, cost, armorVal, wATP, sellVal);
            items.push_back(item);
            slotAvailability[slotIndex] = false;  // Mark the slot as occupied
            cout << "Item added to slot " << slotIndex << endl;
        }
    }

    void removeItem(playerMenu& pOptions, const string& name) {
        int slotIndex = -1;
        for (int i = 0; i < items.size(); ++i) {
            if (items[i].getName() == name) {
                slotIndex = i;
                break;
            }
        }

        if (slotIndex == -1) {
            cout << "Item not found in the inventory.\n";
            return;
        }

        items.erase(items.begin() + slotIndex);  // Remove item from vector
        slotAvailability[slotIndex] = true;      // Mark the slot as available again
        cout << "Item '" << name << "' removed from the inventory.\n";
    }

    void displayInventory(playerMenu& pOptions) {
        system("cls");
        cout << "|==========================================================|" << endl;
        cout << "|                   CHARACTER INVENTORY                    |" << endl;
        cout << "|==========================================================|" << endl;
        cout << "|SLOT  # | ITEM NAME | ARMORS | ATTACK RATING | SELL VALUE |" << endl;
        cout << "|==========================================================|" << endl;
        for (int i = 0; i < items.size(); ++i) {
            cout << "|Slot " << i << " | Name: " << items[i].getName() << " | ATTACK RATING: " << items[i].getCost() << endl;
        }
        cout << "|==========================================================|" << endl;
        system("pause");

    }
};
#endif // ITEMS_H
