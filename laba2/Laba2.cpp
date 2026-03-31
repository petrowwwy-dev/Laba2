#include <iostream>
#include <windows.h>
#include <utility> 
#include "Product.h" 
#include "Customer.h"
#include "Order.h"
#include "Electronics.h"

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

    cout << "\n=== ВВЕДЕННЯ НОВОГО ТОВАРУ ===" << endl;
    Product p_custom(100, "Пустишка");
    cout << "-> Будь ласка, введіть дані для нового товару:" << endl;
    cin >> p_custom; 
    cout << "\nВи успішно додали: " << p_custom << endl;


    

    
    Customer c1(1, "Олександр", "sasha@gmail.com");
    Customer c2(2, "Марія");

    cout << "\n--- дані покупців ---" << endl;
    
    c1.printInfo();
    c2.printInfo();

    cout << "\n=== ТЕСТУВАННЯ КОМПОЗИЦІЇ ТА НАСЛІДУВАННЯ ===" << endl;

    // Створюємо звичайне замовлення з товаром p1, який у тебе вже є вище
    Order order1(101, p1, 1500.50);
    order1.printOrder();
    order1.pay();


    // А тепер створимо наш новий об'єкт Electronics (Електроніка)
    Electronics phone(200, "iPhone 15", 45000.0, 10, 12, "Apple");

    // І покладемо цю електроніку в друге замовлення!
    Order order2(102, phone, 45000.0);
    order2.printOrder();

    order2.pay();





    cout << "\n=== ЗАВЕРШЕННЯ ПРОГРАМИ ===" << endl;

    return 0;
}