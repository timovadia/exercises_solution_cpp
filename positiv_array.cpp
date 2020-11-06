// Найдите количество положительных элементов в данном массиве.

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
    //обработка и вывод
    int count = 0;
    for (auto now : a) {
        if (now > 0) {
            count++;
        }     
    }
    cout << count << endl;
    return 0;
}