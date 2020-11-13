//Научитесь обрабатывать запросы с минус-словами.
//Прежние условия сохраняются :
//слова в документах и запросах разделены ровно одним пробелом;
//перед первым словом и после последнего пробелов нет;
//сами слова состоят только из букв.
//
//Единственное нововведение: запрос может содержать минус-слова — слова с минусом в начале. В документе минус-слов быть не может.
//
//Пример
//Ввод
//и в на
//3
//белый кот и модный ошейник
//пушистый кот пушистый хвост
//ухоженный пёс выразительные глаза
//пушистый ухоженный кот -ошейник
//
//Вывод
//{ document_id = 1, relevance = 2 }
//{ document_id = 2, relevance = 1 }

//Минус-слова запроса должны обрабатываться после плюс-слов.
//Каждый документ, где есть минус-слово, надо удалить из словаря «документ - релевантность».
//Для хранения запроса удобно создать структуру Query с двумя векторами слов : плюс- и минус-словами.
//Возвращать эту структуру по строке запроса нужно в новом приватном методе — ParseQuery.
//После сравнения первого символа с '-' не забудьте отрезать этот минус вызовом .substr(1), а затем проверить результат по словарю стоп-слов.

//Вычисление релевантности по формуле TF-IDF.
//
//Пример:
//
//Ввод:
//и в на
//3
//белый кот и модный ошейник
//пушистый кот пушистый хвост
//ухоженный пёс выразительные глаза
//пушистый ухоженный кот
//
//Вывод:
//{ document_id = 1, relevance = 0.650672 }
//{ document_id = 2, relevance = 0.274653 }
//{ document_id = 0, relevance = 0.101366 }

#include <algorithm>
#include <cmath> // Для расчетов TF, IDF
#include <iostream>
#include <Windows.h> // Обязательно для SetConsoleCP() и SetConsoleOutputCP()
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAX_RESULT_DOCUMENT_COUNT = 5;

struct Document {
	int id;
	double relevance;
};

struct Query {
	vector<string> plus_word;
	vector<string> minus_word;
};

//bool HasDocumentGreaterRelevance(const Document& lhs, const Document& rhs) {
//	return lhs.relevance > rhs.relevance;
//}

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

class SearchServer {
public:
	void SetStopWords(const string& text) {
		for (const string& word : SplitIntoWords(text)) {
			stop_words_.insert(word);
		}
	}

	/*Здесь нужно рассчитать term frequency или TF.
	Для конкретного слова и конкретного документа это доля, которую данное слово занимает среди всех слов данного документа.
	Рассчитаем TF слова кот в документе 1.
	Всего слов в этом документе четыре, из них кот — только одно. 1 / 4 = 0, 25.
	А слово пушистый встречается дважды, так что его TF в этом документе будет 2 / 4 = 0, 5.*/
	void AddDocument(int document_id, const string& document) {
		auto curr_docum = SplitIntoWordsNoStop(document);
		for (const string& word : curr_docum) {
			double count_word = count(begin(curr_docum), end(curr_docum), word);
			double tf = count_word / curr_docum.size();
			map_word_TF_[word] = tf;
			word_to_document_freqs_[word].insert({ document_id, map_word_TF_[word] });
		}
		++document_count_;//количество документов
	}

	vector<Document> FindTopDocuments(const string& query) const {
		auto matched_documents = FindAllDocuments(query);

		//sort(matched_documents.begin(), matched_documents.end(), HasDocumentGreaterRelevance);
		sort(
			matched_documents.begin(),
			matched_documents.end(),
			[](const Document& lhs, const Document& rhs) {//лямбда взамен HasDocumentGreaterRelevance
				return lhs.relevance > rhs.relevance;
			}
		);
		if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT) {
			matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
		}
		return matched_documents;
	}

private:
	//переделать словарь «слово - документы» в более сложную структуру map<string, map<int, double>> word_to_document_freqs_, 
	//сопоставляющую каждому слову словарь «документ - TF».
	//Подумайте, как с этими данными быстро вычислять IDF.

	//map<string, set<int>> word_to_documents_; //словарь «слово - документы»
	int document_count_ = 0;
	map<string, double> map_word_TF_;
	map<string, map<int, double>> word_to_document_freqs_;
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

		Query query_words = ParseQuery(query);

		map<string, double> map_word_IDF_;
		for (auto& elm : word_to_document_freqs_) {
			string word = elm.first;
			double freq_w = size(elm.second);
			double idf = log(document_count_ / freq_w); // inverse document frequency
			map_word_IDF_[word] = idf;
		}

		const vector<string> plus_query_words = query_words.plus_word;
		const vector<string> minus_query_words = query_words.minus_word;
		map<int, double> document_to_relevance;
		for (const string& word : plus_query_words) {
			if (word_to_document_freqs_.count(word) == 0) {
				continue;
			}

			for (auto& curr_map : word_to_document_freqs_.at(word)) {
				double tf_idf = curr_map.second * map_word_IDF_.at(word);
				document_to_relevance[curr_map.first] += tf_idf;
			}
		}
		for (int it = 0; it < document_to_relevance.size(); it++) {
			auto curr_id = document_to_relevance.find(it)->first;
			for (auto& word : minus_query_words) {
				if (word_to_document_freqs_.count(word) != 0) {
					auto v_id_curr_doc = word_to_document_freqs_.find(word)->second;
					if (v_id_curr_doc.count(curr_id) != 0) {
						document_to_relevance.erase(it);
						continue;
					}
					else continue;
				}
				else continue;
			}
		}

		vector<Document> matched_documents;
		for (auto doc : document_to_relevance) {
			matched_documents.push_back({ doc.first, doc.second });
		}

		return matched_documents;
	}

	Query ParseQuery(const string& query) const {
		Query extension_query;
		vector<string> words_query = SplitIntoWordsNoStop(query);
		for (auto& word : words_query) {
			if (word[0] == '-') {//минус-слово
				auto s = word.substr(1);
				if (stop_words_.count(s)) {//проверка на стоп-слово; cтоп-слово в запросе не нужно учитывать при поиске, 
										   //даже если оно с минусом
					continue; //пропускаем стоп-слово
				}
				else extension_query.minus_word.push_back(s);
			}
			else {
				extension_query.plus_word.push_back(word);
			}
		}
		return extension_query;
	}
};

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
	//убираем кракозябры вместо русских букв
	SetConsoleCP(1251);//устанавливаем кодировку Windows-1251 для работы в стандартных потоках ввода/вывода cin, cout и т.д.
	SetConsoleOutputCP(1251);

	const SearchServer server = CreateSearchServer();

	const string query = ReadLine();
	vector<Document> v_top_relevance_docs = server.FindTopDocuments(query);
	for (auto doc : v_top_relevance_docs) {
		cout << "{ document_id = " << doc.id << ", relevance = " << doc.relevance << " }" << endl;
	}

	return 0;
}