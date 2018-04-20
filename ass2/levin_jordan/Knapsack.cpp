#include "Knapsack.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

Knapsack::Knapsack(std::string path):count(0), weight_limit(0), items(), level(-1){
    read(path);
}

void Knapsack::read(std::string path){
    Item item;
    int c, limit, item_val, item_weight;
    char garbage;
    std::ifstream input(path);
    input >> c;
    input >> garbage;
    input >> limit;
    for (int i = 0; i < c; ++i) {
        input >> item_weight;
        input >> garbage;
        input >> item_val;
        item.weight = item_weight;
        item.profit = item_val;
        items.push_back(item);
    }
    count = c;
    weight_limit = limit;
}

bool Knapsack::full() const{
    int weight = 0;
    for(Item i: items){
        if(i.taken)
            weight += i.weight;
    }
    return weight > weight_limit; 
}

int Knapsack::get_val() const{
    int ret = 0;
    for(Item i: items){
        if(i.taken)
            ret += i.profit;
    }
    return ret;
}

int Knapsack::get_weight() const{
    int ret = 0;
    for(Item i: items){
        if(i.taken)
            ret += i.weight;
    }
    return ret;
}

int Knapsack::get_count() const{
    int ret = 0;
    for(Item i: items){
        if(i.taken)
            ret ++;
    }
    return ret;
}

int Knapsack::greedy(){
    int weight = 0;
    int profit = 0;
    bool filled = false;
    Item temp;
    for (int i = level+1; i < items.size(); ++i) {
        if(weight + items[i].weight + get_weight() < weight_limit){
            weight += items[i].weight;
            profit += items[i].profit;
        }
        else{
            temp = items[i];
            filled = true;
            break;
        }
    }
    if(filled){
        int weight_left = weight_limit - get_weight() - weight;
        profit += temp.profit * (float)weight_left/(float)temp.weight;
    }
    return profit + get_val();
}

bool Knapsack::operator<(const Knapsack& other) const{
    return bound < other.bound;
}

void Knapsack::print() const{
    for(Item i: items){
        std::cout << "Weight: " << i.weight << ", Value: " << i.profit <<
            ", Taken: " << i.taken << std::endl;
    }
    std::cout << "Level: " <<level << std::endl;
    std::cout << '\n';
}
