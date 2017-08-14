/* 
 * File:   vector.h
 * Author: zhangke8
 *
 * Created on March 19, 2014, 3:19 PM
 */

#ifndef VECTOR_H
#define	VECTOR_H

#include<string>
#include<sstream>

using std::string;
using std::ostringstream;

struct MathVector {
    long x;
    long y;

    MathVector add(const MathVector &);
    MathVector mult(long);
    long mult(const MathVector &);
    double magnitude();
};


string vec_to_str (const MathVector &);

#endif	/* VECTOR_H */

