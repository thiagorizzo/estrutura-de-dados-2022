#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no {
	int valor;
	struct no *prox;
} no;
 
void adicionar(no **lista , int valor){
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
	
	no *primeiro = *lista;
	if (primeiro->valor == valor)
		*lista = primeiro->prox;
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

void printar(no **lista) {
	no *noAtual = *lista;
	printf("\nLista:\n");
	while(noAtual != NULL){
		printf("%d\n", noAtual->valor);
		noAtual = noAtual->prox;
	}
	printf("\n");
}

int main (){
	no *lista = NULL;
	
	int opcao;
	int valor;
	
	do {
		printf("1- Adicionar\n2- Remover\n3- Listar\n4- Sair\n");
		scanf("%d", &opcao);
		if (opcao != 4) {
			switch(opcao) {
				case 1:
					printf("Valor adicionar:");
					scanf("%d", &valor);
					adicionar(&lista, valor);
					break;
					
				case 2:	
					printf("Valor remover:");
					scanf("%d", &valor);
					remover(&lista, valor);
					break;
					
				case 3:
					printar(&lista);
					break;
			}
		}		
	} while (opcao != 4);
}

