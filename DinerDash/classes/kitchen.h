#include <iostream>
#pragma once

class Kitchen {
public:
    void receiveOrder(int tableId) {
        std::cout << "Kitchen: Received order from table " << tableId << "\n";
    }

    void notifyOrderReady(int tableId) {
        std::cout << "Kitchen: Order for table " << tableId << " is ready!\n";
    }
};