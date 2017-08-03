/* 
 * File:   player.h
 * Author: zhangke8
 *
 * Created on March 27, 2014, 7:38 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "market.h"

#include<string>
using std::string;
#include<map>
using std::map;

struct Player {
    double cash; 
    map <string, long> stocks;
    bool buy (Market &m, string, long, long);
    bool sell (Market &m, string, long, long);
    string to_str();
    
    Player(double x);
};

#endif	/* PLAYER_H */

