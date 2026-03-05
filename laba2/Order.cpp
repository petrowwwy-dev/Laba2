#include "Order.h"
#include <iostream>

using namespace std;


Order::Order(int oId, double oAmount, string oStatus) : orderId(oId), totalAmount(oAmount), status(oStatus) {
    cout << " Створено замовлення №" << orderId << endl;
}

Order::Order(int oId) : Order(oId, 0.0, "") {
    cout << " Спрацював делегуючий конструктор для замовлення №" << orderId << endl;
}

Order::~Order() {
    cout << " Замовлення №" << orderId << " видалено." << endl;
}

void Order::pay() {
    if (totalAmount > 0) {
        status = "Оплачено";
        cout << "--> Замовлення №" << orderId << " успішно оплачено!" << endl;
    }
    else {
        cout << "--> Помилка: Неможливо оплатити порожнє замовлення №" << orderId << "!" << endl;
    }
}

void Order::printOrder() {
    cout << "\n=== Чек Замовлення ===" << endl;
    cout << "Номер: " << orderId << endl;
    cout << "Сума до оплати: " << totalAmount << " грн" << endl;
    cout << "Статус: " << status << endl;
    cout << "======================\n" << endl;
}