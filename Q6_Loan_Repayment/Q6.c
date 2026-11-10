#include <stdio.h>

int main(void)
{
    double principal, rate, repayment;
    double balance, interest, total_interest = 0;
    double amount_due, actual_payment;
    int month = 0;

    printf("Enter loan amount: ");
    scanf("%lf", &principal);

    printf("Enter monthly interest rate (%%): ");
    scanf("%lf", &rate);

    printf("Enter fixed monthly repayment: ");
    scanf("%lf", &repayment);

    if (principal <= 0 || rate < 0 || repayment <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    rate = rate / 100.0;
    balance = principal;

    printf("\n--- LOAN REPAYMENT SCHEDULE ---\n");
    printf("Month\tInterest\tPayment\t\tBalance\n");

    while (balance > 0.005)
    {
        if (month >= 360)
        {
            printf("Maximum repayment period reached.\n");
            break;
        }

        interest = balance * rate;

        if (repayment <= interest)
        {
            printf("Repayment is insufficient to reduce the loan.\n");
            break;
        }

        amount_due = balance + interest;

        actual_payment = repayment;

        if (actual_payment > amount_due)
            actual_payment = amount_due;

        balance = amount_due - actual_payment;

        if (balance < 0.005)
            balance = 0;

        total_interest += interest;
        month++;

        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n",
               month, interest, actual_payment, balance);
    }

    printf("\nTotal months: %d\n", month);
    printf("Total interest paid: Rs. %.2f\n", total_interest);

    return 0;
}