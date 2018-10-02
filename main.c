#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct variaveis{
    int qntd;
    int tamanhoBuffer;
    int auxMenu;
}Var;

typedef struct atributos_Agenda {
    char numero[20];
    char nome[20];
}Agenda;


void criaContato(void *buffer);
//void buscaContato(void *buffer);
void desalocaAgenda(void *buffer);

int main(){

    void *pBuffer = NULL;

    Var *v;

    pBuffer = malloc(sizeof(Var));
        if(pBuffer == NULL){
            return -1;
        }

    v = pBuffer;
    v->qntd = 0;
    v->tamanhoBuffer = sizeof(Var);
    v->auxMenu = -1;

    do{
       printf("1 - Insere\n2 - Busca\n3- Desaloca\n0 - Sair\n");
       scanf("%d", &v->auxMenu);

       switch(v->auxMenu){

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

    }while(v->auxMenu != 0);
    return 0;
}

void criaContato(void *buffer){

    Agenda *pessoa;
    Var *v;

    v = buffer;
    v->qntd += 1;
    v->tamanhoBuffer = (v->tamanhoBuffer + sizeof(Agenda));

    buffer = realloc(buffer, v->tamanhoBuffer);
    v = buffer;

    buffer = buffer + (sizeof(Var) + (sizeof(Agenda) * (v->qntd-1)));
    pessoa = buffer;

    getchar();

    printf("Nome : \n");
    scanf("%s20", pessoa->nome);
    printf("Numero : \n");
    scanf("%s20", pessoa->numero);

}

//void buscaContato(void *buffer){}

void desalocaAgenda(void *buffer){
    free(buffer);
}
