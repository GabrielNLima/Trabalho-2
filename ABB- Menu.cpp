/*
 * �RVORE DE BUSCA BIN�RIA
 */
	
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "ABB - Biblioteca.h"

using namespace std;


int main(){

   no *T, *p;
   int x, c;
   int conta=0;
   no *pmaior, *pmenor;
   
   T=ini_AB(T);
   
   do 
   {
      printf("\n");
	  printf("0 - Sair\n");
      printf("1 - Insere Item na ARVORE DE BUSCA BINARIA\n");
      printf("2 - EMORDEM -  Lista Itens da ARVORE DE BUSCA BINARIA - Em Ordem\n");
      printf("3 - PREORDEM - Lista Itens da ARVORE DE BUSCA BINARIA - Pre Ordem\n");
      printf("4 - POSORDEM - Lista Itens da ARVORE DE BUSCA BINARIA - Pos Ordem\n");
	  printf("5 - ROTACAO A DIREITA - ARVORE DE BUSCA BINARIA \n");
	  printf("6 - ROTACAO A ESQUERDA - ARVORE DE BUSCA BINARIA \n");
	  printf("7 - Remove Item da ARVORE DE BUSCA BINARIA \n");
	  printf("8 - Imprime os filhos da esquerda e direita \n");
      printf("\n Escolha: ");
    //   printf("5 - CONTA nos da ARVORE DE BUSCA BINARIA \n");
    //   printf("6 - APAGA nos da ARVORE DE BUSCA BINARIA \n");
    //   printf("7 - Encontra MAIOR nos da ARVORE DE BUSCA BINARIA \n");
    //   printf("8 - Encontra MENOR nos da ARVORE DE BUSCA BINARIA \n");
    //   printf("9 - Retorna ALTURA da ARVORE DE BUSCA BINARIA \n");
	//   printf("14 - IMPRIMA O VALOR DO PAI \n");
	//   printf("15 - Imprime de maneira decrescente \n");

      cin >> c;

      switch(c) {
        case 0: 
		    exit(0);
            break;

         case 1: 
			cout << " \nEntre com o item a ser inserido: ";
			cin >> x;
			T = insere_AB(T,x); 
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
		// case 5: 
		// 	printf("\n %d", conta_AB(T, conta));
		// 	//conta_AB(T, &conta);
		// 	//printf("\n %d", conta);
		// 	printf("\n");	
		// 	break;
        // case 6: 
		// 	T = apaga_AB(T);
		// 	printf("\n");	
		// 	break;
		// case 7: 
		// 	p = maior_AB(T);
		// 	printf("\n");
 		// 	cout << p->info;
 		// 	printf("\n");	
		// 	break;
        // case 8: 
		// 	p = menor_AB(T);
		// 	printf("\n");
 		// 	cout << p->info;
 		// 	printf("\n");	
		// 	break;
        // case 9: 
		//     printf("\n %d", altura_AB(T));
		// 	printf("\n");	
		// 	break;
        case 5: 
			T = rodaDireita(T);
// a ser desenvolvido pelo aluno
//			cout << " \nEntre com o elemento a ser rotacionado a DIREITA: ";
//			cin >> x;
//			T = rodaDir(T,x);
			printf("\n");	
			break;
        case 6: 
// a ser desenvolvido pelo aluno
//			cout << " \nEntre com o elemento a ser rotacionado a ESQUERDA: ";
//			cin >> x;
//			T = rodaEsq(T,x);
			printf("\n");	
			break;
		case 7: 
			cout << " \nEntre com o item a ser removido: ";
			cin >> x;
			T = remove_AB(T,x); 
            break;
		case 8: 
			cout << " \nInsira o valor do pai: ";
			cin >> x;
			imprimeFilhos_AB(T, x);
            break;
	// 	case 14:
	// 		cout << " \nEntre com o valor do filho: ";
	// 		cin >> x;
	// 		T = buscaPai(T, x);

	// 		break;
	// 	case 15:
	// 		imprimeDecrescente_AB(T);
	// 		break;
	//   }
   } while (c != 9);
}

