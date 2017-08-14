#include<stdio.h>
 
// find largest element of array
int Largest(int array[], int size, int pos) {
	int temp = array[pos]; // set temporary variable
	int tempPos = pos; // set temporary variable
   
	for (int idx = pos; idx < size; idx++) { // loop to find largest
		if (array[idx] > temp) {
			temp = array[idx]; // set temp to largest
			tempPos = idx; // set temp to index
		}
	}
	return tempPos;
}
 
// swapping positions of array
int swap(int array[], int pos1, int pos2) {
	int temp = array[pos1]; // saves pos1's value
	array[pos1] = array[pos2];
	array[pos2] = temp;
}
 
// print an array
void printArray (int arr[], int size) {
	for (int index = 0; index < size; index++) {
		printf("%d, ", arr[index]);
	}
}
 
int main() {
	int NumOfElements = 0;
 
	do { // reprompts until proper array size is given
		printf("Enter an integer between 2 and 15: \n");
		scanf("%d", &NumOfElements);
	} while( (NumOfElements < 2) || (NumOfElements > 15) );
 
	int sorting[NumOfElements]; // declare an array of user input size
   
	// save integers into array
	for (int element = 0; element < NumOfElements; element++) {
		printf("Input a number:");
		scanf("%d", &sorting[element]);
	}

	//Print unsorted array before sorting
	printArray (sorting, NumOfElements);
	printf("\n");

	// loop to call swap function
	for (int idx = 0; idx < NumOfElements; idx++) {
		int largePos = Largest(sorting, NumOfElements, idx); // call function to get largest position
		swap(sorting, idx, largePos); // find largest and swap
	}
   
	//Print sorted array
	printArray (sorting, NumOfElements);
	printf("\n");
    return 0;
}
