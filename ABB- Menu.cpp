#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "AVL.h"

using namespace std;


int main(){

   no *T;
   int x, c;
   
   T=ini_AB(T);
   
   do
   {
   	    printf("\n");
	    printf("0 - Sair\n");
        printf("1 - Insere Item na ARVORE\n");
        printf("2 - EMORDEM -  Lista Itens da ARVORE DE BUSCA BINARIA - Em Ordem\n");
        printf("3 - PREORDEM - Lista Itens da ARVORE DE BUSCA BINARIA - Pre Ordem\n");
  	    printf("4 - POSORDEM - Lista Itens da ARVORE DE BUSCA BINARIA - Pos Ordem\n");
      	printf("\n Escolha: ");

      	cin >> c;

      	switch(c) {
			case 0: 
				exit(0);
				break;

			case 1: 
				cout << " \nEntre com o item a ser inserido: ";
				cin >> x;
				T = insere_AVL(T,x); 
				break;
			case 2: 
				emOrdem_AB(T);
				printf("\n");	
				break;
			case 3: 
				preOrdem_AB(T);
				printf("\n");	
				break;
			case 4: 
				posOrdem_AB(T);
				printf("\n");	
				break;
		} 
	} while (c != 5);
}