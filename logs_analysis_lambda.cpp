/////////////////////////////////////////////
// Анализ логов поисковых запросов
/////////////////////////////////////////////
// Поисковые системы логируют запросы, чтобы потом исследовать их и улучшать качество поиска. 
// Напишите программу, которая изучает популярность определённой темы у пользователей. 
// На вход программа получает список поисковых запросов и слово. 
// Программа должна вывести количество поисковых запросов, содержащих данное слово.

// Пример ввода:
// 3
// apple juice 
// bionic beaver
// funny little beaver
// beaver

// Пример вывода:
// 2 

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

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

int main() {
    int queryCount = ReadLineWithNumber();

    vector<string> queries(queryCount);
    for (string& query : queries) {
        query = ReadLine();
    }
    string buzzword = ReadLine();

    cout << count_if(queries.begin(), queries.end(), [buzzword](const string& query) {
        return query.find(buzzword) != -1;
    });
    cout << endl; 

    return 0;
}