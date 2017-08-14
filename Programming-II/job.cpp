/* 
 * File:   job.cpp
 * Author: zhangke8
 * Section: 007
 * Created on April 2, 2014, 7:23 PM
 */
#include "job.h"

long Job::get_job_id() {
    return JobID;
}

long Job::get_arrival_time() {
    return Arrival_time;
}

long Job::get_time_left() {
    return time_left;
}

void Job::update_time_left(long cnt) {
    time_left = Service_time - cnt;
}

void Job::set_finish_time(long t) {
    finish_time = t;
}

long Job::get_finish_time() {
    return finish_time;
}