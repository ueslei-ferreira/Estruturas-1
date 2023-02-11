#include <stdio.h>
int contar(char s){
	char vogal[6]={"aeiou"};
	int cont=1;
		for(int j=0;vogal[j]!='\0';j++){
			if(s==vogal[j]){
				return cont;	
			}		
		}
	return 0;	
}
void vogais(char s1[], char s2[], char *s3){
	int controle=0,controle2=0, i=0, k=0;
	while(controle!=1&&controle2!=1){
		if(s1[i]!='\0'){
			if(contar(s1[i])==1){
				*s3=s1[i];
				s3++;
			}
			i++;
		}else{
			controle=1;
		}
		if(s2[k]!='\0'){
			if(contar(s2[k])==1){
				*s3=s2[k];
				s3++;
			}
			k++;
		}else{
			controle2=1;
		}
	}
}
int main(){
	   char s1[10], s2[10], s3[11];
	   printf("primeira string: ");
	   scanf("%s",s1);
	   
	   printf("segunda string: ");
	   scanf("%s",s2);
	   
	   vogais(s1, s2, s3);
	   printf("%s",s3);
	return 0;
}