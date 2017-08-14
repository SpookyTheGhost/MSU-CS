#include<stdio.h>
 
int main() {
	int stars = 0; // input number of stars
   
	printf("Please enter the number of stars to pyramid: "); // user input
	scanf("%d", &stars);
 
	for (int i = stars, row = 0; i >= 0; i-=2, row++){ // row figures out how to alternate printing
		for (int k = stars; k > ((stars + i)/2); k--){ // spacing
		printf(" ");
	}
		for (int j = i; j > 0; j--){ // prints stars
			if (row%2 == 0){
			printf("*"); // print * if even row
		}
			else { // print = if odd row
				printf("=");
			}
		}
	printf("\n");
	}
	return 0;
}
