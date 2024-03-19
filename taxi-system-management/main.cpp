//
//  main.cpp
//  taxi-system-management
//
//  Created by Andrzej Zwirko on 12/03/2024.
//
#include "Header.h"


int main() {
    setlocale(LC_ALL, "");
    TaxiCompany company;

    int choice;
    bool exit = false;

    while (!exit) {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                hireDriver(company);
                break;
            case 2:
                addCar(company);
                break;
            case 3:
                placeOrder(company);
                break;
            case 4:
                showDrivers(company);
                break;
            case 5:
                cout << "Całkowity zarobek: " << calculateTotalEarnings(company) << endl;
                break;
            case 6:
                exit = true;
                clearMemory(company);
                break;
            default:
                cout << "Nieprawidłowy wybór. Spróbuj ponownie." << endl;
        }
    }

    return 0;
}
