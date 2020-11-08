//Слова называются анаграммами, если одно из них можно получить перестановкой букв в другом.
//Например, "eat" и "tea" — анаграммы, потому что состоят из одних и тех же букв в разном порядке.
//Даны пары слов. Проверьте, можно ли назвать слова в каждой паре анаграммами.

//Формат ввода:
//Сначала дано число пар слов N, затем в N - строках содержатся пары слов, которые необходимо проверить.Гарантируется, что все слова состоят из строчных латинских букв.
//
//Формат вывода:
//Выведите N строк : для каждой введённой пары слов напечатайте YES, если эти слова — анаграммы, и NO в противном случае.
//
//Примеры:
//ВВОД       ВЫВОД
//3 
//hare rhea  YES
//pig squid  NO
//wolf fowl  YES


#include <iostream>
#include <map>
#include <string> 

using namespace std;

map<char, int> BuildCharMapCounters(string& w) {
    map<char, int> m;
    for (char& s : w) {
        /*if (m.count(s) == 0) {
            m[s] = 1;
        }
        else {
            ++m[s];
        }*/
        ++m[s];//эквивалент условия
    }
    return m;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string first_word, second_word;
        cin >> first_word >> second_word;
        const map<char, int> map_char_fst_word = BuildCharMapCounters(first_word);
        const map<char, int> map_char_snd_word = BuildCharMapCounters(second_word);
        if (map_char_fst_word == map_char_snd_word) {
            cout << "YES"s << endl;
        }
        else {
            cout << "NO"s << endl;
        }
    }

    return 0;
}