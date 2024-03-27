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
                hireDriver(company.getDrivers(), company.getDriverCount());
                break;
            case 2:
                deleteDriver(company.getDrivers(), company.getDriverCount());
                break;
            case 3:
                addCar(company.getCars(), company.getCarCount());
                break;
            case 4:
                deleteCar(company.getCars(), company.getCarCount());
                break;
            case 5:
                placeOrder(company.getOrders(), company.getOrderCount());
                break;
            case 6:
                completeOrder(company.getOrders(), company.getOrderCount(), company);
                break;
            case 7:
                deleteAllOrders(company.getOrders(), company.getOrderCount());
                break;
            case 8:
                showDrivers(company);
                break;
            case 9:
                showOrders(company);
                break;
            case 10:
                showCars(company);
                break;
            case 11:
                cout << "Całkowity zarobek: " << calculateTotalEarnings(company) << endl << endl;
                break;
            case 12:
                generateAllData(company);
                break;
            case 13:
                parsingPlaceOrder (company.getOrders(), company.getOrderCount());
                break;
            case 14:
                exit = true;
                clearMemory(company);
                break;
            default:
                cout << "Nieprawidłowy wybór. Spróbuj ponownie." << endl;
        }
    }

    return 0;
}
