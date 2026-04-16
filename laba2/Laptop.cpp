#include "Laptop.h"
#include <iostream>
#include <utility>

using namespace std;

Laptop::Laptop(int id, string name, double price, int stock,
    int warranty, string brand,
    int ramGB, string cpu)
    : Electronics(id, name, price, stock, warranty, brand),
    ramGB(ramGB), cpu(cpu) {
    cout << "[Laptop] Створено: " << name << " (RAM: " << this->ramGB << " ГБ, CPU: " << this->cpu << ")" << endl;
}

Laptop::Laptop(const Laptop& other)
    : Electronics(other),
    ramGB(other.ramGB), cpu(other.cpu) {
    cout << "[Laptop] Copy конструктор для: " << name << endl;
}

Laptop::Laptop(Laptop&& other) noexcept
    : Electronics(std::move(other)),
    ramGB(other.ramGB), cpu(std::move(other.cpu)) {
    other.ramGB = 0;
    cout << "[Laptop] Move конструктор для: " << name << endl;
}

Laptop& Laptop::operator=(const Laptop& other) {
    if (this == &other) return *this;

    Electronics::operator=(other);

    this->ramGB = other.ramGB;
    this->cpu = other.cpu;

    cout << "[Laptop] Operator= для: " << name << endl;
    return *this;
}

Laptop::~Laptop() {
    cout << "[Laptop] Видалено: " << name << endl;
}

void Laptop::printInfo() const {
    cout << "Ноутбук | ";
    Electronics::printInfo();
    cout << "  RAM: " << ramGB << " ГБ | CPU: " << cpu << endl;
}
double Laptop::calculateDiscount() const { return price * 0.10; }
