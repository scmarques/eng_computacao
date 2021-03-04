#include "Contato.h"

Contato::Contato()
{
	nome = " ";
	numero = 0;
	
}

Contato::~Contato()
{
	cout <<"Contato excluído." <<endl;
	
}

void Contato::setNome (string nome){
	this->nome = nome;
}

void Contato::setNumero (int numero){
	this->numero = numero;
}

string Contato::getNome (){
	return nome;
}

int Contato::getNumero(){
	return numero;
}
