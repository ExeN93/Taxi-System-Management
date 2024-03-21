//
//  lab1.cpp
//  taxi-system-management
//
//  Created by Andrzej Zwirko on 19/03/2024.
//

#include <stdio.h>
#include "Header.h"

// Funkcje operujące na strukturze TaxiCompany
void hireDriver(Driver**& driver, int &size) {
    Driver** newDriver = new Driver * [size + 1];
    if (size == 0) {
        newDriver[size] = new Driver;
        cout << "Podaj imię kierowcy: ";
        cin >> newDriver[size]->driverName.firstName;
        cout << "Podaj nazwisko kierowcy: ";
        cin >> newDriver[size]->driverName.lastName;
        cout << "Podaj numer licencji kierowcy (5 cyfr): ";
        cin >> newDriver[size]->licenseNumber;
        while((newDriver[size]->licenseNumber < 10000) || (newDriver[size]->licenseNumber > 99999)) {
            cout << "Numer licencji ma nieprawidłową ilość znaków, podaj ponownie (5 cyfr): ";
            cin >> newDriver[size]->licenseNumber;
        }
        cout << "Podaj doświadczenie kierowcy (lata) (maksymalnie 2 cyfry): ";
        cin >> newDriver[size]->experience;
        while (newDriver[size]->experience < 1 || newDriver[size]->experience > 99) {
            cout << "Kłamiesz ze swoim doświadczeniem, podaj prawidłowe! (maksymalnie 2 cyfry): ";
            cin >> newDriver[size]->experience;
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            newDriver[i] = driver[i];
        }
        newDriver[size] = new Driver;
        cout << "Podaj imię kierowcy: ";
        cin >> newDriver[size]->driverName.firstName;
        cout << "Podaj nazwisko kierowcy: ";
        cin >> newDriver[size]->driverName.lastName;
        cout << "Podaj numer licencji kierowcy (5 cyfr): ";
        cin >> newDriver[size]->licenseNumber;
        while((newDriver[size]->licenseNumber < 10000) || (newDriver[size]->licenseNumber > 99999)) {
            cout << "Numer licencji ma nieprawidłową ilość znaków, podaj ponownie (5 cyfr): ";
            cin >> newDriver[size]->licenseNumber;
        }
        cout << "Podaj doświadczenie kierowcy (lata) (maksymalnie 2 cyfry): ";
        cin >> newDriver[size]->experience;
        while (newDriver[size]->experience < 1 || newDriver[size]->experience > 99) {
            cout << "Kłamiesz ze swoim doświadczeniem, podaj prawidłowe! (maksymalnie 2 cyfry): ";
            cin >> newDriver[size]->experience;
        }
        delete[] driver;
    }
    driver = newDriver;
    size++;
    cout << "Dodano nowego kierowcę." << endl << endl;
    
}

void deleteDriver(Driver**& driver, int &size) {
    cout << "Podaj numer licencji: ";
    int idLicense;
    int index = -1;
    cin >> idLicense;
    for (int i = 0; i < size; i++) {
        if(idLicense == driver[i]->licenseNumber) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Podałeś zły numer licencji." << endl;
    }
    else {
        Driver** newDriver = new Driver * [size - 1];
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (index != i) {
                newDriver[j] = driver[i];
                j++;
            }
        }
        delete[] driver;
        driver = newDriver;
        size--;
    }
    cout << "Usunięto kierowce." << endl << endl;
 }

void addCar(Car**& car, int &size) {
    Car** newCar = new Car * [size + 1];
    if (size == 0) {
        newCar[size] = new Car;
        cout << "Podaj markę samochodu: ";
        cin >> newCar[size]->brand;
        cout << "Podaj model samochodu: ";
        cin >> newCar[size]->model;
        cout << "Podaj numer rejestracyjny samochodu (5 cyfr): ";
        cin >> newCar[size]->plateNumber;
        while(newCar[size]->plateNumber.length() != 5) {
            cout << "Numer rejestracyjny nieprawidłowy, podaj ponownie (5 cyfr): ";
            cin >> newCar[size]->plateNumber;
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            newCar[i] = car[i];
        }
        newCar[size] = new Car;
        cout << "Podaj markę samochodu: ";
        cin >> newCar[size]->brand;
        cout << "Podaj model samochodu: ";
        cin >> newCar[size]->model;
        cout << "Podaj numer rejestracyjny samochodu (5 cyfr): ";
        cin >> newCar[size]->plateNumber;
        while(newCar[size]->plateNumber.length() != 5) {
            cout << "Numer rejestracyjny nieprawidłowy, podaj ponownie (5 cyfr): ";
            cin >> newCar[size]->plateNumber;
        }
        delete[] car;
    }
    car = newCar;
    size++;
    cout << "Dodano nowy samochód." << endl << endl;
}

void deleteCar(Car**& car, int &size) {
    cout << "Podaj numer rejestracyjny samochodu: ";
    string idLicense;
    int index = -1;
    cin >> idLicense;
    for (int i = 0; i < size; i++) {
        if(idLicense.compare(car[i]->plateNumber) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Podałeś zły numer rejestracyjny." << endl;
    }
    else {
        Car** newCar = new Car * [size - 1];
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (index != i) {
                newCar[j] = car[i];
                j++;
            }
        }
        delete[] car;
        car = newCar;
        size--;
    }
    cout << "Usunięto samochód." << endl << endl;
 }

void placeOrder(Order**& order, int &size) {
    Order** newOrder = new Order * [size + 1];
    if (size == 0) {
        newOrder[size] = new Order;
        cout << "Podaj imię klienta: ";
        cin >> newOrder[size]->customerName.firstName;
        cout << "Podaj nazwisko klienta: ";
        cin >> newOrder[size]->customerName.lastName;
        cout << "Podaj miejsce odbioru: ";
        cin >> newOrder[size]->pickupLocation;
        cout << "Podaj miejsce docelowe: ";
        cin >> newOrder[size]->dropoffLocation;
        cout << "Podaj kwotę zamówienia: ";
        cin >> newOrder[size]->amount;
        newOrder[size]->completed = false;
    }
    else {
        for (int i = 0; i < size; i++) {
            newOrder[i] = order[i];
        }
        cout << "Podaj imię klienta: ";
        cin >> newOrder[size]->customerName.firstName;
        cout << "Podaj nazwisko klienta: ";
        cin >> newOrder[size]->customerName.lastName;
        cout << "Podaj miejsce odbioru: ";
        cin >> newOrder[size]->pickupLocation;
        cout << "Podaj miejsce docelowe: ";
        cin >> newOrder[size]->dropoffLocation;
        cout << "Podaj kwotę zamówienia: ";
        cin >> newOrder[size]->amount;
        newOrder[size]->completed = false;
        delete[] order;
    }
    order = newOrder;
    size++;
    cout << "Dodano nowe zamówienie." << endl << endl;
}

void deleteAllOrders(Order**& order, int &size) {
    int idCompleted = 0;
    for (int i = 0; i < size; i++) {
        if (order[i]->completed == true) {
            idCompleted++;
        }
    }
    if (idCompleted == 0) {
        cout << "Nie ma żadnego zamówienia do usunięcia. " << endl;
        return;
    }
    else {
        Order** newOrder = new Order * [size - idCompleted];
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (order[i]->completed == false) {
                newOrder[j] = newOrder[i];
            }
        }
        delete[] order;
        order = newOrder;
        size = size - idCompleted;
        cout << "Usunięto " << idCompleted << "zamówienia" << endl << endl;
    }
}

double calculateTotalEarnings(const TaxiCompany& company) {
    double totalEarnings = 0;
    for (int i = 0; i < company.orderCount; ++i) {
        totalEarnings += company.orders[i]->amount;
    }
    return totalEarnings;
}

void showDrivers(const TaxiCompany& company) {
    cout << endl << "=== LISTA KIEROWCÓW ===" << endl << endl;
    for (int i = 0; i < company.driverCount; ++i) {
        cout << "Imię i nazwisko: " << company.drivers[i]->driverName.firstName << " " << company.drivers[i]->driverName.lastName << endl;
        cout << "Numer licencji: " << company.drivers[i]->licenseNumber << endl;
        cout << "Doświadczenie (lata): " << company.drivers[i]->experience << endl << endl;
    }
}

void showOrders(const TaxiCompany& company) {
    cout << endl << "=== LISTA ZAMÓWIEŃ ===" << endl;
    for (int i = 0; i<company.orderCount; i++) {
        cout << "Imię i nazwisko: " << company.orders[i]->customerName.firstName << " " << company.orders[i]->customerName.lastName << endl;
        cout << "Miejsce odbioru: " << company.orders[i]->pickupLocation << endl;
        cout << "Miejsce docelowe: " << company.orders[i]->dropoffLocation << endl;
        cout << "Koszt: " << company.orders[i]->amount << endl;
        cout << "Status zamówienia: ";
        if (company.orders[i]->completed == false) {
            cout << "Niezrealizowany" << endl << endl;
        }
        else {
            cout << "Zrealizowany" << endl << endl;
        }
    }
}

void showCars(const TaxiCompany& company) {
    cout << endl << "=== FLOTA POJAZDÓW ===" << endl << endl;
    for (int i = 0; i < company.carCount; ++i) {
        cout << "Marka: " << company.cars[i]->brand << endl;
        cout << "Model: " << company.cars[i]->model << endl;
        cout << "Numer rejestracyjny: " << company.cars[i]->plateNumber << endl << endl;
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
    cout << "2. Usuń kierowcę." << endl;
    cout << "3. Dodaj nowy samochód" << endl;
    cout << "4. Usuń samochód." << endl;
    cout << "5. Dodaj zamówienie" << endl;
    cout << "6. Usuń wszystkie zakończone zamówienia." << endl;
    cout << "7. Wyświetl listę kierowców" << endl;
    cout << "8. Wyświetl listę zamówień" << endl;
    cout << "9. Wyświetl flotę pojazdów" << endl;
    cout << "10. Oblicz całkowity zarobek" << endl;
    cout << "11. Generuj bazę danych" << endl;
    cout << "12. Dodaj zamówienie (z opcją parsowania)" << endl;
    cout << "13. Wyjście" << endl;
    cout << "Wybierz opcję: ";
}

