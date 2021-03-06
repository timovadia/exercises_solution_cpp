// Выведите значение наименьшего нечетного элемента списка, а если в списке нет нечетных элементов - выведите число 0.

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
    vector<int> a;
    //считывание
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp % 2 != 0) {
            a.push_back(temp);
        }
    }
    //обработка и вывод
    if (a.size() > 0) {
        int min = a[0]; //мин элемент
        for (int i = 0; i < a.size(); i++) {
            if (a[i] < min) {
                min = a[i];
            }
        }
        cout << min << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}