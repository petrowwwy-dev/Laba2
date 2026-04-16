#pragma once
#include "Electronics.h"
#include <string>

class Laptop : public Electronics {
private:
    int ramGB;           
    std::string cpu;     

public:
    Laptop(int id, std::string name, double price, int stock,
        int warranty, std::string brand,
        int ramGB, std::string cpu);

    
    Laptop(const Laptop& other);

    
    Laptop(Laptop&& other) noexcept;

    
    Laptop& operator=(const Laptop& other);

    ~Laptop() override;

    void printInfo() const;
};
