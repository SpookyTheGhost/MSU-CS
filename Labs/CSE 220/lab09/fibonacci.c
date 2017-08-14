#include<stdio.h>
 
int fibonacci(int n) {
    if (n == 0 || n == 1) { // check base cases
        return n;
    }
    return (fibonacci(n-1) + fibonacci(n-2)); // calculate fibonacci
}
 
 
int main() {
	int num = 0; // set temp
	printf("Enter the nth fibonacci number to print: ");
	scanf("%d",&num);
	printf("The %d fibonacci number is %d\n",num,fibonacci(num));
	return 0;
}
 
