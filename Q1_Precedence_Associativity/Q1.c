
#include <stdio.h>

int main(void)
{
    double price, gross, discount, tax, total, net;
    int qty, senior;
    int count = 0;

    printf("Enter medicine price: ");
    scanf("%lf", &price);

    printf("Enter quantity: ");
    scanf("%d", &qty);

    printf("Senior citizen? (1 = Yes, 0 = No): ");
    scanf("%d", &senior);

    gross = price * qty;
    discount = senior ? gross * 0.15 : 0.0;
    tax = gross * 0.05;
    total = gross - discount + tax;
    net = total > 1000 ? total - 50 : total;

    count++;

    printf("\n--- PHARMACY BILL ---\n");
    printf("Gross Amount : Rs. %.2f\n", gross);
    printf("Discount     : Rs. %.2f\n", discount);
    printf("GST          : Rs. %.2f\n", tax);
    printf("Total        : Rs. %.2f\n", total);
    printf("Net Payable  : Rs. %.2f\n", net);
    printf("Bill Count   : %d\n", count);

    return 0;
}
