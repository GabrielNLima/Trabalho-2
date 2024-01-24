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

no *rodaDireita(no *p, int x) {
    no *temp, *q;
	if(p==NULL){
		return NULL;
	}
	else{
		if(p->info==x){
			q = p->Llink;
			temp = q->Rlink;
			q->Rlink = p;
			p->Llink = temp;
			return q;
		}
		else if(p->info>x){
				p->Llink = rodaDireita(p->Llink, x);
			}
			else{
				p->Rlink = rodaDireita(p->Rlink, x);
			}
	}
}

no *rodaEsquerda(no *p, int x) {
    no *temp, *q;
	if(p==NULL){
		return NULL;
	}
	else{
		if(p->info==x){
			q = p->Rlink;
			temp = q->Llink;
			q->Llink = p;
			p->Rlink = temp;
			return q;
		}
		else if(p->info>x){
				p->Rlink = rodaEsquerda(p->Rlink, x);
			}
			else{
				p->Llink = rodaEsquerda(p->Llink, x);
			}
	}
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
			p->Rlink = rodaDireita(p->Rlink);
			return rodaEsquerda(p);
	}
		if( Fb(p) == -2 ){
			if( Fb(p->Llink) > 0 )
				p->Llink = rodaEsquerda(p->Llink);
				return rodaDireita(p);
		}
	return p;
}


no *insere_AB(no *T, int valor) {
	if (T == NULL){
		T = (no *) malloc (sizeof(no));
		T->info = valor;
		T->Llink = NULL;
		T->Rlink = NULL;
		return T;
	}
	else {
		if (valor < T->info) 
			T->Llink = insere_AB(T->Llink, valor);
		else {	 
			T->Rlink = insere_AB(T->Rlink, valor);
		}
	}
	int fatbal = Fb(T);
		if (fatbal > 1 && valor > T->Rlink->info){
			return rodaEsquerda(T);
		}
		if (fatbal < -1 && valor < T->Llink->info){
			return rodaDireita(T);
		}
		if (fatbal > 1 && valor < T->Rlink->info){
			T->Rlink = rodaDireita(T->Rlink);
			return rodaEsquerda(T);
		}
		if (fatbal < -1 && valor > T->Llink->info){
			T->Llink = rodaEsquerda(T->Llink);
			return rodaDireita(T);
		}
}