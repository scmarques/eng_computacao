//Matriz transposta

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{

	setlocale(LC_ALL, "Portuguese");
    int m, n, i = 0, j = 0;
    int **mat, **mat_t;
	
	printf("-------Impressão de matriz transposta-------\n\n\n\n");
    printf("Digite a quantidade de linhas:\n");
	scanf("%d", &n);
	
	printf("Digite a quantidade de colunas:\n");
    scanf("%d", &m);

    system("cls");

    mat = (int**) malloc (n * sizeof (int*));
    for (i = 0; i < n; i++)
	{
	    mat [i] = (int*) malloc (m * sizeof (int));
        for (j = 0; j < m; j++)
		{
     	    printf("Digite o valor a ser armazenado na posição[%d][%d]:\n", i, j);
            scanf("%d", &mat[i][j]);
       	}
    }

    mat_t = (int**) malloc (m * sizeof(int*));
    for (i = 0; i < m; i++)
	{
    	mat_t[i] = (int*) malloc (n*sizeof (int));
        for (j = 0; j < n; j++)
		{
            mat_t [i][j] = mat [j][i];
        }
	}
    
    system("cls");

    //imprime

    printf("-----------Matriz-------------\n");
    for (i = 0; i < n; i++)
	{
        for (j = 0; j < m; j++)
		{
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("______________________________________________________\n\n");
    
    printf("\n--------Matriz Transposta------\n");
    for (i = 0; i < m; i++)
	{
        for (j = 0; j < n; j++)
		{
            printf("%d ", mat_t[i][j]);
        }
        printf("\n");
    }
	
	free (mat);
	free (mat_t);
	
    return 0;

}
