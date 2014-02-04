#include<stdlib.h>
#include<time.h>
#include<stdlib.h>

void random(){
	srand(time(NULL));
	
	int i = 0;
	int number[50];
	int count = 0;
	int temp =  0;
	
	printf("\n");
	printf("============================\n");


	while(count<=6){
		temp = rand() % 49 + 1;
		if (number[temp] != 1){
			printf("%d\n", temp);
			number[temp] = 1;
			count++;
		}else{
			continue;
		}
	}	

	printf("============================\n");

	return 0;		
}

int main(){
	int i = 0;

	for(i = 0; i < 100; i++){
		random();
	}

	return 0;

}
