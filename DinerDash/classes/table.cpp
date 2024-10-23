#include "Table.h"
#include <iostream>

Table::Table(int id) : id(id), orderStatus(OrderStatus::Empty), customer(nullptr) {}

int Table::getId() const { return id; }
OrderStatus Table::getOrderStatus() const { return orderStatus; }
void Table::setOrderStatus(OrderStatus status) { orderStatus = status; }
bool Table::hasCustomer() const { return customer != nullptr; }
Customer* Table::getCustomer() { return customer; }
const Customer* Table::getCustomer() const { return customer; }
void Table::assignCustomer(Customer* newCustomer) {
    customer = newCustomer;
    orderStatus = OrderStatus::NotYetTaken;
}
void Table::unseatCustomer() {
    customer = nullptr;
    orderStatus = OrderStatus::DirtyPlates;
}
void Table::cleanTable() {
    orderStatus = OrderStatus::Cleaned;
}
void Table::displayOrderStatus() const {
    std::cout << "Table " << id << ": ";
    if (!hasCustomer() && orderStatus == OrderStatus::Cleaned) {
        std::cout << "Clean\n";
    } else if (orderStatus == OrderStatus::DirtyPlates) {
        std::cout << "Dirty Plates on Table\n";
    } else if (!hasCustomer()) {
        std::cout << "Empty\n";
    } else if (customer->isServed() && customer->isEating()) {
        std::cout << "Customer Eating\n";
    } else if (orderStatus == OrderStatus::FinishedEating) {
        std::cout << "Customer Finished Eating\n";
    } else {
        switch (orderStatus) {
            case OrderStatus::NotYetTaken: std::cout << "Order Not Yet Taken\n"; break;
            case OrderStatus::InKitchen: std::cout << "Order In Kitchen\n"; break;
            case OrderStatus::Served: std::cout << "Order Served\n"; break;
            default: std::cout << "Unknown Status\n"; break;
        }
    }
}
