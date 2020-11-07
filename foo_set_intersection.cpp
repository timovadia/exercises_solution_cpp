//Представьте, что анализируете запросы пользователей в вашей поисковой системе.Есть слова запроса и описание животного.
//Посчитайте релевантность запроса — размер множества слов, которые входят и в запрос, и в описание.
//
//Формат ввода
//Сначала вводится строка - запрос, затем с новой строчки строка - описание.
//
//Формат вывода
//Выведите единственное целое число — размер пересечения множеств слов из запроса и описания.

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int CalculateSetIntersection(set<string> first, set<string> second) {
    //размер пересечения множеств слов
    int i = 0;
    for (auto elm : first) {
        if (second.count(elm)) {
            i++;
        }
    }
    return i;
}

set<string> StringToSetWords(string text) {
    //формируем множество слов
    set<string> set_words;
    string word;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            set_words.insert(word);
            word = "";
        }
        else {
            word += text[i];
        }
    }
    set_words.insert(word);

    return set_words;
}

int main() {
    string query, description;

    getline(cin, query);
    getline(cin, description);

    cout << CalculateSetIntersection(StringToSetWords(query), StringToSetWords(description)) << endl;

    return 0;
}