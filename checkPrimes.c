#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPrime(long long int number) {
    if (number < 2) {
        return false;
    }

    if (number == 2) {
        return true;
    }

    for (long long int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    char input[21];  // long long int can hold up to 19 digits, plus sign and null terminator
    long long int possiblePrimeNumber;
    char *endptr;

    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin);
    possiblePrimeNumber = strtoll(input, &endptr, 10);

    // Check if the input was a valid number
    if (endptr == input || *endptr != '\n') {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    if (possiblePrimeNumber == LLONG_MAX || possiblePrimeNumber == LLONG_MIN) {
        printf("Invalid input. Please enter a number less than %lld.\n", LLONG_MAX);
        return 1;
    }

    if (possiblePrimeNumber == 0) {
        printf("0 is not a prime number.\n");
        return 0;
    }

    if (possiblePrimeNumber < 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    if (isPrime(possiblePrimeNumber)) {
        printf("%lld is a prime number.\n", possiblePrimeNumber);
    } else {
        printf("%lld is not a prime number.\n", possiblePrimeNumber);
    }

    return 0;
}