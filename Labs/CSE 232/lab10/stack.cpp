/* 
 * File:   stack.cpp
 * Author: zhangke8
 *
 * Created on March 26, 2014, 3:19 PM
 */


#include "stack.h"
#include<algorithm>
using std::copy;
#include<iterator>
using std::ostream_iterator;



char Stack::top(){
    return data[data.size()-1];
}

void Stack::push(char s){
    return data.push_back(s);
}

void Stack::pop(){
    data.pop_back();
}


bool Stack::empty(){
    return data.empty();
}


string Stack::stack_to_string(){
    ostringstream out;
    out << "(bottom),";
    copy(data.begin(), data.end(), ostream_iterator<char>(out, ","));
    out << "(top)";
    return out.str();
}


