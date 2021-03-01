#pragma once
class Item
{

public:
    Item();
    Item(double price, double weight);
    double getWeight();
    double getPrice();
private: 
    double price;
    double weight;
};