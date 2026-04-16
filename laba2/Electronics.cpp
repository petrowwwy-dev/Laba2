#include "Electronics.h"

using namespace std;


Electronics::Electronics(int id, string name, double price, int stock, int warranty, string brand)
    : Product(id, name, price, stock), warrantyMonths(warranty), brand(brand) {
    cout << "[Electronics] Створено: " << this->brand << " " << this->name << endl;
}

Electronics::Electronics(const Electronics& other)
    : Product(other), 
    warrantyMonths(other.warrantyMonths), brand(other.brand) {
    cout << "[Electronics] Copy конструктор для: " << brand << endl;
}


Electronics::Electronics(Electronics&& other) noexcept
    : Product(std::move(other)), 
    warrantyMonths(other.warrantyMonths), brand(std::move(other.brand)) {

    other.warrantyMonths = 0; 
    cout << "[Electronics] Move конструктор для: " << brand << endl;
}


Electronics& Electronics::operator=(const Electronics& other) {
    if (this == &other) {
        return *this; 
    }

   
    Product::operator=(other);

    
    this->warrantyMonths = other.warrantyMonths;
    this->brand = other.brand;

    cout << "[Electronics] Operator= (Присвоювання) для: " << brand << endl;
    return *this;
}


Electronics::~Electronics() {
    cout << "[Electronics] Видалено: " << brand << endl;
}


void Electronics::printInfo() const {
    
    cout << "Електроніка [" << brand << "] " << name
        << " | Ціна: " << price << " грн | Гарантія: " << warrantyMonths << " міс." << endl;
}

void Electronics::showType() const {
    std::cout << "Electronics::showType -> Це клас Electronics" << std::endl;
}

std::string Electronics::getDescription() const {
    return "Це електроніка. Бренд: " + brand;
}
