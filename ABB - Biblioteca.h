/*
 * ABB.h
 */
#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct TreeNo {
	int info;
	int altura;
	struct TreeNo *Llink;
	struct TreeNo *Rlink;
} no;

no *ini_AB(no *T) {
	return NULL;
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

no *rotacaoDireita(no *p) {
	no *q = p->Llink;
	no *temp = q->Rlink;
	
	q->Rlink = p;
	p->Llink = temp;
	
	p->altura = altura(p);
	q->altura = altura(q);
	return q;
}

no *rotacaoEsquerda(no *p) {
	no *q = p->Rlink;
	no *temp = q->Llink;
	
	q->Llink = p;
	p->Rlink = temp;
	
	p->altura = altura(p);
	q->altura = altura(q);
	return q;
}

int maximo(int x, int y){
	if (x > y)
		return x;
	else
		return y;
}

int altura(no *p) {
	if(p == NULL)
		return -1;
	else {
		return (1+maximo(altura(p->Llink), altura(p->Rlink))) ;
	}
}

int Fb(no *p){
	return altura(p->Rlink) - altura(p->Llink);
}

no* balance(no *p){
	if( Fb(p) == 2 ){
		if( Fb(p->Rlink) < 0 )
			p->Rlink = rotacaoDireita(p->Rlink);
			return rotacaoEsquerda(p);
	}
		if( Fb(p) == -2 ){
			if( Fb(p->Llink) > 0 )
				p->Llink = rotacaoEsquerda(p->Llink);
				return rotacaoDireita(p);
		}
	return p;
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
	}
	balance(T);
	return T;
}