/*************************************************
* File:   proj06.cpp
* Author: zhangke8
* Section: 007
* Created on February 25, 2014, 1:51 PM
****************************************************/

/********************************************************
*This is the header file for rand_walk, which is project06
*********************************************************/

#ifndef RAND_WALK_H
#define RAND_WALK_H


#include<string>
#include<vector>
#include<random>
#include<map>

using std::string; using std::vector; using std::default_random_engine;
using std::map;

// declaring all required functions
void read_index(map<long, string> &, string &);
void read_arc(map<long, vector<long>> &, string &);
long select(default_random_engine &, vector<long> &);
map<string, long> do_walk(map<long, vector<long>> &, map<long,
string> &, long ,long, default_random_engine &);


#endif    /* RAND_WALK_H */


