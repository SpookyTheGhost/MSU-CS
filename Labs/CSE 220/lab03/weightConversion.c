#include<stdio.h>


int main() {
	float weight1 = 0;
	float weight2 = 0;
	float weight3 = 0;
	float weight4 = 0;

	printf("Input four weights in format weight1/weight2/weight3/weight4: ");
	scanf("%f/%f/%f/%f",&weight1,&weight2,&weight3,&weight4);

	printf("Weight 1: %10.2f lbs =%10.2f Oz =%10.2f g\n",weight1, weight1*16, weight1*453.592);
	printf("Weight 2: %10.2f lbs =%10.2f Oz =%10.2f g\n",weight2, weight2*16, weight2*453.592);
	printf("Weight 3: %10.2f lbs =%10.2f Oz =%10.2f g\n",weight3, weight3*16, weight3*453.592);
	printf("Weight 4: %10.2f lbs =%10.2f Oz =%10.2f g\n",weight4, weight4*16, weight4*453.592);
	return 0;
}
