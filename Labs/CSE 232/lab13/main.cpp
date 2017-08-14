#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string;

#include "singlelink.h"

int main () {
  Node<string> beds("beds");
  Node<string> tables("tables");
  Node<string> chairs("chairs");



  SingleLink<string>sl;
  sl.append_back(beds);
  sl.append_back(tables);
  sl.append_back(chairs);

  Node<string> stuff("stuff");
  sl.append_back(stuff);
  sl.print_list(cout);
  
//  sl.del("beds");
//  sl.del("chairs");
//  sl.print_list(cout);
}
