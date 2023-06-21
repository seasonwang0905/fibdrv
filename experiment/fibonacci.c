#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
typedef enum { false, true } bool;

unsigned long long natural_recursive(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return natural_recursive(n - 1) + natural_recursive(n - 2);
}

unsigned long long repeated_addition(int n)
{
    unsigned long long a = 1, b = 0;
    for (int i = 2; i <= n; i++) {
        temp = a;
        a = a + b;
        b = temp;
    }
    return a;
}
long elapse(struct timespec start, struct timespec end)
{
    return ((long) 1.0e+9 * end.tv_sec + end.tv_nsec) -
           ((long) 1.0e+9 * start.tv_sec + start.tv_nsec);
}
int main()
{
    struct timespec t1, t2;

    for (int i = 2; i < 11; i++) {
        printf("%d ", i);
        clock_gettime(CLOCK_REALTIME, &t1);
        (void) natural_recursive(i);
        clock_gettime(CLOCK_REALTIME, &t2);
        printf("%ld ", elapse(t1, t2));

        clock_gettime(CLOCK_REALTIME, &t1);
        (void) repeated_addition(i);
        clock_gettime(CLOCK_REALTIME, &t2);
        printf("%ld\n ", elapse(t1, t2));
    }
    return 0;
}