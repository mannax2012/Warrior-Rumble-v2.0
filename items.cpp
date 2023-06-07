class Item {
public:
    std::string name;
    int value;

    // Constructor
    Item(const std::string& itemName, int itemValue) : name(itemName), value(itemValue) {}

    // Member function
    void use() {
        // Define the behavior when the item is used
    }
    void buy() {
        system("pause");
    }
};
class Weapon : public Item {
public:
    int damage;

    // Constructor
    Weapon(const std::string& weaponName, int weaponValue, int weaponDamage)
        : Item(weaponName, weaponValue), damage(weaponDamage) {}

    // Additional member function or override base class function
};

class Armor : public Item {
public:
    int defense;

    // Constructor
    Armor(const std::string& armorName, int armorValue, int armorDefense)
        : Item(armorName, armorValue), defense(armorDefense) {}

    // Additional member function or override base class function
};
int main() {
    Weapon sword("Sword", 100, 10);
    Armor helmet("Helmet", 50, 5);

    // Access member variables
    std::cout << "Weapon: " << sword.name << ", Damage: " << sword.damage << std::endl;
    std::cout << "Armor: " << helmet.name << ", Defense: " << helmet.defense << std::endl;

    // Use member functions
    sword.use();
    helmet.use();
    sword.buy();
    return 0;
}