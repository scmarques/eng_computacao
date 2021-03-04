#include "Agenda.h"

Agenda::Agenda() //construtor da agenda
{
	nome = "";
	for (int i = 0; i < 30; i++){
		contato[i] = NULL;
	}
}

Agenda::~Agenda()
{
	cout << "Agenda" << nome << "destruída" <<endl;
}

string Agenda::getNome (){
	return nome;
}

void Agenda::setNome(string nome){
	this->nome = nome;
}

void Agenda::insereContato(Agenda* agenda, Contato* contato, int contador){
	this->contato[contador] = contato;
}

void Agenda::leAgenda(){
	
	cout << nome << endl;
}

void Agenda::leContatos(int contador){
	int i;
	for (i = 0; i <contador; i++){
		cout << "--------------------------------------------------" <<endl;
		cout<<"Nome: " << contato[i]->getNome() <<endl;
		cout<<"Telefone: " << contato[i]->getNumero() << endl;
		cout <<"--------------------------------------------------" <<endl;
		cout <<endl;
	}
}
