#ifndef WAITER_H
#define WAITER_H

#include <vector>
#include "Table.h"
#include "Kitchen.h"

class Waiter {
public:
    Waiter(Kitchen& kitchen);
    void takeOrder(Table& table);
    void serveCustomer(Table& table);
    void deliverOrder(Table& table);
    void checkOrders(std::vector<Table>& tables);
    void simulateEating(Table& table);

private:
    Kitchen& kitchen;
};

#endif
