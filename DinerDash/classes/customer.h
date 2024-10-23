#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
public:
    Customer(int id);
    int getId() const;
    int getEmotion() const;
    void setEmotion(int newEmotion);
    void decreaseEmotion();
    bool isServed() const;
    void setServed(bool value);
    bool isEating() const;
    void setEating(bool value);

private:
    int id;
    int emotion;
    bool served;
    bool eating;
};

#endif
