#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Using the sieve of Eratosthenes algorithm to find all prime numbers up to a certain limit
int main() {
    int loopLength = 100000000;  // Number of numbers to check for primality
    char* isPrime = malloc(loopLength * sizeof(char));
    memset(isPrime, 1, loopLength * sizeof(char));

    isPrime[0] = 0;  // 0 isn't prime
    isPrime[1] = 0;  // 1 isn't prime

    for (int i = 2; i * i < loopLength; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < loopLength; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    int* primes = malloc(loopLength * sizeof(int));
    int index = 0;

    for (int i = 2; i < loopLength; i++) {
        if (isPrime[i]) {
            primes[index++] = i;
        }
    }

    for (int i = 0; i < index; i++) {
        printf("%d ", primes[i]);
    }

    free(isPrime);
    free(primes);

    return 0;
}
