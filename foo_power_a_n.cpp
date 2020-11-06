// Дано действительное положительное число a и целоe число n.

// Вычислите an. Решение оформите в виде рекурсивной функции power(a, n).

// Формат входных данных
// Вводится действительное положительное число a и целоe число n.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double power(double a, int n) {
    double p;
    if (n == 0) p = 1;
    else if (n == 1) p = a;
    else if (n > 1) {
        p = a;
        for (int i = 2; i <= n; i++) p = p * a;
    }
    else if (n < 0) {
        p = a;
        for (int i = 2; i <= -n; i++) p = p * a;
        p = 1 / p;
    }
    return p;
}

int main() {
    double  a;
    int n;
    cin >> a >> n;
    cout << fixed << setprecision(5);
    cout << power(a,n);
    return 0;
}