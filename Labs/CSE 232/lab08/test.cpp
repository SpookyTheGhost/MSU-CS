#include<iostream>
using std::cout;
using std::endl;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<algorithm>
using std::copy;
using std::swap;
using std::min_element;
using std::max_element;
#include<iterator>
using std::ostream_iterator;
#include<functional>
using std::function;
#include "test.h"

void sort_longs(vector<long> &v) {
    string my_str;
    long temp;
    long temp2;
    long index2;

    vector<long>::iterator itr;
    int cnt = 0;
    long index;

    for (long i = 0; i < v.size(); i++) {
        temp = v[i];
        for (long j = i; j < v.size(); j++) {
            if (temp > v[j]) {
                index = j;
                temp = v[j];
                swap(v[i], v[index]);
            }
        }
    }





}

void sort_iterators(vector<long>::iterator first,
        vector<long>::iterator last) {
    long temp2;
    long index2;
    vector<long>::iterator itr;

    for (auto itr = first; itr != last; itr++) {
        temp2 = *itr;
        for (auto k = first; k != last; k++) {
            if (temp2 < *k) {
                index2 = *k;
                temp2 = *k;
                swap(*k, *itr);
            }
        }
    }
}

