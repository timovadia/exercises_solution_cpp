//Научите свою поисковую систему отбрасывать стоп-слова.
//На вход примите сначала строку стоп-слов, а затем с нового абзаца — строку-запрос.
//
//Выводите только те слова, которых нет в списке запрещённых.
//
//Ввод:
//with many very
//very kind dog with brown fur
//
//Вывод :
//[kind]
//[dog]
//[brown]
//[fur]

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<string> MakeSet(vector<string> query_words) {
    set<string> s(query_words.begin(), query_words.end());
    return s;
}

vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            words.push_back(word);
            word = "";
        }
        else {
            word += text[i];
        }
    }
    words.push_back(word);

    return words;
}

int main() {
    string query, stopwords;

    getline(cin, stopwords);
    getline(cin, query);

    vector<string> v_query_words = SplitIntoWords(query);
    vector<string> v_stopwords = SplitIntoWords(stopwords);

    set<string> set_stopwords = MakeSet(v_stopwords);

    for (string word : v_query_words) {
        if (!set_stopwords.count(word)) {
            cout << '[' << word << ']' << endl;
        }
    }
}