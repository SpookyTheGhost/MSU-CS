#include <stdio.h>
#include <string.h>

int isPalindrome(char *str);
int isPalindromeFlexible(char *str);

int main() {
	printf("\tString\t\t\t\t|" "\tisPalindrome\t\t|" "\tisPalindromeFlexible\n");
	printf("Ott   o\t\t\t" "\t\t|\t\t%d\t\t|" "\t%d\t\t\n", isPalindrome("Ott   o"), isPalindromeFlexible("Ott   o"));
	printf("tacocat\t\t\t" "\t\t|\t\t%d\t\t|" "\t%d\t\t\n",isPalindrome("tacocat"), isPalindromeFlexible("tacocat"));
	printf("123 3 2 1\t\t\t" "\t|\t\t%d\t\t|" "\t%d\t\t\n",isPalindrome("123 3 2 1"), isPalindromeFlexible("123 3 2 1") );
	printf("A Santa lived as a devil at NASA \t" "|\t\t%d\t\t" "|\t%d\t\t\n", isPalindrome("A Santa lived as a devil at NASA"), isPalindromeFlexible("A Santa lived as a devil at NASA"));
	printf("anna_bob\t\t\t\t" "|\t\t%d\t\t|" "\t%d\t\t\n", isPalindrome("anna_bob"), isPalindromeFlexible("anna_bob"));
	printf(" C\t\t\t\t\t" "|\t\t%d\t\t" "|\t%d\t\t\n", isPalindrome(" C"), isPalindromeFlexible(" C"));
	printf(" C \t\t\t\t\t" "|\t\t%d\t\t" "|\t%d\t\t\n",isPalindrome(" C "), isPalindromeFlexible(" C ") );

}





int isPalindrome(char *str){
	int end = strlen(str) - 1;
	int i, j;
	for (i = 0, j = end; i != j; i++, j--) {
		if (str[i] != str[j]) {
			return 0;
		}
		else {
			return 1;		
		}
	}
}

int isPalindromeFlexible(char *str){
	int end = strlen(str) - 1;
	int i, j;
	for (i = 0, j = end; i != j; i++, j--) {
		if (tolower(str[i]) != tolower(str[j]) && (tolower(str[i]) != ' ' && tolower(str[j]) != ' ')) {
			return 0;
		}
		else {
			return 1;		
		}
	}
}
