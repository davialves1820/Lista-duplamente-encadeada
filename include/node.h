#ifndef NODE
#define NODE

#include <iostream>

using std::cout;
using std::endl;

template<typename T>

class node {
    T value;
    node<T>* before;
    node<T>* next;
public:
    
    node(const T& value);

    void set_value(const T& v);
    T get_value();

    void set_next(node<T>* h);
    node<T>* get_next();

    void set_before(node<T>* t);
    node<T>* get_before();
};

template<typename T>
node<T>::node(const T& v) : value(v), before(nullptr), next(nullptr) {}

template<typename T>
void node<T>::set_next(node<T>* n) {
    next = n;
}

template<typename T>
node<T>* node<T>::get_next() {
    return next;
}

template<typename T>
void node<T>::set_before(node<T>* b) {
    before = b;
}

template<typename T>
node<T>* node<T>::get_before() {
    return before;
}

template<typename T>
void node<T>::set_value(const T& v) {
    value = v;
}

template<typename T>
T node<T>::get_value() {
    return value;
}

#endif