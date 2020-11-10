//Напишите функцию, которая принимает строку - запрос и множество стоп - слов и возвращает новую строку.
//В новой строке после запроса идут стоп - слова через пробел, перед каждым стоит дефис.
//Передайте в accumulate четвёртым аргументом функцию, сворачивающую множество стоп-слов в «хвост» нужного формата.
//
//Пример:
//ЗАПРОС		
//"some tasty oranges"
//
//СТОП-СЛОВА
//{"of", "in"}	
//
//ВЫХОДНАЯ СТРОКА
//"some tasty oranges -of -in"

#include <iostream>
#include <numeric>
#include <vector>
#include <set>

using namespace std;

string FoldWithMinus(string left, string right) {
    return left + " -"s + right;
}

string AddStopWords(const string& query, const set<string>& stop_words) {
    return query + accumulate(begin(stop_words), end(stop_words), ""s, FoldWithMinus);
}

int main() {
    string query = "some tasty oranges";
    set<string> stop_words = { "of", "in" };
    string query_tail = AddStopWords(query, stop_words);
    cout << query_tail << endl;
    return 0;
}