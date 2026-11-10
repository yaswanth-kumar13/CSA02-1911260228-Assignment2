# Q6 – Loan Repayment Schedule

## Test Input

| Parameter | Value |
|---|---:|
| Principal | Rs. 10,000 |
| Monthly interest rate | 2% |
| Monthly repayment | Rs. 2,000 |

## Hand-Verified Schedule

| Month | Interest (Rs.) | Payment (Rs.) | Balance (Rs.) |
|---:|---:|---:|---:|
| 1 | 200.00 | 2000.00 | 8200.00 |
| 2 | 164.00 | 2000.00 | 6364.00 |
| 3 | 127.28 | 2000.00 | 4491.28 |
| 4 | 89.83 | 2000.00 | 2581.11 |
| 5 | 51.62 | 2000.00 | 632.73 |
| 6 | 12.65 | 645.38 | 0.00 |

## Final Results

- Total months: 6
- Total interest paid: Rs. 645.38
- Final payment is adjusted to the remaining amount due.

## Loop Design

A while loop is suitable because repayment continues until the balance is cleared.

The loop uses balance > 0.005 instead of balance != 0 because floating-point calculations can produce small rounding errors.

If repayment is less than or equal to monthly interest, the loan cannot be reduced, so the program stops.

A maximum limit of 360 months prevents an endless repayment schedule.

## Alternative Concept: Direct Formula

The assignment gives the formula:

n = -log(1 - r*P/E) / log(1+r)

This calculates the repayment duration directly instead of simulating each month.

- Formula: O(1) time and O(1) space.
- Monthly simulation: O(n) time and O(1) space.

The formula may have floating-point precision issues. Monthly simulation provides the detailed repayment schedule.

## Conclusion

The while-loop implementation successfully repays the loan in six months and adjusts the final payment correctly.