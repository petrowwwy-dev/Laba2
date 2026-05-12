#pragma once
#include "Product.h"
#include <string>
#include <iostream>


class Electronics : public Product {
protected:
    int warrantyMonths;
    std::string brand;

public:
    
    Electronics(int id, std::string name, double price, int stock, int warranty, std::string brand);

    Electronics(int id, std::string name, double price, int stock);

    
    Electronics(const Electronics& other);

    
    Electronics(Electronics&& other) noexcept;

    
    Electronics& operator=(const Electronics& other);

    Electronics& operator++();
    Electronics operator+(int extraStock) const;
    
    ~Electronics() override;

    double calculateDiscount() const override;
    void printInfo() const;
    std::string getDescription() const override;
    void showType() const;
    std::string toFileString() const override;
};
