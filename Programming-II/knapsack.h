/*
 * File:   knapsack.h
 * Author: zhangke8
 * Section: 007
 * Created on April 9, 2014, 7:44 PM
 */

#ifndef KNAPSACK_H
#define KNAPSACK_H

#include "package.h"
#include<vector>
using std::vector;
#include<algorithm>
using std::copy;
using std::swap;
using std::sort;

class Knapsack {
    // creates the sack of packages, sets everything up

private:
    Package* data_;
    long weight_limit_;
    long capacity_;
    long size_;

public:
    // constructors
    Knapsack() = default;

    Knapsack(long max) {
        weight_limit_ = max;
        capacity_ = 10;
        size_ = 0;
        data_ = new Package[capacity_];

    }

    ~Knapsack() {
        delete [] data_;
    }
    Knapsack(const Knapsack &);
    // member functions
    bool add(Package p);
    bool empty();
    long weight();
    long priority();

    friend ostream& operator<<(ostream &out, const Knapsack &ks);
    friend void solve_KS(vector<Package>& vp, Knapsack& k);

};

ostream& operator<<(ostream &out, const Knapsack &ks);
void solve_KS(vector<Package>& vp, Knapsack& k);

#endif /* KNAPSACK_H */