#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define TAMANHO_FILA 10

typedef struct pilha {
    int elementos[TAMANHO_FILA];
    int indiceFinalPilha;
} Pilha;

typedef struct resultadoPop {
	bool erro;
	int valor;
} ResultadoPop;

Pilha* inicializarPilha() {
	Pilha *novaPilha = (Pilha*) malloc(sizeof(Pilha));
	novaPilha->indiceFinalPilha = -1;
	return novaPilha;
}

int contagem(Pilha *pilha) {
    return pilha->indiceFinalPilha + 1;
}

bool estaCheia(Pilha *pilha) {
	return contagem(pilha) == TAMANHO_FILA;
}

bool estaVazia(Pilha *pilha) {
	return contagem(pilha) == 0;
}

bool Push(Pilha *pilha, int numero) {
    if (estaCheia(pilha))
    	return false;

	pilha->indiceFinalPilha++;
    pilha->elementos[pilha->indiceFinalPilha] = numero;
    
	return true;
}

ResultadoPop Pop(Pilha *pilha) {
	ResultadoPop resultado;
	resultado.erro = false;
	
    if (estaVazia(pilha)) {
    	resultado.erro = true;
    	return resultado;
    }
    	
    resultado.valor = pilha->elementos[pilha->indiceFinalPilha];
	pilha->indiceFinalPilha--;
    
    return resultado;
}

void listarPilha(Pilha *pilha) {
    int i;
    for(i = 0; i < (pilha->indiceFinalPilha + 1); i++) {
        printf("%d\n", pilha->elementos[i]);
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR_utf8");

	Pilha *pilha = inicializarPilha();

    int numero;
    int opcao;

    ResultadoPop resultadoPop;

    do {
    	printf("\n==============\n");
        printf("\nMenu:\n\n");
        printf("1) Enfileirar.\n");
        printf("2) Desenfileirar.\n");
        printf("3) listar pilha.\n");
        printf("4) sair.\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("digite um número:");
                scanf("%d", &numero);
                
                bool resultado = Push(pilha, numero);
                if (resultado == false) 
                	printf("Não foi possível enfileirar. Pilha cheia.");
                else
                	printf("Valor enfileirado com sucesso.");
                	
                break;
                
            case 2:        	
				resultadoPop = Pop(pilha);
				if (resultadoPop.erro)
					printf("Não foi possível desenfileirar. Pilha Vazia.");
				else
                	printf("Valor desenfileirado: %d", resultadoPop.valor);
                	
                break;                

            case 3:
    			printf("==============\n");            	
            	printf("Valores:\n");
                listarPilha(pilha);
                break;   
        }
    } while(opcao != 4);
}
