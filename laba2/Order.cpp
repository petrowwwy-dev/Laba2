#include "Order.h"
#include <iostream>

using namespace std;

// Оновлений конструктор: тепер він копіює переданий product у внутрішню змінну orderedProduct
Order::Order(int oId, const Product& product, double oAmount, string oStatus)
    : orderId(oId), orderedProduct(const_cast<Product*>(&product)), totalAmount(oAmount), status(oStatus) {
    cout << " Створено замовлення №" << orderId << endl;
}

// Делегуючий конструктор довелось прибрати, бо тепер замовлення НЕ МОЖЕ існувати без товару (це суть композиції)

Order::~Order() {
    cout << " Замовлення №" << orderId << " видалено." << endl;
}

void Order::pay() {
    if (totalAmount > 0) {
        status = "Оплачено";
        cout << "---> Замовлення №" << orderId << " успішно оплачено!" << endl;
    }
    else {
        cout << "---> Помилка: Неможливо оплатити порожнє замовлення №" << orderId << " !" << endl;
    }
}

void Order::printOrder() {
    cout << "\n=== Чек Замовлення ===" << endl;
    cout << "Номер: " << orderId << endl;
    cout << "Сума до оплати: " << totalAmount << " грн" << endl;
    cout << "Статус: " << status << endl;

    // Викликаємо метод вкладеного об'єкта товару (Композиція в дії!)
    cout << "--- Деталі товару ---" << endl;
    orderedProduct->printInfo();

    cout << "=========================\n" << endl;
}
