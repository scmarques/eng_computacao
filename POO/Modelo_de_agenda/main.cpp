#include <iostream>
#include <windows.h>
#include <tchar.h>
#include "Agenda.h"
#include "Contato.h"

using namespace std;

Agenda* lerAgenda (){
	string nome;
	cout <<"                ---> Cadastro de nova agenda" <<endl;
	Agenda* agenda = new Agenda ();
	
	cout <<"Digite o nome que deseja dar para a agenda (Exemplo: Trabalho):" <<endl;
	cin.clear ();
	fflush (stdin);
	getline(cin, nome);
	agenda->setNome(nome);
	
	return agenda;
}

Contato* lerContato(){
	string nome;
	int numero;
	Contato* contato = new Contato();
	cout <<"                ---> Cadastro de novo contato" <<endl;
	cout <<"Digite o nome do contato:" <<endl;
	cin.clear ();
	fflush (stdin);
	getline(cin, nome);
	contato->setNome(nome);
	cout <<"Digite o telefone do contato:" <<endl;
	cin >> numero;
	contato->setNumero (numero);
	return contato;
}

void insereContato (Agenda* agenda, Contato* contato, int contador){
	
	agenda->insereContato(agenda, contato, contador);
	
}


int main() {
	
_tsetlocale(LC_ALL,_T("portuguese"));	

	int aux, menu, i, controle, contAgenda = 0; 
	Contato* contato = new Contato ();
	
	int contador[10]; 
	
	for (i = 0; i < 10; i++){
		contador[i] = 0;
	}
	
	Agenda* listAgenda [10]; 
	

	for (i =0; i < 10; i++){
		listAgenda[i] = new Agenda ();
	}
	
	do{
		system("cls");
		cout <<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
		cout <<"........................AGENDA C++.............................."<<endl;
		cout <<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
		cout <<"Menu de opções:"<<endl;
		cout <<"(1) - Incluir agenda" <<endl;
		cout <<"(2) - Exibir agendas" << endl;
		cout <<"(3) - Incluir contato em uma agenda" <<endl;
		cout <<"(4) - Exibir contatos de uma agenda" <<endl;
		cout <<"(5) - Encerrar aplicação" <<endl;
		
		cout <<"Digite a opção desejada: ";
		cin >> (menu);
		cin.clear();
		fflush(stdin);
		
		switch (menu){
			case 1: 
				system("cls");
				if (contAgenda == 10){
					cout << "Número máximo de agendas já atingido. Impossível criar nova agenda." << endl;
					getchar ();
					break;
				} else {
					listAgenda[contAgenda] = lerAgenda ();
					contAgenda++;
				}
				
			
				break;
				
			case 2:
				system("cls");
				cout << "          --->AGENDAS CADASTRADAS" <<endl;
				
				for (i = 0; i< contAgenda; i++){
					cout << "Agenda [" <<i<<"]:";
					listAgenda[i]->leAgenda();				
				}
				getchar();
				break;
			
			case 3: 
				system("cls");
				cout <<"Digite o número da agenda em que deseja incluir o novo contato:" << endl;
					
				for (i = 0; i< contAgenda; i++){
					cout << "Agenda [" <<i<<"]:";
					listAgenda[i]->leAgenda();				
				}
				
				cin >> (aux);
				
				if (aux < contAgenda){
					
					if (contador[aux] == 29){
						cout << "Agenda cheia. Impossível realizar a operação." <<endl;
						break;
					
					
					} else {
						contato = lerContato();
						insereContato(listAgenda[aux],contato, contador[aux]);
						contador[aux]++; 
						break;
					}
				} else{
				cout << "Agenda inexistente. Retornando ao menu inicial." <<endl;
					getchar ();
					break; 
				
				} 
			
				break;
				
			
			case 4:
				system("cls");
				cout <<"Digite o número da agenda que deseja exibir contatos:" << endl;
					
				for (i = 0; i< contAgenda; i++){
					cout << "Agenda [" <<i<<"]:";
					listAgenda[i]->leAgenda();				
				}
				
				cin >> (aux);
				
				
				if (aux >= contAgenda){
					cout << "Agenda inexistente. Retornando ao menu inicial." <<endl;
					cin.clear ();
					fflush (stdin);
					getchar();
					
					break; 
				
				} else {
					listAgenda[aux]->leContatos (contador[aux]);
				}
				cin.clear ();
				fflush (stdin);
				getchar();
				break;
				
			case 5: 
			
				controle = 5;
				break;
			
			default:
				cout <<endl<< "Opção inválida!"<< endl;
				getchar();
				break;
				
		} 
	}while (controle != 5);
	
	delete contato;
	
	for (i =0; i < 10; i++){
		delete	listAgenda[i];
	}
	
	return 0;
}
