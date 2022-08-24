#include <iostream>
using namespace std;

const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

int countLeapYears(int d, int m, int y)
{
    int years = y;

    if (m <= 2)
        years--;

    return years / 4 - years / 100 + years / 400;
}

int getDifference(int d1, int m1, int y1, int d2, int m2, int y2)
{

    long int n1 = y1 * 365 + d1;

    for (int i = 0; i < m1 - 1; i++)
        n1 += monthDays[i];

    n1 += countLeapYears(d1, m1, y1);

    long int n2 = y2 * 365 + d2;
    for (int i = 0; i < m2 - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(d2, m2, y2);

    return (n2 - n1);
}
