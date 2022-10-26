#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

typedef struct no {
	int valor;
	struct no *esquerda;
	struct no *direita;
} No;

bool estaVazia(No **raiz) {
	if (*raiz == NULL)
		return true;
		
	return false;
}

bool inserir(No **raiz, int valor) {
	No *novoNo = (No*) malloc(sizeof(No));
	novoNo->direita = NULL;
	novoNo->esquerda = NULL;
	novoNo->valor = valor;
	
	if (estaVazia(raiz)) {
		*raiz = novoNo;
		return true;
	} else {
		if (valor > (*raiz)->valor)
			return inserir(&((*raiz)->direita), valor);
		else if (valor < (*raiz)->valor)
			return inserir(&((*raiz)->esquerda), valor);
		else
			return false;
	}
}

void preordem(No *raiz) {
	if (!estaVazia(&raiz)) {
		printf("%d\n", raiz->valor);
		preordem(raiz->esquerda);
		preordem(raiz->direita);
	}
}

void inordem(No *raiz) {
	if (!estaVazia(&raiz)) {
		inordem(raiz->esquerda);
		printf("%d\n", raiz->valor);
		inordem(raiz->direita);
	}
}

void posordem(No *raiz) {
	if (!estaVazia(&raiz)) {
		posordem(raiz->esquerda);
		posordem(raiz->direita);
		printf("%d\n", raiz->valor);
	}
}

int main() {
 	setlocale(LC_ALL, "pt_BR_utf8");

	No *arvore = NULL;

    int numero;
    int opcao;

    do {
    	printf("\n==============\n");
        printf("\nMenu:\n\n");
        printf("1) Inserir.\n");
        printf("2) Préordem.\n");
        printf("3) Inordem.\n");
        printf("4) Pósordem.\n");
        printf("5) Sair.\n");
        scanf("%d", &opcao);

		switch(opcao) {
            case 1:
                printf("digite um número:");
                scanf("%d", &numero);
                
                bool resultado = inserir(&arvore, numero);
                if (resultado == false) 
                	printf("Não foi inserir. Valor já existente.");
                else
                	printf("Valor inserido com sucesso.");
                	
                break;
                
            case 2:
    			printf("==============\n");            	
            	printf("Préordem:\n");
                preordem(arvore);
                break;   

            case 3:
    			printf("==============\n");            	
            	printf("Inordem:\n");
                inordem(arvore);
                break;   

            case 4:
    			printf("==============\n");            	
            	printf("Pósordem:\n");
                posordem(arvore);
                break;   
        }
    } while(opcao != 5);
    
    return 0;
}

