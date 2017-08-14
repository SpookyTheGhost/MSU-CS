
#include<iostream>
using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<algorithm>
using std::copy;
#include<iterator>
using std::ostream_iterator;
#include<functional>
using std::function;

#include "test.h"



bool greaterThan(long &a, long &b){
  return (a > b);
}

int main (){
  vector<long> v1{8,2,6,4};
  copy(v1.begin(), v1.end(), ostream_iterator<long>(cout, ", "));
  cout << endl;
  sort_longs(v1);
  // is it sorted?
  copy(v1.begin(), v1.end(), ostream_iterator<long>(cout, ", "));  
  cout << endl;

   vector<long>v2{8,2,6,4};
   copy(v2.begin(), v2.end(), ostream_iterator<long>(cout, ", "));
   cout << endl;
   sort_iterators(v2.begin(), v2.end());
   // is it sorted?
   copy(v2.begin(), v2.end(), ostream_iterator<long>(cout, ", "));  
   cout << endl;

   vector<long>v3{8,2,6,4};
   copy(v3.begin(), v3.end(), ostream_iterator<long>(cout, ", "));
   cout << endl;
   sort_template(v3.begin(), v3.end());
   // is it sorted?
   copy(v3.begin(), v3.end(), ostream_iterator<long>(cout, ", "));  
   cout << endl;
   string s="uncopyrightable";
   cout << s << endl;
   sort_template(s.begin(), s.end());
   // is the string sorted?
   cout << s << endl;

   vector<long>v4{8,2,6,4,5,6,4,8,9,1,3,5,4,4,333,44,88,22,44,6,2,4,5,4};
   copy(v4.begin(), v4.end(), ostream_iterator<long>(cout, ", "));
   cout << endl;
   sort_function(v4.begin(), v4.end(), greaterThan);
   // should be sorted now biggest to smallest ?
   copy(v4.begin(), v4.end(), ostream_iterator<long>(cout, ", "));  
   cout << endl;

}
  
       
