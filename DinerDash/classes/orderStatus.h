#ifndef ORDERSTATUS_H
#define ORDERSTATUS_H

enum class OrderStatus {
    Empty,
    NotYetTaken,
    InKitchen,
    Served,
    FinishedEating,
    DirtyPlates,
    Cleaned
};

#endif
