// Дано натуральное число n > 1. Проверьте, является ли оно простым. 
// Программа должна вывести слово YES, если число простое и NO, если число составное.
// Решение оформите в виде функции IsPrime(n), которая возвращает True для простых чисел и False для составных чисел. 
// Количество операций в программе должно быть пропорционально корню из n.

// Формат входных данных
// Вводится натуральное число.

#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(int n) {
    int min_divisor = 1;
    int sqrt_n = sqrt((double)n);
    for (int i = 2; i <= sqrt_n; i++) {
        if (n % i == 0)
        {
            min_divisor = i;
            break;
        }
    }
    if (min_divisor == 1)
        return true;
    else
        return false;
}

int main() {
    int n;
    cin >> n;
    if (IsPrime(n)) cout << "YES";
    else cout << "NO";
    return 0;
}