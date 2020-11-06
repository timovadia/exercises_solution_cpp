// Даны два списка чисел, которые могут содержать до 100000 чисел каждый. 
// Посчитайте, сколько чисел содержится одновременно как в первом списке, так и во втором.

// Входные данные
// Вводится число N - количество элементов первого списка, а затем N чисел первого списка. 
// Затем вводится число M - количество элементов второго списка, а затем M чисел второго списка.

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    multiset<int> s1, s2;
    set<int> s3;
    int n, m;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s1.insert(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s2.insert(x);
    }

    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(), inserter(s3,s3.begin()));

    cout << s3.size();
    return 0;
}