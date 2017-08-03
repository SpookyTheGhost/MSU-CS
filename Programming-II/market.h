/* 
 * File:   market.h
 * Author: zhangke8
 *
 * Created on March 27, 2014, 1:03 PM
 */

#ifndef MARKET_H
#define	MARKET_H

#include<vector>
using std::vector;
#include<string>
using std::string;
#include<map>
using std::map;

struct Market {
    
    // key is date, value is vector of close prices
    map <long, vector<double>> stocks; 
    double get_price(string, long); // gets price of valid stock

    Market(string filename); 
};



#endif	/* MARKET_H */

