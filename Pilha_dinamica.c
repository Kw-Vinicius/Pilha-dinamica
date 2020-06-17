#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Elementos{
    int valor;
    struct Elementos *prox;
}Elementos;

int pilha_contador;

Elementos *topo;

// ----------------------------------------FUNÇÕES------------------------------------------------------------------
void inicia();
int vazia();
void tamanho();
void push(int item);
void pop();
void get();
void erase();
void exibe();
void menu();

// ------------------------------------------MAIN--------------------------------------------------------------------

int main(void){
    inicia();
    menu();
    erase();
}

// -----------------------------------------------------------------------------------------------------------------

void inicia(){
    topo = NULL;
    pilha_contador = 0;
}


// -----------------------------------------------------------------------------------------------------------------

int vazia(){
    if(topo==NULL){
        return 1;
    }else return 0;
}


// -----------------------------------------------------------------------------------------------------------------

void tamanho(){
    system("clear");
    printf("O tamanho atual da pilha é de %d elementos\n\n",pilha_contador);
}

// -----------------------------------------------------------------------------------------------------------------

void push(int item){
    Elementos *nova = (Elementos*) malloc(sizeof(Elementos));

    if(nova == NULL){
        printf("Erro na alocação de memória! ");
        sleep(1.5);
        exit(1);
    }else {
        nova->valor = item;
        nova->prox = topo;

        topo = nova;
        pilha_contador ++;
    }
}

// -----------------------------------------------------------------------------------------------------------------

void pop(){
    Elementos *temp;

        if(vazia()){
            printf("Nada para desempilhar!\n");
        }else{
            temp = topo;
            topo = topo->prox;
            temp->prox = NULL;

            free(temp);
            pilha_contador --;
        }
}

// -----------------------------------------------------------------------------------------------------------------

void get(){

     if(vazia()){
            printf("Nada para desempilhar!\n");
        }else{
            system("clear");
            printf("O valor do topo é %d\n\n",topo->valor);
        }
}

// -----------------------------------------------------------------------------------------------------------------

void erase(){
    Elementos *temp;
        if(vazia()){
            printf("Não a nada para apagar! Pilha vazia\n");
        }else {
            while(topo != NULL){
                temp = topo;
                temp->prox=NULL;
                topo = topo->prox;

                free(temp);
            }
            pilha_contador = 0;
        }
}

// -----------------------------------------------------------------------------------------------------------------

void exibe(){
    Elementos *temp;
    temp = topo;
    if(vazia()){
        printf("Pilha vazia, nada a exibir!\n");
    }else{
        while(temp != NULL){
        printf("%d\n",temp->valor);
        temp = temp->prox;
         }
    }  
    
}

// -----------------------------------------------------------------------------------------------------------------

void menu(){
    int op= -1;
    int value;
    

    while(op != 0){
        sleep(1.5);
        system("clear");
        printf("0 - Sair\n");
        printf("1 - Inserir Elemento\n");
        printf("2 - Remover Elemento\n");
        printf("3 - Valor do topo\n");
        printf("4 - Apagar a pilha\n");
        printf("5 - Exibir a pilha\n");
        printf("6 - Tamanho da pilha\n");
        printf("Digite sua opção: ");
        scanf("%d",&op);

        switch(op){
            case 0:
                break;
            case 1:
                printf("Digite um valor para adicionar a pilha: "); 
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                get();
                break;
            case 4:
                erase();
                break;
            case 5:
                exibe();
                break;
            case 6:
                tamanho();
                break;
            default:
                printf("\nEscolha invalida! Escolha uma opção: \n");

        }
    }
}

// -----------------------------------------------------------------------------------------------------------------