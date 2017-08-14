#include <stdio.h>
#include <string.h>

int isPalindrome(char *str);
int isPalindromeFlexible(char *str);
void PalinPrint(char *str);
void PalinFlexPrint(char *str);

int main() {	
	char *s1 = "Ott   o" ;
	char *s2 = "tacocat";
	char *s3 = "123 3 2 1";
	char *s4 = "A Santa lived as a devil at NASA";
	char *s5 = "anna_bob";
	char *s6 = " C";
	char *s7 = " C ";

	printf("\tString\t\t\t\t|" "\tisPalindrome\t\t|" "\tisPalindromeFlexible\n");
	printf("-----------------------------------------------------------------------------------------------------------\n");
	printf("Ott   o\t\t\t\t\t");
	PalinPrint(s1);
	PalinFlexPrint(s1);
	printf("tacocat\t\t\t\t\t");
	PalinPrint(s2);
	PalinFlexPrint(s2);
	printf("123 3 2 1\t\t\t\t");
	PalinPrint(s3);
	PalinFlexPrint(s3);
	printf("A Santa lived as a devil at NASA \t"); 
	PalinPrint(s4);
	PalinFlexPrint(s4);
	printf("anna_bob\t\t\t\t");
	PalinPrint(s5);
	PalinFlexPrint(s5);
	printf(" C\t\t\t\t\t"); 
	PalinPrint(s6);
	PalinFlexPrint(s6);
	printf(" C \t\t\t\t\t");
	PalinPrint(s7);
	PalinFlexPrint(s7);

}

void PalinPrint(char *str) { // prints yes or no based on palindrome result
		if (isPalindrome(str) == 1) {
			printf("|\tYES\t\t\t");
		}

		else {
			printf("|\tNO\t\t\t");	
		} 
}

void PalinFlexPrint(char *str) { // prints yes or no based on flexible palindrome result
		if (isPalindromeFlexible(str) == 1) {
			printf("|\t\tYES\t\n");
		}

		else {
			printf("|\t\tNO\t\n");	
		} 
}

int isPalindrome(char *str){
	// find end of actual string, remove null character
	int end = strlen(str) - 1; 
	int i, j;
	//loop and check each character for equality
	for (i = 0, j = end; i < j; i++, j--) {
		if (str[i] != str[j]) {
			return 0; // not same
		}
	}
	return 1; // same
}

int isPalindromeFlexible(char *str){
	int end = strlen(str) - 1; // find end of actual string, remove null character
	int i, j;
	//loop and check each character for equality
	for (i = 0, j = end; i < j; i++, j--) {
		
		while( isspace(str[i]) ){
			i++;
		}

		while( isspace(str[j]) ){
			j--;
		}

		//need to remove spaces & check numbers
		if ( toupper(str[i]) != toupper(str[j]) ) {
			return 0; // not same
		}
	}
	
	return 1; // same	
}
