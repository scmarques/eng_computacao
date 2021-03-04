//Arvore Binaria espelhada
/*Escreva um algoritmo que dado uma árvore binária busca informada, ele possa
produzir uma arvore espelho e imprimir em ordem, pré-ordem e pós-ordem.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define MAX 20

typedef struct no { 
    int info;
    struct no *esq;
    struct no *dir;
}*Arvore;

Arvore* criaArvore();
int insereArvore (Arvore* raiz, int valor);
void listaArvore(Arvore* raiz);
int arvoreAltura(Arvore* raiz);
void liberaArvore (Arvore* raiz);
int removeArvore (Arvore* raiz);
int consultaArvore(Arvore* raiz, int valor);
struct no* removeNoAtual(struct no* noRemover);
void espelhaArvore(struct no* raiz, Arvore* mirror);
struct no* criaNo(int valor);
void posOrdemArvore(Arvore* tree);
void preOrdemArvore(Arvore* tree);
void emOrdemArvore(Arvore* tree);

int main () {

	setlocale (LC_ALL, "");
	int valor;
	Arvore* tree = criaArvore ();
	Arvore* mirror = criaArvore ();
	int vetor [MAX];
	int i, qtde, aux;

	do { //inicia a apresentaco para o usuario das opcoes
        system ("cls");
        printf("\t\t\t:::ARVORE DE BUSCA ESPELHADA:::.\n\n");
        printf("ESCOLHA A OPÇÃO:\n");
        printf("\n1 - INSERIR VALORES PARA VETOR GERADOR DA ÁRVORE\n2 - VETOR GERADO AUTOMATICAMENTE\n3 - CRIAR ÁRVORE\n4 - ESPELHAR ARVORE!\n5 - IMPRIMIR ÁRVORES\n0 - ENCERRAR APLICAÇÃO\n");
        scanf("%d", &valor);

        switch (valor) {
            case 1:
                system("cls");
                i = -1;
                printf("Insira até 20 valores diferentes. \nLembre-se que essa versão do programa só aceita numeros positivos >= 0!\n");
            	printf("Para interromper a inserção de valores, digite -1.\n");
            	do {
               		i++;
					printf("Digite o valor para posição %d:\n", i);
            		scanf("%d", &vetor[i]);
				} while (vetor[i] != -1 && i < MAX);
				system("cls");
				if (vetor[i]== -1){
					printf("Vetor inserido com sucesso. Total de posições: %i\n", i);
					qtde = i;
					system("pause");
				} else {
					printf("Vetor inserido com sucesso. Total de posições: %i\n", i+1);
					qtde = i+1;
					system("pause");
				}
					printf("\t\t\tVETOR INSERIDO PELO USUÁRIO:\n\n\n");

				for (i = 0; i < MAX; i++){
            		printf("|%d|", vetor[i]);
				}
                 break;


            case 2:
          		system("cls");
          		qtde = 20;
          		srand ( (unsigned)time(NULL));
            	for (i = 0; i < MAX; i++){
            		vetor[i] = rand() % 100;
				}

				printf("\t\t\tVETOR AUTOMATICAMENTE GERADO:\n\n\n");

				for (i = 0; i < MAX; i++){
            		printf("|%d|", vetor[i]);
				}
				printf("\n");
				system ("pause");
                 break;

            case 3:

              	for (i = 0; i < qtde; i++){
            	if (insereArvore (tree, vetor[i]) == 1){
            		aux = 1;
				} else {
					aux = 0;
					}
				}
                if (aux == 1){
                	printf("Árvore criada com sucesso.\n");
				}
				else {
                    printf("Erro na aplicação.\n");

				}
				system("pause");
 				system("cls");
                 break;

            case 4:

                system("cls");

                espelhaArvore(*tree, mirror);
  				printf("Espelhamento realizado com sucesso.\n");
                system("pause");
                 break;

            case 5:
                system ("cls");
                printf("Escolha a forma como deseja realização a impressão:\n");
                printf("( 1 ) ---- EM ORDEM \n");
                printf("( 2 ) ---- PRÉ ORDEM \n");
                printf("( 3 ) ---- PÓS ORDEM \n");
                scanf("%d", &aux);
                if (aux == 1){
                    system("cls");
                    printf("( 1 ) ---- EM ORDEM \n");
                    printf("Árvore binária gerada:\n");
                    emOrdemArvore(tree);
                    printf("\n\n\n\n\n\n\nÁrvore binária espelhada:\n");
                    emOrdemArvore(mirror);
                    system("pause");
                } else if (aux == 2){
                    system("cls");
                    printf("( 2 ) ---- PRÉ ORDEM \n");
                    printf("Árvore binária gerada:\n");
                    preOrdemArvore(tree);
                    printf("\n\n\n\n\n\n\nÁrvore binária espelhada:\n");
                    preOrdemArvore(mirror);
                    system("pause");
                } else if ( aux == 3){
                    system("cls");
                    printf("( 3 ) ---- PÓS ORDEM \n");
                    printf("Árvore binária gerada:\n");
                    posOrdemArvore(tree);
                    printf("\n\n\n\n\n\n\nÁrvore binária espelhada:\n");
                    posOrdemArvore(mirror);
                    system("pause");
                } else if (aux == 0){
                    break;
                } else {
                    do {printf("Valor invalido. Verifique a digitação. Caso queira retornar ao menu principal, digite 0.\n");
                    scanf("%d", &aux);

                    } while (aux < 0 && aux > 3);
                }
                 break;

            case 0:
                break;

            default: printf("\nInsira um valor válido.\n");

        }

    } while (valor != 0);
    liberaArvore(tree);
	liberaArvore (mirror);

return 0;
}



Arvore* criaArvore(){ 

    Arvore* raiz = (Arvore*) malloc(sizeof(Arvore));

    if (raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

void liberaNo (struct no* no){ 
    if (no == NULL){
        return;
    } else {
        liberaNo (no->esq);
        liberaNo(no->dir);
        free (no);
        no = NULL;
    }
}

void liberaArvore (Arvore* raiz){
    if (raiz == NULL){
        return;
    } else {
        liberaNo(*raiz);
        free(raiz);
    }

}

int insereArvore (Arvore* raiz, int valor){
		if (raiz == NULL){
			return 0; //erro caso a arvore nao seja valida
		}

        struct no* novo = (struct no*) malloc (sizeof(struct no));
        if (novo == NULL){
            return 0; //erro casa haja problema na alocaÃ§aÃµ
        } else {
         	novo->info = valor;
            novo->esq = NULL;
        	novo->dir = NULL;

            if (*raiz == NULL){
            	*raiz = novo;
            //localiza onde o valor deve ser inserido - nessa funcao nao ha restricao para valores repetidos
           } else {
        		struct no* atual = *raiz;
                struct no* anterior = NULL;
                while (atual != NULL){ //quando atual chega em NULL, ele encontra uma folha  - essa arvore aceita numeros repetidos
                    anterior = atual;
                    if (valor > atual->info){
                         atual = atual->dir;
                    } else {
                        atual = atual->esq;
                  	}
               }
            	if (valor > anterior->info){
                	anterior->dir = novo;

                }else {
                   anterior->esq = novo;
                }

        	}

		}

    return 1;
}

void listaArvore (Arvore* raiz){
    if (raiz != NULL && *raiz != NULL){
        printf("%d\n", (*raiz)->info);
        listaArvore(&((*raiz)->esq));
 		listaArvore(&((*raiz)->dir));
    }
}
struct no* criaNo (int valor){
	 struct no* novo = (struct no*) malloc (sizeof(struct no));
        if (novo != NULL){
	    	novo->info = valor;
	     	novo->esq = NULL;
	     	novo->dir = NULL;

        }
	return novo;
}

void espelhaArvore (struct no* raiz, Arvore* mirror){

	if (raiz == NULL){
            mirror = NULL;
			return; //erro caso a arvore nao seja valida
    } else {

            *mirror = (criaNo(raiz->info));
   			espelhaArvore(raiz->esq, &((*mirror)->dir));
   			espelhaArvore(raiz->dir, &((*mirror)->esq));
    }

}

void preOrdemArvore(Arvore* raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdemArvore(&((*raiz)->esq));
        preOrdemArvore(&((*raiz)->dir));
    }
}


void emOrdemArvore(Arvore* raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdemArvore(&((*raiz)->esq));
        printf("%d\n",(*raiz)->info);
        emOrdemArvore(&((*raiz)->dir));
    }
}

void posOrdemArvore(Arvore *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdemArvore(&((*raiz)->esq));
        posOrdemArvore(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}
