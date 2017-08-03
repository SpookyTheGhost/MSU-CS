/*
 * File:   Market.cpp
 * Author: zhangke8
 *
 * Created on March 27, 2014, 1:36 PM
 */

#include "market.h"

#include<iostream>
using std::cout;
using std::endl;

#include<fstream>
using std::ifstream;
#include<sstream>
using std::istringstream;
#include<algorithm>
using std::find;
using std::getline;

Market::Market(string filename) {
    ifstream input(filename);
    vector <string> symbol{"AA", "AXP", "BA", "BAC", "CAT", "CSCO",
        "CVX", "DD", "DIS", "GE", "HD"
        , "HPQ", "IBM", "INTC", "JNJ", "JPM", "KFT", "KO", "MCD", "MMM", "MRK",
        "MSFT", "PFE", "PG", "T", "TRV", "UTX", "VZ", "WMT", "XOM"};

    string line;
    long m_date;
    while (getline(input, line)) {// starts outer while loop
        // turns line into string stream
        istringstream iss(line);
        // sends first element of each line to date variable to store
        iss >> m_date;
        double close_price;
        while (iss >> close_price) { // start inner while loop
                stocks[m_date].push_back(close_price);
        } // end inner while loop
    }
}

    double Market::get_price(string stock, long date) {

        vector <string> symbol{"AA", "AXP", "BA", "BAC", "CAT", "CSCO","CVX",
                "DD", "DIS", "GE", "HD", "HPQ", "IBM", "INTC", "JNJ", "JPM",
                "KFT", "KO", "MCD", "MMM", "MRK","MSFT", "PFE", "PG", "T", 
                "TRV", "UTX", "VZ", "WMT", "XOM"};

            auto s = find(symbol.begin(), symbol.end(), stock);
            auto d = stocks.find(date);

            //testing if stock and date are valid
            if ((s != symbol.end()) && (d != stocks.end())) { // start if statement
                for (long x = 0; x <= 30; x++) { // start for loop
                    if (symbol[x] == stock) { // start if statement
                        return stocks[date][x];
                    } // end if statement
                } // end for loop
            }// end if statement

       
                //failed to find date or stock
            else { // start else statement
                return -1.0;
            } // end else statement
    } // ends get_price member function

   