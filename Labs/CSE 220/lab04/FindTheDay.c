#include<stdio.h>


int main() {
	int month = 0;
	int day = 0;
	int year = 0;
	int value = 0;

	printf("Enter your birthdate (mm/dd/yyyy): ");
	scanf("%d/%d/%d",&month,&day,&year);
	
	if ((month < 1) || (month > 12)){ // checks for valid month
		printf("Your month is not valid");
		return 0;
	}
	
	if ((day < 1) || (day > 31)){ // checks for valid day
		printf("Your day is not valid");
		return 0;
	}

    if ((month == 2) && (day > 28)){ // check for feb
		printf("Date not valid");
		return 0;
	}

	if(( (month == 4) || (month == 6) || (month == 9) || (month == 11) ) && (day > 30)){
		printf("Date not valid");
		return 0;
	}
	
	int mc; 
	switch (month){
		case 1: // January so mc is 0
			year--;
			value = (year + year/4 - year/100 + year/400 + 0 + day)%7;
			break; 
		case 2: // February so mc is 3
			year --;
			value = (year + year/4 - year/100 + year/400 + 3 + day)%7;
			break; 
		case 3: // March so mc is 2
			value = (year + year/4 - year/100 + year/400 + 2 + day)%7;
			break;
 		case 4: // April so mc is 5
			value = (year + year/4 - year/100 + year/400 + 5 + day)%7;
			break; 
		case 5: // May so mc is 0
			value = (year + year/4 - year/100 + year/400 + 0 + day)%7;
			break; 
		case 6: // June so mc is 3
			value = (year + year/4 - year/100 + year/400 + 3 + day)%7;
			break; 
		case 7: // July so mc is 5
			value = (year + year/4 - year/100 + year/400 + 5 + day)%7;
			break; 
		case 8: // August so mc is 1
			value = (year + year/4 - year/100 + year/400 + 1 + day)%7;
			break; 
		case 9: // September so mc is 4
			value = (year + year/4 - year/100 + year/400 + 4 + day)%7;
			break; 
		case 10: // October so mc is 6
			value = (year + year/4 - year/100 + year/400 + 6 + day)%7;
			break; 
		case 11: // November so mc is 2
			value = (year + year/4 - year/100 + year/400 + 2 + day)%7;
			break; 
		case 12: // December so mc is 4
			value = (year + year/4 - year/100 + year/400 + 4 + day)%7;
	}

	
	
	switch (value){ // do print statements
		case 0:
			printf("You were born on a Sunday\n");
			break;
		case 1:
			printf("You were born on a Monday\n");
			break;
		case 2:
			printf("You were born on a Tuesday\n");
			break;
		case 3:
			printf("You were born on a Wednesday\n");
			break;
		case 4:
			printf("You were born on a Thursday\n");
			break;
		case 5:
			printf("You were born on a Friday\n");
			break;
		case 6:
			printf("You were born on a Saturday\n");
	}

	return 0;
}


