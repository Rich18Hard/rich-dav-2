#ifndef TABLE_H
#define TABLE_H

#include "Customer.h"
#include "OrderStatus.h"

class Table {
public:
    Table(int id);
    int getId() const;
    OrderStatus getOrderStatus() const;
    void setOrderStatus(OrderStatus status);
    bool hasCustomer() const;
    Customer* getCustomer();
    const Customer* getCustomer() const;
    void assignCustomer(Customer* newCustomer);
    void unseatCustomer();
    void cleanTable();
    void displayOrderStatus() const;

private:
    int id;
    OrderStatus orderStatus;
    Customer* customer;
};

#endif
