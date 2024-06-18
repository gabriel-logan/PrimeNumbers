#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int loopLength = 10000000;
    char* isPrime = malloc(loopLength * sizeof(char));
    memset(isPrime, 1, loopLength * sizeof(char));

    isPrime[0] = 0;  // 0 não é primo
    isPrime[1] = 0;  // 1 não é primo

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
