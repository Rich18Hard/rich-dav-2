#include "Customer.h"

Customer::Customer(int id) : id(id), emotion(5), served(false), eating(false) {}

int Customer::getId() const { return id; }
int Customer::getEmotion() const { return emotion; }
void Customer::setEmotion(int newEmotion) { emotion = newEmotion; }
void Customer::decreaseEmotion() { if (emotion > 0) --emotion; }
bool Customer::isServed() const { return served; }
void Customer::setServed(bool value) { served = value; }
bool Customer::isEating() const { return eating; }
void Customer::setEating(bool value) { eating = value; }
