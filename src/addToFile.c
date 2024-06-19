#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function to get the last number from the file
int getLastNumberFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 2;  // If the file does not exist, return 2
    }

    int number;
    while (fscanf(file, "%d", &number) == 1) {
        // Read all the numbers from the file
    }

    fclose(file);
    return number;
}

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
    const char* filename = "../docs/primes.txt";
    int lastNumber = getLastNumberFromFile(filename);
    int start = lastNumber + 2;   // Start from the next number after the last in the file
    int loopLength = 1000000000;  // Number of numbers to check for primality
    int limit = start + loopLength;

    // Allocate memory for the boolean array that indicates whether the number is prime
    bool* isPrime = malloc((limit + 1) * sizeof(bool));
    if (isPrime == NULL) {
        printf("Insufficient memory.\n");
        return 1;
    }

    // Find all prime numbers up to the limit
    sieveOfEratosthenes(limit, isPrime);

    // Open the file to add the new prime numbers
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Could not open the file %s\n", filename);
        free(isPrime);
        return 1;
    }

    // Write the prime numbers to the file
    for (int i = start; i <= limit; i++) {
        if (isPrime[i]) {
            fprintf(file, "%d\n", i);
        }
    }

    fclose(file);
    free(isPrime);

    return 0;
}
