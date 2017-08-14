#include<stdio.h> 

int main() { 
// odd numbers only
	int stars = 0; // input number of layers
	

	printf("Please enter the number of stars to pyramid: "); // user input
	scanf("%d", &stars);

	for (int i = 1; i <= stars; i+=2){
		for (int k = 0; k < (stars - i)/2; k++){ // spacing
			printf(" ");
		}
		for (int j = 0; j < i; j++){ // prints stars
			printf("*");		
		}
		printf("\n");

		
	      
	}


    return 0; 
}

