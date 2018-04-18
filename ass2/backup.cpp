#include "Knapsack.h"

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <queue>

struct Solution{
    int nodes, leaves;
    Knapsack sack;
};

void write_output(Solution s, std::string path){
    std::ofstream out(path);
    out << s.sack.items.size() << "," << s.sack.get_val() 
        << "," << s.sack.get_count() <<'\n';
    out << s.nodes << "," << s.leaves << '\n';
    for(Item i: s.sack.items){
        if(i.taken)
            out << i.weight << "," << i.profit << std::endl;
    }

}

//solves knapsack problem with best firsts solution
Solution solve(Knapsack k){
    int current_best;
    Solution s;
    std::priority_queue<Knapsack> q;


    //initialize priority queue
    k.bound = k.greedy();
    q.push(k);
    while(!q.empty()){
        s.nodes++;
        k = q.top();
        q.pop();

        std::cout << k.get_val() << std::endl;
        std::cout << k.greedy() << std::endl;
        std::cout << k.full() << std::endl;
        k.print();

        //check it isnt full or done with items
        if(k.full() || k.level >= k.items.size()){
            std::cout <<"LEVEL BAD" << std::endl;
            std::cout << std::endl;
            s.leaves++;
            continue;
        }
        //only continue if the greedy solution is worse than current best
        if(current_best > k.greedy()){
            std::cout <<"BOUND BAD" << std::endl;
            std::cout << std::endl;
            s.leaves++;
            continue;
        }

        //calculate the current best value obtained
        std::cout << "VAL: " <<k.get_val() << std::endl;
        if(k.get_val() > current_best){
            std::cout << "BEST" << std::endl;
            k.print();
            current_best = k.get_val();
            s.sack = k;
        }
        std::cout << std::endl;
        std::cout << std::endl;

        //Take the item and make another knapsack
        Knapsack k2 = k;
        k2.items[k2.level].taken = true;
        //move to next item
        k.level++;
        k2.level++;
        //calculate bounds for deciding which to explore
        //this is for the priority queue to use
        k.bound = k.greedy();
        k2.bound = k2.greedy();

        q.push(k);
        q.push(k2);
    }
    s.sack.print();
    return s;
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

    Solution s = solve(k);
    write_output(s, output);
    
    return 0;
}
