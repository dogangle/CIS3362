#include <stdio.h>


int main() {

    int n;
    int temp;
    int tempAns;
    int a;
    int gcd;
    int flag;

    printf("Enter n.\n");
    scanf("%d", &n);


    for (int p=2; p<n; p++) {
        if (n % p == 0) {
            printf("%d is not prime. It's smallest non-trivial divisor is %d\n", n, p);
            return 0;
        }
        // Simple 'brute-force' method to determine if n is prime or not
        // if there exists a number p where n mod p = 0, then n is not prime
    }

    printf("%d is prime. Its primitive roots are: ", n);

    // First for loop cycles through every number between 2 and n-1 as the base, prime root number
    // Next for loop cycles through every number between 1 and n-1 as the exponent of the base
    // Flag integer is used to mark numbers which can't be primitive roots during the process
    for (int i=2; i<n; i++) {
        tempAns = 1;
        flag = 1;
        for (int j=1; j<n; j++) {

            tempAns = tempAns * i;
            tempAns = tempAns % n;


            // Using Fermat's theorem to test whether a^p-1 = 1 mod p
            // (using my variables, this is represented as i^n-1 = 1 mod n
            // if this is NOT 1 then it cannot be a primitive root
            if (j==n-1) {
                if (tempAns != 1) {
                    flag = 0;
                    break;
                }
            }

            // This checks all the other exponents. If any of the exponents
            // between 1 and n-2 give an answer that is 1 mod n, then it is also
            // not a primitive root.
            else if (tempAns == 1) {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            printf("%d ", i);
        // If the number being tested wasn't caught by the tests, then the base, i, is printed as a primitive root
    }

    return 0;
}
