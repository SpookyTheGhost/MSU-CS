 /************************************************** 
 * File:   proj04.cpp
 * Author: zhangke8
 * Section: 007
 *
 ****************************************************/

/*What this program does:
 *This program allows user input for start and end of range as well as the limit
 * to test each number in range.
 * A Lychrel number is a number that has not been proven to converge to a palindrome
 *counts the total number of naturally occurring palindromes, calculated palindromes
 * and number of lychrel numbers.
 */

#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

******************************************************************************************
// swap function
 void order_parameters (long &first, long &second){ // takes in references
     
   /* tests to see if start value is less than end value, swaps otherwise
    */
    
    if (second < first) {
        int temp = first;
        first = second;
        second = temp;
    }
}
************************************************************************************
// reverse function
long rev_num (long n){
  string str = std::to_string(f); // converts properly
  for (string::reverse_iterator rit=str.rbegin(); rit!=str.rend(); ++rit){
      string k = "";
      k.push_back(*rit);
      long reverse = std::stol(k);
      return reverse;    
     } 
}
******************************************************************************
// palindrome test function
bool is_palindrome (long n){
	long reversed = rev_num(n);
bool test = false;
	if (n == reversed) {
		test = true;
	}
	return test;
}
**********************************************************************************
// lychrel algorithm check function
bool check_lychrel (long n, long limit) {
bool test = true;

// test if number is a natural palindrome
if (is_palindrome(n) == true) {
test = false; // not lychrel palindrome
}

/*tests for a lychrel palindrome until the limit hits 0
*works just like a for loop except quits when it hits 0
*which would be equivalent to quitting when exceeding the limit
*/
for (int x = limit; x >=0; x--) {
/*iterate downward through limit until 0 is reached*/
   reverse = rev_num(n); // since initial test failed, reverse num
   n += reverse; // added reversed to original number

   // test if updated number is a palindrome
   if (n == rev_num(n)) {
       test = false; // is not a lychrel number
   }
} 

return test; 
}
*****************************************************************************
// check_range function
long check_range (long start, long end, long limit,
                  long &natural_cnt, long &pal_cnt) {

 // sets up counter for Lychrel numbers
long Lychrel_cnt = 0;
    
    // if end value is smaller than start, swap them
    if (&end < &start) { 
        order_parameters(start,end);  
    }
    
    // starts up range and iterations through it
    for (long k = first; k <= last;  k++) {

// tests initial number if its a natural palindrome
        if (is_palindrome(k) == true) {
natural_cnt++; // update natural palindrome count
        }

// check_lychrel returns true so its a lychrel number
        else if (check_lychrel(k) == true) {
lychrel_cnt++; // adds one to lychrel count
cout << "Found a lychrel number: " << k << endl;
        }

// if check_lychrel returns false then its a palindrome
        else { 
pal_cnt++ ; // update palindrome count
        }

     } // breaks out of for loop range

// need lychrel count to print for main function
return lychrel_cnt; 

} // end of check function

***************************************************************************
// main function
int main () {
// initializing values
long start = 0, finish = 0, limit = 0;
long natural_cnt = 0, pal_cnt = 0;

// prompting user for information
cout << "Provide first, last and limit (all greater than one): ";
cin >> start >> finish >> limit;

    if ((start <= 1) && (finish <= 1) && (limit <= 1)){
// incorrect inputs, prompting user again
   cout << "Provide first, last and limit (all greater than one): ";
   cin >> start >> finish >> limit;    
   }

   else { // inputs are okay, so actual function begins
// calls check_range
    check_range (start,end,limit,&natural_cnt,&pal_cnt); 
// sets check_range's return to variable
lychrel_cnt = check_range (start,end,limit,&natural_cnt,&pal_cnt); 

// printing summary and count values
cout << "Summary for range " << start << ", " << finish << " with limit: "
     << limit << endl;
cout << Lychrel count: " << lychrel_cnt << ", Natural count: " 
     << natural_cnt << ", Palindrome count: " << pal_cnt << endl;
     }
}
// ************************************************************************************************************

