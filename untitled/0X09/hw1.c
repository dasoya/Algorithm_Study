
#include <stdio.h>

// 유클리드 호제법을 사용하여 최대 공약수(GCD)를 구하는 함수
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 최소 공배수(LCM)를 구하는 함수
int lcm(int a, int b) {
    int lcm = (a * b) / gcd(a, b);
    return lcm;
}

int main() {
    int m, n;

    printf("Enter two positive integers: ");
    scanf("%d %d", &m, &n);


    printf("The greatest common divisor of %d, %d is %d.\n", m, n, gcd(m, n));
    printf("The least common multiple of %d, %d is %d.\n", m, n, lcm(m, n));

    return 0;
}
