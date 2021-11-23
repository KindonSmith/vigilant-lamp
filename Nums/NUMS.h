#ifndef NUMS
#define NUMS
#include <cstdint>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>

int recursiveSum(int val, int limit);

int recursiveEvenFibSum(unsigned int left, unsigned int right, int limit);

long long largestPrimeNumber(uint64_t num);

long long lowestCommonMultiple(int max);

long long sumSquaresDifference();

long long targetPrimeNumber(int n);

int largestSubProduct(int length, std::string series);

double specialPythagoreanTriplet();

bool isPerfectSquare(long double x);

long long sumOfPrimes(long limit);



#endif