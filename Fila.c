#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define TAMANHO_FILA 10

typedef struct fila {
    int elementos[TAMANHO_FILA];
    int indiceFinalFila;
} Fila;

typedef struct resultadoDesenfileirar {
	bool erro;
	int valor;
} ResultadoDesenfileirar;

Fila* inicializarFila() {
	Fila *novaFila = (Fila*) malloc(sizeof(Fila));
	novaFila->indiceFinalFila = -1;
	return novaFila;
}

int contagem(Fila *fila) {
    return fila->indiceFinalFila + 1;
}

bool estaCheia(Fila *fila) {
	return contagem(fila) == TAMANHO_FILA;
}

bool estaVazia(Fila *fila) {
	return contagem(fila) == 0;
}

bool enfileirar(Fila *fila, int numero) {
    if (estaCheia(fila))
    	return false;

	fila->indiceFinalFila++;
    fila->elementos[fila->indiceFinalFila] = numero;
    
	return true;
}

ResultadoDesenfileirar desenfileirar(Fila *fila) {
	ResultadoDesenfileirar resultado;
	resultado.erro = false;
	
    if (estaVazia(fila)) {
    	resultado.erro = true;
    	return resultado;
    }
    	
    resultado.valor = fila->elementos[0];
	
	int i = 0;
    for(i = 0; i < (fila->indiceFinalFila + 1); i++) {
        fila->elementos[i] = fila->elementos[i+1];
    }   
    
    fila->indiceFinalFila--;
    
    return resultado;
}

void listarFila(Fila *fila) {
    int i;
    for(i = 0; i < (fila->indiceFinalFila + 1); i++) {
        printf("%d\n", fila->elementos[i]);
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
