#include "Pessoa.h"
class node
{
	public:
		Pessoa dado;
		node* next;
		node* back;

		node(Pessoa item, node* ptr1, node* ptr2);
};

