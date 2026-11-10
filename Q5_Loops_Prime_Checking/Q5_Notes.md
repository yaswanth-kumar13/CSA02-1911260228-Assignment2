# Q5 – Count the Work Done by a Loop

## Experimental Results

### Original Method: for loop (i < n)

| Number | Result | Divisions |
|---:|---|---:|
| 97 | Prime | 95 |
| 100 | Not Prime | 1 |
| 7919 | Prime | 7917 |
| 1000003 | Prime | 1000001 |

### Improved Method: i * i <= n

| Number | Result | Divisions |
|---:|---|---:|
| 97 | Prime | 8 |
| 100 | Not Prime | 1 |
| 7919 | Prime | 87 |
| 1000003 | Prime | 999 |

The improved for, while and do-while implementations produced identical division counts.

## Observation

The improved algorithm checks divisors only up to the square root of n. This significantly reduces the number of divisions for large prime numbers.

## Do-While Special Care

A do-while loop executes at least once. Therefore, the condition must be checked carefully for n = 2 and n = 3 to avoid unnecessary divisor checks.

## Integer Overflow

The expression i * i can overflow for very large unsigned integers. A safer condition is i <= n / i.

## Alternative Concept: Sieve of Eratosthenes

The Sieve of Eratosthenes calculates prime numbers up to N in O(N log log N) time and O(N) space. Each later prime query takes O(1) time.

Trial division takes O(sqrt(n)) time per query and O(1) extra space.

## Conclusion

The improved trial-division algorithm performs significantly fewer operations while maintaining correct results.