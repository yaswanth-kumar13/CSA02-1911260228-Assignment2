# Q2 – Short-Circuit Evaluation

## Experimental Results

| Test | Expected Calls | Actual Calls |
|---|---:|---:|
| Order 1: (senior && eligible) || verify_card() | 700 | 700 |
| Order 2: verify_card() || (senior && eligible) | 1000 | 1000 |
| Logical && | 0 | 0 |
| Bitwise & | 1 | 1 |

## Observation

Short-circuit evaluation avoids unnecessary function calls. In Order 1, the function was called 700 times. In Order 2, it was called 1000 times.

Logical && skipped the function call when the first operand was false. Bitwise & evaluated both operands.

## Complexity

Both passenger loops take O(n) time and O(1) extra space.

## Conclusion

The order of conditions affects the number of function calls. Short-circuit operators can improve efficiency when conditions are arranged appropriately.