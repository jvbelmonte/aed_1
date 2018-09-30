#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criaContato(void *buffer);
void buscaContato(void *buffer);
void desalocaAgenda(void *buffer);

void *pBuffer = NULL;
int *qnt = NULL;
int *idP = NULL;
int *numero = NULL;
char *nome = NULL;

int main(){

    int *aux = NULL;

    pBuffer = malloc( (sizeof(int) * 3) + (sizeof(char) * 20) );

    pBuffer = qnt;
    pBuffer = idP + 4;
    pBuffer = numero + 8;
    pBuffer = nome + 12;

    do{
       printf("1 - Insere\n2 - Busca\n3- Desaloca");
       scanf("%d", aux);

       switch(*aux){

       case 1:
        criaContato(pBuffer);
       break;

       case 3:
        desalocaAgenda(pBuffer);
       break;

       }

    }while(aux!=0);


    free(aux);
    return 0;
}
