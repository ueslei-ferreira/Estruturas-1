#include <stdio.h>
int imprimir_r(int k){
	if(k==0){
		return k;
	}
	else{
		return k+imprimir_r(k-1);
	}
}
int main(){
	int k;
	scanf("%i",&k);
	printf("%d",imprimir_r(k));
	return 0;
}