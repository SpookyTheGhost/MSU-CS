#include<stdio.h>
 
void integerReversal(int n) {
	int reverse; // set temp value
	
	if (n != 0) {
		reverse = reverse * 10; // sets up correct power when reverseing
		reverse = reverse + (n % 10); // adds up the digits back in correct order
		printf("%d", n % 10);
		integerReversal(n/10); // iterates to get actual digit
	}
}

int main() {
	int num = 0;

	// get user input
	printf("Enter a number to reverse: \n");
	scanf("%d", &num);

	integerReversal(num); // call function

    return 0;
}
