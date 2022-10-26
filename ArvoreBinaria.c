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

No* buscarNoMaiorDireita(No **raiz){
    if ((*raiz)->direita != NULL) 
       return buscarNoMaiorDireita(&(*raiz)->direita);
    else {
       No *aux = *raiz;

       if((*raiz)->esquerda != NULL)
          *raiz = (*raiz)->esquerda;
       else
          *raiz = NULL;

       return aux;
   }
}

No* buscarNoMenorEsquerda(No **raiz){
    if ((*raiz)->esquerda != NULL) 
       return buscarNoMenorEsquerda(&(*raiz)->esquerda);
    else{
       No *aux = *raiz; 
       
	   if ((*raiz)->direita != NULL)
          *raiz = (*raiz)->direita;
       else
          *raiz = NULL;

	   return aux;
   }
}

bool remover(No **raiz, int valor){
    if (*raiz == NULL) {
		return false;
    }
    
    if (valor < (*raiz)->valor)
    	remover(&(*raiz)->esquerda, valor);
    else 
       if (valor > (*raiz)->valor) {
          remover(&(*raiz)->direita, valor);
       } else {
          No *aux = *raiz;
          
		  if (((*raiz)->esquerda == NULL) && ((*raiz)->direita == NULL)) {
            (*raiz) = NULL; 
          } else {
             if ((*raiz)->esquerda == NULL) {
                (*raiz) = (*raiz)->direita;
                aux->direita = NULL;
                aux = NULL;
            } else {
                if ((*raiz)->direita == NULL) {
                    (*raiz) = (*raiz)->esquerda;
                    aux->esquerda = NULL;
                    aux = NULL;
            	} else {
                   aux = buscarNoMaiorDireita(&(*raiz)->esquerda);
                   aux->esquerda = (*raiz)->esquerda;
                   aux->direita = (*raiz)->direita;
                   (*raiz)->esquerda = (*raiz)->direita = NULL;
				   *raiz = aux;
				   aux = NULL;   
                }
            }
        }
    }
    
    return true;
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
        printf("5) Remover.\n");
        printf("6) Sair.\n");
        scanf("%d", &opcao);

		switch(opcao) {
            case 1:
                printf("digite um número:");
                scanf("%d", &numero);
                
                bool resultadoInserir = inserir(&arvore, numero);
                if (resultadoInserir == false) 
                	printf("Não foi possível inserir. Valor já existe.");
                else
                	printf("Valor inserido com sucesso.");
                	
                break;
                
            case 2:
                printf("digite um número:");
                scanf("%d", &numero);
                
                bool resultadoRemover = remover(&arvore, numero);
                if (resultadoRemover == false) 
                	printf("Não foi possível remover. Valor inexistente.");
                else
                	printf("Valor removido com sucesso.");
                	
                break;
                
            case 3:
    			printf("==============\n");            	
            	printf("Préordem:\n");
                preordem(arvore);
                break;   

            case 4:
    			printf("==============\n");            	
            	printf("Inordem:\n");
                inordem(arvore);
                break;   

            case 5:
    			printf("==============\n");            	
            	printf("Pósordem:\n");
                posordem(arvore);
                break;   
        }
    } while(opcao != 6);
    
    return 0;
}

