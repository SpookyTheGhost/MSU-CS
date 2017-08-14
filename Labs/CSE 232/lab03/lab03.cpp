/* 
 * File:   lab03.cpp
 * Author: zhangke8
 *
 * Created on January 29, 2014, 3:00 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
using std::cout; using std::endl; using std::cin;

double integration (double a,double b){
    double Ia = -2*pow(a,3)+(5.0/2)*pow(a,2)+3*pow(a,1);
    double Ib = -2*pow(b,3)+(5.0/2)*pow(b,2)+3*pow(b,1);
    double I = Ib-Ia;
    return I;
}


 double trapezoid (double a,double b, double n){

     for (double cnt = 0; cnt <= n+1; cnt++){
        double num_of_trap = (b-a)/n;
        double c = a; //distance between trapezoids
       
       double area = ((b-a/(n+1)*(-2*pow(a + cnt,3)+(5.0/2)*pow(a + cnt,2)+
       3*pow(a + cnt,1)-2*pow(b + cnt,3)+(5.0/2)*pow(b + 
       cnt,2)+3*pow(b + cnt,1) )))/2;
       double a = b;
       double sum = 0;
       sum += area;
       return sum;
    }
    
    
}
 

int main() {
    double tolerance = 0, a = 0, b = 1, n = 0; // hardcode a, b
    cout << "what is the tolerance of error: " << endl;
    cin >> tolerance;
    cout << "input number of trapezoids: " << endl;
    cin >> n;
    
    double actual = integration (0,1);
    double estimate = trapezoid (0,1,n);
    
    double cnt = 0;
    double diff = actual - estimate;
    while (diff > tolerance){
        n = 2*n;
        double actual = integration (0,1);
        double estimate = trapezoid (0,1,n);
        double diff = actual - estimate;
        cnt ++;
    }
    
    // within tolerance value
    cout << "Trap count: " << cnt << ", estimate: " << estimate << ", exact: " 
            << actual << ", tolerance: " 
            << tolerance << endl;

    return 0;
}

