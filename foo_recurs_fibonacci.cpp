// Напишите функцию fib(n), которая по данному целому положительному n возвращает n-e число Фибоначчи. 
// В этой задаче нельзя использовать циклы - используйте рекурсию.
// Первое и второе числа Фибоначчи равны 1, а каждое следующее равно сумме двух предыдущих.

// Формат входных данных
// Вводится целое число.

#include <iostream>

using namespace std;

int fib(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}