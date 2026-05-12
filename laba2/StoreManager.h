#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Product.h"

class StoreManager {
private:
    std::vector<std::shared_ptr<Product>> products;
    const std::string filename = "store_database.txt";

    void saveToFile() const;
    void loadFromFile();

public:
    StoreManager();
    ~StoreManager();

    void addElectronics(int id, const std::string& name, double price, int stock, int warranty, const std::string& brand);
    void addLaptop(int id, const std::string& name, double price, int stock, int warranty, const std::string& brand, int ram, const std::string& cpu);
    void addSmartphone(int id, const std::string& name, double price, int stock, int warranty, const std::string& brand, const std::string& os, double screenSize);

    void showAllProducts() const;
    std::shared_ptr<Product> getProduct(int index);
    size_t getProductsCount() const;
};
