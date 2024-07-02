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
    long long int startLoop = 1;
    long long int endLoop = 50;

    for (long long int n = startLoop; n <= endLoop; n++) {
        long long int possiblePrimeNumberMin = n * n;
        long long int possiblePrimeNumberMax = (n + 1) * (n + 1);
        bool foundPrime = false;

        for (long long int i = possiblePrimeNumberMin; i <= possiblePrimeNumberMax; i++) {
            if (isPrime(i)) {
                printf("%lld is a prime number. For n = %lld \n", i, n);
                foundPrime = true;
                break;  // Breaks the loop after the first prime number is found.
            }
        }

        if (!foundPrime) {
            printf("No prime number found for n = %lld\n", n);
        }
    }

    return 0;
}
