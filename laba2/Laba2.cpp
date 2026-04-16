#include <iostream>
#include <windows.h>
#include <utility> 
#include "Product.h" 
#include "Customer.h"
#include "Order.h"
#include "Electronics.h"
#include "Smartphone.h"
#include "Laptop.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

   

   
    cout << "Всього товарів у базі: " << Product::getTotalProducts() << endl;

    Product p1(1, "Ноутбук", 25000.0, 5);
    p1.printInfo();

    cout << "\nЗнайшли ще один ноутбук " << endl;
    ++p1;
    cout << p1 << endl;

    cout << "\nФормуємо нову партію з 10 штук :" << endl;
    Product p_batch = p1 + 10;
    cout << "Оригінал залишився без змін: " << p1 << endl;
    cout << "Нова партія: " << p_batch << endl;

    cout << "\n=== КОНСТРУКТОРИ КОПІЮВАННЯ ТА ПЕРЕМІЩЕННЯ ===" << endl;
    Product p2 = p1; 
    Product p3 = std::move(p2);

    cout << "Всього товарів у базі зараз: " << Product::getTotalProducts() << endl;

    cout << "\n=== РОБОТА З CONST ОБ'ЄКТОМ ===" << endl;
    const Product p_const(99, "Архівний товар", 0.0, 0);
    p_const.printInfo(); 
 
    Customer c1(1, "Олександр", "sasha@gmail.com");
    Customer c2(2, "Марія");

    cout << "\n--- дані покупців ---" << endl;
    
    c1.printInfo();
    c2.printInfo();

    cout << "\n=== ТЕСТУВАННЯ КОМПОЗИЦІЇ ТА НАСЛІДУВАННЯ ===" << endl;

   
    Order order1(101, p1, 1500.50);
    order1.printOrder();
    order1.pay();


   
    Electronics phone(200, "iPhone 15", 45000.0, 10, 12, "Apple");


    Order order2(102, phone, 45000.0);
    order2.printOrder();

    order2.pay();

    Smartphone s1(301, "Galaxy S24", 38000.0, 15, 24, "Samsung", "Android", 6.2);
    s1.printInfo();

 
    cout << "\n--- Copy конструктор Smartphone ---" << endl;
    Smartphone s2 = s1;
    s2.printInfo();

    cout << "\n--- Move конструктор Smartphone ---" << endl;
    Smartphone s3 = std::move(s2);
    s3.printInfo();

    cout << "\n--- Operator= Smartphone ---" << endl;
    Smartphone s4(302, "Pixel 8", 32000.0, 5, 12, "Google", "Android", 6.1);
    s4 = s1;
    s4.printInfo();

    cout << "\n--- Замовлення смартфону ---" << endl;
    Order order3(103, s1, 38000.0);
    order3.printOrder();
    order3.pay();

    cout << "\n=== ТЕСТУВАННЯ LAPTOP (3-й рівень ієрархії) ===" << endl;

    Laptop l1(401, "MacBook Pro", 95000.0, 3, 12, "Apple", 16, "M3 Pro");
    l1.printInfo();

    cout << "\n--- Copy конструктор Laptop ---" << endl;
    Laptop l2 = l1;
    l2.printInfo();

    cout << "\n--- Move конструктор Laptop ---" << endl;
    Laptop l3 = std::move(l2);
    l3.printInfo();

    cout << "\n--- Operator= Laptop ---" << endl;
    Laptop l4(402, "ThinkPad X1", 55000.0, 7, 24, "Lenovo", 32, "Intel i7");
    l4 = l1;
    l4.printInfo();

    cout << "\n--- Замовлення ноутбука ---" << endl;
    Order order4(104, l1, 95000.0);
    order4.printOrder();
    order4.pay();


    cout << "\n=== ВВЕДЕННЯ НОВОГО ТОВАРУ ===" << endl;
    Product p_custom(100, "Пустишка");
    cout << "-> Будь ласка, введіть дані для нового товару:" << endl;
    cin >> p_custom;
    cout << "\nВи успішно додали: " << p_custom << endl;



    cout << "\n=== ЗАВЕРШЕННЯ ПРОГРАМИ ===" << endl;

    return 0;
}