#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criaContato(void *buffer);
//void buscaContato(void *buffer);
void desalocaAgenda(void *buffer);

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


    pBuffer = malloc( (sizeof(int) * 3) + (sizeof(char) * 20)   );
        if(pBuffer == NULL){
            return -1;
        }

    qnt = pBuffer;
    idP = pBuffer+ 4;
    numero = pBuffer + 8;
    nome = pBuffer + 12;

    *qnt = 1;
    *idP = 0;

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

       default :
       printf("Codigo incorreto\n");
       break;

       case 0:
       return 0;

       }

    }while(aux!=0);

    free(aux);
    return 0;
}

void criaContato(void *buffer){

    buffer = realloc(buffer, ( ((sizeof(int) * 3) + (sizeof(char) * 20))));

    printf("Nome: \n");
    scanf("%s", nome);


    printf("Numero: \n");
    scanf("%d", numero);


    qnt = buffer;
    idP = buffer+ 4;
    numero = buffer + 8;
    nome = buffer + 12;

    *qnt += 1;
    *idP += 1;

}





//void buscaContato(void *buffer);
void desalocaAgenda(void *buffer){
    free(buffer);
}
