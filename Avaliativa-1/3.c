#include <stdio.h>
float media(float n1, float n2, float n3){
	float M = (n1+n2+n3)/3;
	return M;
}
void aprova(float *p){
	if(*p>=7){
		printf("aluno aprovado com media: %.2f",*p);
	}
	else{
		printf("aluno reprovado com media: %.2f",*p);
	}
}
int main(){
	printf("digite as 3 notas do aluno\n");
	float nota1, nota2, nota3;
	scanf("%f",&nota1);
	scanf("%f",&nota2);
	scanf("%f",&nota3);
	float t;
	t=media(nota1, nota2, nota3);
	aprova(&t);
	
	return 0;
}