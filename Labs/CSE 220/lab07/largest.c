#include<stdio.h>
 
int main() {
 
	for (short int start = 0, count = 0;;start++, count++) { // 32767 is limit
		if (count == 1000){
			char c;
			printf("Enter any character: ");
			scanf("%c",&c); // basically an interrupt so we can view results
			count = 0; // reset counter
		}
		else if (start < 0){
			return 0;		
		}
		else {
			printf("The current count is %d\n",start);
		}
	}
	return 0;
}
