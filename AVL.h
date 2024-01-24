#include <iostream>
using namespace std;

typedef struct TreeNo {
	int info;
	struct TreeNo *Llink;
	struct TreeNo *Rlink;
} no;

no *ini_AB(no *T) {
	return NULL;
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

int nivel(no *T, int x, int n){
	if(T!=NULL){
		if(T->info==x){
			return n;
		}
		else if(T->info>x){
			return nivel(T->Llink, x, n+1);
		}
		else{
			return nivel(T->Rlink, x, n+1);
		}
	}
	return -1;
}

int fatball(no *p){
    return altura_AB(p->Rlink) - altura_AB(p->Llink);
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

bool printPorNivel(no *T, int n){

	if(T==NULL)
		return false;

	if(n==1){
		cout << T->info << " ";
		return true;
	}

	bool filho1 = printPorNivel(T->Llink, n-1);
	bool filho2 = printPorNivel(T->Rlink, n-1);

	return filho1 || filho2;
}

void percursoLargura(no *T){
	int n = 1;
	while(printPorNivel(T, n)){
		n++;
		cout << endl;
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

no *insere_AVL(no *T, int valor){
    if (T == NULL){
		T = (no *) malloc (sizeof(no));
		T->info = valor;
		T->Llink = NULL;
		T->Rlink = NULL;
		return T;
	}
	else {
		if (valor < T->info){
			T->Llink = insere_AVL(T->Llink, valor);
		}
		else {	 
			T->Rlink = insere_AVL(T->Rlink, valor);
		}
	}
	int fatbal = fatball(T);
    if (fatbal > 1 && valor > T->Rlink->info){
        return rodaEsquerda(T, T->info);
    }
    if (fatbal < -1 && valor < T->Llink->info){
        return rodaDireita(T, T->info);
    }
    if (fatbal > 1 && valor < T->Rlink->info){
        T->Rlink = rodaDireita(T->Rlink, T->Rlink->info);
        return rodaEsquerda(T, T->info);
    }
    if (fatbal < -1 && valor > T->Llink->info){
        T->Llink = rodaEsquerda(T->Llink, T->Llink->info);
        return rodaDireita(T, T->info);
    }
	return T;
}