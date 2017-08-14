#include<stdio.h>
#include <math.h>

int main() {
	float velocity = 0;
	float acc = 0;
	float time = 0;
	

	printf("What is the initial velocity?\n");
	scanf("%f",&velocity);
	printf("What is the acceleration?\n");
	scanf("%f",&acc);
	printf("What is the time?\n");
	scanf("%f",&time);

	float distance = acc*(time*time)/2 + velocity*time;

	printf("The initial velocity is: %f  m/s\n", velocity);
	printf("The acceleration is: %f m/s2\n", acc);
	printf("The total distance travelled after %f seconds is: %f meters\n", time, distance);
	return 0;
}
