/*
* File:   scheduler.h
* Author: zhangke8
* Section: 007
* Created on April 3, 2014, 1:55 PM

*/

#ifndef SCHEDULER_H
#define    SCHEDULER_H
#include "job.h"
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<algorithm>
using std::swap;

class Scheduler {

private:
  vector<Job> arrivals;
  vector<Job> process;
  vector<Job> finish;
  long clock_time = 0;
  long job_count = 0;
  long total = 0;


public:
  //constructors
  Scheduler() {};
//  Scheduler(long x, long y, long z, vector<vector<long>>v1,vector<vector<long>>v2, vector<vector<long>>v3):arrivals(v1), process(v2), finish(v3), clock_time(0), job_count(0),total(0) {};

  

  // members

  void load_jobs(string);
  void round_robin();
  bool finished();
  void display();

};

#endif    /* SCHEDULER_H */