#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "capacitor.h"
 
int main () {
       Capacitor Cap1 = {"11-123U", 100, 25, 6.00, 0};
    Capacitor Cap2 = {"65T91a", 22000, 20, 25.00,  1};
    Capacitor Cap3;

    Capacitor Caps[4]; // set up array
  
    
    printf("model number is: \n");
    fgets (Cap3.ModelNumber, 30, stdin);
    printf("\tcapacitance is: \n");
    scanf("%f", &Cap3.capacitance );
    printf("\tvoltage is: \n");
    scanf("%f", &Cap3.voltage );
    printf("\tcost is: \n");
    scanf("%f", &Cap3.cost );
    Cap3.Type = 2;
   
    Caps[0] = Cap1; 
    Caps[1] = Cap2;
    Caps[2] = Cap3;

    getchar();
    printf("model number is: \n");
    fgets (Caps[3].ModelNumber, 30, stdin);
    printf("\tcapacitance is: \n");
    scanf("%f",&Caps[3].capacitance );
    printf("\tvoltage is: \n");
    scanf("%f",&Caps[3].voltage);
    printf("\tcost is: \n");
    scanf("%f", &Caps[3].cost);
    Caps[3].Type = 3;


    int i;
    for (i = 0; i < 4; i++){ // loops through array
        displayCapacitorInfo(Caps[i]); // print details for each capacitor
    }
    Capacitor* c = largestCapacitance(Caps, 4); // find largest capacitance
    printf("The Cost to the largest capacitor is: $ %.2f\n", c->cost); // print info of largest capacitance
    return 0;
}