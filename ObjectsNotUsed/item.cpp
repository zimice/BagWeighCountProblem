#include <iostream>
#include "item.h"

using namespace std;

Item::Item(){
    price=0;
    weight=0;
}
Item::Item(double price, double weight) : price(price),weight(weight){
    //this->price = price;
    //this->weight = weight;
}
double Item::getPrice(){
    return price;
}
double Item::getWeight(){
    return weight;
}