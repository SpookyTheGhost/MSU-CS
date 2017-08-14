#include <stdio.h>

void removeWhite(const char *str1, char *str2); // function prototype
int substring(const char *big, const char *small); // function prototype

int main() {
	char str[10000], removal[10000], str1[10000], str2[10000]; 
	
	printf("Enter in a string\n");
	gets(str);
	printf("Removing white space\n");
	removeWhite(str, removal);
	printf("white space removed: %s\n", removal);
	
	printf("Enter in 2 strings\n");
	gets(str1);
	gets(str2);
	if (substring(str1, str2) == 1) {
		printf("The string '%s' contains the string '%s'\n", str1, str2);
	}
	else {
		printf("The string '%s' does not contain the string '%s'\n", str1, str2);
	}
	return 0;
}

void removeWhite(const char *str1, char *str2) {
    int a, b;
    for (a = 0, b =0; str1[a] != '\0'; a++, b++) {
        if (str1[a] == ' ') { // if space, increment
            a++;
        }
        str2[b] = str1[a]; // save char to second string
    }
    str2[b] = str1[a]; // save null char
}

int substring(const char *big, const char *small) {
	const char *i = big, *j = small;

	while (*i != '\0') {
		while (*i != *j && *j != '\0') { 
			i++; // not equal so increment larger until match
			if (*i == '\0') { // fails to find substring
				return 0;
			}
		}
			
		while (*i == *j && (*i != '\0' && *j != '\0') ) { // match found, start checking
			i++, j++; // increment each index to check
		}
		
		if (*j == '\0') { // substring is found
			return 1;
		}
	}	
}
