#include<stdio.h>

void arrayReverse(float arr[], float size) {
	float i; // set up initializer
	if (size >= 0) {
		printf("element is +%f\n", size);
		arrayReverse(arr, size - 1);
	}

}

int main() {
	int size = 0;

	//get proper array size
	do {
		printf("Enter size of array: \n"); // get array size
		scanf("%d", &size);
	} while (size < 0);


	float arr[size]; // declare an array of user input size

	// save integers into array
	int i;
	for (i = 0; i < size; i++) {
		printf("Input a number:\n");
		scanf("%f", &arr[i]);
	}

	arrayReverse(arr, size); // call function

    return 0;
}
