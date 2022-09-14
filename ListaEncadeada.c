#include <stdlib.h>
#include <stdio.h>

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

int main (){
	no *lista = NULL; // ela é so um endereço para um no, para o primeiro endereço 
	adicionar(&lista,10); 
	adicionar(&lista,5); // & ele é o endereço de memoria do ponteiro lista
	adicionar(&lista,3);
	no *noAtual = lista;
	while(noAtual != NULL){
		printf("%d \n", noAtual->valor);
		noAtual = noAtual->prox;
	}
}

