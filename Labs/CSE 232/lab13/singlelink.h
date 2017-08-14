#ifndef SINGLELINK_H
#define SINGLELINK_H

#include<iostream>
using std::ostream;
using std::cout;
using std::endl;
#include<stdexcept>
using std::out_of_range;

template <typename T>
struct Node {
public:
    Node *next_;
    T data_;

    Node() : next_(nullptr) {
    };

    Node(T d) : data_(d), next_(nullptr) {
    };
};

template <typename T>
class SingleLink {
private:
    Node<T> *begin_;
    Node<T> *last_;

public:

    SingleLink() : begin_(nullptr), last_(nullptr) {
    };

    SingleLink(Node<T> n) : begin_(&n), last_(&n) {
    };
    void append_back(Node<T> &val);
    ostream& print_list(ostream &out);
    bool del(T val);
    Node<T>& operator[](size_t indx);
};

// append node n to the end of the list
// fast because of the last_ pointer

template<typename T>
void SingleLink<T>::append_back(Node<T> &n) {
    if (last_ != nullptr) {
        last_->next_ = &n;
        last_ = &n;
    } else {
        begin_ = &n;
        last_ = &n;
    }
}

template<typename T>
ostream& SingleLink<T>::print_list(ostream &out) {
    Node<T> *temp = begin_;
    out << "List: ";
    while (temp != nullptr) {
        out << temp->data_ << ", ";
        temp = temp->next_;
    }
    out << endl;
    return out;
}

//template<typename T>
//bool SingleLink<T>::del(T val) {
//    Node<T> *tempa = begin_;
//    Node<T> *tempb = begin_->next_;
//    while (tempb != nullptr) {
//        
//        if (tempb->data_ == val) {
//            tempa->next_ = tempb->next_;
//           
//            return true;
//        }
//        tempb = tempb->next_;
//        tempa = tempa->next_;
//        
//    }
//    return false;
//}

template<typename T>
bool SingleLink<T>::del(T val) {
    bool ret_val = false;
    Node<T> *first, *second;
    first = second = begin_;
    if (first != nullptr) {
        if (begin_->data_ == val) {
            begin_ = begin_->next_;
            cout << "found it: " << (begin_ == nullptr) << endl;
            ret_val = true;
        } else {
            cout << "looking" << endl;
            while (first != nullptr) {
                if (first->data_ == val) {
                    second->next_ = first->next_;
                    first = first->next_;
                    ret_val = true;
                }
                second = first;
                first = first->next_;

            }
        }
    }
    return ret_val;
}

template<typename T>
Node<T>& SingleLink<T>::operator[](size_t indx) {
    if (indx < 0) {
        throw out_of_range("negative index");
    }
    int cnt = 0;
    auto itr = begin_;
    while (itr != nullptr) {
        if (cnt == indx) {
            return *itr;
        }
        itr = itr->next_;
        cnt++;
    }

}

#endif