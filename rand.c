#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	

	srand(time(NULL));
	
	while(1){
		printf("%d ",rand() / 100 );

	}
	return 0;
}
