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
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    cout << "Total products in database: " << Product::getTotalProducts() << endl;

    Electronics p1(1, "Laptop", 25000.0, 5);
    p1.printInfo();

    cout << "\nFound another laptop " << endl;
    ++p1;
    cout << p1 << endl;

    cout << "\nForming a new batch of 10 items:" << endl;
    Electronics p_batch = p1 + 10;
    cout << "Original remained unchanged: " << p1 << endl;
    cout << "New batch: " << p_batch << endl;

    cout << "\n=== COPY AND MOVE CONSTRUCTORS ===" << endl;
    Electronics p2 = p1;
    Electronics p3 = std::move(p2);

    cout << "Total products in database now: " << Product::getTotalProducts() << endl;

   /* cout << "\n=== WORKING WITH CONST OBJECT ===" << endl;
    const Product p_const(99, "Archived product", 0.0, 0);
    p_const.printInfo();*/

    Customer c1(1, "Alexander", "sasha@gmail.com");
    Customer c2(2, "Maria");

    cout << "\n--- customer data ---" << endl;

    c1.printInfo();
    c2.printInfo();

    cout << "\n=== TESTING COMPOSITION AND INHERITANCE ===" << endl;

    Order order1(101, p1, 1500.50);
    order1.printOrder();
    order1.pay();

    Electronics phone(200, "iPhone 15", 45000.0, 10, 12, "Apple");

    Order order2(102, phone, 45000.0);
    order2.printOrder();

    order2.pay();

    Smartphone s1(301, "Galaxy S24", 38000.0, 15, 24, "Samsung", "Android", 6.2);
    s1.printInfo();

    cout << "\n--- Copy constructor Smartphone ---" << endl;
    Smartphone s2 = s1;
    s2.printInfo();

    cout << "\n--- Move constructor Smartphone ---" << endl;
    Smartphone s3 = std::move(s2);
    s3.printInfo();

    cout << "\n--- Operator= Smartphone ---" << endl;
    Smartphone s4(302, "Pixel 8", 32000.0, 5, 12, "Google", "Android", 6.1);
    s4 = s1;
    s4.printInfo();

    cout << "\n--- Smartphone order ---" << endl;
    Order order3(103, s1, 38000.0);
    order3.printOrder();
    order3.pay();

    cout << "\n=== TESTING LAPTOP (3rd level of hierarchy) ===" << endl;

    Laptop l1(401, "MacBook Pro", 95000.0, 3, 12, "Apple", 16, "M3 Pro");
    l1.printInfo();

    cout << "\n--- Copy constructor Laptop ---" << endl;
    Laptop l2 = l1;
    l2.printInfo();

    cout << "\n--- Move constructor Laptop ---" << endl;
    Laptop l3 = std::move(l2);
    l3.printInfo();

    cout << "\n--- Operator= Laptop ---" << endl;
    Laptop l4(402, "ThinkPad X1", 55000.0, 7, 24, "Lenovo", 32, "Intel i7");
    l4 = l1;
    l4.printInfo();

    cout << "\n--- Laptop order ---" << endl;
    Order order4(104, l1, 95000.0);
    order4.printOrder();
    order4.pay();

    /*cout << "\n=== ENTERING NEW PRODUCT ===" << endl;
    Product p_custom(100, "Dummy");
    cout << "-> Please enter data for the new product:" << endl;
    cin >> p_custom;
    cout << "\nYou have successfully added: " << p_custom << endl;*/

    cout << "\n=== DEMONSTRATION OF POLYMORPHISM ===" << endl;

    Electronics iphone(101, "iPhone", 40000, 5, 12, "Apple");

    Product* ptr = &iphone;

    cout << ptr->getDescription() << endl;

    ptr->printInfo();

    Laptop l(802, "ThinkPad X1", 55000.0, 5, 24, "Lenovo", 32, "Intel i7");

    Product& ref2 = l;
    ref2.printInfo();     


    cout << "\n=== 1) STATIC BINDING ===" << endl;

    Electronics e1(501, "TV", 15000.0, 2, 12, "LG");

    cout << "Call through Electronics object: ";
    e1.showType();

    Product* basePtr = &e1;
    cout << "Call through Product*: ";
    basePtr->showType();

    cout << "\n=== PURE VIRTUAL FUNCTION DEMO ===" << endl;

    // Product p(1, "Base", 1000.0, 1); // НЕ МОЖНА: Product абстрактний клас

    Product* d1 = new Electronics(901, "TV", 15000.0, 2, 12, "LG");
    Product* d2 = new Smartphone(902, "Galaxy S24", 38000.0, 10, 24, "Samsung", "Android", 6.2);
    Product* d3 = new Laptop(903, "ThinkPad X1", 55000.0, 5, 24, "Lenovo", 32, "Intel i7");

    cout << "Electronics discount: " << d1->calculateDiscount() << " грн" << endl;
    cout << "Smartphone discount:  " << d2->calculateDiscount() << " грн" << endl;
    cout << "Laptop discount:      " << d3->calculateDiscount() << " грн" << endl;

    delete d1;
    delete d2;
    delete d3;
    return 0;
}
