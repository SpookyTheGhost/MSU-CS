/* 
 * File:   stack.h
 * Author: zhangke8
 *
 * Created on March 26, 2014, 3:09 PM
 */

#ifndef STACK_H
#define	STACK_H

#include<ostream>
using std::ostream;
#include<iostream>
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<sstream>
using std::ostringstream;


struct Stack {
    vector<char> data;
    char top();
    void push(char);
    void pop();
    bool empty();
    string stack_to_string();
};






#endif	/* STACK_H */

