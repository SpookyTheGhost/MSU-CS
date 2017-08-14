#include <stdio.h>

int main() {
	//step 1
	int a = 0, b = 100, c = 225;

	// step 2
	printf("The value of a is %p\n", a);
	printf("The address of a is %p\n", &a);
	printf("The value of b is %p\n", b);
	printf("The address of b is %p\n", &b);
	printf("The value of c is %p\n", c);
	printf("The address of c is %p\n", &c);
	// step 3
	int *pA = &a, *pB = &b, *p;
	//printf("the value of pA is %p\n", *pA);
	printf("the address of B is %p\n", &pB);
	

	// step 4
	// because not set, compiler sets random address & value
	//printf("the value of p is %p\n", *p); 
	//printf("the address of p is %p\n", &p);
	printf("hi2\n");
	
	// step 5
	printf("the value of p is %p\n", *p); 
	//printf("the address of p is %p\n", &p);


	printf("the value of pA is %p\n", *pA);
	printf("the address of B is %p\n", &pB);

	// because not set, compiler sets random address & value
	printf("the value of p is %p\n", *p); 
	//printf("the address of p is %p\n", &p);

        // step 7
       int i = 50;
        p = &i; // set p to 50

        // step 8
        p = &a;
 
        // step 9
        // find 3 different ways to change a to 92
        a = 92;
        *pA = a;
        pA = &a;

        // step 10
        p = pA;


    // step 11
    printf("*pA: %p\n", *pA);
    printf("*pB: %p\n", *pB);
    printf("a: %p\n", a);
    printf("b: %p\n", b);
    printf("&a: %p\n", &a);
    printf("&b: %p\n", &b);

    *p = 22;
    printf("*pA: %p\n", *pA);
    printf("*pB: %p\n", *pB);
    printf("a: %p\n", a);
    printf("b: %p\n", b);
    printf("&a: %p\n", &a);
    printf("&b: %p\n", &b);

    p = pB;
    printf("*pA: %p\n", *pA);
    printf("*pB: %p\n", *pB);
    printf("a: %p\n", a);
    printf("b: %p\n", b);
    printf("&a: %p\n", &a);
    printf("&b: %p\n", &b);

    
    *p = pB; // saves address as value, gives warning of cast
    printf("*pA: %p\n", *pA);
    printf("*pB: %p\n", *pB);
    printf("a: %p\n", a);
    printf("b: %p\n", b);
    printf("&a: %p\n", &a);
    printf("&b: %p\n", &b);

    *p = 18;
    p = &b;
    printf("*pA: %p\n", *pA);
    printf("*pB: %p\n", *pB);
    printf("a: %p\n", a);
    printf("b: %p\n", b);
    printf("&a: %p\n", &a);
    printf("&b: %p\n", &b);

    *p = 108;
    printf("*pA: %p\n", *pA);
    printf("*pB: %p\n", *pB);
    printf("a: %p\n", a);
    printf("b: %p\n", b);
    printf("&a: %p\n", &a);
    printf("&b: %p\n", &b);

    p = pA;
    printf("*pA: %p\n", *pA);
    printf("*pB: %p\n", *pB);
    printf("a: %p\n", a);
    printf("b: %p\n", b);
    printf("&a: %p\n", &a);
    printf("&b: %p\n", &b);

    *p = 2;
    printf("*pA: %p\n", *pA);
    printf("*pB: %p\n", *pB);
    printf("a: %p\n", a);
    printf("b: %p\n", b);
    printf("&a: %p\n", &a);
    printf("&b: %p\n", &b);

    // gives a warning about cast
    *p = &a;
    printf("*pA: %p\n", *pA);
    printf("*pB: %p\n", *pB);
    printf("a: %p\n", a);
    printf("b: %p\n", b);
    printf("&a: %p\n", &a);
    printf("&b: %p\n", &b);

    // step 12
    int z[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //step 13
    for (i = 0; i < 10; i++) {
        printf("address of i is: %p\n", &z[i]);
    }

    // step 14
    for (i = 0; i < 10; i++) {
        printf("value of i is: %p\n", z[i]);
    }

    for (i = 0; i < 10; i++) {
        printf("value of i is: %p\n", z[i+1]);
    }

    // step 15
    (*(z+3))++;

    // step 16
    int *t = z;

    // step 17
    printf("t %d\n", t);
    printf("t+1 %d\n", t + 1);
    printf("t+2 %d\n", t + 2);
    printf("t+3 %d\n", t + 3);
    printf("t+4 %d\n", t + 4);

    // step 18
    t = t+5;
    printf("t %d\n", t);
    printf("*t %d\n", *t);
}
