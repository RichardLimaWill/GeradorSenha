#ifndef TADFILA_H_INCLUDED
#define TADFILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int pos=1;
// Estrutura de Dados para o Nó
struct no {
       struct no *prox;
       int val;
};

// Verifica se a Lista está vazia
int vazia(struct no *pinicio) {
    if (pinicio == NULL)
       return 1;
    else
       return 0;
}

// Insere um Nó na Fila
void insere (struct no **p2inicio, struct no **p2fim, int velemento) {
     struct no *pnovo;
     pnovo = (struct no *) malloc (sizeof(struct no));
     pnovo->val = velemento;
     if ((*p2fim) == NULL) {
              (*p2fim) = (*p2inicio) = pnovo;
              (*p2fim)->prox = NULL;
     } else {
            (*p2fim)->prox = pnovo;
            (*p2fim)       = pnovo;
            (*p2fim)->prox = NULL;
       }
}

// Retira Nó da Fila
int retira(struct no **p2inicio, struct no **p2fim) {
    pos=1;
    int velemento;
    struct no *pnoexcluido;

    if((*p2inicio)==NULL) {
                   return 0;
    } else {

           pnoexcluido = (*p2inicio);

           velemento   = (*p2inicio)->val;
           (*p2inicio) = (*p2inicio)->prox;
           if((*p2inicio) == NULL) {
                   (*p2fim)=NULL;
           }
           free(pnoexcluido);
           return velemento;
    }
}

// Consulta Nó da Fila
void consulta(struct no *pinicio, int tipo) {

     if(vazia(pinicio)) {
     } else {
            do {
                if(tipo == 1){
                    printf("\n Posição = %d - Senha = %d - Tipo = Preferencial",pos, pinicio->val);
                    pinicio = pinicio->prox;
                }
                else{
                    printf("\n Posição = %d - Senha = %d - Tipo = Normal",pos, pinicio->val);
                    pinicio = pinicio->prox;
                }
                pos++;
            } while (pinicio!=NULL);
       }
}

#endif // TADFILA_H_INCLUDED
