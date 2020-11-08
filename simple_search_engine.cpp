////////////////////////////////////////////////////////
// Система поиска документов по словам
////////////////////////////////////////////////////////

//У вас есть множество документов. И есть стоп-слова.
//Приходит запрос некоторый.
//Найдите все документы, где есть хотя бы одно слово из запроса.
//Учтите стоп-слова и не включайте их в результаты поиска.
//
//Функция FindDocuments должна искать и выдавать требуемые идентификаторы документов в виде вектора.
//В векторе с результатами не должно быть повторов.
//
//Ввод:
//СТРОКА СТОП-СЛОВ
//a the on cat	
//
//ЧИСЛО ДОКУМЕНТОВ
//4	
//
//ДОКУМЕНТ0
//a fat cat sat on a mat and ate a fat rat
//
//ДОКУМЕНТ1
//little funny fluffy cat
//
//ДОКУМЕНТ2
//the cat	
//
//ДОКУМЕНТ3
//huge green crocodile	
//
//ЗАПРОС
//funny fat cat
//
//Вывод (id документов):
//0
//1

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}

int ReadLineWithNumber() {
    int result;
    cin >> result;
    ReadLine();
    return result;
}

vector<string> SplitIntoWords(const string& text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            words.push_back(word);
            word = "";
        }
        else {
            word += c;
        }
    }
    words.push_back(word);

    return words;
}

set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
    vector<string> words;
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

void AddDocument(map<string, set<int>>& word_to_documents,
    int document_id,
    const string& document) {

    vector<string> v_doc_words = SplitIntoWords(document);
    for (const string& elm : v_doc_words) {
        word_to_documents[elm].insert(document_id); //заполняем словарь: слово - {id документа, где содержится слово} 
    }
}

vector<int> FindDocuments(const map<string, set<int>>& word_to_documents,
    const set<string>& stop_words,
    const string& query) {

    vector<string> v_query_words = SplitIntoWords(query);
    sort(v_query_words.begin(), v_query_words.end());

    vector<int> rez_id;
    set<int> temp_id, set_doc_id;
    for (const string& elm : v_query_words) {
        if (!stop_words.count(elm)) {
            set_doc_id = word_to_documents.find(elm)->second;
            for (auto& elm : set_doc_id) {
                temp_id.insert(elm);
            }
        }
    }
    for (auto& now : temp_id) {
        rez_id.push_back(now);
    }

    return rez_id;
}

int main() {
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Читаем документы
    map<string, set<int>> word_to_documents;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        AddDocument(word_to_documents, document_id, ReadLine());
    }

    // Выводим id
    const string query = ReadLine();
    for (const int document_id : FindDocuments(word_to_documents, stop_words, query)) {
        cout << document_id << endl;
    }
}