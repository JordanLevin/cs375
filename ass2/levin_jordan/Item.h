#ifndef ITEM_H
#define ITEM_H

struct Item{
    int weight;
    int profit;
    bool taken;

    Item(): weight(0), profit(0), taken(false){}

    //so that items can be sorted at start
    bool operator<(const Item& other){
        //used > so std::sort goes high to low
        return (float)profit/(float)weight >
        (float)other.profit/(float)other.weight;
    }
};

#endif /* ifndef ITEM_H */
