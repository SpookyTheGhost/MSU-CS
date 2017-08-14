/* 
 * File:   vector.cpp
 * Author: zhangke8
 *
 * Created on March 19, 2014, 3:22 PM
 */

#include <iostream>
using std::cout;
using std::endl;
#include "vector.h"
#include <cmath>

MathVector MathVector::add(const MathVector &v) {
    long new_x = x + v.x;
    long new_y = y + v.y;
    MathVector v1;
    v1.x = new_x;
    v1.y = new_y;
    return v1;
}

MathVector MathVector::mult(long num) {
    long new_x = x * num;
    long new_y = y * num;
    MathVector v1;
    v1.x = new_x;
    v1.y = new_y;
    return v1;
}
    
long MathVector::mult(const MathVector &v) {
    long result = x * v.x + y * v.y;
    return result;
}

double MathVector::magnitude() {
    double result = sqrt(pow(x,2) + pow(y,2));
    return result;
}

string vec_to_str(const MathVector &v) {
    ostringstream oss;
    oss.clear();
    oss << v.x << ": " << v.y;
    return oss.str();
}

