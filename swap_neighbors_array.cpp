// Переставьте соседние элементы массива (A[0] c A[1], A[2] c A[3] и т.д.). Если элементов нечетное число, то последний элемент остается на своем месте.

// Формат входных данных
// В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.

// Формат выходных данных
// Выведите ответ на задачу.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    //ввод
    int n;
    cin >> n;
    vector<int> a(n);
    //считывание
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //обработка
    for (int i = 0; i < n - 1; i += 2) {
        int temp;
        temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
    }
    for (auto elm : a) {
       cout << elm << " "; 
    }
    return 0;
}