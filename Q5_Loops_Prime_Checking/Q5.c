#include <stdio.h>

unsigned long checks = 0;

/* Original method: test every divisor */
int is_prime_original(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    for (unsigned long i = 2; i < n; i++)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

/* Improved method using for loop */
int is_prime_for(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    for (unsigned long i = 2; i * i <= n; i++)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

/* Improved method using while loop */
int is_prime_while(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    unsigned long i = 2;

    while (i * i <= n)
    {
        checks++;

        if (n % i == 0)
            return 0;

        i++;
    }

    return 1;
}

/* Improved method using do-while loop */
int is_prime_do(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    unsigned long i = 2;

    do
    {
        if (i * i > n)
            break;

        checks++;

        if (n % i == 0)
            return 0;

        i++;
    }
    while (i * i <= n);

    return 1;
}

int main(void)
{
    unsigned long tickets[] = {97, 100, 7919, 1000003};

    printf("ORIGINAL METHOD\n");

    for (int k = 0; k < 4; k++)
    {
        int p = is_prime_original(tickets[k]);

        printf("%8lu %-9s divisions = %lu\n",
               tickets[k], p ? "prime" : "not prime", checks);
    }

    printf("\nIMPROVED FOR LOOP\n");

    for (int k = 0; k < 4; k++)
    {
        int p = is_prime_for(tickets[k]);

        printf("%8lu %-9s divisions = %lu\n",
               tickets[k], p ? "prime" : "not prime", checks);
    }

    printf("\nIMPROVED WHILE LOOP\n");

    for (int k = 0; k < 4; k++)
    {
        int p = is_prime_while(tickets[k]);

        printf("%8lu %-9s divisions = %lu\n",
               tickets[k], p ? "prime" : "not prime", checks);
    }

    printf("\nIMPROVED DO-WHILE LOOP\n");

    for (int k = 0; k < 4; k++)
    {
        int p = is_prime_do(tickets[k]);

        printf("%8lu %-9s divisions = %lu\n",
               tickets[k], p ? "prime" : "not prime", checks);
    }

    return 0;
}