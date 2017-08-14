#include<stdio.h>
 
int main() {
	char selection, character, answer = 'y';
	int number = 0;
	while (answer == 'y') {

		printf("MENU\n\
		A: output ASCII Code\n\
		B: output character\n");
		printf("Please choose a selection: ");
		scanf(" %c",&selection); // get input from user
		   
		if (selection == 'A'){ // checks for selection A
			printf("Please enter a character: ");
			scanf(" %c",&character);
			printf("%d\n",character); // simply prints ascii value
		}
		else if (selection == 'B'){ // checks for selection B
			printf("Please enter an integer: ");
			scanf("%d",&number);
			printf("%c\n",number);
		}
		else { // invalid selection
			printf("Invalid Entry!\n");
		}
		   
		printf("Do you want to try another conversion (y/n)? ");
		scanf(" %c",&answer); // get input from user, yes/no
		if (answer != 'y'){
			return 0;		
		}
	}
}
