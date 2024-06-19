#include <stdbool.h>
#include <stdio.h>

bool isPrime(int number) {
    if (number < 2) {
        return false;
    }

    if (number == 2) {
        return true;
    }

    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int possiblePrimeNumber;

    printf("Enter a number: ");
    scanf("%d", &possiblePrimeNumber);

    if (possiblePrimeNumber == 0) {
        printf("0 is not a prime number.\n");
        return 0;
    }

    if (possiblePrimeNumber < 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    if (isPrime(possiblePrimeNumber)) {
        printf("%d is a prime number.\n", possiblePrimeNumber);
    } else {
        printf("%d is not a prime number.\n", possiblePrimeNumber);
    }

    return 0;
}