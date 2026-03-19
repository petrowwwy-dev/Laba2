#include "Product.h" 
#include <iostream>
#include <utility>

using namespace std;
int Product::totalProducts = 0;


Product::Product(int pId, string pName, double pPrice, int pStock)
    : id(pId), name(pName), price(pPrice), stock(pStock) {
    totalProducts++;
    cout << "Створено товар: " << name << endl;
}


Product::Product(int pId, string pName) : Product(pId, pName, 0.0) {
    cout << "Спрацював делегуючий конструктор для " << name << endl;
}


Product::Product(const Product& other)
    : id(other.id), name(other.name), price(other.price), stock(other.stock) {
    totalProducts++;
    cout << "[Копіювання] Створено точну копію товару: " << name << endl;
}


Product::Product(Product&& other) noexcept
    : id(other.id), name(std::move(other.name)), price(other.price), stock(other.stock) {

    other.id = 0;
    other.price = 0.0;
    other.stock = 0;

    totalProducts++; 
    cout << "[Переміщення] Дані товару '" << name << "' успішно переміщено!" << endl;
}


Product::~Product() {
    totalProducts--;
    cout << "Товар '" << name << "' видалено з пам'яті." << endl;
}


void Product::printInfo() const {
    cout << "--- Товар #" << id << " ---" << endl;
    cout << "Назва: " << name << endl;
    cout << "Ціна: " << price << " грн" << endl;
    cout << "На складі: " << stock << " шт." << endl;
    cout << "-------------------" << endl;
}



void Product::updateStock(int amount) {

    stock += amount;

}


int Product::getTotalProducts() {
    return totalProducts;
}

Product& Product::operator++() {
    this->stock++;
    return *this;
}

    Product Product::operator+(int extraStock) const {
    Product temp = *this; 
    temp.stock += extraStock; 
    return temp; 
}


ostream& operator<<(ostream& os, const Product& p) {
    
    os << "[" << p.name << "] ID: " << p.id
        << " | Ціна: " << p.price << " грн | На складі: " << p.stock << " шт.";
    return os;
}

istream& operator>>(istream& is, Product& p) {
    cout << "Введіть ID товару: ";
    is >> p.id;
    cout << "Введіть назву товару: ";
    is.ignore(); 
    getline(is, p.name);
    cout << "Введіть ціну та кількість на складі (через пробіл): ";
    is >> p.price >> p.stock;
    return is;
}