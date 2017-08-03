#ifndef SINGLELINKMAP_H
#define SINGLELINKMAP_H

#include<iostream>
using std::ostream;
using std::cout;
using std::endl;
#include<algorithm>
using std::swap;

/* NOTES
 * Running just find_then_front works perfectly fine, the random also works!
 * The find_then_swap loses parts of the list, couldn't figure out how to fix it
 * since that fails, the random will segmentation fault. 
 * Try testing the two functions separately.
 * 
 * No need to tell me this in your comments Masoud. 
 */

template <typename Key_Type, typename Value_Type>
struct Node {
public:
    Node *next_;
    Key_Type key_;
    Value_Type value_;

    Node() : key_(Key_Type()), value_(Value_Type()), next_(nullptr) {};

    Node(Key_Type k, Value_Type d) : key_(k), value_(d), next_(nullptr) {};
    ostream & print_node(ostream&);
};

/******************************************************************************/

template<typename Key_Type, typename Value_Type>
ostream& Node<Key_Type, Value_Type>::print_node(ostream& out) {
    /* print a node as "Key:Value"
     * return the ostream passed in
     */

    return out << key_ << ":" << value_;
}

/******************************************************************************/

template <typename Key_Type, typename Value_Type>
class SingleLinkMap {
private:
    Node<Key_Type, Value_Type> *begin_;
    Node<Key_Type, Value_Type> *last_;

public:

    SingleLinkMap() : begin_(nullptr), last_(nullptr) {
    };
    SingleLinkMap(SingleLinkMap &l);
    ~SingleLinkMap();
    SingleLinkMap& operator=(SingleLinkMap l);
    void append_back(const Key_Type &key, const Value_Type &val);
    ostream& print_list(ostream&);
    Value_Type find_then_front(Key_Type);
    Value_Type find_then_swap(Key_Type);
};

/******************************************************************************/
template<typename Key_Type, typename Value_Type>
SingleLinkMap<Key_Type, Value_Type>::SingleLinkMap(SingleLinkMap<Key_Type, Value_Type> &l) {
    /* This is the copy constructor
     * this copies all the elements from one list to another
     */

    this->begin_ = nullptr;
    this->last_ = nullptr;
    for (auto itr = l.begin_; itr != nullptr; itr = itr->next_) {
        this->append_back(itr->key_, itr->value_); // copy list
    }
}
/******************************************************************************/

/******************************************************************************/
template<typename Key_Type, typename Value_Type>
SingleLinkMap<Key_Type, Value_Type>::~SingleLinkMap() {
    /* delete each node individually
     * you need two pointers, delete the trailing pointer node
     * Keep it straight!
     */

    Node<Key_Type, Value_Type> *current = begin_; // current node
    Node<Key_Type, Value_Type> *next = current->next_; // stores next node
    
    while (current != nullptr) { // continue deleting until end of list
        next = current->next_; // advance next node
        delete current;
        current = next; // set current after deletion to next node
    }
    
    //delete next; // delete last node
    next = nullptr; // preventing memory leaks
}
/******************************************************************************/

/******************************************************************************/
template<typename Key_Type, typename Value_Type>
SingleLinkMap<Key_Type, Value_Type>& SingleLinkMap<Key_Type, Value_Type>::
operator=(SingleLinkMap<Key_Type, Value_Type> l) {
    /* This swaps the contents of a list and then calls the destructor
     */

    swap(this->begin_, l.begin_); // swap begin pointers
    swap(this->last_, l.last_); // swap last pointers
    return *this;
}

/******************************************************************************/
template<typename Key_Type, typename Value_Type>
void SingleLinkMap<Key_Type, Value_Type>::append_back(const Key_Type &key,
                                                      const Value_Type &val) {
    /* dynamically allocate a new node initialized with key and val
     * append new node to the end of the list
     */


    // sets up memory for new nodes
    Node<Key_Type, Value_Type> *n = new Node<Key_Type, Value_Type>(key, val);
    
    if (last_ != nullptr) { // since list is not empty, append nodes to list
        last_ ->next_ = n;
        last_ = n;
    }// list is empty, set node to first element of list
    
    else if (begin_ == last_) {
        begin_ = n;
        last_ = n;
    }


}
/******************************************************************************/

/******************************************************************************/
template<typename Key_Type, typename Value_Type>
ostream& SingleLinkMap<Key_Type, Value_Type>::print_list(ostream &out) {
    /* print out each node using the print_node method
     */

    Node<Key_Type, Value_Type> *temp = begin_; // start at beginning of list
    out << "List: "; // set up out stream

    // continue calling print node method until last element
    while (temp != last_) {
        temp->print_node(out);
        out << ", ";
        temp = temp->next_;
    }
    
    last_->print_node(out); // print last element, no trailing comma
    return out;
}
/******************************************************************************/

/******************************************************************************/
template<typename Key_Type, typename Value_Type>
Value_Type SingleLinkMap<Key_Type, Value_Type>::find_then_front(Key_Type key) {
    /* if you find key, return it and move Node to the front of the list
     * if not found, return the default value  
     * how many pointers do you need? probably two
        - first pointer you are using to look for the key
        - trailing second pointer to fix the list when the found node is moved
     * what are the special cases (empty list, one element list, ??). 
     */

    if (begin_ == nullptr) { // empty list
        return Value_Type(); // return default
    } 
    
    else if (begin_->key_ == key) { // first node is beginning of list
        return begin_->value_; // get key's value, return it
    }

    // set up nodes
    Node<Key_Type, Value_Type> *current = nullptr;
    Node<Key_Type, Value_Type> *prev = nullptr;

    current = begin_->next_; // current node
    prev = begin_; // previous node

    while (current != nullptr) {
        if (current->key_ == key) {
            prev->next_ = current->next_; // link previous to next
            current->next_ = begin_; // move current to front of list
            begin_ = current;
            return current->value_; // return value from map
        }

        current = current->next_;
        prev = prev->next_;

    }// end while loop

    return Value_Type(); // return default
}

/******************************************************************************/

/******************************************************************************/
template<typename Key_Type, typename Value_Type>
Value_Type SingleLinkMap<Key_Type, Value_Type>::find_then_swap(Key_Type key) {
    /* if you find key, return it and swap the node it with its predecessor
     * if not found, return the default value 
     * how many pointers do you need? probably 3
        - first pointer you are using to look for key
        - trailing second pointer (one behind first) to swap with
        - trailing third pointer to fix the list after the swap.
     *what are the special cases (empty list, one element list).
     */
    if (begin_ == nullptr) { // empty list
        return Value_Type(); // return default
    }

    else if (begin_->key_ == key) { // first node is beginning of list
        return begin_->value_; // get key's value, return it
    }
    
    

    // set up nodes
    Node<Key_Type, Value_Type> *current = nullptr; //3
    Node<Key_Type, Value_Type> *prev = nullptr; //2
    Node<Key_Type, Value_Type> *nex = nullptr; // 1
    Node<Key_Type, Value_Type> *temp = nullptr;

    current = begin_->next_; // current node
    prev = begin_; // previous node
    nex = current->next_; // next node
    
    while (begin_->next_ != nullptr) {

        if (current->key_ == key) {
            // flip prev and current nodes

            temp = current;
            current = prev;
            prev->next_ = temp;


            return temp->value_; // return value;
        }

        current = current->next_;
        prev->next_ = current;
        nex->next_ = nex->next_;

    }
    return Value_Type(); // return default

}
/******************************************************************************/

#endif
