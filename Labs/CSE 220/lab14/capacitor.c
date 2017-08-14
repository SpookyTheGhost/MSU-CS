#include "capacitor.h"
#include <stdio.h>
/*
* This prints out each capacitor's information
*/
void displayCapacitorInfo (Capacitor cap) {
    printf("Capacitor %s:\n", cap.ModelNumber);
    printf("\t*Capacitance: %f uF\n", cap.capacitance);
    printf("\t*Voltage: %f V\n", cap.voltage);
    printf("\t*Cost: $ %f\n", cap.cost);
    printf("\t*Type: %s\n", enumToString(cap.Type));
}

char* enumToString (CapType type) {
    switch (type) {
        case Ceramic:
            return "Ceramic";
        case Aluminum:
            return "Aluminum";
        case Film:
            return "Film";
        case Supercapacitor:
            return "Supercapacitor";
    }
}
 
/*
* Finds largest capacitance & returns pointer to relevant capacitor
*/
Capacitor* largestCapacitance (Capacitor Caps[], int size) {
    Capacitor* c = &Caps[0]; // set a pointer
    int i;
    for (i = 1; i < size; i++) {
        if (Caps[i].capacitance > c->capacitance) {
            c = &Caps[i]; // set pointer to current index
        }
    }

    return c; // return pointer to largest capacitor
}


void saveCapacitor (Capacitor cap, char* fileName) {
    FILE* file; // file stream
    file = fopen(fileName, "w"); // open file

    // save capacitor to file
    fprintf(file, "%s %f %f %f %s\n", cap.ModelNumber, cap.capacitance, cap.voltage, cap.cost, cap.Type);

    fclose(file); // securely close file
}

void saveCapacitors (Capacitor caps[], int size, char* fileName) {
    FILE* file; // file stream
    file = fopen(fileName, "w"); // open file

    int i;
    for (i = 0; i < size; i++) {
        fprintf(file, "%s %f %f %f %s\n", caps[i].ModelNumber, caps[i].capacitance, caps[i].voltage, caps[i].cost, caps[i].Type);
    }

    fclose(file);  // securely close file
}

Capacitor loadCapacitor (char* fileName){
    FILE* file; 
    file = fopen(fileName, "r"); // open file
    Capacitor cap1;
    fscanf(file, "%s %f %f %f %s\n", cap1.ModelNumber, cap1.capacitance, cap1.voltage, cap1.cost, cap1.Type);
    fclose(file); // close file
}


// removes the newline for formatting issues
void removeNewLines(Capacitor caps[], Capacitor c) {
    char *p;
    for (p = caps[0].ModelNumber; *p != '\0'; p++) {
        if (*p == '\n') {
            *p = '\0';
        }
    }
}
