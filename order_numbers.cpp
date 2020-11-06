// Дано три числа. Упорядочите их в порядке неубывания.

// Формат входных данных
// Вводятся три числа.

// Формат выходных данных
// Выведите ответ на задачу.

#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b > c) {
        swap(b, c);
    } 
    if (a > c) {
        swap(a, c);
    }
    if (a > b) {
        swap(a, b);
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}