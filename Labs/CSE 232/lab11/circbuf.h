/* 
 * File:   circbuf.h
 * Author: zhangke8
 *
 * Created on April 2, 2014, 3:09 PM
 */

#ifndef CIRCBUF_H
#define	CIRCBUF_H

#include<ostream>
using std::ostream;
#include<vector>
using std::vector;


class CircBuf {
 private:
     long size_ ;
     long count_;
     long front_;
     long back_;
     vector<long> buffer_;

public:
  // constructors
 CircBuf() : size_(10), count_(0), front_(0), back_(0), buffer_(10,0) { };
 CircBuf(size_t x): size_(x), count_(0), front_(0), back_(0), buffer_(x,0) { };
 
  // members
long pop_front();
bool remove();
bool add(long);
bool empty();
bool full();

friend ostream& operator << (ostream &out, const CircBuf &cb);

};

#endif	/* CIRCBUF_H */


ostream& operator << (ostream &out, const CircBuf &cb);

