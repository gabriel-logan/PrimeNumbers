#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THREADS 60

typedef struct {
    int start;
    int end;
    char* isPrime;
    int sqrtLimit;
} ThreadData;

void* mark_multiples(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int start = data->start;
    int end = data->end;
    int sqrtLimit = data->sqrtLimit;
    char* isPrime = data->isPrime;

    for (int i = 2; i <= sqrtLimit; i++) {
        if (isPrime[i]) {
            int j = (start / i) * i;
            if (j < i * i) {
                j = i * i;
            }
            if (j < start) {
                j += i;
            }
            for (; j < end; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    return NULL;
}

int main() {
    int loopLength = 100000000;
    char* isPrime = malloc(loopLength * sizeof(char));
    memset(isPrime, 1, loopLength * sizeof(char));

    isPrime[0] = 0;  // 0 isn't prime
    isPrime[1] = 0;  // 1 isn't prime

    int sqrtLimit = (int)sqrt(loopLength);

    // Initial marking up to sqrt(loopLength) in a single thread
    for (int i = 2; i <= sqrtLimit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < loopLength; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    pthread_t threads[THREADS];
    ThreadData threadData[THREADS];
    int blockSize = (loopLength - sqrtLimit) / THREADS;

    // Create and run threads for the part above sqrt(loopLength)
    for (int i = 0; i < THREADS; i++) {
        threadData[i].start = sqrtLimit + i * blockSize;
        threadData[i].end = (i == THREADS - 1) ? loopLength : (sqrtLimit + (i + 1) * blockSize);
        threadData[i].isPrime = isPrime;
        threadData[i].sqrtLimit = sqrtLimit;
        pthread_create(&threads[i], NULL, mark_multiples, &threadData[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
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
