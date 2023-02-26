#include "node.h"
#include <iostream>
using namespace std;
class listaDupla
{
    public:

        node* inicio;
        node* fim;
        int sizeLista;

        listaDupla();
        ~listaDupla();
        bool isEmpty();     
        int getsizeLista();
        void addItemAtBeginning(Pessoa item);
        void removeItemAtBeginning();
        void addItemAtEnd(Pessoa item);
        void removeItemAtEnd();
        void printList();
        void getMinMax();
        void emptyDeque();                               
        void findItem(string item);
        void addItemAtPos(Pessoa item, int posicao);
};

