#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(int cId, string cName, string cEmail)
    : id(cId), name(cName), email(cEmail) {

    cout << "Покупця на ім'я " << name << " успішно створено!" << endl;
}

Customer::Customer(int cId, string cName) : Customer(cId, cName, "немає") {
    cout << "Спрацював делегуючий конструктор!" << endl;
}


Customer::~Customer() {
    cout << "Покупця " << name << " видалено." << endl;
}

void Customer::printInfo() {

    cout << "=== Інформація про покупця ===" << endl;
    cout << "ID: " << id << endl;
    cout << "Ім'я: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "==============================" << endl;
}