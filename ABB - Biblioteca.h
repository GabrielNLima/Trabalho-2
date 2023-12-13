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

// int conta_AB(no *T, int x) {
// 	if(T != NULL) {
// 		x++;
// 		x=conta_AB(T->Llink, x);
// 		x=conta_AB(T->Rlink, x);	
// 	}
// 	return x;
// }

/*
void conta_AB(no *T, int *x) {
	if(T != NULL) {
		(*x)++;
		conta_AB(T->Llink, x);
		conta_AB(T->Rlink, x);	
	}
} */

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


// no *maior_AB(no *T) {
//     no *p;
// 	if (T != NULL) {
// 		while (T->Rlink != NULL){
// 			T = T->Rlink;
// 		}
// 		return T;  
// 	}
// 	else
// 		return NULL;
// }


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

// no *menor_AB(no *T) {
//     no *p;
// 	if (T !=NULL) {
// 		while (T->Llink != NULL){
// 			T = T->Llink;
// 		}
// 			return T;  
// 	}
// 	else
// 		return NULL;
// }

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

// // no *buscaPai(no *T, int x) {
// // 	if (T == NULL || (T->Llink && T->Llink->info == x) || (T->Rlink && T->Rlink->info == x)) {
// // 		cout << "O NO Pai de x e: " << T->info;
// // 		return T;
// // 	}

// // 	if(T== NULL){
// // 		return T;
// // 	}
// // 	if (x < T->info) {

// // 		return buscaPai(T->Llink, x);
// // 	} else {
// // 		return buscaPai(T->Rlink, x);
// // 	}
// // }

// no *buscaAB(no *T, int x){
// 	if(T != NULL) {
// 		if(x == T->info){
// 			return T;
// 		}
// 		else if (x < T->info){	
// 			buscaAB(T->Llink, x);
// 		}
// 		else {
// 		buscaAB(T->Rlink, x);
// 		}
// 	}
// 	else {
// 	return T;
// }
// }

// void imprimeFilhos_AB(no *T, int x) {

// 	no *nodo = buscaAB(T, x);


// 	if (nodo != NULL) {

// 		cout << "No: " << nodo->info << endl;
	

// 		if (nodo->Llink != NULL) {

// 			cout << "Filho da Esquerda: " << nodo->Llink->info << endl;

// 		} else {

// 			cout << "Nao ha filho da Esquerda." << endl;

// 		}



// 		if (nodo->Rlink != NULL) {

// 			cout << "Filho da Direita: " << nodo->Rlink->info << endl;
	
// 		} else {

// 			cout << "Nao ha filho da Direita." << endl;
	
// 		}

// 	} else {

// 	cout << "No nao encontrado." << endl;

// 	}

// }

// void imprimeDecrescente_AB(no *T) {
// 	if (T != NULL) {

// 		imprimeDecrescente_AB(T->Rlink);

// 		cout << T->info << " ";

// 		imprimeDecrescente_AB(T->Llink);
// 	}
// }