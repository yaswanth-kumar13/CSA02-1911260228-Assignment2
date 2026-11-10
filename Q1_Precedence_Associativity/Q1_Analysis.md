
# Q1 - Precedence, Associativity and the Discount Bug

## 1. Objective
To analyse operator precedence, associativity, integer division and undefined behaviour in C programming.

## 2. Test Cases

| Test | Price | Quantity | Senior |
|---|---:|---:|---:|
| A | 99 | 1 | Yes |
| B | 250 | 2 | No |
| C | 1200 | 1 | Yes |

## 3. Predicted Original Expression Results

| Test | Gross | Discount | GST | Total | Net |
|---|---:|---:|---:|---:|---:|
| A | 99 | 14 | 4 | 89 | 89 |
| B | 500 | 0 | 25 | 525 | 525 |
| C | 1200 | 180 | 60 | 1080 | 1030 |

## 4. Corrected Program Results

Record the actual outputs from the executed program here.

## 5. Identified Problems
- Integer division truncates fractional values.
- The original expression is difficult to read and maintain.
- The expression count = count++ + 1 causes undefined behaviour.
- Intermediate variables improve readability and make calculations easier to verify.

## 6. Undefined Behaviour
The expression count = count++ + 1 modifies count without proper sequencing. Its behaviour is undefined in C. GCC may report a warning when compiled with -Wall.

## 7. Corrected Design
The corrected implementation uses separate variables for gross amount, discount, GST, total and net payable. Double precision is used for percentage calculations.

## 8. Alternative Concept
The calculation can be divided into multiple statements using intermediate variables. This improves readability and debugging. Both approaches require a constant number of arithmetic operations.

## 9. Complexity Analysis
- Original expression: O(1) time and O(1) auxiliary space.
- Intermediate-variable solution: O(1) time and O(1) auxiliary space.
- The intermediate-variable approach uses additional temporary variables but improves clarity and maintainability.

## 10. Conclusion
The corrected program calculates the pharmacy bill using floating-point arithmetic and separate calculation steps. The three test cases are used to verify the implementation.
