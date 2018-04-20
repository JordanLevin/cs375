#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
#include <string>
#include "Item.h"

//Represents a possible knapsack. This is used for nodes in the best first sesarch
struct Knapsack{

    //amount of items and weight limit
    int count, weight_limit;
    //list of items
    std::vector<Item> items;
    //which item is being considered
    int level = -1;
    //bound for best first search
    int bound;

    Knapsack() = default;
    Knapsack(std::string path);
    //returns weight of items taken
    int get_val() const;
    //returns value of items taken
    int get_weight() const;
    //returns amount of items used
    int get_count() const;
    //returns true if bag is overfilled
    bool full() const;
    //read a file and populate knapsack with data
    void read(std::string path);
    //print knapsack for debugging
    void print() const;
    //returns upper bound using greedy algorithm
    int greedy();
    //overload less than for the priority queue
    bool operator<(const Knapsack& other) const;
};


#endif /* ifndef KNAPSACK_H */
