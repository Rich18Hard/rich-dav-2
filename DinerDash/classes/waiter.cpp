#include "Waiter.h"
#include <iostream>
#include <thread>
#include <chrono>

Waiter::Waiter(Kitchen& kitchen) : kitchen(kitchen) {}

void Waiter::takeOrder(Table& table) {
    if (table.hasCustomer() && table.getOrderStatus() == OrderStatus::NotYetTaken) {
        table.setOrderStatus(OrderStatus::InKitchen);
        kitchen.receiveOrder(table.getId());
    } else {
        std::cout << "Waiter: No customer to take order from at table " << table.getId() << "\n";
    }
}

void Waiter::serveCustomer(Table& table) {
    if (table.getOrderStatus() == OrderStatus::Served && table.hasCustomer() && !table.getCustomer()->isServed()) {
        table.getCustomer()->setServed(true);
        std::cout << "Waiter: Served customer at table " << table.getId() << "\n";
    } else {
        std::cout << "Waiter: Unable to serve customer at table " << table.getId() << "\n";
    }
}

void Waiter::deliverOrder(Table& table) {
    if (table.hasCustomer()) {
        table.setOrderStatus(OrderStatus::Served);
        table.getCustomer()->setEmotion(5);
        std::cout << "Waiter: Order delivered to table " << table.getId() << "\n";
    }
}

void Waiter::checkOrders(std::vector<Table>& tables) {
    for (auto& table : tables) {
        if (table.getOrderStatus() == OrderStatus::InKitchen) {
            kitchen.notifyOrderReady(table.getId());
        }
    }
}

void Waiter::simulateEating(Table& table) {
    if (table.getOrderStatus() == OrderStatus::Served && table.hasCustomer() && table.getCustomer()->isServed()) {
        table.getCustomer()->setEating(true);
        std::cout << "Waiter: Customer at table " << table.getId() << " is eating.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        table.getCustomer()->setEating(false);
        table.setOrderStatus(OrderStatus::FinishedEating);
        std::cout << "Waiter: Customer at table " << table.getId() << " finished eating.\n";
    }
}
