#include "listaDupla.h"

listaDupla::listaDupla()
{
	inicio = NULL;
	fim = NULL;
	sizeLista = 0;
}

listaDupla::~listaDupla()
{
	inicio = NULL;
	fim = NULL;
	sizeLista = 0;
}

bool listaDupla::isEmpty()
{
	return inicio == NULL;
}

int listaDupla::getsizeLista()
{
	return sizeLista;
}

void listaDupla::addItemAtBeginning(Pessoa item)
{
	node* novo = new node(item, NULL, NULL);
	if (isEmpty()) {
		fim = novo;
		inicio = novo;
	}
	else {
		inicio->back = novo;
		novo->next = inicio;
		inicio = novo;
	}
	sizeLista++;
	novo = NULL;
	delete novo;
}

void listaDupla::removeItemAtBeginning()
{
	if (isEmpty())
		cout << "Lista Vazia!" << endl;
	else if (sizeLista == 1)
	{
		node* aux = inicio;
		inicio = fim = NULL;
		delete aux;
		sizeLista--;
	}
	else
	{
		node* aux = inicio;
		inicio = inicio->next;
		inicio->back = NULL;
		aux->next = NULL;
		delete aux;
		sizeLista--;
	}
}

void listaDupla::addItemAtEnd(Pessoa item)
{
	node* novo = new node(item, NULL, NULL);
	if (isEmpty()) {
		fim = novo;
		inicio = novo;
	}
	else {
		novo->back = fim;
		fim->next = novo;
		fim = novo;
	}
	sizeLista++;
	novo = NULL;
	delete novo;
}

void listaDupla::removeItemAtEnd()
{
	if (isEmpty())
		cout << "Lista Vazia!" << endl << endl;
	else if (sizeLista == 1)
	{
		node* aux = inicio;
		inicio = fim = NULL;
		delete aux;
		sizeLista--;
	}
	else
	{
		node* aux = fim;
		fim = fim->back;
		fim->next = NULL;
		aux->back = NULL;
		delete aux;
		sizeLista--;
	}
}

void listaDupla::printList()
{
	node* aux = inicio;

	cout << "Lista: [ \n";

	while (aux != NULL)
	{
		cout << "Nome: " << aux->dado.nome << "\t"<< "Idade: " << aux->dado.idade<<endl;
		aux = aux->next;
	}
	cout << "]" << endl;
	cout << "Tamanho da lista: " << sizeLista << endl << endl;
	delete aux;
}

void listaDupla::getMinMax()
{
	int minid, maxid;
	string minnome, maxnome;

	if (isEmpty())
		cout << "Lista vazia. Sem min/max." << endl << endl;
	else
	{
		minid = maxid = inicio->dado.idade;
		node* aux = inicio;
		while (aux != NULL)
		{
			if (aux->dado.idade > maxid)
			{
				maxid = aux->dado.idade;
				maxnome = aux->dado.nome;
			}
			if (aux->dado.idade < minid)
			{
				minid = aux->dado.idade;
				minnome = aux->dado.nome;
			}
			aux = aux->next;
		}
		cout << "O mais novo da lista é: " << minnome << " com " << minid << " anos.\n";
		cout << "O mais velho da lista é: " << maxnome << " com " << maxid << " anos.\n\n";
		delete aux;
	}
}

void listaDupla::emptyDeque()
{
	while (!isEmpty())
		removeItemAtBeginning();
	inicio = fim = NULL;
	sizeLista = 0;
}

void listaDupla::findItem(string item)
{
	if (isEmpty())
		cout << item << " não encontrado(a)." << endl << endl;
	else
	{
		int posicao = 1;
		bool encontrou = false;
		node* aux = inicio;
		while (aux != NULL)
		{
			if (aux->dado.nome == item)
			{
				cout << item << " encontrado(a) na posição: " << posicao << endl << endl;
				encontrou = true;
			}
			aux = aux->next;
			posicao++;
		}
		if (encontrou == false)
			cout << item << " não encontrado(a)." << endl << endl;
	}
}

void listaDupla::addItemAtPos(Pessoa item, int posicao)
{
	int i = 1; 
	node* aux;
	node* aux2;
	node* novo;

	if (posicao > sizeLista)
		addItemAtEnd(item);
	
	else if (posicao == 1) 
		addItemAtBeginning(item);
	else 
	{
		aux = inicio;
		aux2 = inicio->next;
		while (i != (posicao - 1)) 
		{
			aux = aux->next;
			aux2 = aux2->next;
			i++;
		}
		novo = new node(item, aux, aux2);
		aux2->back = novo;
		aux->next = novo;
		sizeLista++;
	}
	aux = aux2 = novo = NULL;
	delete aux;
	delete aux2;
	delete novo;
}