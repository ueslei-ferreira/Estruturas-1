#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	   char nome[15];
	   int idade;
	   int numeroCamisa;
	   char posicao[20];
	   float altura;	
}volei;
volei *aloca(int tamanho){ //aloca o vetor dos jogadores
	volei *v;
	v = (volei*)malloc(tamanho*sizeof(volei));
	
	return v;
}
void maisAlto(float *ma, volei *jogador, int tamanho){ //*ma eh o ponteiro que aponta para armazenar a maior altura
	*ma=jogador[0].altura; //recebe a primeira posicao de jogadores
	for(int i=1;i<tamanho;i++){
		if(jogador[i].altura>*ma){ //se existir alguem mais alto que o primeiro armazenado, sera feito o armazenamento dele
			*ma=jogador[i].altura; //eh feito o armazenamento 
		}		
	}
}
int idadeBaixo(volei *jogador, int tamanho){
	float menorA = jogador[0].altura;//recebe a primeira posicao de jogadores
	int m=0;//m eh a variavel que armazena a posicao do jogador mais baixo
	for(int i=1;i<tamanho;i++){
		if(jogador[i].altura<menorA){//se existir alguem mais baixo
			menorA = jogador[i].altura;//pega a altura
			m = i;//pega a posicao
		}
	}
	return jogador[m].idade;//retorna a idade
}
float mediaA(volei *jogador, int tamanho,char nomes[][30], int *cont){
	float media;
	float soma=0;
	for(int i=0;i<tamanho;i++){
		soma=soma+jogador[i].altura;//soma todas as alturas
	}
	media = soma/tamanho;//calcula a media de acordo com a soma
	float *vetMediana = (float*)malloc(tamanho*sizeof(float));//aloca um vetor para receber todas as altura e ordenar para fazer a mediana
	for(int i=0;i<tamanho;i++){
		vetMediana[i]=jogador[i].altura;//recebe as alturas da estrutura completa
	}
	
	int i, j;
	float aux;// variavel auxiliar
	for (i = 0; i < (tamanho - 1); i++){//ordena os valores no vetor de alturas
  		for (j = i + 1; j < tamanho; j++){
			if (vetMediana[i] > vetMediana[j]){
        		aux = vetMediana[i];
        		vetMediana[i] = vetMediana[j];
  				vetMediana[j] = aux;
			}
		}
	}
	
	float mediana;
	if(tamanho%2==0){//se tamanho do vetor for par, encontra os dois valores centrais e calcula a mediana
		mediana = (vetMediana[tamanho/2-1]+vetMediana[tamanho/2])/2;
	}else{
		mediana = vetMediana[tamanho/2];//se for impar, pega o valor central
	}
		
	*cont=0;
	int pos_matriz = 0;//conta a posicao da matriz 
	for(int i=0;i<tamanho;i++){
		if(jogador[i].altura==mediana){//verifica se a altura é igual a mediana
			strcpy(nomes[pos_matriz], jogador[i].nome); //Adiciona nomes na matriz
			++pos_matriz;//incrementa a posicao da linha da matriz
		}
	}
	free(vetMediana);//libera o vetor alocado anteriormente
	*cont = pos_matriz;//contador que armazena o numero necessario que a matriz usa, para que use no main

	return media;
}
int main(){
	volei *jogador;
	printf("quantos jogadores deseja inserir?");
	int tamanho;
	scanf("%d",&tamanho);
	
	jogador = aloca(tamanho); //alocacao da memoria de acordo com o tamanho pedido
	
	for(int i=0;i<tamanho;i++){ //insere dados dos jogadores
		printf("nome: ");
		scanf("%s",jogador[i].nome);
		printf("idade: ");
		scanf("%d",&jogador[i].idade);
		printf("numero da camisa: ");
		scanf("%d",&jogador[i].numeroCamisa);
		printf("posicao: ");
		scanf("%s",jogador[i].posicao);
		printf("altura: ");
		scanf("%f",&jogador[i].altura);
		printf("\n");
	}
	float ma; // variavel que recebe a maior altura
	maisAlto(&ma,jogador, tamanho); //verifica o mais alto
	
	printf("maior altura: %.2f\n", ma); //imprime a maior altura
	
	printf("idade do jogador mais baixo: %d\n",idadeBaixo(jogador, tamanho)); //chama a funcao para saber o jogador mais baixo e retorna a idade
	
	int contador = 0; //variavel que sera usada na contagem de jogadores com altura = mediana de altura 

	char nomes[tamanho][30]; //Matriz que vai armazenar o nome dos jogadores na funcao mediaA
	printf("media das alturas: %.2f\n",mediaA(jogador, tamanho, nomes, &contador));

	if(contador>0){
		for(int i=0;i<contador;i++){
				printf("nomes dos jogadores com altura mediana: %s\n", nomes[i]); //impressão do nome dos jogadores com altura = mediana
		}
	}
	free(jogador);
	return 0;
}