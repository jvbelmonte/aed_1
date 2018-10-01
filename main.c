#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criaContato(void *buffer);
void buscaContato(void *buffer);
void desalocaAgenda(void *buffer);

int *tamAux = NULL;
int *qnt = NULL;
int *idP = NULL;
int *numero = NULL;
char *nome = NULL;

int main(){
    void *pBuffer = NULL;

    int *aux = NULL;
    aux = malloc(sizeof(int));
        if(aux == NULL){
            return -1;
        }


    pBuffer = malloc( (sizeof(int) * 4) + (sizeof(char) * 20)   );
        if(pBuffer == NULL){
            return -1;
        }

    qnt = pBuffer;
    tamAux = pBuffer + sizeof(int) ;
    idP = pBuffer + (sizeof(int) * 2);
    numero = pBuffer + (sizeof(int) * 3);
    nome = pBuffer + (sizeof(int) * 4);

    // BUFFER INICIAL =  || QUANTIDADE DE PESSOAS|| TAMANHO DO BUFFER || ID || NUMERO || PESSOA ||
    *qnt = 1;
    *idP = 0;
    *tamAux = (sizeof(int) * 4) + (sizeof(char) * 20);

    do{
       printf("1 - Insere\n2 - Busca\n3- Desaloca\n0 - Sair\n");
       scanf("%d", aux);

       switch(*aux){

       case 1:
        criaContato(pBuffer);
       break;

       case 3:
        desalocaAgenda(pBuffer);
       break;

       case 0:
       return 0;
       break;

       default :
       printf("Codigo incorreto\n");
       }

    }while(aux!=0);

    free(aux);
    return 0;
}

void criaContato(void *buffer){

    buffer = realloc(buffer, (  (sizeof(int) * 4) + (sizeof(char) * 20) ) * (*qnt) );

    printf("Nome: \n");
    scanf("%s20", nome);

    printf("Numero: \n");
    scanf("%d", numero);

    *tamAux = (*tamAux) * (*qnt);

    qnt = buffer + *tamAux;
    tamAux = buffer + sizeof(int) + *tamAux;
    idP = buffer + (sizeof(int) * 2) + *tamAux;
    numero = buffer + (sizeof(int) * 3) + *tamAux;
    nome = (buffer + (sizeof(int) * 4)) + *tamAux;

    *qnt += 1;
    *idP += 1;

}

void buscaContato(void *buffer){

}

void desalocaAgenda(void *buffer){
    free(buffer);
}
