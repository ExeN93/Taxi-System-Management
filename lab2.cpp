//
//  lab2.cpp
//  taxi-system-management
//
//  Created by Andrzej Zwirko on 19/03/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

string_view imiona[8] = { "Adam", "Anna", "Jan", "Maria", "Piotr", "Ewa", "Krzysztof", "Agnieszka" };
string_view nazwiska[8] = { "Nowak", "Kowalski", "Wisniewski", "Wojcik", "Kowalczyk", "Kaminski", "Lewandowski", "Zielinska" };
string_view markiAut[6] = { "AUDI", "BMW", "TOYOTA", "MERCEDES", "VOLVO", "HYUNDAI" };
string_view modeleAut[6] = { "A4", "A6", "SERIA 5", "SERIA 3", "SERIA 1", "A3" };
string_view numerRejestracyjnyAuta[7] = { "ZDR 20332", "ZS 23213", "WE 32323", "ZKO 32313", "ZGR SA323", "DW XYZ23", "EL 32132"};
string_view miejscaDocelowe[7] = { "Stocznia", "Kołątaja", "Bukowe", "Chopina", "Jaśminowa", "Meksyk", "Arkońska"};
string_view miejscaOdbioru[7] = { "Stocznia", "Kołątaja", "Bukowe", "Chopina", "Jaśminowa", "Meksyk", "Arkońska"};

void generateAllData(TaxiCompany& company) {
    static random_device rd;
    static default_random_engine engine(rd());
    static uniform_int_distribution<int> num(5, 15);
    int size = num(engine);
    for(int i=0; i<size; i++) {
        if (company.driverCount >= MAX_DRIVERS) {
                cout << "Nie można dodać więcej kierowców. Limit osiągnięty." << endl;
                return;
            }
        Driver* newDriver = new Driver;
        
        static uniform_int_distribution<int> imie(0, 7);
        static uniform_int_distribution<int> nazwisko(0, 7);
        size_t indexImie = imie(engine);
        size_t indexNazwisko = nazwisko(engine);
        newDriver->driverName.firstName = imiona[indexImie];
        newDriver->driverName.lastName = nazwiska[indexNazwisko];
        
        static uniform_int_distribution<int> numerLicencji(0, 99999);
        newDriver->licenseNumber = to_string(numerLicencji(engine));
        
        static uniform_int_distribution<int> doswiadczenie(0, 99);
        newDriver->experience = doswiadczenie(engine);
        
        company.drivers[company.driverCount++] = newDriver;
        cout << "Dodano nowego kierowcę." << endl;
    }
    for(int i=0; i<size; i++) {
        if (company.carCount >= MAX_CARS) {
                cout << "Nie można dodać więcej aut. Limit osiągnięty." << endl;
                return;
            }
        Car* newCar = new Car;
        static uniform_int_distribution<int> marka(0, 5);
        static uniform_int_distribution<int> model(0, 5);
        static uniform_int_distribution<int> numerRejestracyjny(0, 6);
        size_t indexMarkaAuta = marka(engine);
        size_t indexModelAuta = model(engine);
        size_t indexNumerRejestracyjnyAuta = numerRejestracyjny(engine);
        newCar->brand = markiAut[indexMarkaAuta];
        newCar->model = modeleAut[indexModelAuta];
        newCar->plateNumber = numerRejestracyjnyAuta[indexNumerRejestracyjnyAuta];
        
        company.cars[company.carCount++] = newCar;
        cout << "Dodano nowy samochód." << endl;
    }
    for(int i=0; i<size; i++) {
        if (company.orderCount >= MAX_ORDERS) {
                cout << "Nie można dodać więcej zamówień. Limit osiągnięty." << endl;
                return;
            }
        Order* newOrder = new Order;
        static uniform_int_distribution<int> imie(0, 7);
        static uniform_int_distribution<int> nazwisko(0, 7);
        static uniform_int_distribution<int> miejsceOdbioru(0, 6);
        static uniform_int_distribution<int> miejsceDocelowe(0, 6);
        size_t indexImie = imie(engine);
        size_t indexNazwisko = nazwisko(engine);
        size_t indexMiejsceOdbioru = miejsceOdbioru(engine);
        size_t indexMiejsceDocelowe = miejsceDocelowe(engine);
        newOrder->customerName.firstName = imiona[indexImie];
        newOrder->customerName.lastName = nazwiska[indexNazwisko];
        newOrder->pickupLocation = miejscaOdbioru[indexMiejsceOdbioru];
        newOrder->dropoffLocation = miejscaDocelowe[indexMiejsceDocelowe];
    
        static uniform_int_distribution<int> kwota(0, 100);
        newOrder->amount = kwota(engine);
    
        newOrder->completed = false;
        
        company.orders[company.orderCount++] = newOrder;
        cout << "Dodano nowe zamówienie." << endl;
    }
}


