#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "TADFila.h"

int main()
{

    setlocale(LC_ALL, "Portuguese");

    //lista normal
    struct no *pinicio = NULL, *pfim = NULL;

    //lista preferencial
    struct no *pinicio2 = NULL, *pfim2 = NULL;

    int vresult,vnumrand, tipo, menu;

    do{


    //Criação do Menu
    printf("\n---------------------------------MENU--------------------------------\n");
    printf("\t\tDigite a função que deseja utilizar\nUse 0 para sair, 1 para cadastrar, 2 para retirar e 3 para consultar: \n");
    scanf("%d", &menu);

    if(menu == 1) // MENU CADASTRAR
        {
            do{
                printf("Digite o tipo de fila: 1-Normal, 2-Preferencial: ");
                scanf("%d", &tipo);
                if(tipo > 2 || tipo < 1)
                {
                    printf("Número Inválido!\n");
                }

                }while(tipo > 2 || tipo < 1);

                //Sorteando Numero e inserindo na lista dos NORMAIS
                 if(tipo == 1)
                {
                    vnumrand = rand () % 999;

                    printf("Número gerado = %d\n",vnumrand);

                    insere(&pinicio,&pfim,vnumrand);
                }
                //Sorteando Numero e inserindo na lista dos PREFERENCIAIS
                else
                {
                    vnumrand = rand () % 999;

                    printf("Número gerado = %d\n",vnumrand);

                    insere(&pinicio2,&pfim2,vnumrand);
                }
        }
    else if(menu == 2){ //MENU RETIRAR

        printf("\n-------------------------------RETIRADO------------------------------\n");

        //CASO PREFERENCIAL
        if(vazia(pinicio2) == 0){
            vresult = retira(&pinicio2,&pfim2);

            printf("Elemento retirado da fila.");
        }

        //CASO NORMAL
        else if (vazia(pinicio) == 0){
            vresult = retira(&pinicio,&pfim);

            printf("Elemento retirado da fila.");
        }
    }

    else if (menu == 3){ //MENU CONSULTAR



        printf("\n-------------------------------CONSULTA------------------------------\n");

        //CONSULTA PREFERENCIAL
        consulta(pinicio2, 1);

        //CONSULTA NORMAL
        consulta(pinicio, 2);

    }
        else
            //MAIOR QUE 3 OU DIFERENTE DE 1, 2, 3
            printf("Você escolheu sair");

    } while(menu <= 3 && menu >= 1);

    return 0;
}
