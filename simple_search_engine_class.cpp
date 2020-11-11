﻿//Поисковая система возвращает не любые документы, а документы с самой высокой релевантностью.
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

struct Document {
	int id;
	int relevance;
};

bool HasDocumentGreaterRelevance(const Document& lhs, const Document& rhs) {
	return lhs.relevance > rhs.relevance;
}

class SearchServer {
public:
	void SetStopWords(const string& text) {
		for (const string& word : SplitIntoWords(text)) {
			stop_words_.insert(word);
		}
	}

	void AddDocument(int document_id, const string& document) {
		for (const string& word : SplitIntoWordsNoStop(document)) {
			word_to_documents_[word].insert(document_id);
		}
	}

	vector<Document> FindTopDocuments(const string& query) const {
		auto matched_documents = FindAllDocuments(query);

		sort(matched_documents.begin(), matched_documents.end(), HasDocumentGreaterRelevance);
		if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
			matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
		}
		return matched_documents;
	}

private:
	map<string, set<int>> word_to_documents_;
	set<string> stop_words_;

	vector<string> SplitIntoWords(const string& text) const {
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

	vector<string> SplitIntoWordsNoStop(const string& text) const {
		vector<string> words;
		for (const string& word : SplitIntoWords(text)) {
			if (stop_words_.count(word) == 0) {
				words.push_back(word);
			}
		}
		return words;
	}

	vector<Document> FindAllDocuments(const string& query) const {

		const vector<string> query_words = SplitIntoWordsNoStop(query);
		map<int, int> document_to_relevance;
		for (const string& word : query_words) {
			if (word_to_documents_.count(word) == 0) {
				continue;
			}
			for (const int document_id : word_to_documents_.at(word)) {
				++document_to_relevance[document_id];
			}
		}

		vector<Document> matched_documents;
		for (auto doc : document_to_relevance) {
			matched_documents.push_back({ doc.first, doc.second });
		}

		return matched_documents;
	}
};

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

SearchServer CreateSearchServer() {
	SearchServer search_server;
	string stop_words_joined = ReadLine();
	search_server.SetStopWords(stop_words_joined);

	const int document_count = ReadLineWithNumber();
	for (int document_id = 0; document_id < document_count; ++document_id) {
		search_server.AddDocument(document_id, ReadLine());
	}
	return search_server;
}

int main() {
	const SearchServer server = CreateSearchServer();

	const string query = ReadLine();
	vector<Document> v_top_relevance_docs = server.FindTopDocuments(query);
	for (auto doc : v_top_relevance_docs) {
		cout << "{ document_id = " << doc.id << ", relevance = " << doc.relevance << " }" << endl;
	}

	return 0;
}