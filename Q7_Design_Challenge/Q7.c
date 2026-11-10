#include <stdio.h>

unsigned long checks;

/* Original prime-checking method */
int original_prime(unsigned long n)
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

/* Redesigned method: skip even divisors */
int redesigned_prime(unsigned long n)
{
    checks = 0;

    if (n < 2)
        return 0;

    if (n % 2 == 0)
    {
        checks++;
        return n == 2;
    }

    checks++;

    for (unsigned long i = 3; i <= n / i; i += 2)
    {
        checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main(void)
{
    unsigned long numbers[] = {97, 100, 7919, 1000003};

    printf("ORIGINAL VS REDESIGNED PRIME CHECKING\n\n");

    printf("Number\t\tOriginal\tRedesigned\n");

    for (int i = 0; i < 4; i++)
    {
        unsigned long n = numbers[i];

        original_prime(n);
        unsigned long original_count = checks;

        redesigned_prime(n);
        unsigned long redesigned_count = checks;

        printf("%lu\t\t%lu\t\t%lu\n",
               n, original_count, redesigned_count);
    }

    return 0;
}