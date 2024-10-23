#include "Kitchen.h"
#include <iostream>

void Kitchen::receiveOrder(int tableId) {
    std::cout << "Kitchen: Received order from table " << tableId << "\n";
}

void Kitchen::notifyOrderReady(int tableId) {
    std::cout << "Kitchen: Order for table " << tableId << " is ready!\n";
}
