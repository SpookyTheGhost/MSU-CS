/* File:   rand_walk.cpp
 * Author: zhangke8
 * section: 007
 * Created on February 25, 2014, 1:56 PM
 */

#include "rand_walk.h"
#include<iostream>
#include<fstream>
#include<algorithm>

using std::ifstream; 
using std::find; using std::default_random_engine;
using std::uniform_int_distribution; 

/**************************************************************************
 * WHAT THIS PROGRAM DOES
 * These functions allow the user to read in 2 files and extract 
 * the website names, website ids and the connecting ids into appropriate 
 * vectors. A random walk can then be performed using the information 
 * gained from the vectors.
 *****************************************************************************/

//*************************************************************************//
void read_index (map<long, string> &m, string &file_name){
/* saves the first and second elements, saves them to a map as key,value pairs
 * with second as the key and first as the value.
 */   

    // opens example_node
    ifstream input(file_name);
    string website; // saving file's first element
    long id; // saving file's second element
    while(input >> website >> id){
         m[id] = website;  // add the key,value to the map      
        }   

    input.close();  // closes input file to prevent damage
} // end of read_index function
//*************************************************************************//


//*************************************************************************//
void read_arc (map<long, vector<long>> &m, string &file_name){
/* maps all website IDs to vector of all website IDs it connects to
*/
    // opens example_arcs
    ifstream input(file_name);
    long website_id;
    long arc;

    // saves first element to website id, second element to arc
    while(input >> website_id >> arc){
      /* finds the key in the map
       * creates a default vector and adds an element
       * otherwise updates the vector
       */
       m[website_id].push_back(arc);
    }
    input.close();  // closes input file to prevent damage
} // end of read_arc function 
//*************************************************************************//


//*************************************************************************//
long select (default_random_engine &dre, vector<long> &container){
/****************************************************************************
*generates a random engine
*returns a random value from the container vector
*****************************************************************************/
    // start-end range
    uniform_int_distribution<long> dist(0,container.size() - 1);
    return container[dist(dre)]; // return a random value from vector
} // end of select function
//*************************************************************************//


//*************************************************************************//
map<string, long> do_walk (map<long, vector<long>> &arc_map,
map<long, string> &index_map, long total_walks,
long walk_length, default_random_engine &dre){
/* does total number of walks of length walk_length
* calls select for a random connection to one of the connecting ids
* returns a visit count map
*/  

    // collecting all ids into a vector
    vector<long> all_ids;
    for (auto itr = index_map.begin(); itr != index_map.end(); itr++){
        // iterating through every pair of map
        auto id = itr -> first; 
        // adds each website id to the vector
        all_ids.push_back(id); 
        }

    // creates a map
    map<string, long> visit_count; 
    
    for (long x = 0; x < total_walks; ++x){
        // gets a random starting node
        long node = select(dre, all_ids);
        // node is a dead end, update count and go to next walk
        if (arc_map.find(node) == arc_map.end()){ 
            ;
        } // ends if statement
        else{
            long arc_int = node; // starting arc    
            ++visit_count[index_map[node]];
            for (long y = 0; y < walk_length; ++y){
                // node has arcs, select an arc
                long arc = select(dre, arc_map[arc_int]); 
                arc_int = arc; // current arc

                // arc is a dead end, update count and go to next walk          
                if (arc_map.find(arc) == arc_map.end()){
                    break; //start new walk
                  } // ends inner if statement

                else { 
                  // attempt walk length, update arc count
                  ++visit_count[index_map[arc]];
                  } // ends inner else statement
               } // ends inner for loop
         } // ends outer else statement
    } // ends outer for loop
    return visit_count;
} // end of do_walk function 
//*************************************************************************//