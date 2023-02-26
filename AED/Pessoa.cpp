#include "Pessoa.h"

void Pessoa::setNome(string N)
{
	nome = N;
}

string Pessoa::getNome()
{
	return string(nome);
}

void Pessoa::setIdade(int id)
{
	idade = id;
}

int Pessoa::getIdade()
{
	return idade;
}
