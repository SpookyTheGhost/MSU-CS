/*
 * File:   package.h
 * Author: zhangke8
 *Created on April 9, 2014, 7:17 PM
 *
 */

#ifndef PACKAGE_H
#define  PACKAGE_H

#include <sstream>
using std::ostream;

struct Package {
    // sets up each individual package elements

    long weight_;
    long priority_;

    //constructors

    Package() {
        weight_ = 1;
        priority_ = 0;
    };

    Package(long weight, long priority) {
        weight_ = weight;
        priority_ = priority;
    }

};

bool package_compare(const Package & lhs, const Package& rhs);
ostream &operator<<(ostream&, Package p);

#endif    /* PACKAGE_H */