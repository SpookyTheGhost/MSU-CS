#include<stdio.h> 

int main() { 
	char ch = 'A'; 
	int a2 = ch*2; 
	int a3 = 3; 
	a3 *= ch + 5; 
	char ch2 = ch + 5;  
	int x = sizeof(ch); 
	printf("%d %c %c %d %d %d\n", ch, ch, ch2, a2, a3, x); 

    return 0; 
}

