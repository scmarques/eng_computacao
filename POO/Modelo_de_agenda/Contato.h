#ifndef CONTATO_H
#define CONTATO_H

#include <iostream>

using namespace std;

class Contato
{
	public:
		Contato();
		~Contato();
		void setNome (string nome);
		void setNumero (int numero);
		string getNome ();
		int getNumero();
		
		
	protected:
	
	private:
		string nome;
		int numero;
};

#endif
