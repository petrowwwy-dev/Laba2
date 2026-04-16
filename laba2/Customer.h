#pragma once
#include <string>

class Customer {
private:
    int id;
    std::string name;
    std::string email;

public:
    Customer(int сId, std::string сName, std::string сEmail);
    Customer(int cId, std::string cName);

    ~Customer();



    void printInfo();

};




