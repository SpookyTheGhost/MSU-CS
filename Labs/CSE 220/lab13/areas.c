#include <stdio.h>
#include <stdlib.h>
#include "geometry.h"

int main(int argc, char *argv[]) {
    if (*argv[1] == 'C' && argc == 3) {
        printf("C %f\n", computeCircleArea(atof(argv[2]) ) );
    }
 
    else if (*argv[1] == 'R' && argc == 4) {
        printf("R %f\n", computeRectangleArea(atof(argv[2]), atof(argv[3]) ) );
    }
 
    else {
        printf("Invalud input\n");
    }
    return 0;
}
