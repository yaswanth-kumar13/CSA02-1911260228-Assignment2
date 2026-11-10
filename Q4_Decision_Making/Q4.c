#include <stdio.h>

/* Method 1: Using else-if ladder */
char grade_ladder(int marks)
{
    if (marks < 0 || marks > 100)
        return '?';
    else if (marks >= 90)
        return 'S';
    else if (marks >= 80)
        return 'A';
    else if (marks >= 70)
        return 'B';
    else if (marks >= 60)
        return 'C';
    else if (marks >= 50)
        return 'D';
    else
        return 'F';
}

/* Method 2: Using switch statement */
char grade_switch(int marks)
{
    if (marks < 0 || marks > 100)
        return '?';

    switch (marks / 10)
    {
        case 10:
        case 9:
            return 'S';

        case 8:
            return 'A';

        case 7:
            return 'B';

        case 6:
            return 'C';

        case 5:
            return 'D';

        default:
            return 'F';
    }
}

int main(void)
{
    int marks[] = {100, 90, 89, 83, 50, 49, 0, -1, 101};
    int n = sizeof(marks) / sizeof(marks[0]);

    printf("GRADE COMPARISON\n");
    printf("-------------------------------\n");
    printf("Marks\tElse-If\tSwitch\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%c\t%c\n",
               marks[i],
               grade_ladder(marks[i]),
               grade_switch(marks[i]));
    }

    /* Missing break experiment */
    printf("\nMISSING BREAK EXPERIMENT\n");

    int test = 90;

    switch (test / 10)
    {
        case 9:
            printf("Grade S\n");

        case 8:
            printf("Grade A\n");

        default:
            printf("Default case\n");
    }

    return 0;
}