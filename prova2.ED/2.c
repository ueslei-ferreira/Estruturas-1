#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int codigo;
	char titulo[30];
	char autor[30];
	char editora[30];
	char ano_edicao[30];
	int exemplares;
}Livros;
void inicializa(Livros **livro, int tamanho){
	for(int i=0;i<tamanho;i++){
		livro[i] = NULL;
	}
}
void preenche(Livros **livro, int i){
	if(livro[i]==NULL){ //se a posicao estiver livre
		livro[i] = (Livros*)malloc(sizeof(Livros)); //aloca um ponteiro na posicao
		int codigo; //codigo a ser inserido
		printf("codigo do livro: \n");
		scanf("%d", &codigo);
		if(codigo >=0){ //verifica se o codigo é maior ou igual a zero
			livro[i]->codigo = codigo; //insere o codigo lido se ele for valido
			
			printf("titulo do livro: "); //insere o resto dos dados
			scanf(" %[^\n]s", livro[i]->titulo);
			
			printf("autor: ");
			scanf(" %[^\n]s",livro[i]->autor);
			
			printf("editora: ");
			scanf(" %[^\n]s", livro[i]->editora);
			
			printf("ano da edicao: ");
			scanf(" %[^\n]s", livro[i]->ano_edicao);
			
			printf("quantidade de exemplares: ");
			scanf("%d", &livro[i]->exemplares);
		}else{
			printf("insercao cancelada\n");
		}
	}
}
void imprime(Livros **livro, int i){ //imprime os dados de determinado livro
	if(livro[i]!=NULL){ //se a posicao nao estiver vazia, imprime os dados
		printf("codigo do livro: %d\n", livro[i]->codigo);
				
		printf("titulo do livro: %s\n", livro[i]->titulo);
				
		printf("autor: %s\n",livro[i]->autor);
				
		printf("editora: %s\n", livro[i]->editora);
				
		printf("ano da edicao: %s\n", livro[i]->ano_edicao);
				
		printf("quantidade de exemplares: %d\n", livro[i]->exemplares);
		printf("\n");
	}
}
void pesquisa_autor(Livros **livro, int tamanho){ //pesquisa livros de acordo com o autor
	char autor[40];
	int cont=0;
	printf("digite o autor: ");
	scanf(" %[^\n]s", autor); // insere o autor
	
	for(int i=0; i<tamanho;i++){
		if( strcmp( autor, livro[i]->autor ) == 0){ //se o autor inserido for igual ao autor do livro na posicao [i], imprime os dados do livro
			imprime(livro, i);
			cont++; //variavel usada para saber se a condicao foi econtrada ao menos uma vez
		}
	}
	if(cont==0){ //controle para verificar se o autor nao foi encontrado
		printf("nao existem livros escritos por esse autor\n");
	}
}
void pesquisa_editora(Livros **livro, int tamanho){ //pesquisa livros de acordo com a editora
	char editora[40];
	int cont=0;
	
	printf("digite a editora a pesquisar: ");
	scanf(" %[^\n]s", editora);// insere a editora
	
	for(int i=0; i<tamanho;i++){
		if( strcmp( editora , livro[i]->editora ) == 0){ //se a editora inserida for igual a editora do livro na posicao [i], imprime os dados do livro
			imprime(livro, i);
			cont++; //variavel usada para saber se a condicao foi econtrada ao menos uma vez
		}
	}
	if(cont==0){ //controle para verificar se a editora nao foi encontrada
		printf("nao existem livros publicados por essa editora\n");
	}
}
void remove(Livros **livro, int tamanho){ //funcao que remove determinado livro
	int codigo;
	char nome[40], autor[40];
	printf("digite o codigo do livro que deseja remover\n"); //pede alguns dados do livro
	scanf("%d", &codigo);
	
	printf("digite o nome do livro que deseja remover\n");
	scanf(" %[^\n]s", nome);
	
	printf("digite o autor do livro que deseja remover\n");
	scanf(" %[^\n]s", autor); 
	
	for(int i=0;i<tamanho;i++){
		if( strcmp(nome, livro[i]->titulo) ==0 && strcmp(autor, livro[i]->autor) == 0 && codigo == livro[i]->codigo){ //verifica se todos os dados solicitados coincidem com algum livro
			
			free(livro[i]); //libera a memoria alocada de determinado livro
			printf("livro removido\n");
		}
	}
}
int main(){
	Livros **livro;
	
	printf("quantos livros deseja inserir\n?");
	int tamanho;
	scanf("%d", &tamanho); //tamanho usado na alocacao
	
	livro = (Livros**)malloc(tamanho*sizeof(Livros)); //aloca o ponteiro para ponteiro
	
	inicializa(livro, tamanho); //inicializa NULL em todas as posicoes
	
	int i=0, conta_livros=0, opcao=1; // "conta_livros" serve para saber se ja tem algum livro cadastrado
	system("cls"); 
	
	printf("se o 'codigo' for menor que '0' a insercao sera cancelada\n");
	while(i<tamanho){ //insere quantos livros o usuario quiser, mesmo que seja menor que a alocacao
		preenche(livro, i); //preenche a posicao 
		printf("\n");
		i++;
		conta_livros++;
	}
	
	while (opcao>0){
		printf(" 1 - para pesquisar livros de acordo com o autor\n");
		printf(" 2 - para pesquisar livros de acordo com a editora\n");
		printf(" 3 - para remover um livro\n");
		printf(": ");
		scanf("%d", &opcao);//pede a opcao desejada
		system("cls");
		
		if(opcao==1){ 
			
			pesquisa_autor(livro, conta_livros);
			
		}else if(opcao==2){
			
			pesquisa_editora(livro, conta_livros);
			
		}else if(opcao==3){
			
			remove(livro, conta_livros);
			
		}
		printf("\n");
		
	}
	
	for(int i=0;i<tamanho;i++){ //libera cada posicao
		free(livro[i]);
	}
	free(livro); //libera o ponteiro para ponteiro
	return 0;
}