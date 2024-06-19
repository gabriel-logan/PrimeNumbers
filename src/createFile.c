#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function to find all prime numbers up to a certain limit
void sieveOfEratosthenes(int limit, bool* isPrime) {
    for (int i = 0; i <= limit; i++) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }
}

int main() {
    int loopLength = 100000000;  // Number of numbers to check for primality
    bool* isPrime = malloc((loopLength + 1) * sizeof(bool));
    if (isPrime == NULL) {
        printf("Insufficient memory.\n");
        return 1;
    }

    // Find all prime numbers up to the limit
    sieveOfEratosthenes(loopLength, isPrime);

    FILE* file = fopen("../docs/primes.txt", "w");
    if (file == NULL) {
        printf("Could not open the file primes.txt\n");
        free(isPrime);
        return 1;
    }

    // Write the prime numbers to the file
    for (int i = 2; i <= loopLength; i++) {
        if (isPrime[i]) {
            fprintf(file, "%d\n", i);
        }
    }

    fclose(file);
    free(isPrime);

    return 0;
}
