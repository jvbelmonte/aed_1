#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct variaveis{
    int qntd;
    int auxMenu;
    int nListar;
    int i;
    int j;
    char nomeAux[20];
    char numAux[20];
}Var;

typedef struct atributos_Agenda {
    char numero[20];
    char nome[20];
}Agenda;

void *pBuffer = NULL;
Var *v;

void criaContato();
void buscaContato();
void desalocaAgenda();
void listarContatos();

int main(){

    pBuffer = malloc(sizeof(Var));
        if(pBuffer == NULL){
            return -1;
        }

    v = pBuffer;
    v->qntd = 0;
    v->auxMenu = -1;
    v->nListar = 0;

    do{
       printf("1 - Insere\n2 - Busca\n3 - Listar\n4- Desalocar\n0 - Sair\n");
       scanf("%d", &v->auxMenu);

       switch(v->auxMenu){

       case 1:
        criaContato();
       break;

       case 2:
        buscaContato();
       break;

       case 3:
        listarContatos();
       break;

       case 4:
        desalocaAgenda();
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

void buscaContato(){

    Agenda *p;

    p = pBuffer + sizeof(Var);

    v->j = 0;

    do{

        printf("1 - Buscar por nome\n2 - Buscar por numero\n");
        scanf("%d", &v->auxMenu);

        switch(v->auxMenu){
            case 1:
                printf("Insira um nome para busca: ");
                scanf("%s20", v->nomeAux);

                for((v->i) = 0; (v->i) < (v->qntd) ; (v->i)++){
                    if(strcmp(v->nomeAux, p->nome) == 0){
                        printf("Nome: %s \nTelefone: %s\n\n", p->nome, p->numero);
                        v->j += 1;
                    }
                    p++;
                }

                if(v->j == 0){
                    printf("Nenhum Contato com este nome foi encontrado\n");
                }
            break;

            case 2:
                printf("Insira um numero para busca: ");
                scanf("%s20", v->numAux);

                for((v->i) = 0; (v->i) < (v->qntd) ; (v->i)++){
                    if(strcmp(v->numAux, p->numero) == 0){
                        printf("Nome: %s \nTelefone: %s\n\n", p->nome, p->numero);
                        v->j += 1;
                    }
                    p++;
                }

                if(v->j == 0){
                    printf("Nenhum Contato com este nome foi encontrado\n");
                }

            break;

            default :
            printf("Codigo incorreto\n");

        }

   }while((v->auxMenu != 1) && (v->auxMenu != 2));

}

void listarContatos(){

    Agenda *p;

    p = pBuffer + sizeof(Var);

    printf("Quantos contatos deseja listar ?\n");
    scanf("%d", &v->nListar);

    for((v->i) = 0; (v->i) < (v->nListar) ; (v->i)++){
        printf("Nome: %s \nTelefone: %s\n\n", p->nome, p->numero);
        p++;
    }

}

void desalocaAgenda(){
    free(pBuffer);
}
