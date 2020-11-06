// Дано натуральное число n > 1. Выведите его наименьший делитель, отличный от 1.
// Решение оформите в виде функции MinDivisor(n). Количество операций в программе должно быть пропорционально корню из n.
// Указание. Если у числа n нет делителя, меньшего n , то число n — простое и ответом будет само число n.

// Формат входных данных
// Вводится натуральное число.

#include <iostream>
#include <cmath>

using namespace std;

int MinDivisor(int n) {
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
        return n;
    else
        return min_divisor;
}

int main() {
    int n;
    cin >> n;
    cout << MinDivisor(n);

    return 0;
}