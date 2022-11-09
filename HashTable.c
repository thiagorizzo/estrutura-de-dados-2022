#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 20

struct DataItem {
   int valor;   
   int chave;
};

struct DataItem* hashArray[TAMANHO]; 
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int chave) {
   return chave % TAMANHO;
}

struct DataItem *buscar(int chave) {
   int hashIndex = hashCode(chave);  
	
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->chave == chave)
         return hashArray[hashIndex]; 
			
      ++hashIndex;
		
      hashIndex %= TAMANHO;
   }        
	
   return NULL;        
}

void adicionar(int chave, int valor) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->valor = valor;
   item->chave = chave;

   int hashIndex = hashCode(chave);

   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->chave != -1) {
      ++hashIndex;
		
      hashIndex %= TAMANHO;
   }
	
   hashArray[hashIndex] = item;
}

struct DataItem* remover(int chave) {
   int hashIndex = hashCode(chave);

   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->chave == chave) {
         struct DataItem* temp = hashArray[hashIndex]; 
			
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
		
      ++hashIndex;
		
      hashIndex %= TAMANHO;
   }      
	
   return NULL;        
}

void listar() {
   int i = 0;
	
   for(i = 0; i < TAMANHO; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%d,%d)", hashArray[i]->chave, hashArray[i]->valor);
      else
         printf(" -- ");
   }
	
   printf("\n");
}

int main() {
	int chave;
    int valor;
    int opcao;
    struct DataItem* removido;

    do {
    	printf("\n==============\n");
        printf("\nMenu:\n\n");
        printf("1) adicionar.\n");
        printf("2) remover.\n");
        printf("3) listar.\n");
        printf("4) sair.\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
            	printf("digite a chave:");
            	scanf("%d", &chave);
            	
                printf("digite um valor:");
                scanf("%d", &valor);
                
                adicionar(chave, valor);
                
                break;
                
            case 2:
            	printf("digite a chave");
            	scanf("%d", &chave);
            	
				removido = remover(chave);
            	
				if (removido == NULL)
					printf("Não foi possível remover.");
				else
                	printf("Valor removido: %d", removido->valor);
                	
                break;                

            case 3:
    			printf("==============\n");            	
            	printf("Valores:\n");
                listar();
                break;   
        }
    } while(opcao != 4);
	
   return 0;
}
