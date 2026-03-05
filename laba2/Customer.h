#pragma once
#include <string>

class Customer {
private:
    int id;
    std::string name;
    std::string email;

public:
    Customer(int ÒId, std::string ÒName, std::string ÒEmail);
    Customer(int cId, std::string cName);

    ~Customer();



    void printInfo();

};




