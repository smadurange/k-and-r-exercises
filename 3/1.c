#include <stdio.h>
#include <time.h>

int binsearch1(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

/* measures time taken for two implementations of binsearch */
int main(int argc, char *argv[]) {
    int i, x, n, iter, i1, i2;
    long t1, t2;
    struct timespec fs, ts;

    x = 7;
    n = 10;
    iter = 10000000;
    int v[] = { 0, 1, 2, 5, 6, 7, 9, 10, 11, 13 };

    clock_gettime(CLOCK_REALTIME, &fs);
    for (i = 0; i < iter; i++)
        i1 = binsearch1(x, v, n);
    clock_gettime(CLOCK_REALTIME, &ts);
    
    t1 = ts.tv_nsec - fs.tv_nsec;
    printf("1: found %d in %f sec\n", i1, (double) t1 / 1e9);

    clock_gettime(CLOCK_REALTIME, &fs);
    for (i = 0; i < iter; i++)
        i2 = binsearch2(x, v, n);
    clock_gettime(CLOCK_REALTIME, &ts);
    
    t2 = ts.tv_nsec - fs.tv_nsec;
    printf("2: found %d in %f sec\n", i2, (double) t2 / 1e9);

    return 0;
}

int binsearch1(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

int binsearch2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low <= high && x != v[mid]) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return x == v[mid] ? mid : -1;
}