#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#include "node.h"
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class double_linked_list {
    int length;
    node<T>* head;
    node<T>* tail;
public:
    double_linked_list();

    void set_head(node<T>* h);
    node<T>* get_head();

    void set_tail(node<T>* t);
    node<T>* get_tail();

    int get_length();
    T get_value(const int& pos);

    bool empty();
    
    void insert(const T& v, const int& pos);
    
    void remove(const int& pos);
    
    void edit(const T& v, const int& pos);
    
    void print();

    ~double_linked_list();
};

// Implementações das funções

template <typename T>
double_linked_list<T>::double_linked_list() : length(0), head(nullptr), tail(nullptr) {}

template <typename T>
void double_linked_list<T>::set_head(node<T>* h) {
    head = h;
}

template <typename T>
node<T>* double_linked_list<T>::get_head() {
    return head;
}

template <typename T>
void double_linked_list<T>::set_tail(node<T>* t) {
    tail = t;
}

template <typename T>
node<T>* double_linked_list<T>::get_tail() {
    return tail;
}

template <typename T>
int double_linked_list<T>::get_length() {
    return length;
}

template <typename T>
T double_linked_list<T>::get_value(const int& pos) {
    if (empty() || pos < 1 || pos > length) {
        return T();
    }

    node<T>* aux = head;
    int i = 0;
    while (aux != nullptr && i < pos - 1) {
        i++;
        aux = aux->get_next();
    }
    return aux->get_value();
}

template <typename T>
bool double_linked_list<T>::empty() {
    return length == 0;
}

template <typename T>
void double_linked_list<T>::insert(const T& v, const int& pos) {
    if (empty() && pos != 1) {
        return;
    }

    if (pos < 1 || pos > length + 1) {
        return;
    }

    if (pos == 1) {
        node<T>* n = new node<T>(v);
        n->set_next(head);
        if (empty()) {
            tail = n;
        } else {
            head->set_before(n);
        }
        head = n;
        length++;
    } else if (pos == length + 1) {
        node<T>* n = new node<T>(v);
        n->set_before(tail);
        tail->set_next(n);
        tail = n;
        length++;
    } else {
        if (pos <= (length / 2) + 1) {
            
            node<T>* n = new node<T>(v);
            node<T>* aux = head;
            int i = 0;
            while (aux != nullptr && i < pos - 1) {
                aux = aux->get_next();
                i++;
            }
            node<T>* ant = aux->get_before();

            n->set_next(aux);
            n->set_before(ant);
            ant->set_next(n);
            aux->set_before(n);
            
            length++;
        } else {
            
            node<T>* n = new node<T>(v);
            node<T>* aux = tail;
            int i = length - 1;
            while (aux != nullptr && i != pos - 1) {
                aux = aux->get_before();
                i--;
            }
            node<T>* ant = aux->get_before();

            n->set_next(aux);
            n->set_before(ant);
            ant->set_next(n);
            aux->set_before(n);
            
            length++;
        }

        
    }
}

template <typename T>
void double_linked_list<T>::remove(const int& pos) {
    if (empty() || pos < 1 || pos > length) {
        return;
    }

    if (pos <= (length / 2) + 1) {
        
        node<T>* aux = head;
        int i = 0;
        while (aux != nullptr && i != pos - 1) {
            i++;
            aux = aux->get_next();
        }
        node<T>* ant = aux->get_before();
        node<T>* prox = aux->get_next();

        ant->set_next(prox);
        prox->set_before(ant);
        length--;
        delete aux;
    } else { 
        
        node<T>* aux = tail;
        int i = length - 1;

        while (aux != nullptr && i != pos - 1) {
            i--;
            aux = aux->get_before();
        }
        
        node<T>* ant = aux->get_before();
        node<T>* prox = aux->get_next();
        ant->set_next(prox);
        prox->set_before(ant);
        length--;
        delete aux;
    }
    
}

template <typename T>
void double_linked_list<T>::edit(const T& v, const int& pos) {
    if (empty() || pos < 1 || pos > length) {
        return;
    }
    node<T>* aux = head;
    int i = 0;
    while (aux != nullptr && i < pos - 1) {
        i++;;
        aux = aux->get_next();
    }
    aux->set_value(v);
}

template <typename T>
void double_linked_list<T>::print() {
    if (empty()) {
        cout << "Lista vazia" << endl;
        return;
    }
    node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->get_value() << " ";
        aux = aux->get_next();
    }
    cout << endl;
}

template <typename T>
double_linked_list<T>::~double_linked_list() {
    while (head != nullptr) {
        node<T>* d = head;
        head = head->get_next();
        delete d;
    }
}

#endif
