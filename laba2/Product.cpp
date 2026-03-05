#include "Product.h" 
#include <iostream>

using namespace std;


Product::Product(int pId, string pName, double pPrice, int pStock)
    : id(pId), name(pName), price(pPrice), stock(pStock) {
    cout << "Створено товар: " << name << endl;
}


Product::Product(int pId, string pName) : Product(pId, pName, 0.0) {
    cout << "Спрацював делегуючий конструктор для " << name << endl;
}


Product::~Product() {
    cout << "Товар '" << name << "' видалено з пам'яті." << endl;
}


void Product::printInfo() {
    cout << "--- Товар #" << id << " ---" << endl;
    cout << "Назва: " << name << endl;
    cout << "Ціна: " << price << " грн" << endl;
    cout << "На складі: " << stock << " шт." << endl;
    cout << "-------------------" << endl;
}



void Product::updateStock(int amount) {

    stock += amount;

}