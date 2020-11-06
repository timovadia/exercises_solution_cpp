// Найдите в данной строке самое длинное слово и выведите его.

// Входные данные
// Вводится одна строка. Слова в ней отделены одним пробелом.

// Выходные данные
// Выведите самое длинное слово. 
// Если таких слов несколько, то выводить нужно, которое встречается раньше.

#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	string w_max, w_now;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != ' ') {
			w_now += s[i];
		}
		else {
			if (w_now.size() > w_max.size()) w_max = w_now;
			w_now = "";
		};
	}
	if (w_now.size() > w_max.size()) w_max = w_now;
	cout << w_max << endl;
}