//Не всегда ответ на запрос соответствует ожиданиям. 
//Чем ближе результат к ожидаемому, тем выше его релевантность исходному запросу.
//Научите свою поисковую систему считать релевантность возвращённого в ответе документа — то есть количество уникальных слов,
//пересекающихся с запросом.
//Эту релевантность нужно возвращать вместе с идентификатором документа как пару из двух целых чисел {document_id, relevance}.

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

vector<pair<int, int>> FindDocuments(const map<string, set<int>>& word_to_documents,
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

    //Считаем релевантность возвращённого в ответе документа — то есть количество уникальных слов, пересекающихся с запросом.
    for (auto& id_doc : temp_id) {
        int count = 0;
        for (const string& elm : v_query_words) {
            if (!stop_words.count(elm)) {
                //находим по запрос-слову множество id документов, где оно встречается, например set_doc_id = {0, 1, 3}
                set_doc_id = word_to_documents.find(elm)->second;
                //в set_doc_id находим документ с текущим id = id_doc
                if (set_doc_id.count(id_doc)) count++;//если документ id_doc существует в set_doc_id, то (count + 1)
            }
        }
        rez_id.push_back({ id_doc, count });
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
    for (auto id_relevance : FindDocuments(word_to_documents, stop_words, query)) {
        cout << "{ document_id = "s << id_relevance.first << ", relevance = "s << id_relevance.second << " }"s << endl;
    }
}