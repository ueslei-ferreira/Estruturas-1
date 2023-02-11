#include <stdio.h>
void primo(int m, int *p1, int *p2){
	int cont=0,i;
	for(i=2;i<m;i++){
		cont=0;
		for(int j=1;j<=i;j++){
			if(i%j==0){
				cont++;
			}
		}
		if(cont==2){
			*p1=i;
		}
	}
	cont=0;
	while(cont!=2){
		i++;
		cont=0;
		for(int j=1;j<=i;j++){
			if(i%j==0){
				cont++;
			}
		}
		if(cont==2){
			*p2=i;
		}
	}
	
}
int main(){
	int m, p1, p2;
	printf("digite M: ");
	scanf("%d",&m);
	primo(m, &p1, &p2);
	printf("p1: %d\np2: %d",p1,p2);
	return 0;
}