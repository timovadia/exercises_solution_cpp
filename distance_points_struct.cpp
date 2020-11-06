// Выведите все исходные точки в порядке возрастания их расстояний от начала координат. 

// Входные данные
// Программа получает на вход набор точек на плоскости. Сначала задано количество точек n, 
// затем идет последовательность из n строк, каждая из которых содержит два числа: координаты точки. 
// Величина n не превосходит 100, все исходные координаты – целые числа, не превосходящие 103.

// Выходные данные

// Необходимо вывести все исходные точки в порядке возрастания их расстояний от начала координат.

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct point {
    double dist;
    pair<int, int> xy;
};

bool cmp(point a, point b) {
    return a.dist < b.dist;
}

int main() {
    int n, a, b;
    cin >> n;
    vector<point> ss(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        point temp; // временная структура для записи значений в вектор
        temp.dist = (double)sqrt(a * a + b * b);
        temp.xy = {a, b};
        ss[i] = temp;
    }
    sort(ss.begin(), ss.end(), cmp);
    for (auto elm : ss) {
        cout << elm.xy.first << " " << elm.xy.second << endl;
    }
    return 0;
}