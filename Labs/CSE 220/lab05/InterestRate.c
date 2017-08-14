
int main() { 
    float LoanAmount = 0.0;
    float InterestRate = 0.0;
    
    printf("Enter loan amount ($): ");
    scanf("%f", &LoanAmount);

    if (LoanAmount == 0) {
        return 0;
    }
        
    while (LoanAmount != 0) { // loop until loan amount is 0
        float InterestAmount = 0.0;
        printf("Enter interest rate (%): ");
        scanf("%f", &InterestRate);
        InterestAmount = LoanAmount*InterestRate/100.0f; // calculates the interest amount to pay
        printf("*** Interest amount ($): %.2f\n", InterestAmount);
        
        printf("Enter loan amount ($): ");
        scanf("%f", &LoanAmount);
    }

    return 0; 
}
