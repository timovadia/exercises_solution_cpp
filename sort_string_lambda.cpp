//В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S.
//Между собой число и строки разделены пробелом.
//Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя регистр букв, и выведите их в стандартный поток вывода.
//
//Ограничения
//0 <= N <= 1000
//1 <= |S| <= 15
//
//Каждая строка S[i] может состоять из следующих символов : [0 - 9, a - z, A - Z]
//
//Пример
//Ввод
//4 quantity AMOUNT Selection Search
//Вывод
//AMOUNT quantity Search Selection

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string ToLower(string& s) {
    string s_low;
    for (auto& i : s) {
        s_low += tolower(i);
    }
    return s_low;
}

int main()
{
    int n;
    string s_words;
    vector<string> v_words;
    cin >> n;
    for (; n > 0; n--) {
        cin >> s_words;
        v_words.push_back(s_words);
    } sort(begin(v_words), end(v_words), [](string& str1, string& str2) {
        return ToLower(str1) < ToLower(str2); // лямбдa
        });
    for (const auto& elm : v_words) {
        cout << elm << " ";
    }
    return 0;
}