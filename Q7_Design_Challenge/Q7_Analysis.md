# Q7 – Diagnose, Redesign and Validate

## A. Diagnose the Bottleneck

The original prime-checking program tests every divisor from 2 to n-1.

For large prime numbers, it performs a very large number of unnecessary division operations.

For 1,000,003, the original program performs 1,000,001 divisions.

## B. Design Objective

Reduce the number of division operations while maintaining the correct prime-checking result.

## C. Revised Solution

The redesigned algorithm checks whether the number is divisible by 2 first.

If it is not divisible by 2, the algorithm checks only odd divisors starting from 3.

It stops when the divisor exceeds the square root of the number.

No additional array or memory is required.

### Pseudocode

1. If n is less than 2, return not prime.
2. Check whether n is divisible by 2.
3. If divisible, return whether n equals 2.
4. Start divisor i at 3.
5. While i <= n / i:
   - Count one division.
   - If n is divisible by i, return not prime.
   - Increase i by 2.
6. Return prime.

## D. Prediction

Skipping even divisors should significantly reduce division operations for large prime numbers.

## E. Experimental Validation

| Number | Original Divisions | Redesigned Divisions |
|---:|---:|---:|
| 97 | 95 | 5 |
| 100 | 1 | 1 |
| 7919 | 7917 | 44 |
| 1000003 | 1000001 | 500 |

## F. Final Evaluation

For 1,000,003, the original program performs 1,000,001 divisions, whereas the redesigned program performs only 500.

This is approximately a 99.95% reduction in division operations.

The redesigned algorithm maintains O(sqrt(n)) time complexity and O(1) extra space.

The original algorithm takes O(n) time and O(1) extra space.

The redesign is more efficient for large prime numbers. The original approach is simpler but performs unnecessary checks.

## Conclusion

The redesign successfully reduces division operations by skipping even divisors. The experimental results support the design objective.