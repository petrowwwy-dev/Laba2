#pragma once
#include <string>
#include "IPrintable.h"

class Product : public IPrintable {
protected:
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
    
    Product& operator=(const Product& other);




    virtual  ~Product();
    virtual double calculateDiscount() const = 0;
    virtual std::string getDescription() const;
    virtual void printInfo() const override;
    void showType() const;
    void updateStock(int amount);
  
    static int getTotalProducts();

    /*Product& operator++();
    Product operator+(int extraStock) const;*/
    friend std::ostream& operator<<(std::ostream& os, const Product& p);
    friend std::istream& operator>>(std::istream& is, Product& p);

};
