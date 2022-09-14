#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no { // alem de vc dar um "apelido" vc pode nomear o struct dentro do typedef
	int valor;
	struct no *prox;
} no;// nesse caso vc deu um apelido de no
 
void adicionar(no **lista , int valor){// nesse caso ele fez um ponteiro q aponta para um ponteiro pq lista ja é um ponteiro
	no *novoNo = (no*) malloc(sizeof(no));
	novoNo->valor = valor;
	novoNo->prox = NULL;
	
	if(*lista == NULL){
		*lista = novoNo;
	}else{
		no *noAtual = *lista;
		while(noAtual ->prox != NULL)
			noAtual = noAtual->prox;
		noAtual->prox = novoNo;	
	}
}

bool remover(no **lista, int valor) {
	if (*lista == NULL)
		return false;
	
	no *noAtual = *lista;
	if (noAtual->valor == valor)
		noAtual = noAtual->prox;
	else {
		no *noAnterior = NULL;
		no *noAtual = *lista;
		
		while (noAtual != NULL && noAtual->valor != valor) {
			noAnterior = noAtual;
			noAtual = noAtual->prox;
		}
		
		if (noAtual == NULL) 
			return false;
			
		noAnterior->prox = noAtual->prox;
	}
}

int main (){
	no *lista = NULL; // ela é so um endereço para um no, para o primeiro endereço 
	adicionar(&lista,10); 
	adicionar(&lista,5); // & ele é o endereço de memoria do ponteiro lista
	adicionar(&lista,3);

	no *noAtual = lista;
	printf("Valores:\n");
	while(noAtual != NULL){
		printf("%d \n", noAtual->valor);
		noAtual = noAtual->prox;
	}

	remover(&lista, 5);

	printf("\nValores:\n");

	noAtual = lista;
	while(noAtual != NULL){
		printf("%d \n", noAtual->valor);
		noAtual = noAtual->prox;
	}
	
}



