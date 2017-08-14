#ifndef _CAPACITOR_H_
#define _CAPACITOR_H_

// declare enumeration
typedef enum {Ceramic, Aluminum, Film, Supercapacitor} CapType;

// declare a struct, a new custom type
typedef struct Capacitors {
    char ModelNumber[30];
    float capacitance;
    float voltage;
    float cost;
    CapType Type;
}Capacitor;
 
void displayCapacitorInfo (Capacitor cap); // function prototype
Capacitor* largestCapacitance (Capacitor Caps[], int size); // function prototype
char* enumToString (CapType type);

void saveCapacitor (Capacitor cap, char* fileName);
void saveCapacitors (Capacitor caps[], int size, char* fileName);
Capacitor loadCapacitor (char* fileName);

void removeNewLines(Capacitor caps[], Capacitor cap);

#endif