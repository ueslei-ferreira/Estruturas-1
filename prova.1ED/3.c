#include <stdio.h>
#include <string.h>
int retorna_q(char s1[], char s2[], int *q, int *q2){
	char juntar[20];
	juntar[0]='\0';
	int vogais=0;
	strcat(juntar,s1);
	strcat(juntar,s2);
	for(int i=0;s1[i]!='\0';i++){
		if((s1[i]>64)&&(s1[i]<91)){
			*q+=1;
		}
	}
	for(int i=0;s2[i]!='\0';i++){
		if((s2[i]>64)&&(s2[i]<91)){
			*q2+=1;
		}
	}
	for(int i=0;juntar[i]!='\0';i++){
		if(juntar[i]>64&&juntar[i]<91){
			juntar[i]=juntar[i]+32;
		}
	}
	for(int i=0;juntar[i]!='\0';i++){
		if(juntar[i]==97||juntar[i]==101||juntar[i]==105||juntar[i]==111||juntar[i]==117){
			vogais+=1;
		}
		
	}
	return vogais;
}
int main(){
	char s1[10];
	char s2[10];
	int q=0,q2=0;
	scanf("%s",s1);
	scanf("%s",s2);
	printf("quantidade de vogais: %d\n",retorna_q(s1, s2, &q, &q2));
	printf("quantidade de letras maiusculas s1: %d\nquantidade de letras maiusculas s2: %d\n ",q,q2);
	return 0;
}