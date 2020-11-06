// Возводить в степень можно гораздо быстрее, чем за n умножений! 
// Для этого нужно воспользоваться следующими рекуррентными соотношениями.

// Реализуйте алгоритм быстрого возведения в степень с помощью рекурсивной функции.

// Формат входных данных
// Вводятся действительное число a и целое неотрицательное число n.

#include <iostream>

using namespace std;

double Power(double a, int n) {
    double pow;
    if (n == 0) return 1;
    if (n % 2 == 0) {
       pow = Power(a * a, n / 2);
    } else {
       pow = a * Power(a, n - 1); 
    }
    return pow;
}
   
int main() {
    double a;
    int n;
    cin >> a >> n;
    cout << Power(a, n) << endl;
    return 0;
}