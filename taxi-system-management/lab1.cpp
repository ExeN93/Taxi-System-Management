//
//  lab1.cpp
//  taxi-system-management
//
//  Created by Andrzej Zwirko on 19/03/2024.
//

#include <stdio.h>
#include "Header.h"

// Funkcje operujące na strukturze TaxiCompany
void hireDriver(TaxiCompany& company) {
    if (company.driverCount >= MAX_DRIVERS) {
        cout << "Nie można dodać więcej kierowców. Limit osiągnięty." << endl;
        return;
    }

    Driver* newDriver = new Driver;
    cout << "Podaj imię kierowcy: ";
    cin >> newDriver->driverName.firstName;
    cout << "Podaj nazwisko kierowcy: ";
    cin >> newDriver->driverName.lastName;
    cout << "Podaj numer licencji kierowcy (5 cyfr): ";
    cin >> newDriver->licenseNumber;
    while(newDriver->licenseNumber.length() != 5) {
        cout << "Numer licencji ma nieprawidłową ilość znaków, podaj ponownie (5 cyfr): ";
        cin >> newDriver->licenseNumber;
    }
    cout << "Podaj doświadczenie kierowcy (lata) (maksymalnie 2 cyfry): ";
    cin >> newDriver->experience;
    while (newDriver->experience < 1 || newDriver->experience > 99) {
        cout << "Kłamiesz ze swoim doświadczeniem, podaj prawidłowe! (maksymalnie 2 cyfry): ";
        cin >> newDriver->experience;
    }
    company.drivers[company.driverCount++] = newDriver;
    cout << "Dodano nowego kierowcę." << endl;
}

void addCar(TaxiCompany& company) {
    if (company.carCount >= MAX_CARS) {
        cout << "Nie można dodać więcej samochodów. Limit osiągnięty." << endl;
        return;
    }

    Car* newCar = new Car;
    cout << "Podaj markę samochodu: ";
    cin >> newCar->brand;
    cout << "Podaj model samochodu: ";
    cin >> newCar->model;
    cout << "Podaj numer rejestracyjny samochodu (5 cyfr): ";
    cin >> newCar->plateNumber;
    while(newCar->plateNumber.length() != 5) {
        cout << "Numer rejestracyjny nieprawidłowy, podaj ponownie (5 cyfr): ";
        cin >> newCar->plateNumber;
    }
    company.cars[company.carCount++] = newCar;
    cout << "Dodano nowy samochód." << endl;
}

void placeOrder(TaxiCompany& company) {
    if (company.orderCount >= MAX_ORDERS) {
        cout << "Nie można dodać więcej zamówień. Limit osiągnięty." << endl;
        return;
    }

    Order* newOrder = new Order;
    cout << "Podaj imię klienta: ";
    cin >> newOrder->customerName.firstName;
    cout << "Podaj nazwisko klienta: ";
    cin >> newOrder->customerName.lastName;
    cout << "Podaj miejsce odbioru: ";
    cin >> newOrder->pickupLocation;
    cout << "Podaj miejsce docelowe: ";
    cin >> newOrder->dropoffLocation;
    cout << "Podaj kwotę zamówienia: ";
    cin >> newOrder->amount;
    newOrder->completed = false;
    company.orders[company.orderCount++] = newOrder;
    cout << "Zamówienie złożone pomyślnie." << endl;
}

double calculateTotalEarnings(const TaxiCompany& company) {
    double totalEarnings = 0;
    for (int i = 0; i < company.orderCount; ++i) {
        totalEarnings += company.orders[i]->amount;
    }
    return totalEarnings;
}

void showDrivers(const TaxiCompany& company) {
    cout << "=== LISTA KIEROWCÓW ===" << endl;
    for (int i = 0; i < company.driverCount; ++i) {
        cout << "Imię i nazwisko: " << company.drivers[i]->driverName.firstName << " " << company.drivers[i]->driverName.lastName << endl;
        cout << "Numer licencji: " << company.drivers[i]->licenseNumber << endl;
        cout << "Doświadczenie (lata): " << company.drivers[i]->experience << endl << endl;
    }
}

void clearMemory(TaxiCompany& company) {
    for (int i = 0; i < company.driverCount; ++i) {
        delete company.drivers[i];
    }

    for (int i = 0; i < company.carCount; ++i) {
        delete company.cars[i];
    }

    for (int i = 0; i < company.orderCount; ++i) {
        delete company.orders[i];
    }
}

void showMenu() {
    cout << "=== MENU ===" << endl;
    cout << "1. Zatrudnij nowego kierowcę" << endl;
    cout << "2. Dodaj nowy samochód" << endl;
    cout << "3. Dodaj zamówienie" << endl;
    cout << "4. Wyświetl listę kierowców" << endl;
    cout << "5. Oblicz całkowity zarobek" << endl;
    cout << "6. Wyjście" << endl;
    cout << "Wybierz opcję: ";
}
