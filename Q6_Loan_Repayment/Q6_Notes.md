
# Q6 – Loops That Must Terminate: Loan Repayment Schedule

## 1. Objective

To develop a C program that calculates a month-by-month loan repayment schedule using a loop. The program calculates monthly interest, adjusts the final repayment amount, tracks total interest and terminates when the loan is fully repaid.

## 2. Test Input – First Experiment

| Parameter | Value |
|---|---:|
| Loan Amount | Rs. 10,000 |
| Monthly Interest Rate | 2% |
| Fixed Monthly Repayment | Rs. 2,000 |

## 3. Hand-Verified Repayment Schedule

| Month | Interest (Rs.) | Payment (Rs.) | Balance (Rs.) |
|---:|---:|---:|---:|
| 1 | 200.00 | 2000.00 | 8200.00 |
| 2 | 164.00 | 2000.00 | 6364.00 |
| 3 | 127.28 | 2000.00 | 4491.28 |
| 4 | 89.83 | 2000.00 | 2581.11 |
| 5 | 51.62 | 2000.00 | 632.73 |
| 6 | 12.65 | 645.38 | 0.00 |

### Final Results

- Total months: 6
- Total interest paid: Rs. 645.38
- Final adjusted payment: Rs. 645.38

The program output matches the hand-calculated repayment schedule.

## 4. Loop Design and Termination

A while loop is suitable because repayment continues until the outstanding balance is cleared.

The loop condition used is:

`while (balance > 0.005)`

A small tolerance is used instead of checking `balance != 0` because floating-point calculations can produce small rounding errors.

Every month, the program:

1. Calculates interest on the outstanding balance.
2. Adds interest to the balance.
3. Calculates the actual payment.
4. Adjusts the final payment if it exceeds the amount due.
5. Updates the outstanding balance.
6. Adds the interest to the total interest.

If the repayment is less than or equal to the monthly interest, the program stops because the loan cannot be reduced.

A maximum limit of 360 months is included to prevent an endless repayment schedule.

## 5. Growth Investigation

The same loan amount and interest rate were used for three experiments. Only the monthly repayment amount was changed.

### Experimental Results

| Experiment | Monthly Repayment (Rs.) | Total Months | Total Interest (Rs.) |
|---|---:|---:|---:|
| Test 1 | 2000 | 6 | 645.38 |
| Test 2 | 1000 | 12 | 1270.33 |
| Test 3 | 500 | 26 | 2898.73 |

### Observation

As the monthly repayment amount decreases, the number of months required to repay the loan increases.

The total interest paid also increases because the outstanding loan balance remains for a longer period.

The experiments demonstrate that the repayment amount significantly affects the loan duration and total interest.

## 6. Final Payment Adjustment

In the final month, the remaining balance plus interest may be less than the fixed monthly repayment.

Therefore, the program adjusts the final payment to the exact amount due instead of charging the full repayment amount.

This prevents overpayment.

## 7. Alternative Concept – Direct Mathematical Formula

The assignment provides the following formula to calculate the repayment duration directly:

`n = -log(1 - r*P/E) / log(1+r)`

Where:

- P = Principal loan amount
- r = Monthly interest rate
- E = Fixed monthly repayment
- n = Number of months

The formula calculates the repayment duration directly instead of simulating each monthly payment.

### Complexity Comparison

| Method | Time Complexity | Space Complexity |
|---|---|---|
| Monthly repayment simulation | O(n) | O(1) |
| Direct mathematical formula | O(1) | O(1) |

The formula is faster for calculating the repayment duration, but it does not directly provide the detailed monthly repayment schedule.

The monthly simulation provides individual interest and payment values but requires more iterations.

The formula also requires careful handling of floating-point precision and invalid inputs.

## 8. Conclusion

The while-loop implementation successfully calculates the loan repayment schedule and terminates when the outstanding balance reaches zero.

The final payment is adjusted correctly, and the program prevents non-terminating repayment schedules using a maximum iteration limit.

The three experiments show that reducing the monthly repayment increases both the repayment duration and total interest paid.

The experimental results support the correctness and usefulness of the implemented loan repayment program.