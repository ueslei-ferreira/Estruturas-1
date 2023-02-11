
#include <stdio.h>
#include <stdlib.h>
int **alocar_matriz(int linha, int coluna){ //funcao que aloca um matriz
	int **novaM;
	if(linha>0&&coluna>0){ // valida as linhas e colunas
		   novaM = (int**)malloc(linha*sizeof(int)); //aloca as linhas
		   if(novaM==NULL){
			   printf("memoria insuficiente\n");
			   return NULL;
		   }
		   for(int i=0;i<linha;i++){ 
			   novaM[i] = (int*)malloc(coluna*sizeof(int)); //aloca as colunas
			   if(novaM==NULL){
				   printf("memoria insuficiente\n");
				   return NULL;
			   }
		   }
		   
	}else{
		printf("indices nao validos\n");
		exit(1);
	}
	return (novaM); //retorna a matriz alocada
}
void preenche(int **matriz, int linha, int coluna){ //funcao que preenche a matriz automaticamente
	for(int i=0;i<linha;i++){
		for(int j=0;j<coluna;j++){
			matriz[i][j] = 1;
		}
	}
}

int **adicao(int **matriz1, int **matriz2, int linha, int coluna){ //funcao que faz as operacoes de adicao
	int **matriz3;
	matriz3 = alocar_matriz(linha, coluna); //aloca a matriz para receber as somas
	
	for(int i=0;i<linha;i++){
		for(int j=0;j<coluna;j++){
			matriz3[i][j] = (matriz1[i][j])+(matriz2[i][j]); //recebe as somas
		}
	}
	return matriz3; //retorna a matriz aloca e preenchida
}
int **subtracao(int **matriz1, int **matriz2, int linha, int coluna){ // funcao que faz a operacao de subtracao
	int **matriz3;
	matriz3 = alocar_matriz(linha, coluna); //aloca a matriz que vai receber os valores
	
	for(int i=0;i<linha;i++){
		for(int j=0;j<coluna;j++){
			matriz3[i][j] = (matriz1[i][j])-(matriz2[i][j]); //recebe a subtracao
		}
	}
	
	return matriz3;
}
int **multiplicacao(int **matriz1, int **matriz2, int linha1, int coluna1, int linha2, int coluna2){
	int **matriz3;
	matriz3 = alocar_matriz(linha1, coluna2); //aloca a matriz que vai receber os valores
	
	int soma=0, j,i,k;
	//linha1 e coluna2
	for(i=0;i<linha1;i++){
		for( j=0;j<coluna2;j++){
			for(k=0;k<linha2;k++){
				soma += matriz1[i][k]*matriz2[k][j]; //soma os valores da multiplicacao de linhas por colunas
			}
			matriz3[i][j] = soma; //a posicao de matriz3 recebe a soma desses valores
			soma=0;
		}
	}
	
	return matriz3;
}
int **liberar_matriz (int **matriz, int linha, int coluna) { //funcao de liberar matrizes
	int i;
	if (matriz == NULL)
		return (NULL);
	if (linha < 1 || coluna < 1) {
		printf ("dimencoes invalidas\n"); \
		return (matriz);
	}
	for (i=0; i<linha; i++)
		 free (matriz[i]); 
	free(matriz); 
	return (NULL); 
}
int main(){
	int l1, c1, l2, c2, controle=1;
	
	printf("linhas da matriz 1: ");
	scanf("%d",&l1);
	
	printf("colunas da matriz 1: ");
	scanf("%d",&c1);
	
	int **matriz1;
	matriz1 = alocar_matriz(l1, c1);
	
	printf("deseja preecher manualmente ou automaticamente a matriz 1? \n");
	printf("1 - manualmente\n2 - automaticamente");
	int d;
	scanf("%d",&d);
	
	
	if(d==1){ //preenche manualmente
		for(int i=0;i<l1;i++){
			for(int j=0;j<c1;j++){
				printf("linha %d, coluna %d: \n",i,j);
				scanf("%d", &matriz1[i][j]);
			}
			printf("\n");
		}
	}else if(d==2){
		for(int i=0;i<l1;i++){
			for(int j=0;j<c1;j++){
				matriz1[i][j] = 1;
			}
		}
	}
	
	printf("linhas da matriz 2: ");
	scanf("%d",&l2);
	
	printf("colunas da matriz 2: ");
	scanf("%d",&c2);
	
	int **matriz2;
	matriz2 = alocar_matriz(l2,c2);
	
	printf("deseja preecher manualmente ou automaticamente a matriz 2? \n");
	printf("1 - manualmente\n2 - automaticamente");
	scanf("%d",&d);
	if(d==1){ //preenche manualmente
		for(int i=0;i<l2;i++){
			printf("linha %d : ",i);
			for(int j=0;j<c2;j++){
				printf("linha %d, coluna %d\n: ",i,j);
				scanf("%d", &matriz2[i][j]);
			}
			printf("\n");
		}
	}else if(d==2){
		for(int i=0;i<l2;i++){
			for(int j=0;j<c2;j++){
				matriz2[i][j] = 1;
			}
		}
	}
	
	
	int **matriz3;
	
	while(controle>0){
		printf("1- para soma\n");
		printf("2 - para subtracao\n");
		printf("3 - para multiplicacao\n");
		printf("-1 - para sair\n");
		scanf("%d",&controle);
	
		
		if(controle==1){ //verifica se escolheu a soma
			if(l1==l2&&c1==c2){
				printf("soma\n");
				printf("matriz 3: \n");
				matriz3 = adicao(matriz1, matriz2,l1,c1);
				for(int i=0;i<l1;i++){
					for(int j=0;j<c1;j++){
						printf(" %d ", matriz3[i][j]);
					}
					printf("\n");
				} 
				matriz3 = liberar_matriz(matriz3, l1,c1); //libera a matriz logo apos ser impressa
			}else{
				printf("soma de matrizes so pode ser feita com dimencoes iguais\n");
				exit(1);
			}
		}
		else if(controle==2){ //verifica se escolheu a subtracao
				if(l1==l2&&c1==c2){
					printf("subtracao\n");
					printf("matriz 3: \n");
					matriz3 = subtracao(matriz1, matriz2,l1,c1);
					for(int i=0;i<l1;i++){
						for(int j=0;j<c1;j++){
							printf(" %d ", matriz3[i][j]);
						}
						printf("\n");
					}
					matriz3 = liberar_matriz(matriz3, l1,c1); //libera a matriz logo apos ser impressa
				}else{
					printf("sutracao de matrizes so pode ser feita com dimencoes iguais\n");
					exit(1);
				}
		}else if(controle==3){ //verifica se escolheu a multiplicacai
				if(l1==c2){ //verifica se a quantidade de linhas é igual a quantidade de colunas das matrizes 1 e 2
					printf("multiplicacao\n");
					printf("matriz 3: \n");
					matriz3 = multiplicacao(matriz1, matriz2,l1,c1,l2,c2); //chama a funcao que retorna a matriz preenchida
					for(int i=0;i<l1;i++){
						for(int j=0;j<c2;j++){
							printf(" %d ", matriz3[i][j]);
						}
						printf("\n");
					}
						matriz3 = liberar_matriz(matriz3, l1,c2); //libera a matriz logo apos ser impressa
				}else{
					printf("multiplicaca de matrizes so pode ser feita com o numero de linhas da primeira matriz com o numero de colunas da segunda matriz\n");
					exit(1);
				}
		}else if(controle>0){ //se a entrada nao se encaixou nas anteriores, eh solcitada a releitura 
			printf("entrada invalida\n");
		}
	}
	matriz1 = liberar_matriz(matriz1, l1,c1);
	matriz2 = liberar_matriz(matriz2, l2,c2);
	return 0;
}