#ifndef AGENDA_H
#define AGENDA_H
#include "Contato.h"

using namespace std;

class Agenda
{
	public:
		Agenda();
		~Agenda();
		void setNome (string nome);
		string getNome ();
		void insereContato (Agenda* agenda, Contato* contato, int cont);
		void leAgenda ();
		void leContatos (int contador);
	protected:
		
	private:
		string nome;
		Contato* contato[30];
	
};

#endif
