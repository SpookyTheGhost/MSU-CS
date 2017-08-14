/* 
 * File:   circbuf.cpp
 * Author: zhangke8
 *
 * Created on April 2, 2014, 3:47 PM
 */

#include "circbuf.h"
#include <iostream>
using std::endl;
using std::cout;
#include<algorithm>
using std::transform;
#include<iterator>
using std::ostream_iterator;
#include<sstream>
using std::ostringstream;
#include<string>
using std::string;
#include<stdexcept>
using std::runtime_error;

long CircBuf::pop_front() {

    if (CircBuf::empty() != false) {
        if (front_ > size_) {
            front_ = 0;
            front_++;
            return buffer_[front_ - 1];
        }
        else {
            front_++;
            return buffer_[front_ - 1];
        }
    } else {
//        throw runtime_error("Accessing an empty Circular Buffer");
        return false;
    }
}

//bool CircBuf::remove() {
//    if (buffer_.empty() != false) {
//        front_++;
//        count_--;
//        return true;
//    }
//    else {
//        return false;
//    }
//}

bool CircBuf::add(long x) {
    if (CircBuf::full() == false) {
        buffer_[back_] = x;
        count_++;
        back_++;
        return true;
    } else {
        back_ = 0;
        buffer_[back_] = x;
        count_++;
        back_++;
        return false;
    }
}

bool CircBuf::empty() {
    if (count_ == 0) {
        return true;
    } else {
        return false;
    }
}

bool CircBuf::full() {
    if (count_ == size_) {
        return true;
    } else {
        return false;
    }
}

ostream& operator <<(ostream &out, const CircBuf &cb) {
    for (auto x : cb.buffer_) {
        out << x << " ";
    }
    return out;
}


