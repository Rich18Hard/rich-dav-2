#pragma once

class Customer {
public:
    Customer(int id) : id(id), emotion(5) {}

    int getId() const { return id; }
    int getEmotion() const { return emotion; }
    void setEmotion(int newEmotion) { emotion = newEmotion; }
    void decreaseEmotion() { if (emotion > 1) --emotion; }

private:
    int id;
    int emotion;
};