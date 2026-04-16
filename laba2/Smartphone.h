#pragma once
#include "Electronics.h"
#include <string>

class Smartphone : public Electronics {
private:
    std::string os;         
    double screenSize;       

public:
    Smartphone(int id, std::string name, double price, int stock,
        int warranty, std::string brand,
        std::string os, double screenSize);

    Smartphone(const Smartphone& other);

    Smartphone(Smartphone&& other) noexcept;

    Smartphone& operator=(const Smartphone& other);

    ~Smartphone() override;

    void printInfo() const;
};

