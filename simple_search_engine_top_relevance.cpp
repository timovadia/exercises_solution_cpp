//Пусть ваша поисковая система возвращает не любые документы, а документы с самой высокой релевантностью.
//Напишите функцию FindTopDocuments, которая должна находить только MAX_RESULT_DOCUMENT_COUNT = 5 результатов.
//
//Примеры:
//
//Ввод
//a the on cat
//6
//a fat cat sat on a mat and ate a fat rat
//fat rat
//a fat cat rat
//a fat cat sat
//a fat cat
//a fat dog
//funny fat cat on a mat with rat
//
//Вывод
//{ document_id = 0, relevance = 3 }
//{ document_id = 2, relevance = 2 }
//{ document_id = 1, relevance = 2 }
//{ document_id = 5, relevance = 1 }
//{ document_id = 4, relevance = 1 }


#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int MAX_RESULT_DOCUMENT_COUNT = 5;

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

vector<pair<int, int>> FindAllDocuments(const map<string, set<int>>& word_to_documents,
    const set<string>& stop_words,
    const string& query) {

    vector<pair <int, int>> rez_id;

    vector<string> v_query_words = SplitIntoWords(query);
    sort(v_query_words.begin(), v_query_words.end());

    set<int> temp_id, set_doc_id;
    for (const string& elm : v_query_words) {
        if (!stop_words.count(elm)) {
            set_doc_id = word_to_documents.find(elm)->second;
            for (auto& elm : set_doc_id) {
                temp_id.insert(elm);
            }
        }
    }

    //Считаем релевантность count_relevance возвращённого в ответе документа — то есть количество уникальных слов, пересекающихся с запросом.
    for (auto& id_doc : temp_id) {
        int count_relevance = 0;
        for (const string& elm : v_query_words) {
            if (!stop_words.count(elm)) {
                //находим по запрос-слову множество id документов, где оно встречается, например set_doc_id = {0, 1, 3}
                set_doc_id = word_to_documents.find(elm)->second;
                //в set_doc_id находим документ с текущим id = id_doc
                if (set_doc_id.count(id_doc)) count_relevance++;//если документ id_doc существует в set_doc_id, то (count + 1)
            }
        }
        rez_id.push_back({ count_relevance, id_doc });
    }

    sort(begin(rez_id), end(rez_id));
    reverse(begin(rez_id), end(rez_id));
    return rez_id;
}

vector<pair<int, int>> FindTopDocuments(const map<string, set<int>>& word_to_documents,
    const set<string>& stop_words,
    const string& query) {

    vector<pair <int, int>> TopDocuments;
    vector<pair<int, int>> AllDocuments = FindAllDocuments(word_to_documents, stop_words, query);
    if (AllDocuments.size() < MAX_RESULT_DOCUMENT_COUNT) MAX_RESULT_DOCUMENT_COUNT = AllDocuments.size();
    for (size_t i = 0; i < MAX_RESULT_DOCUMENT_COUNT; i++)
    {
        TopDocuments.push_back({ AllDocuments[i].first, AllDocuments[i].second });
    }
    return TopDocuments;
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
    for (auto& id_doc_relevance : FindTopDocuments(word_to_documents, stop_words, query)) {
        cout << "{ document_id = "s << id_doc_relevance.second << ", relevance = "s << id_doc_relevance.first << " }"s << endl;
    }

    return 0;
}