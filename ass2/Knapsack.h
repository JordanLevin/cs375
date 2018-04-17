#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
#include <string>
#include "Item.h"

struct Knapsack{

    //amount of items and weight limit
    int count, weight_limit;
    //list of items
    std::vector<Item> items;
    //which item is being considered
    unsigned int level;
    //bound for best first search
    int bound;

    Knapsack() = default;
    Knapsack(std::string path);
    //calculate weight of items taken
    int get_val() const;
    //calculate value of items taken
    int get_weight() const;
    //counts amount of items used
    int get_count() const;
    //returns if bag is overfilled
    bool full() const;
    //read a file and populate knapsack with data
    void read(std::string path);
    //print knapsack for debugging
    void print() const;
    //use greedy algorithm to find upper bound
    int greedy();
    //overload less than for the priority queue
    bool operator<(const Knapsack& other) const;
};


#endif /* ifndef KNAPSACK_H */
