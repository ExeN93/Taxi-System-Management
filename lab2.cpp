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
string_view modeleAut[6] = { "A4", "A6", "A8", "A2", "A7", "A3" };
string_view numerRejestracyjnyAuta[7] = { "20332", "23213", "32323", "32313", "55555", "55523", "32132"};
string_view miejscaDocelowe[7] = { "Stocznia", "Kołątaja", "Bukowe", "Chopina", "Jaśminowa", "Meksyk", "Arkońska"};
string_view miejscaOdbioru[7] = { "Portowa", "Mieszka", "Potulicka", "Felczaka", "Pleciuga", "Klonowica", "Wernyhory"};

void generateAllData(TaxiCompany& company) {
    static random_device rd;
    static default_random_engine engine(rd());
    static uniform_int_distribution<int> num(5, 15);
    int size = num(engine);
    Driver** newDriver = new Driver * [size];
    for(int i=0; i<size; i++) {
        newDriver[i] = new Driver;
        static uniform_int_distribution<int> imie(0, 7);
        static uniform_int_distribution<int> nazwisko(0, 7);
        size_t indexImie = imie(engine);
        size_t indexNazwisko = nazwisko(engine);
        newDriver[i]->setDriverFirstName(string(imiona[indexImie]));
        newDriver[i]->setDriverLastName(string(nazwiska[indexNazwisko]));
        
        static uniform_int_distribution<int> numerLicencji(0, 99999);
        newDriver[i]->setLicenseNumber(numerLicencji(engine));
        
        static uniform_int_distribution<int> doswiadczenie(0, 99);
        newDriver[i]->setExperience(doswiadczenie(engine));
        
        cout << "Dodano nowego kierowcę." << endl;
    }
    Car** newCar = new Car * [size];
    for(int i=0; i<size; i++) {
        newCar[i] = new Car;
        static uniform_int_distribution<int> marka(0, 5);
        static uniform_int_distribution<int> model(0, 5);
        static uniform_int_distribution<int> numerRejestracyjny(0, 6);
        size_t indexMarkaAuta = marka(engine);
        size_t indexModelAuta = model(engine);
        size_t indexNumerRejestracyjnyAuta = numerRejestracyjny(engine);
        newCar[i]->setBrand(string(markiAut[indexMarkaAuta]));
        newCar[i]->setModel(string(modeleAut[indexModelAuta]));
        newCar[i]->setPlateNumber(string(numerRejestracyjnyAuta[indexNumerRejestracyjnyAuta]));
        
        cout << "Dodano nowy samochód." << endl;
    }
    Order** newOrder = new Order * [size];
    for(int i=0; i<size; i++) {
        newOrder[i] = new Order;
        static uniform_int_distribution<int> imie(0, 7);
        static uniform_int_distribution<int> nazwisko(0, 7);
        static uniform_int_distribution<int> miejsceOdbioru(0, 6);
        static uniform_int_distribution<int> miejsceDocelowe(0, 6);
        size_t indexImie = imie(engine);
        size_t indexNazwisko = nazwisko(engine);
        size_t indexMiejsceOdbioru = miejsceOdbioru(engine);
        size_t indexMiejsceDocelowe = miejsceDocelowe(engine);
        newOrder[i]->setCustomerFirstName(string(imiona[indexImie]));
        newOrder[i]->setCustomerLastName(string(nazwiska[indexNazwisko]));
        newOrder[i]->setPickupLocation(string(miejscaOdbioru[indexMiejsceOdbioru]));
        newOrder[i]->setDropOffLocation(string(miejscaDocelowe[indexMiejsceDocelowe]));
    
        static uniform_int_distribution<int> kwota(0, 100);
        newOrder[i]->setAmount(kwota(engine));
    
        newOrder[i]->setCompleted(false);
        newOrder[i]->setOrderId(i);
        
        cout << "Dodano nowe zamówienie." << endl;
    }
    company.setCars(newCar);
    company.setDrivers(newDriver);
    company.setOrders(newOrder);
    company.setCarCount(size);
    company.setDriverCount(size);
    company.setOrderCount(size);
    cout << "Poprawnie wygenerowano bazę." << endl << endl;
}

void parsingPlaceOrder(Order**& order, int &size) {
    Order** newOrder = new Order * [size + 1];
    cout << "1. Imię 2. Nazwisko 3. Miejsce odbioru 4. Miejsce docelowe 5. Koszt zamówienia" << endl;
    if (size == 0) {
        newOrder[size] = new Order;
        string input;
        getline(cin, input);
                
        vector<string> words;
                
        size_t start = 0, end;
        while ((end = input.find(' ', start)) != string::npos) {
            words.push_back(input.substr(start, end - start));
            start = end + 1;
        }
        words.push_back(input.substr(start));
        
        words[0][0] = toupper(words[0][0]);
        words[1][0] = toupper(words[1][0]);
        words[2][0] = toupper(words[2][0]);
        words[3][0] = toupper(words[3][0]);
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < words.at(i).size(); j++) {
                words[i][j] = tolower(words[i][j]);
            }
        }
        newOrder[size]->setCustomerFirstName(words.at(0));
        newOrder[size]->setCustomerLastName(words.at(1));
        newOrder[size]->setPickupLocation(words.at(2));
        newOrder[size]->setDropOffLocation(words.at(3));
        newOrder[size]->setAmount(stoi(words.at(4)));
        newOrder[size]->setCompleted(false);
    }
    else {
        for (int i = 0; i < size; i++) {
            newOrder[i] = order[i];
        }
        newOrder[size] = new Order;
        string input;
        getline(cin, input);
                
        vector<string> words;
                
        size_t start = 0, end;
        while ((end = input.find(' ', start)) != string::npos) {
            words.push_back(input.substr(start, end - start));
            start = end + 1;
        }
        words.push_back(input.substr(start));
        
        words[0][0] = toupper(words[0][0]);
        words[1][0] = toupper(words[1][0]);
        words[2][0] = toupper(words[2][0]);
        words[3][0] = toupper(words[3][0]);
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < words.at(i).size(); j++) {
                words[i][j] = tolower(words[i][j]);
            }
        }
        newOrder[size]->setCustomerFirstName(words.at(0));
        newOrder[size]->setCustomerLastName(words.at(1));
        newOrder[size]->setPickupLocation(words.at(2));
        newOrder[size]->setDropOffLocation(words.at(3));
        newOrder[size]->setAmount(stoi(words.at(4)));
        newOrder[size]->setCompleted(false);
    }
    order = newOrder;
    size++;
    cout << "Dodano nowe zamówienie." << endl << endl;
}
