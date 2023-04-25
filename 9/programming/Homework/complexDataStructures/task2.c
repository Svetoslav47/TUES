#include <stdio.h>

enum week_days
{
    MONDAY = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main()
{
    int day_num;
    printf("Enter day number (1-7): ");
    scanf("%d", &day_num);
    switch (day_num)
    {
    case MONDAY:
        printf("MONDAY\n");
        break;
    case Tuesday:
        printf("Tuesday\n");
        break;
    case Wednesday:
        printf("Wednesday\n");
        break;
    case Thursday:
        printf("Thursday\n");
        break;
    case Friday:
        printf("Friday\n");
        break;
    case Saturday:
        printf("Saturday\n");
        break;
    case Sunday:
        printf("Sunday\n");
        break;
    default:
        printf("Invalid input\n");
    }
    return 0;
}
