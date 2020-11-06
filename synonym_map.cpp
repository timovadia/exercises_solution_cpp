// Вам дан словарь, состоящий из пар слов. Каждое слово является синонимом к парному ему слову. 
// Все слова в словаре различны. Для одного данного слова определите его синоним.

// Входные данные

// Программа получает на вход количество пар синонимов N. Далее следует N строк, 
// каждая строка содержит ровно два слова-синонима. После этого следует одно слово.

// Выходные данные

// Программа должна вывести синоним к данному слову.

// Sample Input:
// 3
// Hello Hi
// Bye Goodbye
// List Array
// Goodbye

// Sample Output:
// Bye

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, string> words;
    int n;
    string key_w, w, search_w; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> key_w >> w;
        words[key_w] = w;  
    }
    cin >> search_w;
    bool exist = 0;
    for (auto str : words) {
        if (str.first == search_w) {
           cout << str.second << endl;
           exist = 1;
        } else if (str.second == search_w) {
           cout << str.first << endl; 
           exist = 1;
        } 
    }
    if (!exist) cout << "Word don't exist." << endl;
    return 0;
}