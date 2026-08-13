#include <iostream>
#include <string> 
#include <iomanip> 

class Fruit {
private:
    std::string name;
    double price;
    int quantity;

public:
    // Constructor

    Fruit(std::string n = " ", double p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    // Destructor

    ~Fruit() {
        std::cout << "Fruit Destructor is Called: " << name << std::endl;
    }

    // Copy Constructor

    Fruit(const Fruit& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // Copy Assignment

    Fruit& operator=(const Fruit& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    double totalSum() const {
        return price * quantity;
    }

    void receipt() const {
        std::cout << std::left
                  << std::setw(15) << "Fruit"
                  << std::setw(15) << name
                  << std::setw(12) << price
                  << std::setw(12) << quantity
                  << std::setw(12) << totalSum()
                  << std::endl;
    }
};

class Vegetable {
private:
    std::string name;
    double price;
    int quantity;

public:
    // Constructor

    Vegetable(std::string n = " ", double p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    // Destructor

    ~Vegetable() {
        std::cout << "Vegetable Destructor is Called: " << name << std::endl;
    }

    // Copy Constructor

    Vegetable(const Vegetable& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // Copy Assignment

    Vegetable& operator=(const Vegetable& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    double totalSum() const {
        return price * quantity;
    }

    void receipt() const {
      std::cout << std::left
                  << std::setw(15) << "Vegetables"
                  << std::setw(15) << name
                  << std::setw(12) << price
                  << std::setw(12) << quantity
                  << std::setw(12) << totalSum()
                  << std::endl;
    }
};

double totalSum(Fruit* fruits[], int fruitCount,
                Vegetable* vegetables[], int vegetableCount);

int main() {

    Fruit* fruitsTaken[2];
    Vegetable* vegetablesTaken[2];

    fruitsTaken[0] = new Fruit("Apple", 10, 7);
    fruitsTaken[1] = new Fruit("Banana", 10, 8);

    vegetablesTaken[0] = new Vegetable("Broccoli", 60, 12);
    vegetablesTaken[1] = new Vegetable("Lettuce", 50, 10);

    std::cout << "\n================MEMORY================\n";

    std::cout << "Apple Pointer      : " << fruitsTaken[0] << std::endl;

    std::cout << "Banana Pointer     : " << fruitsTaken[1] << std::endl;

    std::cout << "Broccoli Pointer   : " << vegetablesTaken[0] << std::endl;

    std::cout << "Lettuce Pointer    : " << vegetablesTaken[1] << std::endl;

    std::cout << "------------------------------------------------------------\n";
    std::cout << "                           RECEIPT\n";
    std::cout << "------------------------------------------------------------\n";

    std::cout << std::left
              << std::setw(15) << "Type"
              << std::setw(15) << "Item"
              << std::setw(10) << "Price"
              << std::setw(10) << "Quantity"
              << std::setw(10) << "Total"
              << std::endl;
    std::cout << "------------------------------------------------------------\n";

    std::cout << "Fruits:" << std::endl;
    for (int i = 0; i < 2; i++) {
        fruitsTaken[i]->receipt();
    }

    std::cout << "Vegetables:" << std::endl;
    for (int i = 0; i < 2; i++) {
        vegetablesTaken[i]->receipt();
    }

    std::cout << "\nTotal Amount in Pesos: "
              << totalSum(fruitsTaken, 2, vegetablesTaken, 2)
              << std::endl;

    char answer;

    std::cout << "\nDelete Lettuce? (Y/N): ";
    std::cin >> answer;

    if (answer == 'Y' || answer == 'y') {

    std::cout << "\n----------Pointer List Before Deletion---------\n";

    std::cout << "Apple Pointer    : " << fruitsTaken[0] << std::endl;
    std::cout << "Banana Pointer   : " << fruitsTaken[1] << std::endl;
    std::cout << "Broccoli Pointer : " << vegetablesTaken[0] << std::endl;
    std::cout << "Lettuce Pointer  : " << vegetablesTaken[1] << std::endl;

  std::cout << "------------------------------------------------------------\n";

    std::cout << "\nDeleting Lettuce...\n";

    delete vegetablesTaken[1];

    vegetablesTaken[1] = nullptr;

    std::cout << "\nMemory successfully deallocated.\n";

    std::cout << "\n-----------Pointer List After Deletion------------\n";

    std::cout << "Apple Pointer    : " << fruitsTaken[0] << std::endl;
    std::cout << "Banana Pointer   : " << fruitsTaken[1] << std::endl;
    std::cout << "Broccoli Pointer : " << vegetablesTaken[0] << std::endl;
    std::cout << "Lettuce Pointer  : " << vegetablesTaken[1] << std::endl;

    std::cout << "------------------------------------------------------------\n";

    if (vegetablesTaken[1] == nullptr) {
        std::cout << "\nLettuce successfully deleted.\n";
        std::cout << "Lettuce pointer is now nullptr.\n";
    }
}
    else {
    std::cout << "\nDeletion cancelled.\n";
}

    std::cout << "\nPress Enter to Continue...";
    std::cin.ignore();
    std::cin.get();

    std::cout << "------------------------------------------------------------\n";
    std::cout << "              Updated Grocery Receipt\n";
    std::cout << "------------------------------------------------------------\n";

    std::cout << "Fruits:" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (fruitsTaken[i] != nullptr) {
            fruitsTaken[i]->receipt();
        }
    }

    std::cout << "\nVegetables:" << std::endl;
    for (int i = 0; i < 2; i++) {
        if (vegetablesTaken[i] != nullptr) {
            vegetablesTaken[i]->receipt();
        }
    }

    std::cout << "\nNew Total Amount in Pesos: "
              << totalSum(fruitsTaken, 2, vegetablesTaken, 2)
              << std::endl;

    std::cout << "\n-----------Pointer List After Cleanup----------\n";

    std::cout << "Apple Pointer    : " << fruitsTaken[0] << std::endl;
    std::cout << "Banana Pointer   : " << fruitsTaken[1] << std::endl;
    std::cout << "Broccoli Pointer : " << vegetablesTaken[0] << std::endl;
    std::cout << "Lettuce Pointer  : " << vegetablesTaken[1] << std::endl;

    std::cout << "------------------------------------------------------------\n";

    std::cout << "\nCleaning up remaining memory...\n";

    for (int i = 0; i < 2; i++) {
    delete fruitsTaken[i];
    fruitsTaken[i] = nullptr;
}

    delete vegetablesTaken[0];

    vegetablesTaken[0] = nullptr;

    std::cout << "\nMemory successfully cleaned up.\n";

    std::cout << "\n---------Pointer List After Cleanup---------\n";

    std::cout << "Apple Pointer    : " << fruitsTaken[0] << std::endl;
    std::cout << "Banana Pointer   : " << fruitsTaken[1] << std::endl;
    std::cout << "Broccoli Pointer : " << vegetablesTaken[0] << std::endl;
    std::cout << "Lettuce Pointer  : " << vegetablesTaken[1] << std::endl;

    std::cout << "------------------------------------------------------------\n";

    if (fruitsTaken[0] == nullptr &&
        fruitsTaken[1] == nullptr &&
        vegetablesTaken[0] == nullptr &&
        vegetablesTaken[1] == nullptr) {

    std::cout << "\nAll dynamically allocated memory has been deallocated successfully.\n";
    std::cout << "No memory leaks remain.\n";
}

    return 0;
}

double totalSum(Fruit* fruits[], int fruitCount,
                Vegetable* vegetables[], int vegetableCount) {

    double total = 0;

    for (int i = 0; i < fruitCount; i++) {
        if (fruits[i] != nullptr) {
            total += fruits[i]->totalSum();
        }
    }

    for (int i = 0; i < vegetableCount; i++) {
        if (vegetables[i] != nullptr) {
            total += vegetables[i]->totalSum();
        }
    }

    return total;
}