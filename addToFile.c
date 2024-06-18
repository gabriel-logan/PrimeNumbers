#include <stdio.h>
#include <stdlib.h>

int getLastNumberFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 2;  // If the file does not exist, return 2
    }

    int number;
    while (fscanf(file, "%d", &number) == 1) {
        // Read all numbers from the file
    }

    fclose(file);
    return number;
}

int main() {
    const char* filename = "./docs/primes.txt";
    int start = getLastNumberFromFile(filename) + 2;  // Start from the next number after the last one in the file
    int loopLength = 100;
    int* primes = malloc(loopLength * sizeof(int));
    int index = 0;

    for (int i = start; i < start + loopLength; i += 2) {
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

    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
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