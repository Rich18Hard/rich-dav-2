#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#include "../classes/customer.h"
#include "../classes/kitchen.h"
#include "../classes/orderStatus.h"
#include "../classes/table.h"
#include "../classes/waiter.h"

int main() {
    Kitchen kitchen;
    Waiter waiter(kitchen);
    std::vector<Table> tables = { Table(1), Table(2), Table(3) };

    while (true) {
        std::cout << "\nRestaurant Management System\n";
        std::cout << "1. Display Order Status\n";
        std::cout << "2. Take Order\n";
        std::cout << "3. Simulate Order Processing\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            // Display all table statuses
            for (const auto& table : tables) {
                table.displayOrderStatus();
                std::cout << "Customer " << table.getCustomer().getId() 
                          << " emotion: " << table.getCustomer().getEmotion() << "\n";
            }
        } else if (choice == 2) {
            // Take an order for a specific table
            std::cout << "Enter table number to take order (1, 2, or 3): ";
            int tableId;
            std::cin >> tableId;
            if (tableId < 1 || tableId > 3) {
                std::cout << "Invalid table number.\n";
            } else {
                waiter.takeOrder(tables[tableId - 1]);
            }
        } else if (choice == 3) {
            // Simulate order processing
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate 1 second delay
            for (auto& table : tables) {
                table.getCustomer().decreaseEmotion();
            }
            waiter.checkOrders(tables);
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}