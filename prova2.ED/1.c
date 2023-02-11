#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct{
	char nome_curso[15];
	int codigo_curso;
	int qt_per;
	float carga_horaria_total;
	char turno[10];
	
}Curso;
typedef struct{
	char nome_disc[20];
	int codigo_disc;
	int codigo_cursoD;
	int periodo;
	float carga_horaria;
}Disciplina;

void inicializa_curso(Curso **curso, int tamanho){ //inicializa o ponteiro para ponteiros
	for(int i=0;i<tamanho;i++){
		curso[i] = NULL; //todas as posicoes recebem nulo
	}
}

void inicializa_disciplina(Disciplina **disciplina, int tamanho){
	for(int i=0;i<tamanho;i++){
		disciplina[i] = NULL; //todas as posicoes recebem nulo
	}
}

int busca_binaria_recursiva(Curso **vet, int inicio, int fim, int item){
	int posicao = (inicio+fim)/2; //posicao a ser testada 
	if(inicio>fim){ //item nao foi encontrado
		return -1;
	}
	if(vet[posicao]->codigo_curso==item){ //item foi encontrado
		return posicao;
	}
	if(vet[posicao]->codigo_curso<item){ //item esta¡ para a direita do vetor
		return busca_binaria_recursiva(vet, posicao+1, fim, item); 
	}
	else{	//item esta para a esquerda do vetor
		return busca_binaria_recursiva(vet, inicio, posicao-1, item);	
	}
}

int busca_binaria_disc(Disciplina **vet, int inicio, int fim, int item){
	int posicao = (inicio+fim)/2; //posicao a ser testada 
	if(inicio>fim){ //item nao foi encontrado
		return -1;
	}
	if(vet[posicao]->codigo_disc==item){ //item foi encontrado
		return posicao;
	}
	if(vet[posicao]->codigo_disc<item){ //item esta¡ para a direita do vetor
		return busca_binaria_disc(vet, posicao+1, fim, item); 
	}
	else{	//item esta para a esquerda do vetor
		return busca_binaria_disc(vet, inicio, posicao-1, item);	
	}
}

void cadastra_curso(Curso **curso, int i){ //cadastra um curso por vez
	int controle=0, aux;
	if(curso[i]==NULL){ //se a posicao estiver vazia, podem ser inseridos os atributos 
		
		curso[i] = (Curso*)malloc(sizeof(Curso)); //aloca cada posicao do ponteiro para ponteiros
	
		printf("codigo do curso: ");
		scanf("%d",&aux); //usa uma varivel auxiliar para receber o codigo a ser inserido, pois se inserir diretamente, ja vai constar na estrutura antes de realizar a busca
		
		while(controle==0){
			if(busca_binaria_recursiva(curso, 0, i, aux)>=0){ // realiza a busca
				printf("ja existe um curso cadastrado com este codigo, tente novamente: ");
				scanf("%d",&aux);
			}else{
				controle=1;
				curso[i]->codigo_curso = aux; //atribui o codigo quando ele for valido
			}
		}	
	
		printf("nome do curso: ");
		scanf("%s",curso[i]->nome_curso);
		
		printf("quantidade de periodos: ");
		scanf("%d",&curso[i]->qt_per);
		
		printf("carga horaria total: ");
		scanf("%f",&curso[i]->carga_horaria_total);
		
		printf("turno: ");
		scanf("%s", curso[i]->turno);
	}
}

void busca_curso(Curso **curso, int tamanho, int item){ //funcao que busca o codigo do curso e imprime
	int recebe = busca_binaria_recursiva(curso, 0, tamanho-1, item); // a variavel recebe o retorno da busca binaria
	if(recebe>=0&&curso[recebe]!=NULL){ //pega a posicao, se for menor que 0, significa que nao foi encontrado
		printf("nome do curso: %s\n", curso[recebe]->nome_curso);
		printf("codigo do curso: %d\n", curso[recebe]->codigo_curso);
		printf("quantidade de periodos: %d\n", curso[recebe]->qt_per);
		printf("carga horaria total: %.2f\n", curso[recebe]->carga_horaria_total);
		printf("turno: %s\n", curso[recebe]->turno);
		printf("\n");
	}else{
		printf("curso nao encontrado\n");
	}
}
void troca_curso(Curso **curso, int p1, int p2){ //funcao usada para troca de cursos na ordenacao

	strcpy(curso[p1]->nome_curso, curso[p2]->nome_curso);
	curso[p1]->codigo_curso = curso[p2]->codigo_curso;
	curso[p1]->qt_per = curso[p1]->qt_per;
	curso[p1]->carga_horaria_total = curso[p2]->carga_horaria_total;
	strcpy(curso[p1]->turno, curso[p2]->turno);
	
}
void troca_disciplina(Disciplina **disciplina, int p1, int p2){ //funcao usada para troca de disciplinas na ordenacao
	
	strcpy(disciplina[p1]->nome_disc, disciplina[p2]->nome_disc);
	disciplina[p1]->codigo_disc = disciplina[p2]->codigo_disc;
	disciplina[p1]->codigo_cursoD = disciplina[p2]->codigo_cursoD;
	disciplina[p1]->periodo = disciplina[p2]->periodo;
	disciplina[p1]->carga_horaria = disciplina[p2]->carga_horaria;
	
}
void ordena_curso(Curso **curso, int tamanho){
	int i, j;
  	Curso aux; //estrutura auxiliar que recebe os valores dos cursos para n perder valores durante a troca
	for(i = 1; i < tamanho; i++){
		
		aux.codigo_curso = curso[i]->codigo_curso;
		strcpy(aux.nome_curso, curso[i]->nome_curso);
		aux.qt_per = curso[i]->qt_per;
		aux.carga_horaria_total = curso[i]->carga_horaria_total;
		strcpy(aux.turno, curso[i]->turno);
		
		for(j = i; j>0 && (aux.codigo_curso<curso[j-1]->codigo_curso); j--){
			troca_curso(curso, j, j-1);
		}
		curso[j]->codigo_curso = aux.codigo_curso;
		curso[j]->qt_per = aux.qt_per;
		curso[j]->carga_horaria_total = aux.carga_horaria_total;
		strcpy(curso[j]->turno, aux.turno);
		strcpy(curso[j]->nome_curso, aux.nome_curso);
		
	}
}
void ordena_disciplina(Disciplina **disciplina, int tamanho){ 
	int i, j;
  	Disciplina aux; //estrutura auxiliar que recebe os valores das disciplinas para n perder valores durante a troca
	for(i = 1; i < tamanho; i++){
		
		aux.codigo_disc = disciplina[i]->codigo_disc;
		strcpy(aux.nome_disc, disciplina[i]->nome_disc);
		aux.codigo_cursoD = disciplina[i]->codigo_cursoD;
		aux.periodo = disciplina[i]->periodo;
		aux.carga_horaria = disciplina[i]->carga_horaria;
		
		for(j = i; j>0 && (aux.codigo_disc<disciplina[j-1]->codigo_disc); j--){
			troca_disciplina(disciplina, j, j-1);
		}
		disciplina[j]->codigo_disc = aux.codigo_disc;
		strcpy(disciplina[j]->nome_disc, aux.nome_disc);
		disciplina[j]->codigo_cursoD = aux.codigo_cursoD;
		disciplina[j]->periodo = aux.periodo;
		disciplina[j]->carga_horaria = aux.carga_horaria;
		
	}
}

void busca_turno(Curso **curso, int tamanho, char turno[]){ //busca os cursos pelo turno inserido
	int cont=0;
	for(int i=0;i<tamanho;i++){ //imprime todos os cursos com o turno inserido
		if(strcmp(turno, curso[i]->turno)==0&&curso[i]!=NULL){ 
			cont++;
			printf("nome do curso: %s\n", curso[i]->nome_curso);
			printf("codigo do curso: %d\n", curso[i]->codigo_curso);
			printf("quantidade de periodos: %d\n", curso[i]->qt_per);
			printf("carga horaria total: %.2f\n", curso[i]->carga_horaria_total);
			printf("turno: %s\n", curso[i]->turno);
			printf("\n");
		}
	}
	if(cont==0){
		printf("nenhum curso encontrado nesse turno\n");
	}
}

void cadastra_disciplina(Disciplina **disciplina, Curso **curso, int tamanhoC,int i){
	int codigo, periodo, recebe; //codigo serve para ser lido e comparado ao inves de ler diretamente na estrutura disciplinas, periodo serve para ler o codigo ate que seja aceito
	float ch;
	if(disciplina[i]==NULL){ //se a posicao estiver livre, ele preenchera
		
		printf("codigo do curso que deseja cadastrar a disciplina: ");
		
		scanf("%d", &codigo);
		recebe = busca_binaria_recursiva(curso, 0, tamanhoC-1, codigo); //variavel recebe o valor retornado de busca binaria
		
		if(recebe>=0){ //se o codigo foi encontrado, eh pedida a insercao da disciplina
			disciplina[i] = (Disciplina*)malloc(sizeof(Disciplina));
		
			disciplina[i]->codigo_cursoD = codigo;	
		
			printf("codigo da disciplina: ");
			scanf("%d", &disciplina[i]->codigo_disc);
			
			printf("nome da disciplina: ");
			scanf("%s", disciplina[i]->nome_disc);
			
			printf("periodo da disciplina: ");
			scanf("%d", &periodo);
			
			while(periodo < 0 || periodo > curso[recebe]->qt_per){ //verifica se o periodo se encontra valido no curso, e obriga a inserir um valor valido
				printf("periodo invalido, digite novamente: ");
				scanf("%d", &periodo);
			}
			
			disciplina[i]->periodo = periodo;
			
			printf("carga horaria da disciplina: ");
			scanf("%f", &ch);
			while(fmod(ch, 15.0)!=0){
				printf("valor de carga horaria deve ser multiplo de 15, tente novamente: ");
				scanf("%f", &ch);
			}
			disciplina[i]->carga_horaria = ch;
		}else{
			printf("\ncurso inexistente de acordo com o codigo digitado\n");
		}
		
	}
}
void busca_disc(Disciplina **disciplina, int tamanho, int item){
	int recebe;
	recebe = busca_binaria_disc(disciplina, 0, tamanho-1, item);
	if( recebe>=0 && disciplina[recebe] !=NULL ){
		printf("nome do curso: %s\n", disciplina[recebe]->nome_disc);
		printf("codigo do curso: %d\n", disciplina[recebe]->codigo_cursoD);
		printf("codigo do disciplina: %d\n", disciplina[recebe]->codigo_disc);
		printf("periodo da disciplina: %d\n", disciplina[recebe]->periodo);
		printf("carga horaria: %.2f\n", disciplina[recebe]->carga_horaria);
		printf("\n");
	}else{
		printf("disciplina nao encontrada\n");
	}	

}
void remove_curso(Curso **curso, Disciplina **disciplina, int tamanhoC, int tamanhoD, int codigo_curso){
	int cont=0; //contador usado para saber se existem disciplinas no curso
	for(int i=0;i<tamanhoD;i++){
		if(disciplina[i]->codigo_cursoD==codigo_curso){ //se encontrar alguma disciplina no curso, para o laco de repeticao e informa que n eh possivel remover
			cont=1;
			printf("impossivel remover este curso, ja existem disciplinas cadastradas, ou a disciplina nao existe\n");
			break;
		}
	}
	if(cont==0){ //se nao existem disciplinas, remove o curso pelo codigo
		for(int i=0;i<tamanhoC;i++){
			if(curso[i]->codigo_curso == codigo_curso){
				curso[i] = NULL; //remove
				printf("curso removido\n");
			}
		}
	}
	
}
void remove_disciplina(Disciplina **disciplina, int tamanho, int codigo){
	int recebe;
	recebe = busca_binaria_disc(disciplina, 0, tamanho-1, codigo); //recebe a posicao da disciplina
	if( recebe>=0 && disciplina[recebe]!=NULL ){ //se a posicao da disciplina existir 
		disciplina[recebe] = NULL; //remove
		printf("disciplina removida\n");
	}else{
		printf("disciplina nao removida\n");
	}
}

void disc_periodo(Disciplina **disciplina, Curso **curso, int tamanhoC, int tamanhoD){
	
	int recebe, codigo, per; // variavel "recebe" pega a posicao retornada pela busca, variavel "codigo" pega o codigo a ser pesquisado no curso, variavel "per", le o periodo a ser pesquisado
	printf("digite o codigo do curso");
	scanf("%d", &codigo);
	
	recebe = busca_binaria_recursiva(curso, 0, tamanhoC-1, codigo);
	
	if( recebe>=0 && curso[recebe] != NULL){ //se a posicao de curso existir
		printf("digite o periodo do curso: ");
		scanf("%d", &per);
		
		if(per > 0 && per <= curso[recebe]->qt_per){ //verifica se o periodo eh valido
			for(int i=0;i<tamanhoD;i++){
				if(disciplina[i]->periodo == per){ // se o periodo pesquisado for encontrado na disciplina, sao impressos os dados da disciplina
					printf("nome do curso: %s\n", disciplina[i]->nome_disc);
					printf("codigo do curso: %d\n", disciplina[i]->codigo_cursoD);
					printf("codigo do disciplina: %d\n", disciplina[i]->codigo_disc);
					printf("periodo da disciplina: %d\n", disciplina[i]->periodo);
					printf("carga horaria: %.2f\n", disciplina[i]->carga_horaria);
					printf("\n");
				}
			}
		}else{
			printf("periodo invalido\n");
		}
	}else{
		printf("curso nao encontrado");
	}
	
	
}

int main(){
	//cadastrar, buscar e imprimir cursos e suas disciplinas
	int opcao=0, tamanhoC, tamanhoD, cont_curso=0, codigo1, codigo2, codigo3;
	Curso **curso;
	Disciplina **disciplina;
	while(opcao>=0){
		
		printf("---------------menu de opcoes----------------\n");
		printf("|  1 - para cadastrar curso                 |\n");
		printf("|  2 - para buscar curso por codigo         |\n");
		printf("|  3 - para buscar curso por turno          |\n");
		printf("|  4 - para remover um curso                |\n");
		if(cont_curso>0){
			printf("|  5 - para cadastrar disciplinas           |\n");
			printf("|  6 - para buscar uma disciplina por codigo|\n");
			printf("|  7 - para buscar disciplinas de um periodo|\n");
			printf("|  8 - para remover uma disciplina          |\n");
		}
		printf("|  -1 - para buscar sair                    |\n");
		printf("---------------------------------------------");
		printf("\n");
		
		scanf("%d",&opcao);//le a opcao desejada
			
		system("cls"); //limpa a tela
		
		if(opcao==1){
			printf("quantos cursos deseja cadastrar?\n");
			scanf("%d", &tamanhoC); //tamanho usado na alocacao de cursos
			
			curso = (Curso**)malloc(tamanhoC*sizeof(Curso));
			
			inicializa_curso(curso, tamanhoC); //inicializa todas as posicoes com NULL
			
			for(int i=0;i<tamanhoC;i++){
				cadastra_curso(curso, i); //cadastra cada posicao que estiver vazia
				printf("\n");
				cont_curso++;
			}
			ordena_curso(curso, tamanhoC);
			system("cls");
			
		}else if(opcao==2){
			int item;
			printf("digite o codigo do curso a ser encontrado: ");
			scanf("%d", &item); //item que vai ser pesquisado
			busca_curso(curso, tamanhoC, item); // busca o curso

		}else if(opcao==3){
			char turno[10];
			printf("qual turno? ");
			scanf("%s", turno);
			busca_turno(curso, tamanhoC, turno);

		}else if(opcao==4){
		 	
		 	printf("digite o codigo do curso que deseja remover: ");
		 	scanf("%d", &codigo2);		 	
		 	
		 	remove_curso(curso, disciplina, tamanhoC, tamanhoD, codigo2);
		 	
		}else if(opcao==5&&cont_curso>0){
			printf("quantas disciplinas deseja cadastrar?\n");
			scanf("%d", &tamanhoD); //tamanho usado na alocacao de disciplinas
			
			while(tamanhoD<=0){
				printf("valor invalido, tente novamente\n");
				scanf("%d", &tamanhoD); //tamanho usado na alocacao de cursos
			}
			
			
			disciplina = (Disciplina**)malloc(tamanhoD*sizeof(Disciplina));
		
			inicializa_disciplina(disciplina, tamanhoD);
			
			for(int i=0;i<tamanhoD;i++){
				cadastra_disciplina(disciplina, curso, tamanhoD, i); //cadastra cada posicao que estiver vazia
				printf("\n");
			}
			
			ordena_disciplina(disciplina, tamanhoD); //ordena a disciplina pelo codigo
			system("cls");

		}else if(opcao==6){
			
			printf("busque pelo codigo da disciplina: ");
			scanf("%d",&codigo1);

			busca_disc(disciplina, tamanhoD, codigo1); //busca disciplia pelo codigo
		
		}else if(opcao==7){
			
			disc_periodo(disciplina, curso, tamanhoC, tamanhoD); //busca disciplinas em um periodo
			
		}
		else if(opcao==8){
			
			printf("codigo da disciplina que deseja remover: \n");
			scanf("%d", &codigo3);
			
			remove_disciplina(disciplina, tamanhoD, codigo3); //remove uma disciplina
		}
		else{
			printf("opcao invalida\n");
		}
		
	}
	
	for(int i=0;i<tamanhoC;i++) //parte que libera a memoria alocada
		free(curso[i]);
	free(curso);
	
	for(int i=0;i<tamanhoD;i++) //parte que libera a memoria alocada
		free(disciplina[i]);
	free(disciplina);
	
	return 0;
}