#include <stdio.h>
#include <time.h>
#include <x86intrin.h>

typedef unsigned t;

void f1(t N) {
    clock_t start = clock();
    t ret = 0;
    for (t x = 0, y=0; y < N; y++, x += 2535571) {
        for (t i = 0; i < 32; i++) {
            if (x & (1 << i)) ret++;
        }
    }
    clock_t end = clock();
    printf("f1: %u bits, time=%.4f\n", ret, 
            (double)(end-start) / CLOCKS_PER_SEC);
}

void f2(t N) {
    clock_t start = clock();
    t ret = 0;
    for (t x = 0, y=0; y < N; y++, x += 2535571) {
        for (t i = 0; i < 32; i++) {
            ret += (x >> i) & 0x1;
        }
    }
    clock_t end = clock();
    printf("f2: %u bits, time=%.4f\n", ret,
            (double)(end-start) / CLOCKS_PER_SEC);
}

void f3(t N) {
    clock_t start = clock();
    t ret = 0;
    for (t x = 0, y=0; y < N; y++, x += 2535571) {
        for (t i = x; i != 0; i >>= 1) {
            ret += i & 0x1;
        }
    }
    clock_t end = clock();
    printf("f3: %u bits, time=%.4f\n", ret,
            (double)(end-start) / CLOCKS_PER_SEC);
}

void f4(t N) {
    clock_t start = clock();
    t ret = 0;
    for (t x = 0, y=0; y < N; y++, x += 2535571) {
        for (t i = x; i != 0; i &= i-1) {
            ret++;
        }
    }
    clock_t end = clock();
    printf("f4: %u bits, time=%.4f\n", ret,
            (double)(end-start) / CLOCKS_PER_SEC);
}

void f5(t N) {
    clock_t start = clock();
    t ret = 0;
    for (t x = 0, y=0; y < N; y++, x += 2535571) {
        t i = (x & 0x55555555) + ((x >> 1) & 0x55555555);
          i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
          i = (i & 0x0F0F0F0F) + ((i >> 4) & 0x0F0F0F0F);
          i = (i & 0x00FF00FF) + ((i >> 8) & 0x00FF00FF);
          ret += (i & 0x0000FFFF) + ((i >> 16) & 0x0000FFFF);
    }
    clock_t end = clock();
    printf("f5: %u bits, time=%.4f\n", ret,
            (double)(end-start) / CLOCKS_PER_SEC);
}

int main() {
    const t N = 30000000;
    f1(N);
    f2(N);
    f3(N);
    f4(N);
    f5(N);
}





