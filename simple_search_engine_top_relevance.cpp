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
//{ document_id = 1, relevance = 2 }
//{ document_id = 2, relevance = 2 }
//{ document_id = 3, relevance = 1 }
//{ document_id = 4, relevance = 1 }


#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAX_RESULT_DOCUMENT_COUNT = 5;

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
	const set<string>& stop_words,
	int document_id,
	const string& document) {
	for (const string& word : SplitIntoWordsNoStop(document, stop_words)) {
		word_to_documents[word].insert(document_id);
	}
}

struct Document {
	int id;
	int relevance;
};

bool HasDocumentGreaterRelevance(const Document& lhs, const Document& rhs) {
	return lhs.relevance > rhs.relevance;
}

vector<Document> FindAllDocuments(
	const map<string, set<int>>& word_to_documents,
	const set<string>& stop_words,
	const string& query) {

	const vector<string> query_words = SplitIntoWordsNoStop(query, stop_words);
	map<int, int> document_to_relevance;
	for (const string& word : query_words) {
		if (word_to_documents.count(word) == 0) {
			continue;
		}
		for (const int document_id : word_to_documents.at(word)) {
			++document_to_relevance[document_id];
		}
	}

	vector<Document> matched_documents;
	for (auto doc : document_to_relevance) {
		matched_documents.push_back({ doc.first, doc.second });
	}

	return matched_documents;
}

vector<Document> FindTopDocuments(
	const map<string, set<int>>& word_to_documents,
	const set<string>& stop_words,
	const string& query) {

	auto matched_documents = FindAllDocuments(word_to_documents, stop_words, query);

	sort(matched_documents.begin(), matched_documents.end(), HasDocumentGreaterRelevance);
	if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
		matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
	}
	return matched_documents;
}

int main() {
	const string stop_words_joined = ReadLine();
	const set<string> stop_words = ParseStopWords(stop_words_joined);

	// Read documents
	map<string, set<int>> word_to_documents;
	const int document_count = ReadLineWithNumber();
	for (int document_id = 0; document_id < document_count; ++document_id) {
		AddDocument(word_to_documents, stop_words, document_id, ReadLine());
	}

	const string query = ReadLine();
	for (auto doc : FindTopDocuments(word_to_documents, stop_words, query)) {
		cout << "{ document_id = " << doc.id << ", relevance = " << doc.relevance << " }" << endl;
	}

	return 0;
}
