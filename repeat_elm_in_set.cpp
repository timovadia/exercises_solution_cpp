// Во входной строке записана последовательность чисел через пробел. 
// Для каждого числа выведите слово YES (в отдельной строке), если это число ранее встречалось в последовательности или NO, если не встречалось.

// Входные данные
// Вводится число N - количество элементов списка, а затем N чисел.

#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (s.find(x) != s.end()) {
            cout << "YES\n";
        } else cout << "NO\n";
        s.insert(x);
    }
	return 0;
}