# PrimeNumbers
Repository containing code that aims to find prime numbers and displays a list of them available on the web.

The idea of ​​the repository is to create the most optimized code possible, to generate increasingly larger prime numbers and add them to the primes.txt list

## List of prime numbers
https://github.com/gabriel-logan/PrimeNumbers/blob/main/docs/primes.txt

## Raw file
https://raw.githubusercontent.com/gabriel-logan/PrimeNumbers/main/docs/primes.txt

## Small List of prime numbers (first 1000)
https://github.com/gabriel-logan/PrimeNumbers/blob/main/docs/small-primes-list.txt

## Small List of prime numbers (first 1000) Raw file
https://raw.githubusercontent.com/gabriel-logan/PrimeNumbers/main/docs/small-primes-list.txt

## You can also check if a number is prime using

```bash 
gcc ./checkPrimes.c -o checkPrimes

./checkPrimes
```

```
user@user$ time ./checkPrimes
Enter a number: 1779999803
1779999803 is a prime number.

real    0m0.945s
user    0m0.001s
sys     0m0.000s
user@user$
```

## How each code works

### addToFile.c
This code is responsible for adding a number to the primes.txt file.

### checkMultiPrimes.c
This code is responsible for checking if a interval of numbers is prime. And if it is, print it on the screen.

### checkPrimes.c
This code is responsible for checking if a number is prime. And if it is, print it on the screen.

### createFile.c
This code is responsible for creating the primes.txt file. It will erase the file if it already exists.

### createFileWithLimit.c
This code is responsible for creating the primes.txt file. It will erase the file if it already exists. It will also create a file with a limit of numbers.
Example: if you want to create a file with the first 1000 prime numbers, you can use this code.

### checkPrimesWithThreads.c
NOT WORKING YET

### genAndPrint.c
This code is responsible for generating and printing prime numbers on the screen.

