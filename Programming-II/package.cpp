/*
* File:   package.cpp
* Author: zhangke8
*
* Created on April 9, 2014, 7:22 PM
*/


/* Purpose: this is to set up each individual "package" and to allow printing
* of said package.
*/

#include "package.h"
#include <iostream>
using std::endl;
#include<algorithm>
using std::transform;

bool package_compare (const Package & lhs, const Package& rhs) {
/* if the ratio of priority to weight of lhs is greater, return true
* otherwise return false
*/
return ((lhs.priority_/lhs.weight_)>(rhs.priority_/rhs.weight_));
}

ostream &operator<< (ostream& o, Package p){
    // print out each package
   o << "  weight: " << p.weight_ << "  Priority: "
       << p.priority_ << endl;
   return o;
}