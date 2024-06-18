#include <stdio.h>
#include <stdlib.h>

int main() {
    int loopLength = 1000;
    int* primes = malloc(loopLength * sizeof(int));
    int index = 0;

    if (loopLength >= 2) {
        primes[index++] = 2;
    }

    for (int i = 3; i < loopLength; i += 2) {
        int isPrime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            primes[index++] = i;
        }
    }

    FILE* file = fopen("./docs/primes.txt", "w");
    if (file == NULL) {
        printf("Could not open file primes.txt\n");
        free(primes);
        return 1;
    }

    for (int i = 0; i < index; i++) {
        fprintf(file, "%d\n", primes[i]);
    }

    fclose(file);
    free(primes);

    return 0;
}