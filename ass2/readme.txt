# CS375 Assignment 2
# Jordan Levin

=====================================
Instructions
=====================================

1. In directory levin_jordan run "make"
2. Run "./BestFirstSearch input.txt output.txt" where input.txt
   is a valid file in the directory


=====================================
Data structures and implementation
=====================================

The main data structures used are a vector and a priority queue. The
Knapsack class uses a vector to keep track of all items in the knapsack
as well as which items have been used in the current knapsack. The knapsack
also stores a variety of other information because it is used as the node
for the priority queue.

The other data structure used is a priority queue (std::priority_queue) from 
<queue> in the standard library. The priority queue stores Knapsack objects which 
represent nodes in the tree. Because the Knapsack class has the comparison operator
overloaded the priority queue keeps the Knapsack with highest bound on top in order
to perform the best first search.

=====================================
Analysis of computation time
=====================================

The program uses a best first search branch-and-bound algorithm to find an 
optimal solution to the 0-1 Knapsack problem. This is achieved by exploring the
most promising node available, the node with the highest bound. In the worst
case scenario the algorithm will fail to prune any nodes and every option will
need to be explored. This means that in the worst case the algorithm has an O(2^n)
time complexity.

=====================================
Classes and interaction
=====================================

Classes used are: Item, Knapsack, Solution. Priority_queue also but I didnt make that.

The Item class just stores the weight and value of an item, as well as if it is taken.

The Knapsack class is used as the nodes for the best first search. The Knapsack contains
a list of items as well as the amount of items total, the weight limit, the bound, and
the level in the tree. The < operator is overloaded so that the priority_queue will get
the Knapsack with the highest bound. The Knapsack class also contains a function which
calculates the bound using the greedy algorithm for fractional knapsack, and some functions
to get information about the weight used, value, and number of items in the knapsack.

The Solution class just contains the information needed to write to the solution file.
It contains the optimal knapsack as well as node count and leaf count.

The main function runs the solve function which creates a priority queue of knapsacks
and returns a solution object.
