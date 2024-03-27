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
        string firstName, lastName;
        int numberLicense, experience;
        newDriver[size] = new Driver;
        cout << "Podaj imię kierowcy: ";
        cin >> firstName;
        newDriver[size]->setDriverFirstName(firstName);
        cout << "Podaj nazwisko kierowcy: ";
        cin >> lastName;
        newDriver[size]->setDriverLastName(lastName);
        cout << "Podaj numer licencji kierowcy (5 cyfr): ";
        cin >> numberLicense;
        while((numberLicense < 10000) || (numberLicense > 99999)) {
            cout << "Numer licencji ma nieprawidłową ilość znaków, podaj ponownie (5 cyfr): ";
            cin >> numberLicense;
        }
        newDriver[size]->setLicenseNumber(numberLicense);
        cout << "Podaj doświadczenie kierowcy (lata) (maksymalnie 2 cyfry): ";
        cin >> experience;
        while (experience < 1 || experience > 99) {
            cout << "Kłamiesz ze swoim doświadczeniem, podaj prawidłowe! (maksymalnie 2 cyfry): ";
            cin >> experience;
        }
        newDriver[size]->setExperience(experience);
    }
    else {
        for (int i = 0; i < size; i++) {
            newDriver[i] = driver[i];
        }
        string firstName, lastName;
        int numberLicense, experience;
        newDriver[size] = new Driver;
        cout << "Podaj imię kierowcy: ";
        cin >> firstName;
        newDriver[size]->setDriverFirstName(firstName);
        cout << "Podaj nazwisko kierowcy: ";
        cin >> lastName;
        newDriver[size]->setDriverLastName(lastName);
        cout << "Podaj numer licencji kierowcy (5 cyfr): ";
        cin >> numberLicense;
        while((numberLicense < 10000) || (numberLicense > 99999)) {
            cout << "Numer licencji ma nieprawidłową ilość znaków, podaj ponownie (5 cyfr): ";
            cin >> numberLicense;
        }
        newDriver[size]->setLicenseNumber(numberLicense);
        cout << "Podaj doświadczenie kierowcy (lata) (maksymalnie 2 cyfry): ";
        cin >> experience;
        while (experience < 1 || experience > 99) {
            cout << "Kłamiesz ze swoim doświadczeniem, podaj prawidłowe! (maksymalnie 2 cyfry): ";
            cin >> experience;
        }
        newDriver[size]->setExperience(experience);
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
        if(idLicense == driver[i]->getLicenseNumber()) {
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
        string brand, model, plateNumber;
        newCar[size] = new Car;
        cout << "Podaj markę samochodu: ";
        cin >> brand;
        newCar[size]->setBrand(brand);
        cout << "Podaj model samochodu: ";
        cin >> model;
        newCar[size]->setModel(model);
        cout << "Podaj numer rejestracyjny samochodu (5 cyfr): ";
        cin >> plateNumber;
        while(plateNumber.length() != 5) {
            cout << "Numer rejestracyjny nieprawidłowy, podaj ponownie (5 cyfr): ";
            cin >> plateNumber;
        }
        newCar[size]->setPlateNumber(brand);
    }
    else {
        for (int i = 0; i < size; i++) {
            newCar[i] = car[i];
        }
        string brand, model, plateNumber;
        newCar[size] = new Car;
        cout << "Podaj markę samochodu: ";
        cin >> brand;
        newCar[size]->setBrand(brand);
        cout << "Podaj model samochodu: ";
        cin >> model;
        newCar[size]->setModel(model);
        cout << "Podaj numer rejestracyjny samochodu (5 cyfr): ";
        cin >> plateNumber;
        while(plateNumber.length() != 5) {
            cout << "Numer rejestracyjny nieprawidłowy, podaj ponownie (5 cyfr): ";
            cin >> plateNumber;
        }
        newCar[size]->setPlateNumber(brand);
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
        if(idLicense.compare(car[i]->getPlateNumber()) == 0) {
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
        string firstName, lastName, pickupLocation, dropoffLocation;
        int amount;
        newOrder[size] = new Order;
        cout << "Podaj imię klienta: ";
        cin >> firstName;
        newOrder[size]->setCustomerFirstName(firstName);
        cout << "Podaj nazwisko klienta: ";
        cin >> lastName;
        newOrder[size]->setCustomerLastName(lastName);
        cout << "Podaj miejsce odbioru: ";
        cin >> pickupLocation;
        newOrder[size]->setPickupLocation(pickupLocation);
        cout << "Podaj miejsce docelowe: ";
        cin >> dropoffLocation;
        newOrder[size]->setDropOffLocation(dropoffLocation);
        cout << "Podaj kwotę zamówienia: ";
        cin >> amount;
        newOrder[size]->setOrderId(size);
        newOrder[size]->setAmount(amount);
        newOrder[size]->setCompleted(false);
    }
    else {
        for (int i = 0; i < size; i++) {
            newOrder[i] = order[i];
        }
        string firstName, lastName, pickupLocation, dropoffLocation;
        int amount;
        newOrder[size] = new Order;
        cout << "Podaj imię klienta: ";
        cin >> firstName;
        newOrder[size]->setCustomerFirstName(firstName);
        cout << "Podaj nazwisko klienta: ";
        cin >> lastName;
        newOrder[size]->setCustomerLastName(lastName);
        cout << "Podaj miejsce odbioru: ";
        cin >> pickupLocation;
        newOrder[size]->setPickupLocation(pickupLocation);
        cout << "Podaj miejsce docelowe: ";
        cin >> dropoffLocation;
        newOrder[size]->setDropOffLocation(dropoffLocation);
        cout << "Podaj kwotę zamówienia: ";
        cin >> amount;
        newOrder[size]->setOrderId(size);
        newOrder[size]->setAmount(amount);
        newOrder[size]->setCompleted(false);
        delete[] order;
    }
    order = newOrder;
    size++;
    cout << "Dodano nowe zamówienie." << endl << endl;
}

void deleteAllOrders(Order**& order, int &size) {
    int idCompleted = 0;
    for (int i = 0; i < size; i++) {
        if (order[i]->getCompleted() == true) {
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
            if (order[i]->getCompleted() == false) {
                newOrder[j] = newOrder[i];
                newOrder[j]->setOrderId(j);
                j++;
            }
        }
        delete[] order;
        order = newOrder;
        size = size - idCompleted;
        cout << "Usunięto " << idCompleted << "zamówienia" << endl << endl;
    }
}

double calculateTotalEarnings(TaxiCompany& company) {
    double totalEarnings = 0;
    for (int i = 0; i < company.getOrderCount(); ++i) {
        totalEarnings += company.getOneOrder(i)->getAmount();
    }
    return totalEarnings;
}

void showDrivers(TaxiCompany& company) {
    cout << endl << "=== LISTA KIEROWCÓW ===" << endl << endl;
    for (int i = 0; i < company.getDriverCount(); ++i) {
        cout << "Imię i nazwisko: " << company.getOneDriver(i)->getDriverFirstName() << " " << company.getOneDriver(i)->getDriverFirstName() << endl;
        cout << "Numer licencji: " << company.getOneDriver(i)->getLicenseNumber() << endl;
        cout << "Doświadczenie (lata): " << company.getOneDriver(i)->getExperience() << endl << endl;
    }
}

void showOrders(TaxiCompany& company) {
    cout << endl << "=== LISTA ZAMÓWIEŃ ===" << endl;
    for (int i = 0; i<company.getOrderCount(); i++) {
        cout << "Imię i nazwisko: " << company.getOneOrder(i)->getCustomerFirstName() << " " << company.getOneOrder(i)->getCustomerLastName() << endl;
        cout << "Miejsce odbioru: " << company.getOneOrder(i)->getPickupLocation() << endl;
        cout << "Miejsce docelowe: " << company.getOneOrder(i)->getDropOffLocation() << endl;
        cout << "Id: " << company.getOneOrder(i)->getOrderId() << endl;
        cout << "Koszt: " << company.getOneOrder(i)->getAmount() << endl;
        cout << "Status zamówienia: ";
        if (company.getOneOrder(i)->getCompleted() == false) {
            cout << "Niezrealizowany" << endl << endl;
        }
        else {
            cout << "Zrealizowany" << endl << endl;
        }
    }
}

void showCars(TaxiCompany& company) {
    cout << endl << "=== FLOTA POJAZDÓW ===" << endl << endl;
    for (int i = 0; i < company.getCarCount(); ++i) {
        cout << "Marka: " << company.getOneCar(i)->getBrand() << endl;
        cout << "Model: " << company.getOneCar(i)->getModel() << endl;
        cout << "Numer rejestracyjny: " << company.getOneCar(i)->getPlateNumber() << endl << endl;
    }
}

void clearMemory(TaxiCompany& company) {
    for (int i = 0; i < company.getDriverCount(); ++i) {
        delete company.getOneDriver(i);
    }

    for (int i = 0; i < company.getCarCount(); ++i) {
        delete company.getOneCar(i);
    }

    for (int i = 0; i < company.getOrderCount(); ++i) {
        delete company.getOneOrder(i);
    }
}

void completeOrder(Order**& orders, int &size, TaxiCompany &company) {
    showOrders(company);
    int id;
    cout << "Podaj id zamówienia: ";
    cin >> id;
    for (int i = 0; i < size; i++) {
        if (orders[i]->getOrderId() == id) {
            orders[i]->setCompleted(true);
            break;
        }
    }
}

void showMenu() {
    cout << "=== MENU ===" << endl;
    cout << "1. Zatrudnij nowego kierowcę" << endl;
    cout << "2. Usuń kierowcę." << endl;
    cout << "3. Dodaj nowy samochód" << endl;
    cout << "4. Usuń samochód." << endl;
    cout << "5. Dodaj zamówienie" << endl;
    cout << "6. Zmień status zamówienia na zakończony" << endl;
    cout << "7. Usuń wszystkie zakończone zamówienia" << endl;
    cout << "8. Wyświetl listę kierowców" << endl;
    cout << "9. Wyświetl listę zamówień" << endl;
    cout << "10. Wyświetl flotę pojazdów" << endl;
    cout << "11. Oblicz całkowity zarobek" << endl;
    cout << "12. Generuj bazę danych" << endl;
    cout << "13. Dodaj zamówienie (z opcją parsowania)" << endl;
    cout << "14. Wyjście" << endl;
    cout << "Wybierz opcję: ";
}
