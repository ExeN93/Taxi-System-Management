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
    company.drivers = nullptr;
    company.cars = nullptr;
    company.orders = nullptr;

    int choice;
    bool exit = false;

    while (!exit) {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                hireDriver(company.drivers, company.driverCount);
                break;
            case 2:
                deleteDriver(company.drivers, company.driverCount);
                break;
            case 3:
                addCar(company.cars, company.carCount);
                break;
            case 4:
                deleteCar(company.cars, company.carCount);
                break;
            case 5:
                placeOrder(company.orders, company.orderCount);
                break;
            case 6:
                deleteAllOrders(company.orders, company.orderCount);
                break;
            case 7:
                showDrivers(company);
                break;
            case 8:
                showOrders(company);
                break;
            case 9:
                showCars(company);
                break;
            case 10:
                cout << "Całkowity zarobek: " << calculateTotalEarnings(company) << endl << endl;
                break;
            case 11:
                generateAllData(company);
                break;
            case 12:
                parsingPlaceOrder (company.orders, company.orderCount);
                break;
            case 13:
                exit = true;
                clearMemory(company);
                break;
            default:
                cout << "Nieprawidłowy wybór. Spróbuj ponownie." << endl;
        }
    }

    return 0;
}
