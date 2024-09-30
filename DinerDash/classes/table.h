#pragma once

#include <iostream>
#include <vector>
#include <thread>

#include "orderStatus.h"
#include "customer.h"

class Table {
public:
    Table(int id) : id(id), orderStatus(OrderStatus::NotYetTaken), customer(id) {}

    int getId() const { return id; }
    OrderStatus getOrderStatus() const { return orderStatus; }
    void setOrderStatus(OrderStatus status) { orderStatus = status; }
    Customer& getCustomer() { return customer; }  // Provide non-const access
    const Customer& getCustomer() const { return customer; }  // Provide const access

    void displayOrderStatus() const {
        std::cout << "Table " << id << ": ";
        switch (orderStatus) {
            case OrderStatus::NotYetTaken: std::cout << "Order Not Yet Taken\n"; break;
            case OrderStatus::InKitchen: std::cout << "Order In Kitchen\n"; break;
            case OrderStatus::Served: std::cout << "Order Served\n"; break;
        }
    }

private:
    int id;
    OrderStatus orderStatus;
    Customer customer;
};