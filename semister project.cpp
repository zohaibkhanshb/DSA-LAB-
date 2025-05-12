#include <iostream>
#include <string>
#include <limits>
using namespace std;
struct Car {
    int id;
    string name;
    float price;
    Car* next;
};

struct SoldCar {
    string name;
    SoldCar* next;
};

struct SparePart {
    int id;
    string name;
    float price;
    SparePart* next;
};

class Inventory {
    Car* head;
public:
    Inventory() {
        head = NULL;
    }

    void addCar(int id, string name, float price) {
        Car* newCar = new Car;
        newCar->id = id;
        newCar->name = name;
        newCar->price = price;
        newCar->next = head;
        head = newCar;
    }

    void viewCars() {
        Car* temp = head;
        if (temp == NULL) {
            cout << "No cars in inventory.\n";
            return;
        }
        cout << "\n===== Available Cars =====\n";
        while (temp != NULL) {
            cout << "ID: " << temp->id << " | Name: " << temp->name << " | Price: RS " << temp->price << "\n";
            temp = temp->next;
        }
        cout << "=========================\n";
    }

    void deleteCar(int id) {
        Car* temp = head, *prev = NULL;
        while (temp != NULL && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Car not found.\n";
            return;
        }
        if (prev == NULL)
            head = head->next;
        else
            prev->next = temp->next;
        delete temp;
        cout << "Car deleted from inventory.\n";
    }
    bool carExists(int id) {
        Car* temp = head;
        while (temp != NULL) {
            if (temp->id == id)
                return true;
            temp = temp->next;
        }
        return false;
    }
    string getCarName(int id) {
        Car* temp = head;
        while (temp != NULL) {
            if (temp->id == id)
                return temp->name;
            temp = temp->next;
        }
        return "";
    }
};
class SoldStack {
    SoldCar* top;
public:
    SoldStack() {
        top = NULL;
    }

    void push(string name) {
        SoldCar* car = new SoldCar;
        car->name = name;
        car->next = top;
        top = car;
    }

    void view() {
        if (top == NULL) {
            cout << "No sold cars.\n";
            return;
        }
        cout << "\n===== Recently Sold Cars =====\n";
        while (top != NULL) {
            cout << "- " << top->name << "\n";
            top = top->next;
        }
        cout << "=============================\n";
    }
};
class SparePartsStore {
    SparePart* head;
public:
    SparePartsStore() {
        head = NULL;
    }

    void addPart(int id, string name, float price) {
        SparePart* newPart = new SparePart;
        newPart->id = id;
        newPart->name = name;
        newPart->price = price;
        newPart->next = head;
        head = newPart;
    }
    void viewParts() {
        SparePart* temp = head;
        if (temp == NULL) {
            cout << "No spare parts available.\n";
            return;
        }
        cout << "\n===== Available Spare Parts =====\n";
        while (temp != NULL) {
            cout << "ID: " << temp->id << " | Name: " << temp->name << " | Price: RS " << temp->price << "\n";
            temp = temp->next;
        }
        cout << "==============================\n";
    }
    void buyPart(int id) {
        SparePart* temp = head;
        while (temp != NULL && temp->id != id) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Part not found.\n";
            return;
        }

        int quantity;
        cout << "Enter quantity: ";
        while (!(cin >> quantity) || quantity <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer for quantity: ";
        }

        float total = quantity * temp->price;
        cout << "You bought " << quantity << " x " << temp->name << " for RS " << total << "\n";
    }
    void returnPart(int id) {
        SparePart* temp = head;
        while (temp != NULL && temp->id != id) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Part not found.\n";
            return;
        }

        int quantity;
        cout << "Enter quantity to return: ";
        while (!(cin >> quantity) || quantity <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer for quantity: ";
        }

        float refund = quantity * temp->price;
        cout << "You returned " << quantity << " x " << temp->name << "    Refund of RS " << refund << "\n";
    }
    void exchangePart(int buyId, int exchangeId) {
        SparePart* buyPart = NULL;
        SparePart* exchangePart = NULL;

        SparePart* temp = head;
        while (temp != NULL) {
            if (temp->id == buyId)
                buyPart = temp;
            if (temp->id == exchangeId)
                exchangePart = temp;
            temp = temp->next;
        }

        if (buyPart == NULL || exchangePart == NULL) {
            cout << "Invalid parts for exchange.\n";
            return;
        }

        float priceDifference = exchangePart->price - buyPart->price;
        if (priceDifference > 0) {
            cout << "You need to pay an additional RS " << priceDifference << " for the exchange.\n";
        } else if (priceDifference < 0) {
            cout << "You will get a refund of RS " << -priceDifference << " for the exchange.\n";
        } else {
            cout << "The parts are of the same value. No additional payment required.\n";
        }
    }
};
int main() {
    Inventory inv;
    SoldStack sold;
    SparePartsStore partsStore;  
    inv.addCar(101, "Toyota Camry    ", 25000);
    inv.addCar(102, "Honda Civic     ", 22000);
    inv.addCar(103, "Ford Mustang    ", 35000);
    inv.addCar(104, "Tesla Model 3   ", 45000);
    inv.addCar(105, "Chevrolet Malibu", 24000);
    inv.addCar(106, "BMW 3 Series    ", 41000);
    inv.addCar(107, "Audi A4         ", 43000);
    inv.addCar(108, "Hyundai Elantra ", 20000);
    inv.addCar(109, "Kia Sportage    ", 27000);
    inv.addCar(110, "Nissan Altima   ", 23000);
    partsStore.addPart(201, "Air Filter      ", 800);
    partsStore.addPart(202, "Oil Filter      ", 500);
    partsStore.addPart(203, "Brake Pads      ", 800);
    partsStore.addPart(204, "Spark Plugs     ", 200);
    partsStore.addPart(205, "Battery         ", 3500);

    int choice;
    do {
        cout << "\n===== Automobile Sales and Service Tracker =====\n";
        cout << "1. Add Car to Inventory\n";
        cout << "2. View Cars\n";
        cout << "3. Delete Car (Sold)\n";
        cout << "4. View Recently Sold Cars\n";
        cout << "5. View Spare Parts\n";
        cout << "6. Buy Spare Part\n";
        cout << "7. Return Spare Part\n";
        cout << "8. Exchange Spare Part\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        while (!(cin >> choice) || choice < 0 || choice > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid choice (0-9): ";
        }
        if (choice == 1) {
            int id;
            string name;
            float price;
            cout << "Enter Car ID: "; cin >> id;
            cin.ignore();
            cout << "Enter Car Name: "; getline(cin, name);
            cout << "Enter Car Price: "; cin >> price;
            inv.addCar(id, name, price);
        }
        else if (choice == 2) {
            inv.viewCars();
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Car ID to delete: ";
            cin >> id;
            if (inv.carExists(id)) {
                string name = inv.getCarName(id);
                inv.deleteCar(id);
                sold.push(name);
            } else {
                cout << "Car not found.\n";
            }
        }
        else if (choice == 4) {
            sold.view();
        }
        else if (choice == 5) {
            partsStore.viewParts();
        }
        else if (choice == 6) {
            int id;
            cout << "\n===== Available Spare Parts =====\n";
            partsStore.viewParts();
            cout << "Enter Part ID to buy: ";
            cin >> id;
            partsStore.buyPart(id);
        }
        else if (choice == 7) {
            int id;
            cout << "Enter Part ID to return: ";
            cin >> id;
            partsStore.returnPart(id);
        }
        else if (choice == 8) {
            int buyId, exchangeId;
            cout << "Enter Part ID to exchange: ";
            cin >> buyId;
            cout << "Enter Part ID to exchange with: ";
            cin >> exchangeId;
            partsStore.exchangePart(buyId, exchangeId);
        }
        else if (choice == 0) {
            cout << "Exiting system...\n";
        }
        else {
            cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);
    return 0;
}
