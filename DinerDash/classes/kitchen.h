#ifndef KITCHEN_H
#define KITCHEN_H

class Kitchen {
public:
    void receiveOrder(int tableId);
    void notifyOrderReady(int tableId);
};

#endif
