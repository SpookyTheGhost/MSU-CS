/* 
 * File:   lab04.cpp
 * Author: zhangke8 & feldma91
 *
 * Created on February 6, 2014, 11:42 AM
 */

#include <string>
#include <iostream>
#include<algorithm>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::sort;

// finished loc_to_dec function
long loc_to_dec(string loc){
    long index = 0;
    long convert= 0;
    for (char c = loc[index]; index < loc.size();index++){
        convert += pow(2,loc[index]-'a');
        
    }
    return convert;
}


string abbreviate (string loc){
   sort(loc.begin(), loc.end()); // sorts string
   for (long index = 0; index < loc.size();index++){
       if (loc[index] == loc[index +1]){
           loc[index] = loc[index]+1;
           loc.erase (index+1,1);
           sort(loc.begin(), loc.end());
           
           index = -1;
           
       }
    }
   return loc;
}

string dec_to_loc (long dec){
    string newstr = "";
    while (dec > 0){
        newstr += "a";
        dec--;
    }
    //cout << newstr << endl;
    string result = abbreviate(newstr);
    return result;
}

long add_loc (string loc1,string loc2){
    string mix = loc1+loc2;
    string clean_up = abbreviate(mix);
    long result = loc_to_dec(clean_up);
    return result;
    
}


 int main () {
    //string x = "acdbe";
    string location = "";
    long result = 0;
    cout << "input a location string and an integer: ";
    cin >> location >> result;
    
    // print decimal conversion
    long dec = loc_to_dec(location);
    cout << dec << endl;
    
    // print abbreviate result
    string a = abbreviate(location);
    cout << a << endl;
    
    //print integer and location string
    string loc = dec_to_loc (result);
    cout << loc << endl;
    
    long x = add_loc(location, location);
    cout << x << endl;
}