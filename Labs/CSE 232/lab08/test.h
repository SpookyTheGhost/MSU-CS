/*

* File:   functions.h

* Author: nunezarn

*

* Created on March 12, 2014, 2:54 PM

*/


#ifndef FUNCTIONS_H
#define    FUNCTIONS_H
#include<iostream>
using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<algorithm>
using std::copy; using std::swap;
using std::min_element;
using std::max_element;
#include<iterator>
using std::ostream_iterator;
#include<functional>
using std::function;
using std::vector; using std::string; using std::cin; using std::cout;
using std::endl;


void sort_longs(vector<long> &);
void sort_iterators(vector<long>::iterator first,
vector<long>::iterator last);
template <typename Iterator>
void sort_template(Iterator first, Iterator last){
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



template <typename Iterator, typename Func>
void sort_function(Iterator first, Iterator last, Func fn){
    long temp2;
//    long index2;
    vector<long>::iterator itr;


    for (auto itr = first; itr != last; itr++) {
       temp2 = *itr;
       for (auto k = first; k != last; k++) {
           if ( fn(temp2, *k) == false ) {
//               index2 = *k;
//               temp2 = *k;
               swap(*k, *itr);
           }
       }
    }
}



#endif    /* FUNCTIONS_H */