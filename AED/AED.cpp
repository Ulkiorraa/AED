#include "listaDupla.h"

#include <fstream>
#include <cstdlib>

listaDupla* amigos = new listaDupla();

int retornaPos(string nome);
void lerArquivo();

int main()
{
    setlocale(LC_ALL, ".utf-8");
    lerArquivo();
    amigos->findItem("Pedro");
    amigos->getMinMax();
    amigos->printList();
}


int retornaPos(string nome)
{
    node* aux = amigos->inicio;
    int indice = 1;
    while (aux != NULL)
    {
        if (aux->dado.getNome().compare(nome) < 0)
        {
            indice++;
            aux = aux->next;
        }
        else
            aux = NULL;
    }
    delete aux;
    return indice;
}

void lerArquivo()
{
    int pos;
    string linha;
    ifstream arq("dados.txt");
    if (arq.is_open())
    {
        while (!arq.eof())
        {
            Pessoa objeto;
            getline(arq, linha);
            size_t pos = linha.find(",");
            string idade = linha.substr(0, pos);
            string nome = linha.substr(pos + 1, linha.size());
            objeto.setIdade(atoi(idade.c_str()));
            objeto.setNome(nome);
            pos = retornaPos(nome);
            amigos->addItemAtPos(objeto, pos);
        }
        arq.close();
    }
}
