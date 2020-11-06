// В сети интернет каждому компьютеру присваивается четырехбайтовый код, который принято записывать в виде четырех чисел, 
// каждое из которых может принимать значения от 0 до 255, разделенных точками. 
// Вот примеры правильных IP-адресов:
// 127.0.0.0
// 192.168.0.1
// 255.0.255.255

// Напишите программу, которая определяет, является ли заданная строка правильным IP-адресом.

// Входные данные
// Программа получает на вход строку из произвольных символов.

// Выходные данные
// Если эта строка является корректной записью IP-адреса, выведите YES, иначе выведите NO.

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool IsIP(string s) {
	bool rez;
	string numip;
	int count = 0, count_dots = 0, count_num = 0;
	for (auto c : s) {
		if (count == 0) {
			if (isdigit(c)) {
				numip += c;
				++count;
				continue;
			}
			else {
				rez = 0;
				break;
			}
		}
		else {
			if (isdigit(c) && count_dots <= 3) {
				numip += c;
				int ss = stoi(numip);
				string iss = to_string(ss);
				if (stoi(numip) >= 0 && stoi(numip) <= 255 && numip.size() == iss.size()) {
					rez = 1;
					if (count_dots == 3) {
						++count_num;
					}
				}
				else {
					rez = 0;
					break;
				}
			}
			else {
				if (c == '.' && count_dots <= 3 && numip != "") {
					if (stoi(numip) >= 0 && stoi(numip) <= 255) {
						rez = 1;
						numip = "";
						++count_dots;
						continue;
					}
					else {
						rez = 0;
						break;
					}
				}
				else {
					rez = 0;
					break;
				}
			}
		}

	}
	if (rez && count_dots == 3 && count_num > 0) {
		rez = 1;
	}
	else rez = 0;
	return rez;
}

int main() {
    string s;
    getline(cin, s);
    if (IsIP(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}