#include "Knapsack.h"

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <queue>

int nodes = 0;
int leaves = 0;
int current_best = 0;
int item_count = 0;
Knapsack best;


void write_output(Knapsack k, std::string path){
    std::ofstream out(path);
    out << best.items.size() << "," << current_best << "," << item_count <<'\n';
    out << nodes << "," << leaves << '\n';
    for(Item i: best.items){
        if(i.taken)
            out << i.weight << "," << i.profit << std::endl;
    }

}

int solve(Knapsack k){
    std::priority_queue<Knapsack> q;
    k.bound = k.greedy();
    q.push(k);
    while(!q.empty()){
        nodes++;
        //get top node
        k = q.top();
        q.pop();

        //std::cout << "Value: "<<k.get_val() << std::endl;
        //std::cout << "Greedy: "<<k.greedy() << std::endl;
        //k.print();

        //check it isnt full or done with items
        if(k.full() || k.level >= k.items.size()){
            leaves++;
            continue;
        }

        //calculate the current best value obtained
        if(k.get_val() > current_best){
            current_best = k.get_val();
            item_count = k.get_count();
            best = k;
        }
        if(current_best > k.greedy()){
            leaves++;
            continue;
        }

        //Take the item and make another knapsack
        Knapsack k2 = k;
        k2.items[k2.level].taken = true;
        //look at next item
        k.level++;
        k2.level++;
        //calculate bounds for deciding which to explore
        //this is for the priority queue to use
        k.bound = k.greedy();
        k2.bound = k2.greedy();

        q.push(k);
        q.push(k2);
    }
    return current_best;
}

int main(int argc, char *argv[]){
    if(argc != 3){
        std::cout << "Usage: ./BestFirstSearch <input.txt> <output.txt>\n";
        return -1;
    }

    std::string input, output;

    input = std::string(argv[1]);
    output = std::string(argv[2]);

    Knapsack k(input);
    std::sort(k.items.begin(), k.items.end());

    int s = solve(k);
    write_output(k, output);
    
    return 0;
}
