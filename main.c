#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct variaveis{
    int qntd;
    int auxMenu;
}Var;

typedef struct atributos_Agenda {
    char numero[20];
    char nome[20];
}Agenda;

void *pBuffer = NULL;
Var *v;

void criaContato();
void desalocaAgenda(void *buffer);


int main(){


    pBuffer = malloc(sizeof(Var));
        if(pBuffer == NULL){
            return -1;
        }

    v = pBuffer;
    v->qntd = 0;
    v->auxMenu = -1;

    do{
       printf("1 - Insere\n2 - Busca\n3- Desaloca\n0 - Sair\n");
       scanf("%d", &v->auxMenu);

       switch(v->auxMenu){

       case 1:
        criaContato();
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

void criaContato(){

    Agenda *pessoa;

    v = pBuffer;
    v->qntd += 1;

    pBuffer = realloc(pBuffer, sizeof(Var) + (sizeof(Agenda) * (v->qntd)));
    v = pBuffer;
    pessoa = pBuffer + (sizeof(Var) + (sizeof(Agenda) * (v->qntd-1)));

    printf("Nome : \n");
    scanf("%s20", pessoa->nome);
    printf("Numero : \n");
    scanf("%s20", pessoa->numero);
}

//void buscaContato(void *buffer){}

void desalocaAgenda(void *buffer){
    free(buffer);
}
