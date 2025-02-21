#include "double_linked_list.h"
#include <string>

using namespace std;

int main(void) {
    double_linked_list<std::string> l;
    cout << "Lista vazia? " << (l.empty() ? "Sim" : "Nao") << endl;
    l.insert("Davi",1);
    l.print();
    l.insert("Daniel",2);
    l.print();
    l.insert("Pedro",2);
    l.print();
    l.insert("Maria", 2);
    l.print();
    l.insert("Sofia",4);
    l.print();
    l.remove(2);
    l.print();
    cout << "Tamanho da lista: " << l.get_length() << endl;
    cout << "Valor da segunda posicao: " << l.get_value(2) << endl;
    
    cout << "Lista vazia? " << (l.empty() ? "Sim" : "Nao") << endl;

    return 0;
}