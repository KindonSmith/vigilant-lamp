#include "NUMS.h"


using namespace std;

int recursiveSum(int val, int limit) {
	/*
    Method to recursively sum all numbers that are divisible by 3 or 5 between val and limit
    Takes:      int val, the starting value
                int limit, the maximum value
    Returns:    int, the sum of all values between val and limit that are divisible by 3 or 5
    */
    if (val >= limit) return 0;                     
    if (val % 3 == 0 || val % 5 == 0) {             
        return val + recursiveSum(val + 1, limit);
    }
    return recursiveSum(val + 1, limit);            
}

int recursiveEvenFibSum(unsigned int left, unsigned int right, int limit) {
    /*
    Method to recursively add even integers from a Fibonacci sequence up to a limit
    Takes:      unsigned int left, the starting number in a Fibonacci sequence
                unsigned int right, the second number in a Fibonacci sequence
                int limit, a ceiling that will terminate the recursive function once right has reached or exceeded it
    Returns:    int, the sum of even integers in a Fibonacci sequence that terminates at limit
    */
    
    unsigned int fib = left + right;                            
    cout << "Next Fib: " << fib << endl;
    if (right >= limit) return 0;                                 // if right number exceeds our limit, return and collapse recursive stack
    if (right % 2 == 0) {                                         // if right number is even, return right number + recursive stack with next fibonacci
        return right + recursiveEvenFibSum(right, fib, limit);    // when calling, right becomes new left, next fibonacci number becomes new right                                                                
    }
    
    return recursiveEvenFibSum(right, fib, limit);
}

long long largestPrimeNumber(uint64_t num) {
    /*
    Method to determine the largest prime number for a given integer
    Takes:      uint64_t num, the value that will be checked
    Returns:    long long, the largest prime number for the input integer
    */
    uint64_t value = num;
    uint64_t largest = 0;
    for (uint64_t factor = 2; factor <= value/factor; ++factor) {
        if (value % factor == 0) {
            largest = factor;
            while (value % factor == 0) {
                value /= factor;
            }
        }
    }

    if (value != 1) largest = value;
    return largest;
}

long long lowestCommonMultiple(int max) {
    /*
    Method to find the lowest common multiple value for a range of digits, ranging from 1-max
    Takes: int max, the highest multiple value (I.E., providing 20 will operate on natural numbers (1,2,3...,20))
    Returns: long long, the lowest common multiple of the given sequence (1,2,3,...,max)
    */
    long long lowestCommonM = 1;
    for (int i = 1; i <= max; i++) {
        if (lowestCommonM % i) {
            lowestCommonM *= largestPrimeNumber(i);
        }
    }
    return lowestCommonM;
}

long long sumSquaresDifference() {

    /*
    One-pass operation to find the difference between:
    The sum of natural numbers, 1-100, squared (1+2+3+4...+100)^2
    The sum of squared natural numbers, 1-100  (1^2 + 2^2 + 3^2... + 100^2)
    Takes:      null, N/A
    Returns:    long long, difference between sum of natural numbers squared and the sume of squared natural numbers, 1-100
    */
    long long squaredSum = 0;
    long long sumSquared = 0;

    for (long long i = 1; i <= 100; i++) {
        squaredSum += i;
        sumSquared += i * i;
    }
    squaredSum *= squaredSum;

    return(squaredSum - sumSquared);
}

long long targetPrimeNumber(int n) {
    /*
    * Method to find the nth prime number, where n = any positive real number <= int_max
    * Takes: int n, the target prime number's index in a list of all prime numbers
    * Returns: long long, the prime number at the given index (the nth prime number)
    */
    int capacity = n;
    long long primeNum = 1;
    vector<long long> primeNums = {};

    while (capacity > 0) {
        if (primeNum == largestPrimeNumber(primeNum)) {
            primeNums.push_back(primeNum);
            capacity -= 1;
        }
        primeNum += 2;
    }
    return primeNums.back();
}

int largestSubProduct(int length, string series) {
    /*
    Method that returns the largest product of all substrings (of size length) for a fixed series of digits
    Takes: int length, the size of the substring
    Returns: int, the product of the substring with the largest value
    */    
    vector<int> values = {};

    char num;
    for (int i = 0; i < series.length(); i++) {
        num = series[i];
        values.push_back(stoi(&num));
    }
    return 0;
}

double specialPythagoreanTriplet() {
    /*
    * Method to return the product of a pythagorean triplet whos sum equals 1000
    * Takes: n/a
    * Returns: int, the product of the pythagorean triplet whos sum equals 1000
    */

    // a^2 + b^2 = c^2
    // c = sqrt(a^2 + b^2)
    // a + b + c = 1000
    // a + b + c - 1000 = 0

    // a + b + sqrt(a^2 + b^2) - 1000 == 0;
    long double c = 0;

    for (int i = 0; i < 1000/3; i++) {
        for (int j = 0; j < 1000/2; j++) {
            c = 1000 - i - j;
            
            if (pow(i,2) + pow(j, 2) == pow(c,2)) {
                cout << "EUREKA" << endl;
                return i * j * c;
            }
        }
    }
        
    return 0;
}

bool isPerfectSquare(long double x) {
    if (x >= 0) {
        long long squareRoot = sqrt(x);

        return (pow(squareRoot, 2) == x);
    }
    return false;
}

long long sumOfPrimes(long limit) {
    long long sum = 0;
    for (int i = 0; i < limit; i++) {
        if (i == largestPrimeNumber(i)) sum += i;
    }
    return sum;
}