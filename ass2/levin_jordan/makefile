FLAGS = -g -Wall -Wextra -std=c++14

main: Knapsack.o main.cpp
	g++ $(FLAGS) main.cpp Knapsack.o -o BestFirstSearch
Knapsack.o: Knapsack.cpp Knapsack.h Item.h
	g++ $(FLAGS) Knapsack.cpp -c
