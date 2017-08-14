/* 
 * File:   job.h
 * Author: zhangke8
 * Section: 007
 * Created on April 2, 2014, 7:19 PM
 */

#ifndef JOB_H
#define	JOB_H

class Job {
private:

    long time_left = 0;
    long update = 0;
    long finish_time = 0;

public:
    // constructors

    Job() {};

    Job(long x, long y, long z) : JobID(x), Arrival_time(y), Service_time(z) {};
    long JobID = 0;
    long Arrival_time = 0;
    long Service_time = 0;
    // members
    long get_job_id();
    long get_arrival_time();
    long get_time_left();
    void update_time_left(long);
    void set_finish_time(long);
    long get_finish_time();

};

#endif	/* JOB_H */


