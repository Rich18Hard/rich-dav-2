#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "../classes/Customer.h"
#include "../classes/Kitchen.h"
#include "../classes/Table.h"
#include "../classes/Waiter.h"

int main() {
    Kitchen kitchen;
    Waiter waiter(kitchen);
    std::vector<Table> tables = { Table(1), Table(2), Table(3) };
    int customerIdCounter = 1;
    std::vector<Customer*> customerList; // Store customers dynamically to avoid pointer issues

    while (true) {
        std::cout << "\nRestaurant Management System\n";
        std::cout << "1. Display Order Status\n";
        std::cout << "2. Assign Customer to Table\n";
        std::cout << "3. Take Order\n";
        std::cout << "4. Serve Customer\n";
        std::cout << "5. Simulate Order Processing\n";  // Retained original name
        std::cout << "6. Unseat Customer\n";
        std::cout << "7. Clean Table\n";
        std::cout << "8. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            // Display all table statuses
            for (const auto& table : tables) {
                table.displayOrderStatus();
                if (table.hasCustomer()) {
                    std::cout << "Customer " << table.getCustomer()->getId() 
                              << " emotion: " << table.getCustomer()->getEmotion() << "\n";
                }
            }
        } else if (choice == 2) {
            // Assign a customer to a table
            std::cout << "Enter table number to assign customer (1, 2, or 3): ";
            int tableId;
            std::cin >> tableId;
            if (tableId < 1 || tableId > 3) {
                std::cout << "Invalid table number.\n";
            } else {
                if (!tables[tableId - 1].hasCustomer()) {
                    Customer* newCustomer = new Customer(customerIdCounter++);
                    customerList.push_back(newCustomer);  // Keep track of customers
                    tables[tableId - 1].assignCustomer(newCustomer);
                    std::cout << "Customer assigned to table " << tableId << "\n";
                } else {
                    std::cout << "Table " << tableId << " is already occupied.\n";
                }
            }
        } else if (choice == 3) {
            // Take an order for a specific table
            std::cout << "Enter table number to take order (1, 2, or 3): ";
            int tableId;
            std::cin >> tableId;
            if (tableId < 1 || tableId > 3) {
                std::cout << "Invalid table number.\n";
            } else {
                waiter.takeOrder(tables[tableId - 1]);
            }
        } else if (choice == 4) {
            // Serve a customer manually
            std::cout << "Enter table number to serve (1, 2, or 3): ";
            int tableId;
            std::cin >> tableId;
            if (tableId < 1 || tableId > 3) {
                std::cout << "Invalid table number.\n";
            } else {
                waiter.serveCustomer(tables[tableId - 1]);
            }
        } else if (choice == 5) {
            // Simulate Order Processing (retains original function and adds eating behaviour)
            waiter.checkOrders(tables);
            std::cout << "Simulating customer order processing...\n";
            for (auto& table : tables) {
                if (table.hasCustomer() && table.getCustomer()->isServed()) {
                    waiter.simulateEating(table);
                }
            }
        } else if (choice == 6) {
            // Unseat a customer
            std::cout << "Enter table number to unseat customer (1, 2, or 3): ";
            int tableId;
            std::cin >> tableId;
            if (tableId < 1 || tableId > 3) {
                std::cout << "Invalid table number.\n";
            } else {
                if (tables[tableId - 1].hasCustomer()) {
                    tables[tableId - 1].unseatCustomer();
                    std::cout << "Customer unseated from table " << tableId << ". Dirty plates left on the table.\n";
                } else {
                    std::cout << "No customer to unseat at table " << tableId << ".\n";
                }
            }
        } else if (choice == 7) {
            // Clean a table
            std::cout << "Enter table number to clean (1, 2, or 3): ";
            int tableId;
            std::cin >> tableId;
            if (tableId < 1 || tableId > 3) {
                std::cout << "Invalid table number.\n";
            } else {
                if (tables[tableId - 1].getOrderStatus() == OrderStatus::DirtyPlates) {
                    tables[tableId - 1].cleanTable();
                    std::cout << "Table " << tableId << " cleaned and ready for new customer.\n";
                } else {
                    std::cout << "Table " << tableId << " doesn't need cleaning.\n";
                }
            }
        } else if (choice == 8) {
            break;
        }
    }

    // Clean up dynamically allocated customers
    for (auto customer : customerList) {
        delete customer;
    }

    return 0;
}
