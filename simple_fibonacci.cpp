// Последовательность Фибоначчи определяется так:

// F(0) = 0, F(1) = 1, …, F(n) = F(n−1) + F(n−2).

// По данному числу N определите N-е число Фибоначчи F(N).

#include <iostream>

using namespace std;

int main() {
    int n, fib, i = 1, f = 1, f0 = 0;
    cin >> n;
    while (i < n) {
        fib = f;
        f = f0 + f;
        f0 = fib;
        i = i + 1;
    }
    cout << f;
}