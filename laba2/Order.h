#pragma once
#include <string>

class Order {
private:
    int orderId;
    double totalAmount;
    std::string status;

public:

    Order(int oId, double oAmount, std::string oStatus = "Нове");
    Order(int oId);

    ~Order();

    void pay();
    void printOrder();
};