
#include <stdio.h>
#include <stdlib.h>

/*definindo  STRUCT pilha*/
typedef struct{
int numPilha;
struct sNO *proxPilha;
}NO;

/*Definindo Struct Fila*/
typedef struct{
    int numFila;
    struct sDADOS *proxFila;
}DADOS;

typedef DADOS* FILA;

void iniciar(FILA* Fila, NO** Pilha)
{
    *Fila = NULL;
    *Pilha = NULL;
}

void inserirFila(FILA* Fila, int numFila,int contador)
{
    if(*Fila == NULL)
    {
        *Fila=(FILA)malloc(sizeof(DADOS));
        if(*Fila==NULL)
            return;
        (*Fila)->numFila = numFila;
        (**Fila).proxFila = NULL;
    }
    else{
        inserirFila(&(**Fila).proxFila,numFila,contador);
    }

}

void inserirPilha(NO** Pilha, int numPilha)
{
    NO * TMP;
    TMP = (NO*)malloc(sizeof(NO));
    TMP->numPilha = numPilha;
    TMP->proxPilha = *Pilha;
    *Pilha = TMP;
}
int empty(NO * Pilha)
{
    return(Pilha==NULL);
}
void listarFila(FILA Fila)
{
    if(Fila == NULL)
    return;
    printf("Lista: %d\n",Fila->numFila);
    listarFila(Fila->proxFila);
}

void listarPilha(NO* Pilha)
{
if(empty(Pilha))
    return;

printf("Pilha: %d\n",Pilha->numPilha);
listarPilha(Pilha->proxPilha);
}

void apagarFila(FILA* Fila)
{   DADOS *TMP = *Fila;

    if(*Fila == NULL)
        return;
    *Fila =(*Fila)->proxFila;
    free(TMP);
}



int main(){
NO *P;
FILA F;
iniciar(&F,&P);
int contador;
contador = 3;
inserirFila(&F,10,contador);
inserirFila(&F,20,contador);
inserirPilha(&P,10);
inserirPilha(&P,20);
listarFila(F);
printf("\n");
listarPilha(P);
apagarFila(&F);
listarFila(F);
}
