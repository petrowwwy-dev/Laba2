#include <iostream>
#include < windows.h >
#include "Product.h" 
#include "Customer.h"
#include "Order.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Product p1(1, "Ноутбук", 25000.0, 5);
    p1.printInfo();

    cout << "\n=== ОНОВЛЕННЯ ДАНИХ ===" << endl;

    cout << "Приїхала нова партія ноутбуків!" << endl;
    p1.updateStock(15);
    p1.printInfo();

    Customer c1(1, "Олександр", "sasha@gmail.com");
    Customer c2(2, "Марія");

    cout << "\n--- Виводимо дані покупців ---" << endl;

    c1.printInfo();
    c2.printInfo();

    Order order1(101, 1500.50);
    order1.printOrder();


    order1.pay();
    order1.printOrder();


    Order order2(102);
    order2.printOrder();

    order2.pay();





    cout << "\n=== ЗАВЕРШЕННЯ ПРОГРАМИ ===" << endl;

    return 0;
}