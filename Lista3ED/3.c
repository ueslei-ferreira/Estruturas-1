#include <stdio.h>
#include <stdlib.h>
typedef struct{
	   char nome[81];
	   char matricula[8];
	   char turma;
	   float p1;
	   float p2;
	   float p3;
}Aluno;

void inicializa(Aluno **turma, int tamanho){
	
	for(int i=0;i<tamanho;i++){//inicializa a struct para indicar que pode ser usada
		turma[i]=NULL;
	}
}

void preenche(Aluno **turma, int tamanho, int indice){ //funcao que preenche a struct da turma
	
	if(indice<0||indice>tamanho){//verifica se o indice esta dentro da margem de preenchimento
		printf("indice fora do escopo\n");
		exit(1);
	}
	if(turma[indice]==NULL){ //preenche os dados do aluno
		turma[indice] = (Aluno*)malloc(sizeof(Aluno));
		printf("digite o nome: ");
		scanf(" %s",turma[indice]->nome);
		printf("digite a matricula: ");
		scanf(" %s",turma[indice]->matricula);
		printf("digite a turma: ");
		fflush(stdin);
		scanf(" %c",&turma[indice]->turma);
		
		printf("digite a primeira nota: ");
		scanf("%f",&turma[indice]->p1);
		printf("digite a segunda nota: ");
		scanf("%f",&turma[indice]->p2);
		printf("digite a terceira nota: ");
		scanf("%f",&turma[indice]->p3);
		printf("\n");
	}
}
void imprimeAprovados(int tamanho, Aluno **turmas){
	float soma=0, media; //variaveis para calculo da media
	
	for(int i=0;i<tamanho;i++){
		soma+= turmas[i]->p1 + turmas[i]->p2 + turmas[i]->p3; //soma das 3 notas
		
		media = soma/3; //calculo da media
		
		if(media>=7){ //impressao dos dados dos alunos aprovados
			
			printf("aluno %s aprovado\n", turmas[i]->nome);
			printf("numero da matricula: %s\n",turmas[i]->matricula);
			printf("turma: %c\n",turmas[i]->turma);
			printf("aprovado com media %.2f\n", media);
			printf("\n");	
			
		}
		soma=0; // zera o valor da soma para nao pegar as notas anteriores
	}
	
}

float media_turma(int tamanho, Aluno **turmas, char turma){
	float soma=0, media, mediaTotal, somaMedia=0;
	int cont=0;
	for(int i=0;i<tamanho;i++){
		if(turmas[i]->turma==turma&&turmas[i]!=NULL){
			soma+= turmas[i]->p1 + turmas[i]->p2 + turmas[i]->p3; //soma as tres notas de cada aluno da turma
			
			media = soma/3; //faz a media da soma das notas
			
			somaMedia+=media; //soma todas as medias da turma
			
			cont+=1; // conta quantos alunos existem na turma, para calcular a media
		}
		soma=0; // zera o valor da soma para nao pegar as notas anteriores
	}
	if(cont==0){
		return -1;
	}
	
	mediaTotal=somaMedia/cont; //divide a soma das media pela quantidade de alunos na turma
	
	return mediaTotal; //retorna a media da turma
}

int main(){
	printf("quantos alunos deseja inserir? ");
	
	int tamanho;
	
	scanf("%d",&tamanho); // pede a quantidade de alunos a serem inseridos
	
	while(tamanho<=0){
		printf("tamanho invalido, insira corretamente\n");
		scanf("%d",&tamanho);
	}
	
	Aluno **turma; //cria o ponteiro de ponteiro
	
	turma = (Aluno**)malloc(tamanho * sizeof(Aluno)); // aloca a struct dos alunos
	
	inicializa(turma, tamanho); //funcao que inicializa a struct com NULL
	
	for(int i = 0; i < tamanho; ++i){
		preenche(turma, tamanho, i); //chamada da funcao que preenche aluno por aluno
	}
	
	imprimeAprovados(tamanho, turma); //chamada da funcao que imprime os aprovados
	
	printf("digite a turma que deseja calcular a media\n");
	char turmA;
	fflush(stdin);
	scanf("%c",&turmA); //pede a insercao da turma a ser buscada
	float media = media_turma(tamanho, turma, turmA);
	if (media>=0){
		printf("media da turma '%c': %.2f",turmA,media); //chama a funcao da media de turma e imprime seu retorno
	}else{
		printf("turma nao encontrada\n");
	}
	
	for(int i=0;i<tamanho;i++){
		free(turma[i]);
	}
	
	free(turma);
	return 0;
}