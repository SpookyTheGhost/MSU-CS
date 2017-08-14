#include<iostream>
#include<string>
using std::cout; using std::endl; using std::cin;
using std::string;
#include "stack.h"

int main (){
  Stack stk;
  string user_string="", reverse_string="";

  cout << "Give me a string to reverse:";
  getline(cin, user_string);

  for (auto ch : user_string)
    stk.push(ch);

  cout << "After processing, stack contains:"<<endl;
  cout << stk.stack_to_string() <<endl;

  while (!stk.empty()){
    reverse_string = reverse_string + stk.top();
    stk.pop();
  }

  cout<<"Original String was:"<<user_string<<endl;
  cout<<"Reversed String was:"<<reverse_string<<endl;

  
}
