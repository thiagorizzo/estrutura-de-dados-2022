#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

typedef struct resultadoDesenfileirar {
	bool erro;
	int valor;
} ResultadoDesenfileirar;

typedef struct resultadoRemoverIndice {
	bool erro;
	int valor;
} ResultadoRemoverIndice;

typedef struct no {
	int valor;
	struct no *prox;
} no;

typedef struct fila {
    no *lista;
} Fila;
 
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

ResultadoRemoverIndice removerIndice(no **lista, int indice) {
	
	ResultadoRemoverIndice resultado;
	resultado.erro = false;
	
	if (*lista == NULL) {
		resultado.erro = true;
		return resultado;
	}
	
	no *primeiro = *lista;
	
	if (indice == 0) {
		*lista = primeiro->prox;
		resultado.valor = primeiro->valor;
	} else {
		no *noAnterior = NULL;
		no *noAtual = *lista;
		
		int indiceAtual = 0;
		
		while (noAtual != NULL && indiceAtual != indice) {
			noAnterior = noAtual;
			noAtual = noAtual->prox;
		}
		
		if (noAtual == NULL) {
			resultado.erro = true;
			return resultado;			
		}
			
		noAnterior->prox = noAtual->prox;
		resultado.valor = noAtual->valor;
	}
	
	return resultado;
}

Fila* inicializarFila() {
	Fila *novaFila = (Fila*) malloc(sizeof(Fila));
	novaFila->lista = NULL;
	return novaFila;
}

bool estaVazia(Fila *fila) {
	if (fila->lista == NULL)
		return true;
	
	return false;
}

int contagem(Fila *fila) {
	if (estaVazia(fila)) {
		return 0;
	}
	
	int count = 0;
	
	no *noAtual = fila->lista;
	while(noAtual) {
		noAtual = noAtual->prox;
		count++;
	}	
	
    return count;
}


bool enfileirar(Fila *fila, int numero) {
    adicionar(&fila->lista, numero);
	return true;
}

ResultadoDesenfileirar desenfileirar(Fila *fila) {
	ResultadoDesenfileirar resultado;
	resultado.erro = false;
	
    if (estaVazia(fila)) {
    	resultado.erro = true;
    	return resultado;
    }
    	
	ResultadoRemoverIndice resultadoRemover = removerIndice(fila, 0);
	if (resultadoRemover.erro == true)
		resultado.erro = true;
	else
		resultado.valor = resultadoRemover.valor;
    
    return resultado;
}

void listarFila(Fila *fila) {
	no *noAtual = fila->lista;
	while(noAtual) {
		printf("%d\n", noAtual->valor);
		noAtual = noAtual->prox;
	}	
}

int main() {
    setlocale(LC_ALL, "pt_BR_utf8");

	Fila *fila = inicializarFila();

    int numero;
    int opcao;

    ResultadoDesenfileirar resultadoDesenfileirar;

    do {
    	printf("\n==============\n");
        printf("\nMenu:\n\n");
        printf("1) Enfileirar.\n");
        printf("2) Desenfileirar.\n");
        printf("3) listar fila.\n");
        printf("4) sair.\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("digite um número:");
                scanf("%d", &numero);
                
                bool resultado = enfileirar(fila, numero);
                if (resultado == false) 
                	printf("Não foi possível enfileirar. Fila cheia.");
                else
                	printf("Valor enfileirado com sucesso.");
                	
                break;
                
            case 2:
            	
				resultadoDesenfileirar = desenfileirar(fila);
				if (resultadoDesenfileirar.erro)
					printf("Não foi possível desenfileirar. Fila Vazia.");
				else
                	printf("Valor desenfileirado: %d", resultadoDesenfileirar.valor);
                	
                break;                

            case 3:
    			printf("==============\n");            	
            	printf("Valores:\n");
                listarFila(fila);
                break;   
        }
    } while(opcao != 4);
}
