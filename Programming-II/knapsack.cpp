/*
 * File:   knapsack.cpp
 * Author: zhangke8
 * Section: 007
 * Created on April 10, 2014, 1:04 PM
 */

#include<vector>
using std::vector;
#include<algorithm>
using std::copy;
#include<iostream>
using std::cout; using std::endl;

#include "knapsack.h"

bool Knapsack::empty() {
    /* checks if knapsack is empty
     * or not
     */
	return (size_ == 0);
} // end empty method


bool Knapsack::add(Package p) {
    /* tests if adding will exceed weight limit
     * if adding does not exceed weight limit then
     * package is added. if size is exceeded then memory is doubled
     */

    // exceeding weight limit, return false
    if ((p.weight_ + weight()) > weight_limit_) {
        return false;
    } 
    
    else { // authorized to add package
        Package *new_data_;
        if (capacity_ == size_) { // double size of memory
            new_data_ = new Package[2 * capacity_];
            copy(data_, data_ + size_, new_data_);
            swap(new_data_, data_);
            delete [] new_data_; // give OS memory back
            new_data_ = nullptr; // reset pointer to null
        }
        data_[size_] = p; // add package to knapsack
        size_++; // update size
	weight(); // update weight
        return true;
    }
} // end add method


long Knapsack::weight() {
    /* This adds up the total of all the
     * packages weights in the knapsack
     */

    if (empty() == false) { // test if knapsack is empty
        long weight = 0;
        for (int x = 0; x < size_; x++) {
            weight = weight + data_[x].weight_; // add up the sum of weights
        } // end for loop
        return weight;
    }// end if statement

    else {
        return 0; // knapsack is empty
    }

} // end weight method


long Knapsack::priority() {
    /* This adds up the total of all the
     * packages priorities in the knapsack
     */

    if (empty() == false) { // test if knapsack is empty
        long priority = 0;
        for (int y = 0; y < size_; y++) {
            priority = priority + data_[y].priority_; // add up the sum of priorities
        } // end for loop
        return priority;
    }// end if statement

    else {
        return 0; // knapsack is empty
    }

} // end priority method


void solve_KS(vector<Package>& vp, Knapsack& k) {

    sort(vp.begin(), vp.end(), package_compare); // sort the vector    

    for (auto x : vp) {
        k.add(x); //add weights until weight limit is reached
        if (k.weight() > k.weight_limit_) {
            break;

        }
    } // end of for
} // end friend function


ostream& operator<<(ostream &out, const Knapsack &ks) {
    // prints out each package and other elements
    long cnt = 0;
    out <<  "\nMax weight: " << ks.weight_limit_ << "\nCapacity: "
            << ks.capacity_ << "\nSize: " << ks.size_ << endl; 
    for (int x = 0; x < ks.size_; x++) {
        out << "Package " << cnt << "  weight: " << ks.data_[x].weight_ 
            << "  Priority: " << ks.data_[x].priority_ << endl;
        cnt++;
    } // end for loop
    return out;
}
