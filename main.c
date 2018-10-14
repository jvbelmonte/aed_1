#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct atributos_Agenda {
    char numero[20];
    char nome[20];
}Agenda;

typedef struct variaveis{
    int qntd;
    int auxMenu;
    int i;
    int j;
    int excAux;
    int nomeCmp;
    char nomeAux[20];
    char numAux[20];
    Agenda auxAg, tempAg;
}Var;

void *pBuffer = NULL;
Var *v;

void criaContato();
void buscaContato();
void desalocaAgenda();
void listarContatos();
void excluirContato();
void mainSort();
void bubblesort();
int buscaCmp();

int main(){

    pBuffer = malloc(sizeof(Var));
        if(pBuffer == NULL){
            return -1;
        }

    v = pBuffer;
    v->qntd = 0;
    v->auxMenu = -1;

    do{
       printf("\n1 - Insere\n2 - Busca\n3 - Listar\n4 - Desalocar\n5 - Excluir\n6 - Sort Main\n7 - Bubble\n0 - Sair\n");
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

        case 5:
            excluirContato();
        break;
        
        case 6:
            mainSort();
        break;

        case 7:
            bubblesort();
        break;
       
        case 0:
            return 0;
        break;

       default :
        printf("Codigo incorreto\n");
       }

    }while(v->auxMenu != 0);
    return -1;
}

void mainSort(){
    do{
        printf("1 - Bubble Sort\n2 - Selection Sort\n3 - Insertion Sort\n0 - Main\n");    
        scanf("%d", v->excAux);
        
        switch(v->excAux){

        case 1:
            bubblesort();
        break;
        
        case 0:
            main();
        break;

        default:
            printf("Wrong Code\n");
        break;
        }

    }while(v->excAux < 0);
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

    do{
        printf("Numero : \n");
        scanf("%s20", pessoa->numero);

        strcpy(v->numAux, pessoa->numero);

        v->excAux = buscaCmp();

    }while(v->excAux == 1);
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

    if(v->qntd > 0){
        for((v->i) = 0; (v->i) < (v->qntd) ; (v->i)++){
            printf("Nome: %s \nTelefone: %s\n\n", p->nome, p->numero);
            p++;
        }
    }else{
        printf("Agenda Vazia\n");
    }

}

void excluirContato(){

    Agenda *p;
    p = pBuffer + sizeof(Var);

    do{
        printf("1 - Excluir pelo nome\n2 - Excluir pelo numero\n");
        scanf("%d", &v->auxMenu);
        
        switch (v->auxMenu)    {
            
            case 1:
            printf("Digite o nome: \n");
            scanf("%s20", v->nomeAux);

            for(v->i = 0; v->i < v->qntd; v->i++){
                if(strcmp(v->nomeAux, p->nome)==0){
                    v->qntd--;
                    
                    for(v->j = v->i; v->j < v->qntd; v->j++){
                        p[v->j] = p[v->j+1];
                    }
                    pBuffer = realloc(pBuffer, sizeof(Var) + sizeof(Agenda) * v->qntd);
                    v->excAux = 0;
                    break;
                }
            }
            if(v->excAux == 0){
                printf("Contato excluido com sucesso\n");
            }else{
                printf("Contato não encontrado\n");
            }
            
            break;
        
            case 2:
            printf("Digite o numero: \n");
            scanf("%s20", v->numAux);

            for(v->i = 0; v->i < v->qntd; v->i++){
                if(strcmp(v->numAux, p->numero)==0){
                    v->qntd--;
                    
                    for(v->j = v->i; v->j < v->qntd; v->j++){
                        p[v->j] = p[v->j+1];
                    }
                    pBuffer = realloc(pBuffer, sizeof(Var) + sizeof(Agenda) * v->qntd);
                    v->excAux = 0;
                    break;
                }
            }
            if(v->excAux == 0){
                printf("Contato excluido com sucesso\n");
            }else{
                printf("Contato não encontrado\n");
            }
            break;
            
            default:
                printf("Opção Invalida\n");
            break;
        }
    }while((v->auxMenu != 1) && (v->auxMenu != 2));
}

int buscaCmp(){
    Agenda *p;
    p = pBuffer + sizeof(Var);
    
    for((v->i) = 0; (v->i) < (v->qntd)-1; (v->i)++){
        if(strcmp(v->numAux, p->numero) == 0){
            printf("Ja registrado na Agenda\n");
            return 1;
        }
        p++;
    }
    return 0;
}

void bubblesort(){
    Agenda *pessoa;
    pessoa = pBuffer + sizeof(Var);

    for(v->i = 0; v->i < (v->qntd) - 1; v->i++){
        for(v->j = 0; v->j < (v->qntd) - (v->i) - 1; v->j++){            
            if(strcmp(pessoa[v->j].nome, pessoa[v->j+1].nome) > 0){
                v->auxAg = pessoa[v->j];
                pessoa[v->j] = pessoa[v->j+1];
                pessoa[v->j+1] = v->auxAg;
            }
        }
    }
}

void desalocaAgenda(){
    free(pBuffer);
}

