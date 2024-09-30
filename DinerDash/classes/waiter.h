#pragma once

#include <iostream>
#include <vector>
#include <thread>

#include "orderStatus.h"
#include "table.h"
#include "kitchen.h"

class Waiter {
public:
    Waiter(Kitchen& kitchen) : kitchen(kitchen) {}

    void takeOrder(Table& table) {
        table.setOrderStatus(OrderStatus::InKitchen);
        kitchen.receiveOrder(table.getId());
    }

    void deliverOrder(Table& table) {
        table.setOrderStatus(OrderStatus::Served);
        table.getCustomer().setEmotion(5);
        std::cout << "Waiter: Delivered order to table " << table.getId() << "\n";
    }

    void checkOrders(std::vector<Table>& tables) {
        for (auto& table : tables) {
            if (table.getOrderStatus() == OrderStatus::InKitchen) {
                kitchen.notifyOrderReady(table.getId());
                deliverOrder(table);
            }
        }
    }

private:
    Kitchen& kitchen;
};