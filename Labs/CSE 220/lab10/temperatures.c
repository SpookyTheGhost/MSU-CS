#include<stdio.h>

float temperatureAverage();
float lastFiveAverage();
void newTemperature();
void numberofTemperatures();
void printArray();

float temperatures[500]; // set up global array
int arraySize;

int main() {
	arraySize = 0; 
	
	char selection; // choose from menu
	
	printf("MENU\n(A) compute average of all temperatures\n(B) compute average of last five\n(C) add a new temperature\n(D) print number of temperatures recorded\n(E) print the temperatures recorded\n(F) exit\n");

	while (1){
		// get valid selection from menu
		printf("Choose an option: \n");
		scanf(" %c", &selection);

		if (selection == 'A'){
			printf("Total average temperature is %f\n", temperatureAverage());
		}
		
		else if (selection == 'B'){
			printf("Average of last 5 elements is %f\n", lastFiveAverage()); 
		}
			
		else if (selection == 'C'){
			newTemperature();
		}
			
		else if (selection == 'D'){
			numberofTemperatures();
		}
			
		else if (selection == 'E'){
			printArray();
		}
		
		else if (selection == 'F'){
			return 0;
		}
			
		else {
			printf("Invalid input\n");
		}
	}

}

float temperatureAverage() {
	float total = 0.0;
	float average = 0.0;
	
	if (arraySize == 0) { // prevent divide by 0 error
		return average;
	}
	
	// loop through array and add to total
	int i;
	for (i = 0; i < arraySize; i++) {
		total += temperatures[i];
	}
	
	average = (float) total/arraySize; // calculate average
	return average;
}


float lastFiveAverage(){
	if (arraySize < 5) {
		// call total temperature average function
		return temperatureAverage();
	} 
	
	else { // calculate average of past 5 elements
		float total = 0;
		
		// add up last 5 elements
		int i;
		for (i = arraySize - 6; i < arraySize; i++) {
			total += temperatures[i];
		}
		return total/5.0;
	}
}

void newTemperature() {
	// check array size
	if (arraySize < 500) {
		// prompt for a new temperature
		printf("Enter a new temperature\n");
		
		// save new temperature into next index
		scanf("%f", &temperatures[arraySize]); // save value to next index via pointer position increment
		arraySize++; // update global number of elements
	}
	
	else { // error message
		printf("Maximum array size reached, unable to store further values!\n");
	}

}

// prints total temperatures recorded
void numberofTemperatures() {
	printf("Number of temperatures recorded is %d\n", arraySize);
}

// print array
void printArray() {
	int i;
	// loop through and print the array elements
	for (i = 0; i < arraySize; i++) {
		printf("%f, \n", temperatures[i]);
	}
}

