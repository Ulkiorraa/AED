#include "node.h"

node::node(Pessoa item, node* ptr1, node* ptr2)
{
	dado = item;
	back = ptr1;
	next = ptr2;
}
