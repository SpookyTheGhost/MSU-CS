#include<stdio.h>
int main() {
	double a = 0, b = 0, c = 0, d = 0, result; //1 -6 11 -6 gives roots 1, 2, 3
	
	printf("Please input 4 decimals:"); // user input
	scanf("%lf/%lf/%lf/%lf", &a, &b, &c, &d);
	 
	for (double x = -100.0; x <= 100.0; x += 0.0001){
		result = a*x*x*x + b*x*x + c*x + d;
		if ((result > -0.00001f) && (result < 0.00001f)){
			printf("Root is: %f\n", x);
		}
		
	}
	return 0;
}
