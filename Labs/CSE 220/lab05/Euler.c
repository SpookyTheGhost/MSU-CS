#include<stdio.h> 

int main() { 
    int n = 0;
    double factorial = 1.0;
    double euler = 1.0;
    printf("Please enter the value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        factorial *= i; // calculates each iteration of factorial
        euler += (1.0/factorial); // adds inverse of each factorial to euler
        
    }
    printf("%.20lf\n",euler);

    return 0; 
}


