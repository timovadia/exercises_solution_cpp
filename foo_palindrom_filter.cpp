//Напишите функцию, которая
//называется PalindromFilter,
//возвращает vector<string>,
//принимает vector<string> words и int min_length,
//возвращает из вектора words все строки - палиндромы длиной не меньше min_length.
//
//Примеры
//WORDS/min_length  РЕЗУЛЬТАТ
//abacaba, aba	           
//5                 abacaba
//abacaba, aba	           
//2                 abacaba, aba
//weew, bro, code	       
//4                 weew

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string s) {
    // является ли строка s палиндромом
    bool rez = false;
    string s_rev = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        s_rev = s_rev + s[i];
    }
    if (s == s_rev) {
        rez = true;
    }
    else rez = false;
    return rez;
}

vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;

    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ',') {
            words.push_back(word);
            word = ""s;
        }
        else if (text[i] == ' ') {
            continue;
        }
        else {
            word += text[i];
        }
    }
    words.push_back(word);
    return words;
}

vector<string> PalindromFilter(vector<string> words, int min_length) {
    // формируем и возвращаем вектор подходящих палиндромов
    vector<string> rez;
    for (auto now : words) {
        if (IsPalindrom(now) && size(now) >= min_length) {
            rez.push_back(now);
        }
    }
    return rez;
}

int main() {
    string query;
    int min_length;

    getline(cin, query);
    cin >> min_length;

    vector<string> v_words = SplitIntoWords(query);
    vector<string> v_palindrom = PalindromFilter(v_words, min_length);
    for (string word : v_palindrom) {
        cout << word << endl;
    }
    return 0;
}
