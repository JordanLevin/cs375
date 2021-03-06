#include "Knapsack.h"

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <queue>

//contains a solution to be written to a file
struct Solution{
    int nodes, leaves;
    Knapsack sack;
    Solution():nodes{0}, leaves{0}, sack{}{}
};

//writes the solution parameter to a file located at the path parameter
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
    int current_best = 0;
    Solution s;
    std::priority_queue<Knapsack> q;

    //initialize priority queue
    k.bound = k.greedy();
    q.push(k);
    while(!q.empty()){
        s.nodes++;
        k = q.top();
        q.pop();

        //debug
        //std::cout << k.full() << std::endl;
        //std::cout << current_best << std::endl;
        //std::cout << k.get_val() << std::endl;
        //std::cout << k.greedy() << std::endl;
        //k.print();

        if(k.full()){
            s.leaves++;
            continue;
        }
        //only continue if the greedy solution is worse than current best
        if(current_best >= k.greedy()){
            s.leaves++;
            continue;
        }

        //calculate the current best value obtained
        if(k.get_val() >= current_best){
            current_best = k.get_val();
            s.sack = k;
        }

        if(k.get_val() == k.greedy()){
            s.leaves++;
            continue;
        }

        //move to next item and check it isn't done
        k.level++;
        if(k.level >= k.items.size()){
            s.leaves++;
            continue;
        }

        //Take the item and make another knapsack
        Knapsack k2 = k;
        k2.items[k2.level].taken = true;
        //calculate bounds for deciding which to explore
        //this is for the priority queue to use
        k.bound = k.greedy();
        k2.bound = k2.greedy();

        q.push(k);
        q.push(k2);
    }
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

    std::cout << input << " " << output << std::endl;

    Knapsack k(input);
    std::sort(k.items.begin(), k.items.end());

    Solution s = solve(k);
    write_output(s, output);
    
    return 0;
}
