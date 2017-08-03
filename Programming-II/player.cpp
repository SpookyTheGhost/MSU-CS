///* 
// * File:   player.cpp
// * Author: zhangke8
// *
// * Created on March 27, 2014, 7:41 PM
// */

#include "player.h"
using std::pair;
#include<iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include<algorithm>
using std::copy;
using std::transform;
#include<iterator>
using std::ostream_iterator;
#include<sstream>
using std::ostringstream;


Player::Player(double x) {
    cash = x;
};

bool Player::buy (Market &m, string stock, long date, long quantity) {
    vector <string> symbol{"AA", "AXP", "BA", "BAC", "CAT", "CSCO",
        "CVX", "DD", "DIS", "GE", "HD"
        , "HPQ", "IBM", "INTC", "JNJ", "JPM", "KFT", "KO", "MCD", "MMM", "MRK",
        "MSFT", "PFE", "PG", "T", "TRV", "UTX", "VZ", "WMT", "XOM"};

    auto f = find(symbol.begin(), symbol.end(), stock);
    double price = m.get_price(stock, date); // gets stock price
    double stock_cost = price*quantity; // calculates price of stock quantity
    if ((f != symbol.end()) && (cash >= stock_cost) && (stock_cost > 0)) { // start if statement
        stocks[stock] += quantity;
        cash -= stock_cost;
        return true;
    }// end if statement

    else { // start else statement
        return false;
    } // end else statement
} // end buy member function

bool Player::sell (Market &m, string stock, long date, long quantity) {
    vector <string> symbol{"AA", "AXP", "BA", "BAC", "CAT", "CSCO",
        "CVX", "DD", "DIS", "GE", "HD"
        , "HPQ", "IBM", "INTC", "JNJ", "JPM", "KFT", "KO", "MCD", "MMM", "MRK",
        "MSFT", "PFE", "PG", "T", "TRV", "UTX", "VZ", "WMT", "XOM"};

    auto s = find(symbol.begin(), symbol.end(), stock);
    double price = m.get_price(stock, date); // gets stock price
    double money_earned = price*quantity; // calculates money earned selling

    if ((s != symbol.end()) && (stocks[stock] >= quantity) && (money_earned > 0)) { // start if statement
            stocks[stock] -= quantity;
            cash += money_earned;
            return true;
        }// end if statement

    else { // start else statement
        return false;
    } // end else statement
} // end sell member function

typedef pair<string, long> Cnt;

string s(Cnt p) {
    ostringstream oss;
    oss << p.first << ", quantity " << p.second << endl;
    return oss.str();
}



string Player::to_str() {
    ostringstream o;
    o << "Player has: " << Player::cash << " dollars, Stocks are: \n";
    transform(stocks.begin(),stocks.end(),ostream_iterator<string>(o, ""), s);
    return o.str();
}


//
//int main() {
//
//    return 0;
//}