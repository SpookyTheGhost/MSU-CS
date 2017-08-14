///*
// * File:   scheduler.cpp
// * Author: zhangke8
// * Section: 007
// * Created on April 3, 2014, 2:06 PM
// */

#include "scheduler.h"
#include<iostream>
using std::cout;
using std::endl;
#include<fstream>
using std::ifstream;
#include<sstream>
using std::istringstream;
#include<algorithm>
using std::reverse;
using std::find;
#include<cmath>
#include<iomanip>
using std::fixed;
using std::setprecision;

void Scheduler::load_jobs(string file) { // this works
    ifstream f(file);
    string line;
    while (getline(f, line)) { // start while loop
        long id, arrival, service; // sets variables to store
        istringstream iss(line); // turns line into string stream format
        //puts each line element into variable to store
        iss >> id >> arrival >> service;
        //creates a temporary vector to store job elements
        Job j;
        j.JobID = id;
        j.Arrival_time = arrival;
        j.Service_time = service;
        job_count++;
        arrivals.push_back(j);
    } // ends load_jobs

} // ends load_jobs

bool Scheduler::finished() {
    return ((arrivals.empty()) && (process.empty()));
}

void Scheduler::round_robin() {
    while (finished()) {
        //initial check for arrivals
        cout << "start while" << endl;
        for (auto itr = arrivals.begin(); itr != arrivals.end(); itr++) { // start arrival for loop
            if (itr->get_arrival_time() <= clock_time) { //check arrival against current clock time
                process.push_back(*itr); // adding job to process vector if true
                arrivals.erase(itr);
            } // end if statement
        } // end for loop  
        //        cout << process.size() << endl;
        cout << "end arrival check" << endl;

        vector <Job> queue;
        // actual Round Robin Simulation
        cout << "start simulation" << endl;
        for (auto itr = process.begin(); itr != process.end(); itr++) {
            //            for (auto y : process) { // start simulation for loop!
            queue.push_back(*itr); // creating copy of vector to reverse;
            reverse(queue.begin(), queue.end()); // reversed copy
            Job current = queue[queue.size() - 1]; // getting first job
            process.erase(itr); // remove current job
            queue.pop_back(); // erase job from queue
            cout << " new job and remove?" << endl;
            long cnt = 0;

            cout << "enter if statements?" << endl;
            if (current.get_time_left() != 0) {
                current.update_time_left(cnt++); // update service time
                reverse(queue.begin(), queue.end()); // reverse back to normal
                queue.push_back(current);
            } else {
                current.set_finish_time(clock_time);
                finish.push_back(current);
            }
        } // end for loop

        cout << "start arrival check again " << process.size() << endl;
        // check for new jobs
        clock_time++;
        for (auto itr = arrivals.begin(); itr != arrivals.end(); itr++) { // start arrival for loop
            if (itr->get_arrival_time() <= clock_time) { //check arrival against current clock time
                process.push_back(*itr); // adding job to process vector if true
                arrivals.erase(itr);
            } // end if statement
        } // end for loop  

    } //end simulation for loop 
} // end round_robin member function

void Scheduler::display() { // this also works
    cout << "---------------------------------------------------------";
    cout << "\n\tJobID\tArrival time\t\tFinish time\t" << endl;
    for (Job y : finish) {
        cout << "\t" << y.JobID << "\t\t" << y.Arrival_time << "\t\t"
                << y.get_finish_time() << endl;
        total += (y.get_finish_time());
    }

    double x = total / job_count; // should be 109/7

    cout << total << endl;

    cout << job_count << endl;
    cout << fixed << setprecision(2);
    cout << "The average amount of time to finish one job is "
            << x << " time units.\n";
    cout << "---------------------------------------------------------" << endl;

}

//int main () {
//return 0;    
//}

