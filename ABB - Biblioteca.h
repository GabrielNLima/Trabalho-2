/*
 * ABB.h
 */
#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct TreeNo {
	int info;
	struct TreeNo *Llink;
	struct TreeNo *Rlink;
} no;

no *ini_AB(no *T) {
	return NULL;
}

no *insere_AB(no *T, int x) {
	if (T == NULL){
		T = (no *) malloc (sizeof(no));
		T->info = x;
		T->Llink = NULL;
		T->Rlink = NULL;
		return T;
	}
	else {
		if (x < T->info) 
			T->Llink = insere_AB(T->Llink, x);
		else {	 
			T->Rlink = insere_AB(T->Rlink, x);
		}
		return T;
	}
}

void emOrdem_AB(no *T) {
	if(T != NULL) {
		emOrdem_AB(T->Llink);
		printf("\n %d", T->info);	
		emOrdem_AB(T->Rlink);
	}
}

void preOrdem_AB(no *T) {
	if(T != NULL) {
		printf("\n %d", T->info);	
		preOrdem_AB(T->Llink);
		preOrdem_AB(T->Rlink);
	}
}

void posOrdem_AB(no *T) {
	if(T != NULL) {
		posOrdem_AB(T->Llink);
		posOrdem_AB(T->Rlink);
		printf("\n %d", T->info);	
	}
}

no *apaga_AB(no *T) {
	no *p;
	if(T != NULL) {
		apaga_AB(T->Llink);
		apaga_AB(T->Rlink);
		printf("apagando - %d - ", T->info);
		p = T;	
		free(p);
		T = NULL;		
	}
	return T;
}

no *maior_AB(no *T) {
	no *p;
 	if (T != NULL){
 		if(T->Rlink != NULL)
			p = maior_AB(T->Rlink);
		else
			p=T;
		return p;
	}
}

int altura_AB(no *T) {
	int aL, aR;
		
	if(T == NULL) {
		return -1;
	}
	else {
		aL = altura_AB(T->Llink);
		aR =  altura_AB(T->Rlink);
		if (aL < aR){
			return (aR+1);
		}
		else{
			return (aL+1);
		}
	}
}

no *remove_AB(no *T, int x){
	no *p;

	if (T == NULL) {
		return NULL;
	}
	else{
		if (x < T->info)
			T->Llink = remove_AB(T->Llink, x);
		else {
			if (x > T->info)
				T->Rlink = remove_AB(T->Rlink, x);
			else {
				//no folha
				if ((T->Llink == NULL) && (T->Rlink == NULL)){
					p = T;
					free(p);
					T = NULL;
					return T;
				}
				else{
					// so tem o filho da direita
					if (T->Llink == NULL){ 
						p = T;
						T = T->Rlink;
						free(p);
						return T;
					}
					else{
						// so tem o filho da esquerda 
						if (T->Rlink == NULL){ 
							p = T;
							T = T->Llink;
							free(p);
							return T;
						}
						else {
							// NO tem 2 filhos 
							p = maior_AB(T->Llink);
							T->info = p->info;
							T->Llink = remove_AB(T->Llink,p->info);
						}
					}
				}
			}
		}
	}
}

no *rodaDireita(no *p) {
    no *temp, *q;
	q = p->Llink;
	temp = q->Rlink;
	q->Rlink = p;
	p->Llink = temp;
	return q;
}

no *rodaEsquerda(no *p) {
    no *temp, *q;
	q = p->Rlink;
	temp = q->Llink;
	q->Llink = p;
	p->Rlink = temp;
	return q;
}