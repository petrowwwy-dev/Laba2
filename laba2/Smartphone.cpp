#include "Smartphone.h"
#include <iostream>
#include <utility>

using namespace std;

Smartphone::Smartphone(int id, string name, double price, int stock,
    int warranty, string brand,
    string os, double screenSize)
    : Electronics(id, name, price, stock, warranty, brand),
    os(os), screenSize(screenSize) {
    cout << "[Smartphone] Створено: " << name << " (" << this->os << ", " << this->screenSize << "\")" << endl;
}

Smartphone::Smartphone(const Smartphone& other)
    : Electronics(other),
    os(other.os), screenSize(other.screenSize) {
    cout << "[Smartphone] Copy конструктор для: " << name << endl;
}

Smartphone::Smartphone(Smartphone&& other) noexcept
    : Electronics(std::move(other)),
    os(std::move(other.os)), screenSize(other.screenSize) {
    other.screenSize = 0.0;
    cout << "[Smartphone] Move конструктор для: " << name << endl;
}

Smartphone& Smartphone::operator=(const Smartphone& other) {
    if (this == &other) return *this;

    Electronics::operator=(other);

    this->os = other.os;
    this->screenSize = other.screenSize;

    cout << "[Smartphone] Operator= для: " << name << endl;
    return *this;
}

Smartphone::~Smartphone() {
    cout << "[Smartphone] Видалено: " << name << endl;
}

void Smartphone::printInfo() const {
    cout << "Смартфон | ";
    Electronics::printInfo();
    cout << "  ОС: " << os << " | Екран: " << screenSize << "\"" << endl;
}
