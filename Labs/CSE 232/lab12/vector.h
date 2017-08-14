/* 
 * File:   vector.h
 * Author: zhangke8
 *
 * Created on April 9, 2014, 3:17 PM
 */

#ifndef VECTOR_H
#define	VECTOR_H
#include<stdexcept>
using std::range_error;
#include <algorithm> 
using std::swap;
using std::copy;
#include<iostream>
using std::endl;
using std::cout;



namespace student {

    template<typename T>
    class vector {
    private:

        T *data_;
        size_t capacity_;
        size_t size_;

    public:
        // take defaults for the following 4. Vector handles it already.

        vector(size_t capacity = 10) {
            capacity_ = capacity;
            size_ = 0;
            data_ = new T[capacity_];
        }
        ~vector();

        //vector operations
        size_t capacity();
        size_t size();
        void push_back(T val);
        T& operator[](size_t val);
    };

    template<typename T>
    vector<T>::~vector() {
        delete [] data_;
    }

    template<typename T>
    size_t vector<T>::capacity() {
        return capacity_;
    }

    template<typename T>
    size_t vector<T>::size() {
        return size_;
    }

        template <typename T>
        void vector<T>::push_back(T val){
            T *new_data_;
            if (capacity_ == size_){
            capacity_*=2;
            new_data_ = new T[capacity_];
            copy(data_,data_+size_,new_data_);
            swap(new_data_,data_);
            delete [] new_data_;
            }
            data_[size_] = val;  
            size_++;
        }

    template<typename T>
    T& vector<T>::operator[] (size_t val) {
        if (val < size_) {
            return data_[val];
        } 
        else {
            throw range_error("out of range");
        }
    }

}
#endif	/* VECTOR_H */