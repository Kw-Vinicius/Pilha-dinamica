// ---------------------------------------------------------------------------------

// Utilizar pilha dinâmica para avaliar uma expressão prefixa e retornar o resultado:

// Vinicius Atsushi Sato Kawai
// Ciência da Computação - Estrutura de Dados 1 (ED1)
// UNESP Rio Claro

// ---------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>


typedef struct Elementos{
    int valor;
    struct Elementos *prox;
}Elementos;

int pilha_contador;

Elementos *topo;

int vazia();
void inicia();
void erase();
void push(int x);
void get();
void expressao(char *exp);
int pop();
int operacao(char item);


void soma();
void sub();
void mult();
void exponencial();
void divisao();

// ----------------------------------- Main --------------------------------------------

int main(void){
    char exp[50];     
    inicia();

    system("clear");
    printf("Digite a expressão: \n");             
    fgets(exp,50,stdin);
    fflush(stdin);
    sleep(1.5);

    expressao(exp);
    get();
    erase();
}

// ------------------------------------ Funções ----------------------------------------

void inicia(){
    topo = NULL;
    pilha_contador = 0;
}

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

void push(int x){
    Elementos *nova = (Elementos*) malloc(sizeof(Elementos));

    if(nova == NULL){
        printf("Erro na alocação de memória! ");
        sleep(1.5);
        exit(1);
    }else {
        nova->valor = x;
        nova->prox = topo;

        topo = nova;
        pilha_contador ++;
    }
}

int vazia(){
    if(topo==NULL){
        return 1;
    }else return 0;
}

int operacao(char item){
    if(item != '+' && item !='-' && item !='*' && item !='/' && item !='^'){
        return 1;
    }else return 0;
}

void expressao(char *exp){
    int index;
    int conv;

    for(index = strlen(exp)-1;index>=0;index --){
        if(operacao(exp[index])){
            conv = exp[index] - '0';
            push(conv);
        }else{
            switch(exp[index]){
                case '+':
                    soma();
                    break;
                case '-':
                    sub();
                    break;
                case '^':
                    exponencial();
                    break;
                case '*':
                    mult();
                    break;
                case '/':
                    divisao();
                    break;

                default: 
                    break;
            }
        }
        
    }
}

int pop(){
    Elementos *temp;
    int aux;

        if(vazia()){
            printf("Nada para desempilhar!\n");
        }else{
            temp = topo;
            aux = topo->valor;
            topo = topo->prox;
            temp->prox = NULL;

            free(temp);
            pilha_contador --;
            return aux;
        }
}

void get(){

     if(vazia()){
            printf("Nada para desempilhar!\n");
        }else{
            printf("O resultado é %d\n\n",topo->valor);
        }
}


// ------------------------------- Operações ----------------------------------------


void soma()
{
    int aux,
        op1,
        op2;
    
    op1 = pop();
    op2 = pop();
    aux = op1 + op2;
    push(aux);
}

void sub()
{
    int aux,
        op1,
        op2;
    
    op1 = pop();
    op2 = pop();
    aux = op1 - op2;
    push(aux);
}

void mult()
{
   int aux,
        op1,
        op2;
    
    op1 = pop();
    op2 = pop();
    aux = op1 * op2;
    push(aux); 
}

void exponencial()
{
    int aux,
        op1,
        op2;
    
    op1 = pop();
    op2 = pop();
    aux = pow(op1,op2);
    push(aux);
}

void divisao()
{
    int aux,
        op1,
        op2;
    
    op1 = pop();
    op2 = pop();
    aux = op1 - op2;
    push(aux);
}

// ---------------------------------------------------------------------------------