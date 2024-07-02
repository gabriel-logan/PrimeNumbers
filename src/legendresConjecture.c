#include <stdbool.h>
#include <stdio.h>

bool isPrime(long long int number) {
    if (number < 2) {
        return false;
    }

    if (number <= 3) {
        return true;
    }

    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }

    for (long long int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    long long int n = 50;
    long long int possiblePrimeNumberMin = n * n;
    long long int possiblePrimeNumberMax = (n + 1) * (n + 1);

    for (long long int i = possiblePrimeNumberMin; i <= possiblePrimeNumberMax; i++) {
        if (isPrime(i)) {
            printf("%lld is a prime number.\n", i);
        }
    }

    return 0;
}

/**
 *     for (long long int i = possiblePrimeNumberMin; i <= possiblePrimeNumberMax; i++) {
        if (isPrime(i)) {
            printf("%lld is a prime number.\n", i);
        } else {
            printf("%lld is not a prime number.\n", i);
        }
    }
 *
 */