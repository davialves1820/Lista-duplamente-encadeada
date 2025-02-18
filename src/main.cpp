#include "double_linked_list.h"
#include <string>

using namespace std;

int main(void) {
    double_linked_list<std::string> l;

    l.insert("Davi",1);
    l.print();
    l.insert("Daniel",2);
    l.print();
    l.insert("Dan",2);
    l.print();
    l.insert("val", 2);
    l.print();
    l.insert("Di",4);
    l.print();
    l.remove(2);
    l.print();
    cout << l.get_value(2) << endl << l.get_length();

    return 0;
}