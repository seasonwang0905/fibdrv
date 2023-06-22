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

unsigned long long fast_doubling1(int n)
{
    if (n <= 2)
        return !!n;

    unsigned long long f1 = 1, f2 = 1, t1, t2;
    int count = n / 2;
    for (int i = 0; i < count; i++) {
        t1 = 2 * f1 * f2 - f1 * f1;
        t2 = f1 * f1 + f2 * f2;
        temp = f2;
        f2 = f1 + temp;
        f1 = temp;
    }

    if (n & 1)
        return t2;
    return t1;
}

unsigned long long double_fib1(int n)
{
    unsigned long long f1 = 0, f2 = 1;
    for (int i = n; i >= 0; i--) {
        t1 = f1 * (f2 * 2 - f1);
        t2 = f2 * f2 + f1 * f1;
        f1 = t1;
        f2 = t2;
        if ((n & (1 << i))) {
            t1 = f1 + f2;
            f1 = f2;
            f2 = t1;
        }
    }
    return f1;
}

unsigned long long double_fib2(int n)
{
    unsigned long long f1 = 0, f2 = 1;
    int i = 31 - __builtin_clz(n);
    for (; i >= 0; i--) {
        unsigned long long t1, t2;
        t1 = f1 * (f2 * 2 - f1);
        t2 = f2 * f2 + f1 * f1;
        f1 = t1;
        f2 = t2;
        if ((n & (1 << i))) {
            t1 = f1 + f2;
            f1 = f2;
            f2 = t1;
        }
    }
    return f1;
}

unsigned long long double_fib3(int k)
{
    int bin_k[8];
    int count = 0;
    while (k) {
        bin_k[count] = k % 2;
        k = k >> 1;
        count++;
    }
    unsigned long long int a = 0, b = 1;
    for (int i = count - 1; i >= 0; i--) {
        t1 = a * ((2 * b) - a);
        t2 = b * b + a * a;
        a = t1;
        b = t2;
        if (bin_k[i] == 1) {
            temp = a + b;
            a = b;
            b = temp;
        }
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

    for (int i = 2; i < 9; i++) {
        printf("%d ", i);
        clock_gettime(CLOCK_REALTIME, &t1);
        (void) repeated_addition(i);
        clock_gettime(CLOCK_REALTIME, &t2);
        printf("%ld ", elapse(t1, t2));

        clock_gettime(CLOCK_REALTIME, &t1);
        (void) fast_doubling1(i);
        clock_gettime(CLOCK_REALTIME, &t2);
        printf("%ld ", elapse(t1, t2));

        clock_gettime(CLOCK_REALTIME, &t1);
        (void) double_fib1(i);
        clock_gettime(CLOCK_REALTIME, &t2);
        printf("%ld ", elapse(t1, t2));

        clock_gettime(CLOCK_REALTIME, &t1);
        (void) double_fib2(i);
        clock_gettime(CLOCK_REALTIME, &t2);
        printf("%ld ", elapse(t1, t2));

        clock_gettime(CLOCK_REALTIME, &t1);
        (void) double_fib3(i);
        clock_gettime(CLOCK_REALTIME, &t2);
        printf("%ld\n", elapse(t1, t2));
    }

    return 0;
}