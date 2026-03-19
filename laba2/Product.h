#pragma once
#include <string>

class Product {
private:
    int id;
    std::string name;
    double price;
    int stock;

    static int totalProducts;

public:


    Product(int pId, std::string pName, double pPrice, int pStock = 0);

    Product(int pId, std::string pName);

    Product(const Product& other);

    Product(Product&& other) noexcept;

    ~Product();

    void printInfo() const;
    void updateStock(int amount);

    static int getTotalProducts();

    Product& operator++();
    Product operator+(int extraStock) const;
    friend std::ostream& operator<<(std::ostream& os, const Product& p);
    friend std::istream& operator>>(std::istream& is, Product& p);

};