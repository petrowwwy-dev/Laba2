#include "StoreManager.h"
#include "Electronics.h"
#include "Laptop.h"
#include "Smartphone.h"
#include "Logger.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;

StoreManager::StoreManager() {
    loadFromFile();
}

StoreManager::~StoreManager() {
    saveToFile();
}

void StoreManager::saveToFile() const {
    ofstream file(filename);
    if (!file.is_open()) return;
    for (const auto& prod : products) {
        file << prod->toFileString() << "\n";
    }
    file.close();
}

void StoreManager::loadFromFile() {
    ifstream file(filename);
    if (!file.is_open()) return;

    products.clear();
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string type, idStr, name, priceStr, stockStr, warrStr, brand, extra1, extra2;

        getline(ss, type, ';');
        getline(ss, idStr, ';');
        getline(ss, name, ';');
        getline(ss, priceStr, ';');
        getline(ss, stockStr, ';');
        getline(ss, warrStr, ';');
        getline(ss, brand, ';');

        try {
            int id = stoi(idStr);
            double price = stod(priceStr);
            int stock = stoi(stockStr);
            int warr = stoi(warrStr);

            if (type == "E") {
                products.push_back(make_shared<Electronics>(id, name, price, stock, warr, brand));
            }
            else if (type == "L") {
                getline(ss, extra1, ';'); 
                getline(ss, extra2);      
                products.push_back(make_shared<Laptop>(id, name, price, stock, warr, brand, stoi(extra1), extra2));
            }
            else if (type == "S") {
                getline(ss, extra1, ';'); 
                getline(ss, extra2);      
                products.push_back(make_shared<Smartphone>(id, name, price, stock, warr, brand, extra1, stod(extra2)));
            }
        }
        catch (...) {
            
        }
    }
    file.close();
}

void StoreManager::addElectronics(int id, const string& name, double price, int stock, int warranty, const string& brand) {
    if (price < 0 || stock < 0) throw invalid_argument("Ціна та кількість не можуть бути від'ємними!");
    products.push_back(make_shared<Electronics>(id, name, price, stock, warranty, brand));
    saveToFile();
    Logger::log("Адміністратор додав Електроніку: [" + brand + "] " + name);
}

void StoreManager::addLaptop(int id, const string& name, double price, int stock, int warranty, const string& brand, int ram, const string& cpu) {
    if (price < 0 || stock < 0) throw invalid_argument("Ціна та кількість не можуть бути від'ємними!");
    products.push_back(make_shared<Laptop>(id, name, price, stock, warranty, brand, ram, cpu));
    saveToFile();
    Logger::log("Адміністратор додав Ноутбук: [" + brand + "] " + name);
}

void StoreManager::addSmartphone(int id, const string& name, double price, int stock, int warranty, const string& brand, const string& os, double screenSize) {
    if (price < 0 || stock < 0) throw invalid_argument("Ціна та кількість не можуть бути від'ємними!");
    products.push_back(make_shared<Smartphone>(id, name, price, stock, warranty, brand, os, screenSize));
    saveToFile();
    Logger::log("Адміністратор додав Смартфон: [" + brand + "] " + name);
}

void StoreManager::showAllProducts() const {
    if (products.empty()) {
        cout << "\nМагазин наразі порожній.\n";
        return;
    }
    cout << "\n=== КАТАЛОГ ТОВАРІВ ===\n";
    for (size_t i = 0; i < products.size(); ++i) {
        cout << "[" << i + 1 << "] ";
        products[i]->printInfo(); 
    }
    cout << "=======================\n";
}

shared_ptr<Product> StoreManager::getProduct(int index) {
    if (index < 0 || index >= products.size()) {
        throw out_of_range("Товару з таким номером не існує!");
    }
    return products[index];
}

size_t StoreManager::getProductsCount() const {
    return products.size();
}
