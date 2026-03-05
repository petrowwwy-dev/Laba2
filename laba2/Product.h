#pragma once
#include <string>

class Product {
private:
    int id;
    std::string name;
    double price;
    int stock;

public:


    Product(int pId, std::string pName, double pPrice, int pStock = 0);

    Product(int pId, std::string pName);

    ~Product();

    void printInfo();
    void updateStock(int amount);
};