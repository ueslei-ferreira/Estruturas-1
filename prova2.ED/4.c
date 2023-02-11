#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *ocorre, valores; //variavel "ocorre" eh um vetor a ser alocado para receber a ocorrencia de cada valor, e "valores" serve para ler a quantidade de valores a serem inseridos e comparados com a matriz

int **aloca(int linhas, int colunas){ //aloca a matriz dinamicamente
	int **matriz, i;
	
	if(linhas>0 && colunas>0){
		
		matriz = (int**)malloc(linhas*sizeof(int*)); //aloca o ponteiro para ponteiros
		if(matriz==NULL){
				printf("erro\n");
				return NULL;
		}
		for( i=0;i<linhas;i++){
			matriz[i] = (int*)malloc(colunas*sizeof(int)); //aloca cada posicao do ponteiro
			if(matriz[i]==NULL){
				printf("erro\n");
				return NULL;
			}
		}
	}else{
		printf("indices nao validos");
		exit(1);
	}
	return matriz; //retorna uma matriz alocada
}

void preenche(int **matriz,int linhas,int colunas){
	int i,j;
	for( i=0; i<linhas ;i++){
		for(j=0; j<colunas ;j++){
			matriz[i][j] = rand() % 10000; //preenche com rand()
		}
	}
}

int *ocorrencias(int **matriz, int linhas , int colunas){
	printf("quantos valores deseja verificar na matriz: ");
	int k;
	scanf("%d", &valores);

	int *vet = (int*)malloc(valores*sizeof(int)); //inicializa o vetor de acordo com o tamanho inserido pelo usuario
	ocorre = (int*)malloc(valores*sizeof(int)); //aloca o ponteiro global que sera do mesmo tamanho do vetor pedido pelo usuario
	
	for(int i=0;i<valores;i++){
		scanf("%d", &vet[i]); //insere os valores no vetor de valores pelo usuario
		ocorre[i] = 0; //inicializa com '0', pois sera feito um incremento caso o valor do vetor anterior for encontrado na matriz
	}
	
	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			for( k=0;k<valores;k++){
				if(vet[k] == matriz[i][j]){
					ocorre[k]+=1; //soma 1 ocorrencia caso o valor dentro do vetor for encontrado na matriz
				}
			}	
		}
	}	
	return vet; //retorna o vetor com os valores inseridos pelo usuario
}

void libera_matriz(int **matriz, int linhas){ //libera as posicoes da matriz
  int i;
  for(i = 0; i < linhas; i++)
    free(matriz[i]);
  free(matriz);
}
int main(){
	int **matriz, linhas, colunas; //matriz que recebe a alocacao, linhas e colunas inseridas pelo usuario
	
	printf("quantidade de linhas: ");
	scanf("%d", &linhas);
	printf("quantidade de colunas: ");
	scanf("%d", &colunas);
	
	matriz = aloca(linhas, colunas); //aloca a matriz de acordo com as linhas e colunas inseridas pelo usuario
	
	srand(time(NULL)); //funcao que evita sempre os mesmo numero de rand()
	preenche(matriz, linhas, colunas); //preenche a matriz com rand
	
	for(int i=0;i<linhas;i++){
		for(int j=0;j<colunas;j++){
			printf("  %d  ", matriz[i][j]); //imprime a matriz para saber quais valores estão dentro
		}
		printf("\n");
	}
	
	int *vet = ocorrencias(matriz, linhas, colunas); //recebe um vetor com os valores inseridos na occorrencia
	for(int i=0; i<valores ;i++){
		
		printf("valor %d ", vet[i]); //vetor retornado com o numeros inseridos para comparacao
		if(ocorre[i] == 0){
			printf("sem ocorrencia\n");
		}else{
			printf("ocorrencia %d\n", ocorre[i]); //vetor global contendo as ocorrencias de cada numero inserido e comparado
		}
	}
	
	libera_matriz(matriz, linhas);
	free(vet);
	free(ocorre);
	
	return 0;
}