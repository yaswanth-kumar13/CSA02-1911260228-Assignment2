#include <stdio.h>

int calls = 0;

int verify_card(int has_card)
{
    calls++;
    return has_card;
}

int main(void)
{
    int senior_count = 300;
    int eligible_count = 600;
    int disability_count = 200;
    int i, result;

    calls = 0;

    for (i = 0; i < 1000; i++)
    {
        int senior = (i < senior_count);
        int eligible = (i < eligible_count);
        int disability = (i < disability_count);

        result = (senior && eligible) || verify_card(disability);
    }

    printf("Order 1 function calls: %d\n", calls);
    printf("Order 1 last result: %d\n", result);

    calls = 0;

    for (i = 0; i < 1000; i++)
    {
        int senior = (i < senior_count);
        int eligible = (i < eligible_count);
        int disability = (i < disability_count);

        result = verify_card(disability) || (senior && eligible);
    }

    printf("Order 2 function calls: %d\n", calls);
    printf("Order 2 last result: %d\n", result);

    calls = 0;
    result = 0 && verify_card(1);
    printf("Logical && calls: %d\n", calls);

    calls = 0;
    result = 0 & verify_card(1);
    printf("Bitwise & calls: %d\n", calls);

    return 0;
}