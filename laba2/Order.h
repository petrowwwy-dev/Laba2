#pragma once
#include <string>
#include "Product.h"

class Order {
private:
    int orderId;
    Product orderedProduct;
    double totalAmount;
    std::string status;

public:

    Order(int oId, const Product& product, double oAmount, std::string oStatus = "Нове");
    Order(int oId);

    ~Order();

    void pay();
    void printOrder();
};